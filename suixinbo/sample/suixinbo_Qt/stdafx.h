#ifndef stdafx_h_
#define stdafx_h_

#include <set>
#include <time.h>

#include <QtWidgets>
#include <QtCore/QSettings>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkAccessManager>

#include "iLiveSDKWrap.h"
#include "Util.h"
#include "Event.h"
#include "PicDownHelper.h"
#include "SxbServerHelper.h"
#include "MainWindow.h"

#ifdef _DEBUG
	#pragma comment(lib, "Qt5Networkd.lib")
#else
	#pragma comment(lib, "Qt5Network.lib")
#endif//_DEBUG


#define SafeDelete(p) {delete p; p = 0;}
#define SafeDeleteArr(pArr) {delete[] pArr; pArr = 0;}

#define FromStdStr(str) QString::fromStdString(str)
#define FromBits(str) QString::fromLocal8Bit(str)

#define LiveMaster	"LiveMaster" //����
#define LiveGuest	"LiveGuest"  //�������
#define Guest		"Guest"		 //����

extern MainWindow* g_pMainWindow;

#endif//stdafx_h_