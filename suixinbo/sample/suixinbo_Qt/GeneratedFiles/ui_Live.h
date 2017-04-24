/********************************************************************************
** Form generated from reading UI file 'Live.ui'
**
** Created: Tue Apr 18 23:00:52 2017
**      by: Qt User Interface Compiler version 5.0.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LIVE_H
#define UI_LIVE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Live
{
public:
    QGroupBox *cameraGB;
    QPushButton *btnCloseCamera;
    QPushButton *btnOpenCamera;
    QComboBox *cbCamera;
    QGroupBox *screenShareGB;
    QPushButton *btnCloseScreenShare;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QSpinBox *sbX0;
    QSpinBox *sbY0;
    QSpinBox *sbX1;
    QSpinBox *sbY1;
    QSpinBox *sbFPS;
    QPushButton *btnUpdateScreenShare;
    QPushButton *btnOpenScreenShareArea;
    QPushButton *btnOpenScreenShareWnd;
    QGroupBox *microphoneGB;
    QPushButton *btnOpenMic;
    QPushButton *btnCloseMic;
    QSlider *hsMicVol;
    QSpinBox *sbMicVol;
    QTextEdit *teEditText;
    QPushButton *btnSendGroupMsg;
    QGroupBox *screenShareVideoGB;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *layoutScreenShare;
    QGroupBox *localCameraVideoGB;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *layoutLocalVideo;
    QGroupBox *remoteCameraVideoGB;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *layoutRemoteVideo0;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *layoutRemoteVideo1;
    QWidget *verticalLayoutWidget_5;
    QVBoxLayout *layoutRemoteVideo2;
    QGroupBox *playerGB;
    QPushButton *btnOpenPlayer;
    QPushButton *btnClosePlayer;
    QSlider *hsPlayerVol;
    QSpinBox *sbPlayerVol;
    QListWidget *liMembers;
    QLabel *lbTotalMemNum;
    QSpinBox *sbTotalMemNum;
    QGroupBox *pushStreamGB;
    QPushButton *btnStartPushStream;
    QPushButton *btnStopPushStream;
    QComboBox *cbPushDataType;
    QComboBox *cbPushEncodeType;
    QTextEdit *tePushStreamUrl;
    QGroupBox *recordGB;
    QPushButton *btnStopRecord;
    QPushButton *btnStartRecord;
    QComboBox *cbRecordDataType;
    QGroupBox *praiseGB;
    QPushButton *btnPraise;
    QLabel *lbPraiseNum;
    QListWidget *liMsgs;
    QGroupBox *SkinGB;
    QLabel *lbSkinSmooth;
    QLabel *lbSkinWhite;
    QSpinBox *sbSkinWhite;
    QSpinBox *sbSkinSmooth;
    QSlider *vsSkinSmooth;
    QSlider *vsSkinWhite;
    QGroupBox *externalCaptureGB;
    QPushButton *btnOpenExternalCapture;
    QPushButton *btnCloseExternalCapture;

    void setupUi(QWidget *Live)
    {
        if (Live->objectName().isEmpty())
            Live->setObjectName(QStringLiteral("Live"));
        Live->resize(1208, 572);
        cameraGB = new QGroupBox(Live);
        cameraGB->setObjectName(QStringLiteral("cameraGB"));
        cameraGB->setGeometry(QRect(10, 10, 191, 101));
        btnCloseCamera = new QPushButton(cameraGB);
        btnCloseCamera->setObjectName(QStringLiteral("btnCloseCamera"));
        btnCloseCamera->setEnabled(false);
        btnCloseCamera->setGeometry(QRect(100, 60, 79, 31));
        btnOpenCamera = new QPushButton(cameraGB);
        btnOpenCamera->setObjectName(QStringLiteral("btnOpenCamera"));
        btnOpenCamera->setGeometry(QRect(10, 60, 81, 31));
        cbCamera = new QComboBox(cameraGB);
        cbCamera->setObjectName(QStringLiteral("cbCamera"));
        cbCamera->setEnabled(true);
        cbCamera->setGeometry(QRect(10, 20, 168, 31));
        screenShareGB = new QGroupBox(Live);
        screenShareGB->setObjectName(QStringLiteral("screenShareGB"));
        screenShareGB->setGeometry(QRect(10, 190, 191, 211));
        btnCloseScreenShare = new QPushButton(screenShareGB);
        btnCloseScreenShare->setObjectName(QStringLiteral("btnCloseScreenShare"));
        btnCloseScreenShare->setEnabled(false);
        btnCloseScreenShare->setGeometry(QRect(10, 170, 171, 31));
        label = new QLabel(screenShareGB);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 20, 21, 16));
        label_2 = new QLabel(screenShareGB);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 50, 21, 16));
        label_3 = new QLabel(screenShareGB);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 80, 21, 16));
        label_4 = new QLabel(screenShareGB);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 110, 21, 16));
        label_5 = new QLabel(screenShareGB);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 140, 31, 21));
        sbX0 = new QSpinBox(screenShareGB);
        sbX0->setObjectName(QStringLiteral("sbX0"));
        sbX0->setGeometry(QRect(50, 20, 41, 22));
        sbX0->setButtonSymbols(QAbstractSpinBox::NoButtons);
        sbX0->setMaximum(10000);
        sbY0 = new QSpinBox(screenShareGB);
        sbY0->setObjectName(QStringLiteral("sbY0"));
        sbY0->setGeometry(QRect(50, 50, 41, 22));
        sbY0->setButtonSymbols(QAbstractSpinBox::NoButtons);
        sbY0->setMaximum(10000);
        sbX1 = new QSpinBox(screenShareGB);
        sbX1->setObjectName(QStringLiteral("sbX1"));
        sbX1->setGeometry(QRect(50, 80, 41, 22));
        sbX1->setButtonSymbols(QAbstractSpinBox::NoButtons);
        sbX1->setMaximum(10000);
        sbY1 = new QSpinBox(screenShareGB);
        sbY1->setObjectName(QStringLiteral("sbY1"));
        sbY1->setGeometry(QRect(50, 110, 41, 22));
        sbY1->setButtonSymbols(QAbstractSpinBox::NoButtons);
        sbY1->setMaximum(10000);
        sbFPS = new QSpinBox(screenShareGB);
        sbFPS->setObjectName(QStringLiteral("sbFPS"));
        sbFPS->setGeometry(QRect(50, 140, 131, 22));
        sbFPS->setButtonSymbols(QAbstractSpinBox::NoButtons);
        sbFPS->setMaximum(300);
        sbFPS->setValue(0);
        btnUpdateScreenShare = new QPushButton(screenShareGB);
        btnUpdateScreenShare->setObjectName(QStringLiteral("btnUpdateScreenShare"));
        btnUpdateScreenShare->setEnabled(false);
        btnUpdateScreenShare->setGeometry(QRect(100, 60, 81, 33));
        btnOpenScreenShareArea = new QPushButton(screenShareGB);
        btnOpenScreenShareArea->setObjectName(QStringLiteral("btnOpenScreenShareArea"));
        btnOpenScreenShareArea->setGeometry(QRect(100, 20, 81, 33));
        btnOpenScreenShareWnd = new QPushButton(screenShareGB);
        btnOpenScreenShareWnd->setObjectName(QStringLiteral("btnOpenScreenShareWnd"));
        btnOpenScreenShareWnd->setGeometry(QRect(100, 100, 81, 33));
        microphoneGB = new QGroupBox(Live);
        microphoneGB->setObjectName(QStringLiteral("microphoneGB"));
        microphoneGB->setGeometry(QRect(210, 135, 131, 111));
        btnOpenMic = new QPushButton(microphoneGB);
        btnOpenMic->setObjectName(QStringLiteral("btnOpenMic"));
        btnOpenMic->setGeometry(QRect(8, 20, 55, 35));
        btnCloseMic = new QPushButton(microphoneGB);
        btnCloseMic->setObjectName(QStringLiteral("btnCloseMic"));
        btnCloseMic->setEnabled(false);
        btnCloseMic->setGeometry(QRect(70, 20, 55, 35));
        hsMicVol = new QSlider(microphoneGB);
        hsMicVol->setObjectName(QStringLiteral("hsMicVol"));
        hsMicVol->setEnabled(false);
        hsMicVol->setGeometry(QRect(10, 75, 80, 20));
        hsMicVol->setMaximum(100);
        hsMicVol->setPageStep(10);
        hsMicVol->setValue(100);
        hsMicVol->setOrientation(Qt::Horizontal);
        sbMicVol = new QSpinBox(microphoneGB);
        sbMicVol->setObjectName(QStringLiteral("sbMicVol"));
        sbMicVol->setEnabled(false);
        sbMicVol->setGeometry(QRect(100, 75, 25, 20));
        sbMicVol->setButtonSymbols(QAbstractSpinBox::NoButtons);
        sbMicVol->setMaximum(100);
        sbMicVol->setSingleStep(10);
        sbMicVol->setValue(100);
        teEditText = new QTextEdit(Live);
        teEditText->setObjectName(QStringLiteral("teEditText"));
        teEditText->setGeometry(QRect(970, 490, 175, 71));
        btnSendGroupMsg = new QPushButton(Live);
        btnSendGroupMsg->setObjectName(QStringLiteral("btnSendGroupMsg"));
        btnSendGroupMsg->setGeometry(QRect(1150, 490, 52, 71));
        btnSendGroupMsg->setDefault(true);
        screenShareVideoGB = new QGroupBox(Live);
        screenShareVideoGB->setObjectName(QStringLiteral("screenShareVideoGB"));
        screenShareVideoGB->setGeometry(QRect(490, 10, 231, 201));
        verticalLayoutWidget_2 = new QWidget(screenShareVideoGB);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(10, 20, 211, 161));
        layoutScreenShare = new QVBoxLayout(verticalLayoutWidget_2);
        layoutScreenShare->setObjectName(QStringLiteral("layoutScreenShare"));
        layoutScreenShare->setContentsMargins(0, 0, 0, 0);
        localCameraVideoGB = new QGroupBox(Live);
        localCameraVideoGB->setObjectName(QStringLiteral("localCameraVideoGB"));
        localCameraVideoGB->setGeometry(QRect(490, 220, 231, 201));
        verticalLayoutWidget_3 = new QWidget(localCameraVideoGB);
        verticalLayoutWidget_3->setObjectName(QStringLiteral("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(10, 20, 211, 171));
        layoutLocalVideo = new QVBoxLayout(verticalLayoutWidget_3);
        layoutLocalVideo->setObjectName(QStringLiteral("layoutLocalVideo"));
        layoutLocalVideo->setContentsMargins(0, 0, 0, 0);
        remoteCameraVideoGB = new QGroupBox(Live);
        remoteCameraVideoGB->setObjectName(QStringLiteral("remoteCameraVideoGB"));
        remoteCameraVideoGB->setGeometry(QRect(730, 10, 231, 551));
        verticalLayoutWidget = new QWidget(remoteCameraVideoGB);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 20, 211, 171));
        layoutRemoteVideo0 = new QVBoxLayout(verticalLayoutWidget);
        layoutRemoteVideo0->setObjectName(QStringLiteral("layoutRemoteVideo0"));
        layoutRemoteVideo0->setContentsMargins(0, 0, 0, 0);
        verticalLayoutWidget_4 = new QWidget(remoteCameraVideoGB);
        verticalLayoutWidget_4->setObjectName(QStringLiteral("verticalLayoutWidget_4"));
        verticalLayoutWidget_4->setGeometry(QRect(10, 200, 211, 161));
        layoutRemoteVideo1 = new QVBoxLayout(verticalLayoutWidget_4);
        layoutRemoteVideo1->setObjectName(QStringLiteral("layoutRemoteVideo1"));
        layoutRemoteVideo1->setContentsMargins(0, 0, 0, 0);
        verticalLayoutWidget_5 = new QWidget(remoteCameraVideoGB);
        verticalLayoutWidget_5->setObjectName(QStringLiteral("verticalLayoutWidget_5"));
        verticalLayoutWidget_5->setGeometry(QRect(10, 369, 211, 171));
        layoutRemoteVideo2 = new QVBoxLayout(verticalLayoutWidget_5);
        layoutRemoteVideo2->setObjectName(QStringLiteral("layoutRemoteVideo2"));
        layoutRemoteVideo2->setContentsMargins(0, 0, 0, 0);
        playerGB = new QGroupBox(Live);
        playerGB->setObjectName(QStringLiteral("playerGB"));
        playerGB->setGeometry(QRect(210, 10, 131, 111));
        btnOpenPlayer = new QPushButton(playerGB);
        btnOpenPlayer->setObjectName(QStringLiteral("btnOpenPlayer"));
        btnOpenPlayer->setGeometry(QRect(8, 20, 55, 35));
        btnClosePlayer = new QPushButton(playerGB);
        btnClosePlayer->setObjectName(QStringLiteral("btnClosePlayer"));
        btnClosePlayer->setEnabled(false);
        btnClosePlayer->setGeometry(QRect(70, 20, 55, 35));
        hsPlayerVol = new QSlider(playerGB);
        hsPlayerVol->setObjectName(QStringLiteral("hsPlayerVol"));
        hsPlayerVol->setEnabled(false);
        hsPlayerVol->setGeometry(QRect(10, 75, 80, 20));
        hsPlayerVol->setMinimum(0);
        hsPlayerVol->setMaximum(100);
        hsPlayerVol->setValue(100);
        hsPlayerVol->setOrientation(Qt::Horizontal);
        sbPlayerVol = new QSpinBox(playerGB);
        sbPlayerVol->setObjectName(QStringLiteral("sbPlayerVol"));
        sbPlayerVol->setEnabled(false);
        sbPlayerVol->setGeometry(QRect(100, 75, 25, 20));
        sbPlayerVol->setButtonSymbols(QAbstractSpinBox::NoButtons);
        sbPlayerVol->setMinimum(0);
        sbPlayerVol->setMaximum(100);
        sbPlayerVol->setSingleStep(10);
        sbPlayerVol->setValue(100);
        liMembers = new QListWidget(Live);
        liMembers->setObjectName(QStringLiteral("liMembers"));
        liMembers->setGeometry(QRect(350, 50, 131, 321));
        liMembers->setContextMenuPolicy(Qt::CustomContextMenu);
        lbTotalMemNum = new QLabel(Live);
        lbTotalMemNum->setObjectName(QStringLiteral("lbTotalMemNum"));
        lbTotalMemNum->setGeometry(QRect(350, 20, 61, 21));
        sbTotalMemNum = new QSpinBox(Live);
        sbTotalMemNum->setObjectName(QStringLiteral("sbTotalMemNum"));
        sbTotalMemNum->setGeometry(QRect(420, 20, 61, 22));
        sbTotalMemNum->setReadOnly(true);
        sbTotalMemNum->setButtonSymbols(QAbstractSpinBox::NoButtons);
        pushStreamGB = new QGroupBox(Live);
        pushStreamGB->setObjectName(QStringLiteral("pushStreamGB"));
        pushStreamGB->setEnabled(true);
        pushStreamGB->setGeometry(QRect(10, 400, 331, 161));
        btnStartPushStream = new QPushButton(pushStreamGB);
        btnStartPushStream->setObjectName(QStringLiteral("btnStartPushStream"));
        btnStartPushStream->setEnabled(true);
        btnStartPushStream->setGeometry(QRect(10, 20, 81, 31));
        btnStopPushStream = new QPushButton(pushStreamGB);
        btnStopPushStream->setObjectName(QStringLiteral("btnStopPushStream"));
        btnStopPushStream->setEnabled(false);
        btnStopPushStream->setGeometry(QRect(100, 20, 81, 31));
        cbPushDataType = new QComboBox(pushStreamGB);
        cbPushDataType->setObjectName(QStringLiteral("cbPushDataType"));
        cbPushDataType->setEnabled(true);
        cbPushDataType->setGeometry(QRect(10, 70, 171, 31));
        cbPushEncodeType = new QComboBox(pushStreamGB);
        cbPushEncodeType->setObjectName(QStringLiteral("cbPushEncodeType"));
        cbPushEncodeType->setEnabled(true);
        cbPushEncodeType->setGeometry(QRect(10, 120, 171, 31));
        tePushStreamUrl = new QTextEdit(pushStreamGB);
        tePushStreamUrl->setObjectName(QStringLiteral("tePushStreamUrl"));
        tePushStreamUrl->setGeometry(QRect(190, 20, 131, 131));
        tePushStreamUrl->setReadOnly(true);
        recordGB = new QGroupBox(Live);
        recordGB->setObjectName(QStringLiteral("recordGB"));
        recordGB->setEnabled(true);
        recordGB->setGeometry(QRect(210, 258, 131, 141));
        btnStopRecord = new QPushButton(recordGB);
        btnStopRecord->setObjectName(QStringLiteral("btnStopRecord"));
        btnStopRecord->setEnabled(false);
        btnStopRecord->setGeometry(QRect(10, 60, 108, 31));
        btnStartRecord = new QPushButton(recordGB);
        btnStartRecord->setObjectName(QStringLiteral("btnStartRecord"));
        btnStartRecord->setEnabled(true);
        btnStartRecord->setGeometry(QRect(10, 20, 108, 31));
        cbRecordDataType = new QComboBox(recordGB);
        cbRecordDataType->setObjectName(QStringLiteral("cbRecordDataType"));
        cbRecordDataType->setEnabled(true);
        cbRecordDataType->setGeometry(QRect(10, 100, 107, 31));
        praiseGB = new QGroupBox(Live);
        praiseGB->setObjectName(QStringLiteral("praiseGB"));
        praiseGB->setGeometry(QRect(490, 430, 231, 131));
        btnPraise = new QPushButton(praiseGB);
        btnPraise->setObjectName(QStringLiteral("btnPraise"));
        btnPraise->setGeometry(QRect(50, 60, 121, 51));
        lbPraiseNum = new QLabel(praiseGB);
        lbPraiseNum->setObjectName(QStringLiteral("lbPraiseNum"));
        lbPraiseNum->setGeometry(QRect(50, 20, 121, 31));
        liMsgs = new QListWidget(Live);
        liMsgs->setObjectName(QStringLiteral("liMsgs"));
        liMsgs->setGeometry(QRect(970, 18, 231, 463));
        liMsgs->setFocusPolicy(Qt::NoFocus);
        liMsgs->setSelectionMode(QAbstractItemView::NoSelection);
        SkinGB = new QGroupBox(Live);
        SkinGB->setObjectName(QStringLiteral("SkinGB"));
        SkinGB->setGeometry(QRect(350, 380, 131, 181));
        lbSkinSmooth = new QLabel(SkinGB);
        lbSkinSmooth->setObjectName(QStringLiteral("lbSkinSmooth"));
        lbSkinSmooth->setGeometry(QRect(20, 150, 31, 21));
        lbSkinWhite = new QLabel(SkinGB);
        lbSkinWhite->setObjectName(QStringLiteral("lbSkinWhite"));
        lbSkinWhite->setGeometry(QRect(80, 150, 31, 21));
        sbSkinWhite = new QSpinBox(SkinGB);
        sbSkinWhite->setObjectName(QStringLiteral("sbSkinWhite"));
        sbSkinWhite->setGeometry(QRect(80, 20, 31, 22));
        sbSkinWhite->setButtonSymbols(QAbstractSpinBox::NoButtons);
        sbSkinWhite->setMaximum(9);
        sbSkinSmooth = new QSpinBox(SkinGB);
        sbSkinSmooth->setObjectName(QStringLiteral("sbSkinSmooth"));
        sbSkinSmooth->setGeometry(QRect(20, 20, 31, 22));
        sbSkinSmooth->setButtonSymbols(QAbstractSpinBox::NoButtons);
        sbSkinSmooth->setMaximum(9);
        vsSkinSmooth = new QSlider(SkinGB);
        vsSkinSmooth->setObjectName(QStringLiteral("vsSkinSmooth"));
        vsSkinSmooth->setGeometry(QRect(20, 50, 31, 91));
        vsSkinSmooth->setMaximum(9);
        vsSkinSmooth->setPageStep(1);
        vsSkinSmooth->setOrientation(Qt::Vertical);
        vsSkinWhite = new QSlider(SkinGB);
        vsSkinWhite->setObjectName(QStringLiteral("vsSkinWhite"));
        vsSkinWhite->setGeometry(QRect(80, 50, 31, 91));
        vsSkinWhite->setMaximum(9);
        vsSkinWhite->setPageStep(1);
        vsSkinWhite->setOrientation(Qt::Vertical);
        externalCaptureGB = new QGroupBox(Live);
        externalCaptureGB->setObjectName(QStringLiteral("externalCaptureGB"));
        externalCaptureGB->setGeometry(QRect(10, 120, 191, 61));
        btnOpenExternalCapture = new QPushButton(externalCaptureGB);
        btnOpenExternalCapture->setObjectName(QStringLiteral("btnOpenExternalCapture"));
        btnOpenExternalCapture->setGeometry(QRect(10, 20, 81, 31));
        btnCloseExternalCapture = new QPushButton(externalCaptureGB);
        btnCloseExternalCapture->setObjectName(QStringLiteral("btnCloseExternalCapture"));
        btnCloseExternalCapture->setEnabled(false);
        btnCloseExternalCapture->setGeometry(QRect(100, 20, 81, 31));

        retranslateUi(Live);
        QObject::connect(liMembers, SIGNAL(customContextMenuRequested(QPoint)), Live, SLOT(OnMemberListMenu(QPoint)));

        QMetaObject::connectSlotsByName(Live);
    } // setupUi

    void retranslateUi(QWidget *Live)
    {
        Live->setWindowTitle(QApplication::translate("Live", "\346\210\221\347\232\204\347\233\264\346\222\255\351\227\264", 0));
#ifndef QT_NO_WHATSTHIS
        Live->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        cameraGB->setTitle(QApplication::translate("Live", "\346\221\204\345\203\217\345\244\264", 0));
        btnCloseCamera->setText(QApplication::translate("Live", "\345\205\263\351\227\255\346\221\204\345\203\217\345\244\264", 0));
        btnOpenCamera->setText(QApplication::translate("Live", "\346\211\223\345\274\200\346\221\204\345\203\217\345\244\264", 0));
        cbCamera->setCurrentText(QString());
        screenShareGB->setTitle(QApplication::translate("Live", "\345\261\217\345\271\225\345\210\206\344\272\253", 0));
        btnCloseScreenShare->setText(QApplication::translate("Live", "\345\205\263\351\227\255\345\261\217\345\271\225\345\210\206\344\272\253", 0));
        label->setText(QApplication::translate("Live", "X0:", 0));
        label_2->setText(QApplication::translate("Live", "Y0:", 0));
        label_3->setText(QApplication::translate("Live", "X1:", 0));
        label_4->setText(QApplication::translate("Live", "Y1:", 0));
        label_5->setText(QApplication::translate("Live", "FPS:", 0));
        btnUpdateScreenShare->setText(QApplication::translate("Live", "\346\233\264\346\224\271\345\210\206\344\272\253\345\214\272\345\237\237", 0));
        btnOpenScreenShareArea->setText(QApplication::translate("Live", "\345\210\206\344\272\253\346\214\207\345\256\232\345\214\272\345\237\237", 0));
        btnOpenScreenShareWnd->setText(QApplication::translate("Live", "\345\210\206\344\272\253\346\214\207\345\256\232\347\252\227\345\217\243", 0));
        microphoneGB->setTitle(QApplication::translate("Live", "\351\272\246\345\205\213\351\243\216", 0));
        btnOpenMic->setText(QApplication::translate("Live", "\346\211\223\345\274\200", 0));
        btnCloseMic->setText(QApplication::translate("Live", "\345\205\263\351\227\255", 0));
        btnSendGroupMsg->setText(QApplication::translate("Live", "\345\217\221\351\200\201", 0));
        screenShareVideoGB->setTitle(QApplication::translate("Live", "\345\261\217\345\271\225\345\210\206\344\272\253", 0));
        localCameraVideoGB->setTitle(QApplication::translate("Live", "\346\234\254\345\234\260\347\224\273\351\235\242", 0));
        remoteCameraVideoGB->setTitle(QApplication::translate("Live", "\350\277\234\347\250\213\347\224\273\351\235\242", 0));
        playerGB->setTitle(QApplication::translate("Live", "\346\211\254\345\243\260\345\231\250", 0));
        btnOpenPlayer->setText(QApplication::translate("Live", "\346\211\223\345\274\200", 0));
        btnClosePlayer->setText(QApplication::translate("Live", "\345\205\263\351\227\255", 0));
        lbTotalMemNum->setText(QApplication::translate("Live", "\346\210\277\351\227\264\346\200\273\344\272\272\346\225\260:", 0));
        pushStreamGB->setTitle(QApplication::translate("Live", "\346\216\250\346\265\201", 0));
        btnStartPushStream->setText(QApplication::translate("Live", "\345\274\200\345\247\213\346\216\250\346\265\201", 0));
        btnStopPushStream->setText(QApplication::translate("Live", "\345\201\234\346\255\242\346\216\250\346\265\201", 0));
        recordGB->setTitle(QApplication::translate("Live", "\345\275\225\345\210\266", 0));
        btnStopRecord->setText(QApplication::translate("Live", "\345\201\234\346\255\242\345\275\225\345\210\266", 0));
        btnStartRecord->setText(QApplication::translate("Live", "\345\274\200\345\247\213\345\275\225\345\210\266", 0));
        cbRecordDataType->setCurrentText(QString());
        praiseGB->setTitle(QApplication::translate("Live", "\347\202\271\350\265\236", 0));
        btnPraise->setText(QApplication::translate("Live", "\344\270\272\344\270\273\346\222\255\347\202\271\350\265\236", 0));
        lbPraiseNum->setText(QApplication::translate("Live", "\347\202\271\350\265\236\346\225\260: 0", 0));
        SkinGB->setTitle(QApplication::translate("Live", "\347\276\216\351\242\234\\\347\276\216\347\231\275", 0));
        lbSkinSmooth->setText(QApplication::translate("Live", "\347\276\216\351\242\234", 0));
        lbSkinWhite->setText(QApplication::translate("Live", "\347\276\216\347\231\275", 0));
        externalCaptureGB->setTitle(QApplication::translate("Live", "\350\207\252\345\256\232\344\271\211\351\207\207\351\233\206", 0));
        btnOpenExternalCapture->setText(QApplication::translate("Live", "\346\211\223\345\274\200", 0));
        btnCloseExternalCapture->setText(QApplication::translate("Live", "\345\205\263\351\227\255", 0));
    } // retranslateUi

};

namespace Ui {
    class Live: public Ui_Live {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LIVE_H
