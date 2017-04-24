#include "stdafx.h"
#include "VideoRender.h"

#define VIEW_BKG_COLOR 0x60	//Ĭ�ϱ�����ɫֵ

#define FPS_Count 10 //ÿ��Ⱦ10�Σ�����һ��fps

VideoRender::VideoRender(QWidget* parent/* = 0*/, Qt::WindowFlags f/* = 0*/)
	:QWidget(parent, f)
	,m_colorFormat(COLOR_FORMAT_RGB24)
	,m_frameDataBufLen(0)
	,m_pFrameDataBuf(NULL)
	,m_pBkgDataBuf(NULL)
	,m_nRenderDataBufLen(0)
	,m_pRenderDataBuf(NULL)
	,m_pParentWidget(parent)
	,m_bPause(false)
	,m_lastClock(0)
	,m_nFpsCounter(FPS_Count)
	,m_nFps(0)
{
	//setFixedSize(200, 150);
	setStyleSheet("background-color:gray;");
}

void VideoRender::DoRender( VideoFrame *pFrameData )
{
	if (m_bPause)
	{
		return;
	}

	if (pFrameData == NULL || pFrameData->data_size == 0)
	{		
		return;
	}
	assert(pFrameData->desc.color_format == COLOR_FORMAT_RGB24);//SDK1.3�汾��demo��Ⱦģ��ֻ֧����ȾCOLOR_FORMAT_RGB24��ʽ��ͼ��

	m_identifier = pFrameData->identifier;

	if (m_frameDataBufLen!=pFrameData->data_size)
	{
		if (m_pFrameDataBuf)
		{
			SafeDeleteArr(m_pFrameDataBuf)
		}
		if (m_pBkgDataBuf)
		{
			SafeDeleteArr(m_pBkgDataBuf);
		}

		m_colorFormat = pFrameData->desc.color_format;
		m_frameDataBufLen = pFrameData->data_size;
		m_pFrameDataBuf = new uint8[m_frameDataBufLen];
		m_pBkgDataBuf = new uint8[m_frameDataBufLen];
		memset(m_pFrameDataBuf, 0, m_frameDataBufLen);
		memset(m_pBkgDataBuf, VIEW_BKG_COLOR, m_frameDataBufLen);
	}

	static void (* fun_table[4])(uint8*, uint8*, UINT, const SIZE &) = {&_CopyBits2Tex_None_0, &_CopyBits2Tex_None_90, &_CopyBits2Tex_None_180, &_CopyBits2Tex_None_270};

	if(pFrameData->desc.rotate == 0)//0
	{
		m_frameWidth = pFrameData->desc.width;
		m_frameHeight = pFrameData->desc.height;
	}
	else if(pFrameData->desc.rotate == 1)//90
	{
		m_frameWidth = pFrameData->desc.height;
		m_frameHeight = pFrameData->desc.width;
	}
	else if(pFrameData->desc.rotate == 2)//180
	{
		m_frameWidth = pFrameData->desc.width;
		m_frameHeight = pFrameData->desc.height;
	}
	else if(pFrameData->desc.rotate == 3)//270
	{
		m_frameWidth = pFrameData->desc.height;
		m_frameHeight = pFrameData->desc.width;
	}

	const SIZE size = {pFrameData->desc.width, pFrameData->desc.height};
	memset(m_pFrameDataBuf, 0, m_frameDataBufLen);
	fun_table[pFrameData->desc.rotate](m_pFrameDataBuf, pFrameData->data, m_frameDataBufLen, size);

	//paintPic(m_pBkgDataBuf);
	paintPic(m_pFrameDataBuf);
}

void VideoRender::Clear()
{
	m_frameWidth = width();
	m_frameHeight = height();
	paintPic(m_pBkgDataBuf);
	m_lastClock = 0;
}

void VideoRender::pauseRender()
{
	m_bPause = true;
	m_pParentWidget->setEnabled(false);
}

void VideoRender::recoverRender()
{
	m_bPause = false;
	m_pParentWidget->setEnabled(true);
}

void VideoRender::enterFullScreen()
{
	if (!isFullScreen())
	{
		m_pParentWidget = parentWidget();
		m_Rect = geometry();
		this->setParent(NULL);
		this->showFullScreen();
	}
}

void VideoRender::exitFullScreen()
{
	if ( isFullScreen() )
	{
		this->setParent(m_pParentWidget);
		this->setGeometry(m_Rect);
		this->showNormal();
	}
}

void VideoRender::paintEvent( QPaintEvent * event )
{
	QStyleOption opt;
	opt.initFrom(this);
	QPainter painter(this);
	style()->drawPrimitive(QStyle::PE_Widget, &opt, &painter, this);
	QWidget::paintEvent(event);
}

void VideoRender::mouseDoubleClickEvent( QMouseEvent * event )
{
	if (m_bPause)
	{
		return;
	}

	if (isFullScreen())
	{
		emit exitFullScreen(this);
	}
	else
	{
		emit applyFullScreen(this);
	}
}

void VideoRender::paintPic( uint8* pData )
{
	int winWidth = width();
	int winHeight = height();

	int srcWidth = m_frameWidth;
	int srcHeight = m_frameHeight;

	int dstWidth = 0;
	int dstHeight = 0;

	float fWinRate = winWidth/(float)winHeight;
	float fSrcRate = srcWidth/(float)srcHeight;

	if (fWinRate>fSrcRate)//�߲��䣬�����ڱ�
	{
		dstWidth = (int)(srcHeight * winWidth / (float)winHeight);
		dstHeight = srcHeight;
	}
	else//����,�����ڱ�
	{
		dstWidth = srcWidth;
		dstHeight = (int)(srcWidth * winHeight / (float)winWidth);
	}
	dstWidth = (dstWidth + 3) / 4 * 4; //��֤�����4�ı�����

	if(m_nRenderDataBufLen != dstWidth * dstHeight * 3)
	{
		if(m_pRenderDataBuf != NULL)
		{
			SafeDeleteArr(m_pRenderDataBuf);
		}

		m_nRenderDataBufLen = dstWidth * dstHeight * 3; //RGB24
		m_pRenderDataBuf = new uint8[m_nRenderDataBufLen];
	}
	memset(m_pRenderDataBuf, 0 , m_nRenderDataBufLen);//�����һ����Ⱦ

	SIZE srcSize = {srcWidth, srcHeight};
	SIZE dstSize = {dstWidth, dstHeight};

	_ResizeWithMendBlack(m_pRenderDataBuf, pData, m_nRenderDataBufLen, m_frameDataBufLen, dstSize, srcSize, 3);

	BITMAPINFO Bitmap;
	memset(&Bitmap,0,sizeof(BITMAPINFO));
	Bitmap.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);		
	Bitmap.bmiHeader.biWidth = dstWidth;
	Bitmap.bmiHeader.biHeight = -dstHeight;

	Bitmap.bmiHeader.biBitCount = 3 * 8;//COLOR_FORMAT_RGB24	
	Bitmap.bmiHeader.biPlanes = 1;	
	Bitmap.bmiHeader.biCompression = BI_RGB;//COLOR_FORMAT_RGB24	
	Bitmap.bmiHeader.biSizeImage = 0;	
	Bitmap.bmiHeader.biClrUsed = 0;
	Bitmap.bmiHeader.biXPelsPerMeter = 0;
	Bitmap.bmiHeader.biYPelsPerMeter = 0;	
	Bitmap.bmiHeader.biClrImportant = 0;

	HWND hWnd = (HWND)this->winId();
	HDC hDC = GetDC(hWnd);
	HDC hMemDC = CreateCompatibleDC(hDC);
	HBITMAP hMemBitmap= CreateCompatibleBitmap(hDC, winWidth, winHeight);
	SelectObject(hMemDC, hMemBitmap);

	SetStretchBltMode(hMemDC, HALFTONE);
	SetBrushOrgEx(hMemDC, 0, 0, NULL);
	StretchDIBits(hMemDC, 0, 0, winWidth, winHeight, 0, 0, dstWidth, dstHeight,		
		m_pRenderDataBuf, &Bitmap, DIB_RGB_COLORS, SRCCOPY);

	BitBlt(hDC, 0, 0, winWidth, winHeight, hMemDC, 0, 0, SRCCOPY);

	if(m_nFpsCounter > 0)
	{
		--m_nFpsCounter;
	}
	else
	{
		clock_t curClock = clock();
		time_t nSpace = curClock - m_lastClock;
		if (nSpace!=0)
		{
			m_nFps = 1000*FPS_Count/nSpace;
		}
		m_lastClock = curClock;
		m_nFpsCounter = FPS_Count;
	}

	QString info;
	if (m_identifier.empty())
	{
		m_identifier = g_pMainWindow->getUserId().toStdString();
	}
	info += FromStdStr(m_identifier);
	info += ",";
	info += QString("%1*%2").arg(srcWidth).arg(srcHeight);
	info += ",";
	info += QString::number(m_nFps);
	TextOutA( hDC, 0, 0, info.toLocal8Bit().data(), info.length() );

	DeleteObject(hMemBitmap);
	DeleteObject(hMemDC);	
	ReleaseDC(hWnd, hDC);
}

