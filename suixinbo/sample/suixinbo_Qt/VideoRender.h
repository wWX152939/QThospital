#ifndef VideoRender_h_
#define VideoRender_h_

#include <avsdk/av_common.h>

class VideoRender : public QWidget
{
	Q_OBJECT
public:
	VideoRender(QWidget* parent = 0, Qt::WindowFlags f = 0);
	void	DoRender(VideoFrame *pFrameData);
	void	Clear();

	void	pauseRender();
	void	recoverRender();

	void	enterFullScreen();//ȫ��
	void	exitFullScreen();//�˳�ȫ��

signals:
	void	applyFullScreen(VideoRender* pRender);
	void	exitFullScreen(VideoRender* pRender);

protected:
	void	paintEvent(QPaintEvent * event) override;
	void	mouseDoubleClickEvent( QMouseEvent * event ) override;

private:
	void	paintPic(uint8* pData);

private:
	std::string	m_identifier;
	ColorFormat m_colorFormat;
	uint32		m_frameDataBufLen;	//֡���ݳ���
	uint8*		m_pFrameDataBuf;	//֡���ݻ���
	uint8*		m_pBkgDataBuf;		//��������

	uint32		m_frameWidth;		//֡���
	uint32		m_frameHeight;		//֡�߶�

	uint32		m_nRenderDataBufLen;//��Ⱦ�����С
	uint8*		m_pRenderDataBuf;	//��Ⱦ����

	QWidget*	m_pParentWidget;
	QRect		m_Rect;
	bool		m_bPause;//�Ƿ���ͣ��Ⱦ	

	clock_t		m_lastClock;
	int			m_nFpsCounter;
	int			m_nFps;
};

#endif //VideoRender_h_
