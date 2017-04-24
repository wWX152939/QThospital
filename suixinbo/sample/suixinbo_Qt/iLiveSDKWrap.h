#ifndef iLiveSDKWrap_h_
#define iLiveSDKWrap_h_

#include <ilivesdk/iLiveLog.h>
#include <ilivesdk/iLiveSDK.h>
#include <ilivesdk/iLiveLoginMgr.h>
#include <ilivesdk/iLiveRoomMgr.h>

using namespace ilivesdk;

#pragma comment(lib, "iLiveSDK.lib")

class iLiveSDKWrap
{
public:
	static iLiveSDKWrap* getInstance();

	int initSdk(const int appId, const int accountType);///< ��ʼ��sdk
	void destroy();

	void setForceOfflineCallback( ForceOfflineCallback cb );
	void setGroupMessageCallBack( GropuMessageCallback cb );
	void setC2CMessageCallBack( C2CMessageCallback cb );
	void setSysemMessageCallback( SysemMessageCallback cb );
	void setLocalVideoCallBack( AVSupportVideoPreview::PreviewCallback pLocalVideoCB, void* pCustomData );
	void setRemoteVideoCallBack( AVSupportVideoPreview::PreviewCallback pRemoteVideoCB, void* pCustomData );//����Զ����Ƶ�ص�,��Ҫ�ڽ��뷿��ǰ����

	void LiveLogin ( const std::string szUserId, const std::string szUserSig, SuccessCalllback suc, ErrorCallback err, void* data );///< ��¼
	void LiveLogout( SuccessCalllback suc, ErrorCallback err, void* data );///< �ǳ�

	void createRoom( const iLiveRoomOption& roomOption, SuccessCalllback suc, ErrorCallback err, void* data );
	void joinRoom( const iLiveRoomOption& roomOption, SuccessCalllback suc, ErrorCallback err, void* data );
	void quitRoom( SuccessCalllback suc, ErrorCallback err, void* data );

	void requestViewList( const std::vector<std::string>& identifiers, const std::vector<View>& views, SuccessCalllback suc, ErrorCallback err, void* data );
	void cancelViewList( const std::vector<std::string>& identifiers, const std::vector<View>& views, SuccessCalllback suc, ErrorCallback err, void* data );
	void cancelAllView( SuccessCalllback suc, ErrorCallback err, void* data );

	void sendC2CMessage( const std::string dstUser, TIMMessage& message, SuccessCalllback suc, ErrorCallback err, void* data );
	void sendGroupMessage( TIMMessage& message, SuccessCalllback suc, ErrorCallback err, void* data );

	void startRecordVideo( const iLiveRecordOption& recordOption, SuccessCalllback suc, ErrorCallback err, void* data );
	void stopRecordVideo( ilivesdk::Type<std::list<std::string>&>::VlaueSuccessCallback suc, ErrorCallback err, void* data );

	void startPushStream( const iLivePushOption& pushOption, ilivesdk::Type<TIMStreamRsp&>::VlaueSuccessCallback suc, ErrorCallback err, void* data );
	void stopPushStream( uint64 channelId, SuccessCalllback suc, ErrorCallback err, void* data );

	void changeAuthority( uint64 authBits, const std::string& authBuffer, SuccessCalllback suc, ErrorCallback err, void* data );
	void changeRole( const std::string& szControlRole, SuccessCalllback suc, ErrorCallback err, void* data );

	int SetSkinSmoothGrade(int grade);
	int SetSkinWhitenessGrade(int grade);

	int getCameraList( std::vector< std::pair<std::string/*id*/, std::string/*name*/> >& cameraList );
	int	openCamera(std::string szCameraId);
	int closeCamera();

	int openExternalCapture();
	int closeExternalCapture();
	int fillExternalCaptureFrame( const VideoFrame& frame );

	int openMic();
	int	setMicVolume(uint32 value);
	uint32 getMicVolume();
	int closeMic();

	int openPlayer();
	int setPlayerVolume( uint32 value );
	uint32 getPlayerVolume();
	int closePlayer();

	int openScreenShare( HWND hWnd, uint32& fps );
	int openScreenShare( uint32& left, uint32& top, uint32& right, uint32& bottom, uint32& fps );
	int changeScreenShareSize( uint32& left, uint32& top, uint32& right, uint32& bottom );
	int closeScreenShare();

	bool getCurCameraState();
	bool getExternalCaptureState();
	bool getCurMicState();
	bool getCurPlayerState();
	E_ScreenShareState getScreenShareState();
	bool getPushStreamState();
	bool getRecordState();

private:
	iLiveSDKWrap();
	~iLiveSDKWrap();
};


#endif //iLiveSDKWrap_h_