#ifndef Util_h_
#define Util_h_


void _CopyBits2Tex_None_0(uint8* pDst, uint8* pSrc, UINT uLen, const SIZE & size);
void _CopyBits2Tex_None_90(uint8* pDst, uint8* pSrc, UINT uLen, const SIZE & size);
void _CopyBits2Tex_None_180(uint8* pDst, uint8* pSrc, UINT uLen, const SIZE & size);
void _CopyBits2Tex_None_270(uint8* pDst, uint8* pSrc, UINT uLen, const SIZE & size);
bool _ResizeWithMendBlack(uint8* pDst, uint8* pSrc, UINT uDstLen, UINT uSrcLen, const SIZE & dstSize, const SIZE & srcSize, UINT bpp);

QImage qt_fromWinHBITMAP(HDC hdc, HBITMAP bitmap, int w, int h);

void ShowTips( const QString& title, const QString& desc, QWidget* parent = NULL );
void ShowSucTips( const QString& desc, QWidget* parent = NULL );
void ShowErrorTips( const QString& desc, QWidget* parent = NULL );
void ShowCodeErrorTips( const int code, const QString& desc, QWidget* parent = NULL, const QString& title = "Error" );

QString getFileNameByUrl(QString szUrl);

#endif//Util_h_
