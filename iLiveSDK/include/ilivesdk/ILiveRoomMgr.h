#ifndef iLiveRoomMgr_h_
#define iLiveRoomMgr_h_

#include <imsdk/tim_group_c.h>
#include <imsdk/tim_msg.h>
#include <imsdk/tim_int.h>
#include <imsdk/tim_comm.h>
#include <avsdk/av_common.h>
#include <avsdk/av_device.h>
#include <ilivesdk/iLiveCommon.h>
#include <ilivesdk/iLiveRoomOption.h>
#include <ilivesdk/iLivePushOption.h>
#include <ilivesdk/iLiveRecordOption.h>

namespace ilivesdk
{
	/**
	@brief ��Ļ����״̬��
	@details ��Ļ����״̬��
	*/
	enum E_ScreenShareState
	{
		E_ScreenShareNone,	///< δ������Ļ����
		E_ScreenShareWnd,	///< ������ָ�����ڵĹ���
		E_ScreenShareArea,	///< ������ָ������Ĺ���
	};

	/**
	@brief �յ�Ⱥ��Ϣ�ص�����ָ������;
	@param [in] msg �յ���Ⱥ��Ϣ
	*/
	typedef void (*GropuMessageCallback)( const TIMMessage& msg );
	/**
	@brief �յ�C2C��Ϣ�ص�����ָ������;
	@param [in] msg �յ���C2C��Ϣ
	*/
	typedef void (*C2CMessageCallback)( const TIMMessage& msg );
	/**
	@brief �յ�ϵͳ��Ϣ�ص�����ָ������;
	*/
	typedef void (*SysemMessageCallback)( const TIMMessage& msg );

	/**
	@brief iLiveRoom�����ࡣ
	@details �����װ��iLiveRoom����ز����ӿڡ�
	*/
	class iLiveAPI iLiveRoomMgr
	{
		enum E_EnterRoomType
		{
			E_EnterRoomInvalid,
			E_EnterRoomCreate,
			E_EnterRoomJoin,
		};

		struct sRequestPair
		{
			sRequestPair(std::string id, View v);
			bool IdAndSrcTypeEqual(const sRequestPair& other);

			std::string identifier;
			View view;
		};

		class AVRoomMultiDelegate : public AVRoomMulti::Delegate
		{
		public:
			virtual void	OnEnterRoomComplete(int32 result, const std::string& error_info) override; //����AVContext::EnterRoom()���첽��������ĺ���
			virtual void	OnExitRoomComplete() override; //�˳�������ɻص�
			virtual void	OnRoomDisconnect(int32 reason, const std::string& error_info) override; //SDK�����˳�������ʾ
			virtual void	OnEndpointsUpdateInfo(AVRoomMulti::EndpointEventId event_id, std::vector<std::string> identifier_list) override; //�����Ա״̬�仯֪ͨ�ĺ���
			virtual void	OnPrivilegeDiffNotify(int32 privilege); //�����Ա��ĳ��ͨ������Ȩ��ȴȥʹ�����ͨ�����������µ��쳣֪ͨ�ĺ���
			virtual void	OnSemiAutoRecvCameraVideo(std::vector<std::string> identifier_list) override;//���Զ�ģʽ��������ͷ��Ƶ���¼�֪ͨ
			virtual void	OnSemiAutoRecvScreenVideo(std::vector<std::string> identifier_list) override;//���Զ�ģʽ������Ļ������¼�֪ͨ
			virtual void	OnSemiAutoRecvMediaFileVideo(std::vector<std::string> identifier_list) override;//���Զ�ģʽ���ղ�Ƭ���¼�֪ͨ
			virtual void	OnCameraSettingNotify(int32 width, int32 height, int32 fps) override;//����ͷ�ֱ��ʺ�֡���޸�֪ͨ
			virtual void	OnSwitchRoomComplete(int32 result, const std::string& error_info) override;//����switchRoom()���첽��������ĺ���
		};
		
		class SendC2CMessageCB : public TIMCallBack
		{
		public:
			virtual void OnSuccess();
			virtual void OnError(int code, const std::string &desc);
		};

		class SendGroupMessageCB : public TIMCallBack
		{
		public:
			virtual void OnSuccess();
			virtual void OnError(int code, const std::string &desc);
		};

		class StartPushStreamCB : public TIMValueCallBack<TIMStreamRsp&>
		{
		public:
			virtual void OnSuccess(TIMStreamRsp& value);
			virtual void OnError(int code, const std::string &desc);
		};

		class StopPushStreamCB: public TIMCallBack
		{
		public:
			virtual void OnSuccess();
			virtual void OnError(int code, const std::string &desc);
		};

		class StartRecordCB : public TIMCallBack
		{
		public:
			virtual void OnSuccess();
			virtual void OnError(int code, const std::string &desc);
		};

		class StopRecordCB : public TIMValueCallBack< std::list<std::string>& >
		{
		public:
			virtual void OnSuccess(std::list<std::string>& value);
			virtual void OnError(int code, const std::string &desc);
		};

		class MessageCallBack : public TIMMessageCallBack
		{
		public:
			virtual void OnNewMessage(const std::vector<TIMMessage> &msgs) override;
		};

	public:
		/**
		@brief ��ȡ��������
		@return ���ش���ĵ�������
		*/
		static iLiveRoomMgr*	getInstance();

		/**
		@brief ����Ԥ������ָ�롣
		@param [in] pPreTreatmentFun Ԥ������ָ�룬�μ�AVSupportVideoPreTreatment::PreTreatmentFun�Ķ��塣
		@param [in] pCustomData ҵ����Զ���Ĳ���������ִ�лص�����ʱԭ�ⲻ���ط��ظ�ҵ��ࡣ���ڻص�����ͨ����ĳ����ľ�̬����������ͨ���ò���ָ����ǰ����Ӧ����ľ������
		@remark ҵ���ʵ�ָ�Ԥ��������Ȼ����SDKͬ����������ʵ��Ԥ��������ע�����Ԥ��������ʱ��Ҫ���ã���ÿ�����10ms�ڣ�ͬʱ���ܸı�ͼ���С��ͼ����ɫ��ʽ��
		*/
		void					setPreTreatmentFun( AVSupportVideoPreTreatment::PreTreatmentFun pPreTreatmentFun, void* pCustomData );
		/**
		@brief ���ñ�����Ƶ�ص�����ָ�롣
		@param [in] pLocalVideoCB ������Ƶ�ص�����ָ�룬�μ�AVSupportVideoPreview::PreviewCallback�Ķ��塣
		@param [in] pCustomData ҵ����Զ���Ĳ���������ִ�лص�����ʱԭ�ⲻ���ط��ظ�ҵ��ࡣ���ڻص�����ͨ����ĳ����ľ�̬����������ͨ���ò���ָ����ǰ����Ӧ����ľ������
		@remark ҵ���ʵ�ָûص�������SDK��ûص��������뱾����Ƶ������ݣ�ҵ����õ����ݺ������Ⱦ��ʾ;
		*/
		void					setLocalVideoCallBack( AVSupportVideoPreview::PreviewCallback pLocalVideoCB, void* pCustomData );
		/**
		@brief ����Զ����Ƶ�ص�����ָ�롣
		@param [in] pRemoteVideoCB Զ����Ƶ�ص�����ָ�룬�μ�AVSupportVideoPreview::PreviewCallback�Ķ��塣
		@param [in] pCustomData ҵ����Զ���Ĳ���������ִ�лص�������ԭ�ⲻ���ط��ظ�ҵ��ࡣ���ڻص�����ͨ����ĳ����ľ�̬����������ͨ���ò���ָ����ǰ����Ӧ����ľ������
		@remark ҵ���ʵ�ָûص�������SDK��ûص���������Զ����Ƶ������ݣ�ҵ����õ����ݺ������Ⱦ��ʾ;
		*/
		void					setRemoteVideoCallBack( AVSupportVideoPreview::PreviewCallback pRemoteVideoCB, void* pCustomData );

		/**
		@brief �����յ�Ⱥ��Ϣ�Ļص�����ָ�롣
		@param [in] cb Ⱥ��Ϣ�Ļص�����ָ��;
		@note ֻ���յ���ǰ���ڷ����Ⱥ��Ϣ;
		*/
		void					setGroupMessageCallBack( GropuMessageCallback cb );
		/**
		@brief �����յ�C2C��Ϣ�Ļص�����ָ�롣
		@param [in] cb C2C��Ϣ�Ļص�����ָ��;
		*/
		void					setC2CMessageCallBack( C2CMessageCallback cb );
		/**
		@brief �����յ�ϵͳ��Ϣ�Ļص�����ָ�롣
		@param [in] cb ϵͳ��Ϣ�Ļص�����ָ��;
		@remark �ڼ���Ⱥ��Ⱥ��ɢ������£����յ�ϵͳ��Ϣ;
		*/
		void					setSysemMessageCallback( SysemMessageCallback cb );

		/**
		@brief ����ֱ������(�����˵���)��
		@param [in] roomOption �������á�
		@param [in] suc �ɹ��Ļص�������
		@param [in] err ʧ�ܵĻص�������
		@param [in] data �û��Զ�������ݵ�ָ�룬�ڳɹ���ʧ�ܵĻص�������ԭ�ⲻ���ط���;
		*/
		void					createRoom( const iLiveRoomOption& roomOption, SuccessCalllback suc, ErrorCallback err, void* data );
		/**
		@brief ����ֱ������(���ڶ˵���)��
		@param [in] roomOption �������á�
		@param [in] suc �ɹ��Ļص�������
		@param [in] err ʧ�ܵĻص�������
		@param [in] data �û��Զ�������ݵ�ָ�룬�ڳɹ���ʧ�ܵĻص�������ԭ�ⲻ���ط���;
		*/
		void					joinRoom( const iLiveRoomOption& roomOption, SuccessCalllback suc, ErrorCallback err, void* data );
		/**
		@brief �˳�ֱ���䡣
		@param [in] suc �ɹ��Ļص�������
		@param [in] err ʧ�ܵĻص�������
		@param [in] data �û��Զ�������ݵ�ָ�룬�ڳɹ���ʧ�ܵĻص�������ԭ�ⲻ���ط���;
		*/
		void					quitRoom( SuccessCalllback suc, ErrorCallback err, void* data );

		/**
		@brief ����C2C��Ϣ��
		@param [in] dstUser ���շ�id��
		@param [in] message IM��Ϣ��
		@param [in] suc �ɹ��Ļص�������
		@param [in] err ʧ�ܵĻص�������
		@param [in] data �û��Զ�������ݵ�ָ�룬�ڳɹ���ʧ�ܵĻص�������ԭ�ⲻ���ط���;
		*/
		void					sendC2CMessage( const std::string dstUser, TIMMessage& message, SuccessCalllback suc, ErrorCallback err, void* data );
		/**
		@brief ����Group��Ϣ��
		@param [in] message IM��Ϣ��
		@param [in] suc �ɹ��Ļص�������
		@param [in] err ʧ�ܵĻص�������
		@param [in] data �û��Զ�������ݵ�ָ�룬�ڳɹ���ʧ�ܵĻص�������ԭ�ⲻ���ط���;
		@remark  �˴�����Group��Ϣ���������ڵ�ǰֱ�����з���Group��Ϣ��
		*/
		void					sendGroupMessage( TIMMessage& message, SuccessCalllback suc, ErrorCallback err, void* data );
		
		/**
		@brief ����һ��������Ա����Ƶ���档
		@param [in] identifiers �������id�б�;
		@param [in] views �������view�б�;
		@param [in] suc �ɹ��Ļص�������
		@param [in] err ʧ�ܵĻص�������
		@param [in] data �û��Զ�������ݵ�ָ�룬�ڳɹ���ʧ�ܵĻص�������ԭ�ⲻ���ط���;
		@note 
		1��identifiers��views����һһ��Ӧ;<br/>
		2��requestViewList��������ȴ��첽�ص�����ִ�н����󣬲��ܽ����µ�requestViewList������<br/>
		3��requestViewList��cancelViewList��cancelAllView���ܲ���ִ�У���ͬһʱ��ֻ�ܽ���һ�ֲ�����<br/>
		4����������ǰ����ȼ��ó�Ա�Ƿ��ж�Ӧ����ƵԴ��
		*/
		void					requestViewList( const std::vector<std::string>& identifiers, const std::vector<View>& views, SuccessCalllback suc, ErrorCallback err, void* data );
		/**
		@brief  ȡ��ָ���û��Ļ��档
		@param [in] identifiers ȡ��������û��б�
		@param [in] views ȡ�������view�б�;
		@param [in] suc �ɹ��Ļص�������
		@param [in] err ʧ�ܵĻص�������
		@param [in] data �û��Զ�������ݵ�ָ�룬�ڳɹ���ʧ�ܵĻص�������ԭ�ⲻ���ط���;
		@note identifiers��views����һһ��Ӧ;requestViewList��cancelViewList��cancelAllView���ܲ���ִ�У���ͬһʱ��ֻ�ܽ���һ�ֲ���;
		*/
		void					cancelViewList( const std::vector<std::string>& identifiers, const std::vector<View>& views, SuccessCalllback suc, ErrorCallback err, void* data );
		/**
		@brief ȡ�������������Ƶ���档
		@param [in] suc �ɹ��Ļص�������
		@param [in] err ʧ�ܵĻص�������
		@param [in] data �û��Զ�������ݵ�ָ�룬�ڳɹ���ʧ�ܵĻص�������ԭ�ⲻ���ط���;
		@note requestViewList��cancelViewList��cancelAllView���ܲ���ִ�У���ͬһʱ��ֻ�ܽ���һ�ֲ�����
		*/
		void					cancelAllView( SuccessCalllback suc, ErrorCallback err, void* data );

		/**
		@brief  ����ͨ������Ȩ�ޡ�
		@details ͨ������Ȩ�ް����Ƿ���Դ�������/���뷿��/������Ƶ/������Ƶ/��������ͷ��Ƶ/��������ͷ��Ƶ/������Ļ��Ƶ/������Ļ��Ƶ�ȡ�
		@param [in] authBits ͨ������Ȩ��λ,��<ilivesdk/iLiveRoomOption.h>�ļ��п��Բ鿴����Ȩ��λ���塣
		@param [in] authBuffer ͨ������Ȩ��λ�ļ��ܴ���
		@param [in] suc �ɹ��Ļص�������
		@param [in] err ʧ�ܵĻص�������
		@param [in] data �û��Զ�������ݵ�ָ�룬�ڳɹ���ʧ�ܵĻص�������ԭ�ⲻ���ط���;
		*/
		void					changeAuthority( uint64 authBits, const std::string& authBuffer, SuccessCalllback suc, ErrorCallback err, void* data );
		/**
		@brief ���Ľ�ɫ��
		@details ���Ľ�ɫ�������޸���Ƶ��������Ƶ������Ҫ�ڽ��뷿��ǰָ�����ҽ��뷿���Ժ����޸ġ�
		@param [in] szControlRole ��ɫ�ַ���(���û�App�Ŀ���̨����)��
		@param [in] suc �ɹ��Ļص�������
		@param [in] err ʧ�ܵĻص�������
		@param [in] data �û��Զ�������ݵ�ָ�룬�ڳɹ���ʧ�ܵĻص�������ԭ�ⲻ���ط���;
		*/
		void					changeRole( const std::string& szControlRole, SuccessCalllback suc, ErrorCallback err, void* data );

		/**
		@brief �������ճ̶ȡ�
		@param [in] grade ���ճ̶Ȳ�����gradeȡֵ��Χ��0-9֮�䣬0��ʾ���չر�
		@return ����ֵΪNO_ERRʱ��ʾ�ɹ��������ʾʧ�ܡ�
		*/
		int						SetSkinSmoothGrade(int grade);
		
		/**
		@brief �������׳̶ȡ�
		@param [in] grade ���׳̶Ȳ�����gradeȡֵ��Χ��0-9֮�䣬0��ʾ���׹ر�
		@return ����ֵΪNO_ERRʱ��ʾ�ɹ��������ʾʧ�ܡ�
		*/
		int						SetSkinWhitenessGrade(int grade);

		/**
		@brief ��ȡ����������õ�����ͷ�б�
		@param [out] cameraList ���ػ�ȡ����������б�,������ص��б�Ϊ�գ���ʾ�����޿�������ͷ��
		@return �������,NO_ERR��ʾ�޴���;
		*/
		int						getCameraList( std::vector< std::pair<std::string/*id*/, std::string/*name*/> > &cameraList );
		/**
		@brief ������ͷ��
		@param [in] szCameraId ͨ��getCameraList()������ȡ������ͷ�б��е�ĳ������ͷid��
		@return ���������NO_ERR��ʾ�޴���;
		@note 
		1��������ͷ�ɹ�������û����ϴ���ƵȨ�ޣ�����Զ���ʼ�ϴ�����ͷ��Ƶ;<br/>
		2��������ͷ�����ʹ��Զ���ɼ��ǻ���Ĳ���;���ͬʱ�򿪣��᷵�ش���AV_ERR_EXCLUSIVE_OPERATION;
		*/
		int						openCamera( std::string szCameraId );
		/**
		@brief �رյ�ǰ�򿪵�����ͷ��
		@return ���������NO_ERR��ʾ�޴���
		*/
		int						closeCamera();

		/**
		@brief ���Զ���ɼ���
		@return ���������NO_ERR��ʾ�޴���;
		@note 
		1�����Զ���ɼ��ɹ�������û����ϴ���ƵȨ�ޣ��û�ͨ��fillExternalCaptureFrame()�����ÿһ֡���潫��ͨ��sdk�ϴ�;<br/>
		2��������ͷ�����ʹ��Զ���ɼ��ǻ���Ĳ���;���ͬʱ�򿪣��᷵�ش���AV_ERR_EXCLUSIVE_OPERATION;
		3��Ŀǰ�汾�����Զ���ɼ����������չ��ܽ���Ч;
		*/
		int						openExternalCapture();
		/**
		@brief �ر��Զ���ɼ���
		@return ���������NO_ERR��ʾ�޴���;
		*/
		int						closeExternalCapture();
		/**
		@brief �ⲿ������Ƶ���ݽӿڡ�
		@return ���������NO_ERR��ʾ�޴���;
		@note 
		1��Ŀǰsdk֧�ֵ�VideoFrame��ʽֻ��COLOR_FORMAT_RGB24��COLOR_FORMAT_I420,����������Ƶ֡���Ǵ����ָ�ʽ��������ERR_NOT_SUPPORT;<br/>
		2����Ƶֻ֡������Щ����(176*144��192*144��320*240��480*360��640*368��640*480��960*540��1280*720��144*176��144*192��240*320��360*480��368*640��480*640��540*960��720*1280),���򷵻�AV_ERR_INVALID_ARGUMENT;<br/>
		3����Ƶ֡�������10-15֡����;
		4���������Ƶ֡�ֱ���������ڿ���̨SPEAR�������õ�ֵ����Ƶ���ᱻ�ü���SPEAR���õķֱ���(������Ԥ������͹��ڶ˻����С���᲻һ��);<br/>
			���С�ڿ���̨���õ�ֵ�����ᰴ�մ������Ƶ֡��С���뵽���ڶ�(�����ᱻ�Ŵ󵽿���̨���õ�ֵ);
		*/
		int						fillExternalCaptureFrame(const VideoFrame& frame);

		/**
		@brief ��ȡ����������õ���˷��б�
		@param [out] micList ���ػ�ȡ������˷��б�,������ص��б�Ϊ�գ���ʾ�����޿�����˷硣
		@return �������,NO_ERR��ʾ�޴���;
		*/
		int						getMicList( std::vector< std::pair<std::string/*id*/, std::string/*name*/> > &micList);
		/**
		@brief ����˷硣
		@param [in] szMicId ͨ��getMicList()������ȡ����˷��б��е�ĳ����˷�id��
		@return ���������NO_ERR��ʾ�޴���;
		@note ����˷�ɹ�������û����ϴ�����Ȩ�ޣ�����Զ���ʼ�ϴ���˷���Ƶ��
		*/
		int						openMic( std::string szMicId );
		/**
		@brief ������˷�������
		@param [in] value ������˷��Ŀ������,ȡֵ��Χ[0,100].
		@return ���������NO_ERR��ʾ�޴���;
		@note ֻ�д�����˷���ܽ�������,���򷵻�ERR_WRONG_STATE;
		*/
		int						setMicVolume(uint32 value);
		/**
		@brief ��ȡ��˷�������
		@return ������˷�����,δ����˷��򷵻�0;
		*/
		uint32					getMicVolume();
		/**
		@brief �رյ�ǰ�򿪵���˷硣
		@return ���������NO_ERR��ʾ�޴���
		*/
		int						closeMic();
		
		/**
		@brief ��ȡ����������õ��������б�
		@param [out] playerList ���ػ�ȡ�����������б�,������ص��б�Ϊ�գ���ʾ�����޿�����������
		@return �������,NO_ERR��ʾ�޴���;
		*/
		int						getPlayerList( std::vector< std::pair<std::string/*id*/, std::string/*name*/> > &playerList );
		/**
		@brief ����������
		@param [in] szPlayerId ͨ��getPlayerList()������ȡ���������б��е�ĳ��������id��
		@return ���������NO_ERR��ʾ�޴���;
		@note ���������ɹ�������û��н�����ƵȨ�ޣ�����Զ���ʼ����Զ����Ƶ��
		*/
		int						openPlayer( std::string szPlayerId );
		/**
		@brief ����������������
		@param [in] value ������������Ŀ������,ȡֵ��Χ[0,100].
		@return ���������NO_ERR��ʾ�޴���;
		@note ֻ�д������������ܽ�������,���򷵻�ERR_WRONG_STATE;
		*/
		int						setPlayerVolume( uint32 value );
		/**
		@brief ��ȡ������������
		@return ��������������,δ���������򷵻�0;
		*/
		uint32					getPlayerVolume();
		/**
		@brief �رյ�ǰ�򿪵���������
		@return ���������NO_ERR��ʾ�޴���
		*/
		int						closePlayer();

		/**
		@brief ����Ļ����(ָ������)��
		@param [in] hWnd ��Ҫ����Ĵ��ھ����
		@param [in] fps ����֡��,ȡֵ��Χ[MIN_SCREEN_VIDEO_CAPTURE_FPS-MAX_SCREEN_VIDEO_CAPTURE_FPS],����ο�MIN_SCREEN_VIDEO_CAPTURE_FPS��MAX_SCREEN_VIDEO_CAPTURE_FPS������Ķ��塣
		@return ���������NO_ERR��ʾ�޴���
		@remark ����Ĳ���(fps)���ܻᾭ��sdk�ڲ���������ͨ�����÷�ʽ���ظ������ߣ�ʵ�ʷ���ʹ�õ�fps�Դ���ֵΪ׼;
		*/
		int						openScreenShare( HWND hWnd, uint32& fps );
		/**
		@brief ����Ļ����(ָ������)��
		@param [in] left/top/right/bottom ��Ҫ������Ļ�������������Ͻ�����(left, top)�����½�����(right, bottom)������������Ļ�����Ͻ�����Ϊԭ��ġ�
		@param [in] fps ����֡�ʣ�ȡֵ��Χ[MIN_SCREEN_VIDEO_CAPTURE_FPS-MAX_SCREEN_VIDEO_CAPTURE_FPS]������ο�MIN_SCREEN_VIDEO_CAPTURE_FPS��MAX_SCREEN_VIDEO_CAPTURE_FPS������Ķ��塣
		@return ���������NO_ERR��ʾ�޴���
		@remark ����Ĳ������ܻᾭ��sdk�ڲ�ϸ΢�ĵ�������ͨ�����÷�ʽ���ظ������ߣ�ʵ�ʵķ��������Դ��ص�ֵΪ׼;
		*/
		int						openScreenShare( uint32& left, uint32& top, uint32& right, uint32& bottom, uint32& fps );
		/**
		@brief ��Ļ���������,��̬�޸���Ļ���������
		@param [in] left/top/right/bottom ��Ҫ������Ļ�������������Ͻ�����(left, top)�����½�����(right, bottom)������������Ļ�����Ͻ�����Ϊԭ��ġ�
		@return ���������NO_ERR��ʾ�޴���
		@remark ����Ĳ������ܻᾭ��sdk�ڲ�ϸ΢�ĵ�������ͨ�����÷�ʽ���ظ������ߣ�ʵ�ʵķ��������Դ��ص�ֵΪ׼;
		@note �˽ӿ�ֻ���ڴ���ָ���������Ļ����ʱ����Ч,����״̬�½��᷵��ERR_WRONG_STATE����;
		*/
		int						changeScreenShareSize( uint32& left, uint32& top, uint32& right, uint32& bottom );
		/**
		@brief �ر���Ļ����
		@return ���������NO_ERR��ʾ�޴���
		@remark ָ�����ڵ���Ļ�����ָ���������Ļ�������ô˽ӿ����ر�.
		*/
		int						closeScreenShare();

		/**
		@brief ��ʼ������
		@param [in] pushOption ��������ѡ�
		@param [in] suc �ɹ��Ļص�������
		@param [in] err ʧ�ܵĻص�������
		@param [in] data �û��Զ�������ݵ�ָ�룬�ڳɹ���ʧ�ܵĻص�������ԭ�ⲻ���ط���;
		@remark �����ɹ��Ļص������У�sdk�ᴫ��TIMStreamRsp�ṹ���˽ṹ�а�����Ƶ��ID(channel_id)����ֹͣ����ʱ��ҵ�����Ҫ�����Ƶ��ID.
		*/
		void					startPushStream( const iLivePushOption& pushOption, Type<TIMStreamRsp&>::VlaueSuccessCallback suc, ErrorCallback err, void* data );
		/**
		@brief ֹͣ������
		@param [in] channelId ֹͣ������Ƶ��ID��SDK��startPushStream()�����Ļص��д��ظ�ҵ����Ƶ��ID��
		@param [in] suc �ɹ��Ļص�������
		@param [in] err ʧ�ܵĻص�������
		@param [in] data �û��Զ�������ݵ�ָ�룬�ڳɹ���ʧ�ܵĻص�������ԭ�ⲻ���ط���;
		*/
		void					stopPushStream( uint64 channelId, SuccessCalllback suc, ErrorCallback err, void* data );

		/**
		@brief ��ʼ¼�ơ�
		@param [in] recordOption ¼������ѡ�
		@param [in] suc �ɹ��Ļص�������
		@param [in] err ʧ�ܵĻص�������
		@param [in] data �û��Զ�������ݵ�ָ�룬�ڳɹ���ʧ�ܵĻص�������ԭ�ⲻ���ط���;
		*/
		void					startRecordVideo( const iLiveRecordOption& recordOption, SuccessCalllback suc, ErrorCallback err, void* data );
		/**
		@brief ֹͣ¼�ơ�
		@param [in] suc �ɹ��Ļص�������
		@param [in] err ʧ�ܵĻص�������
		@param [in] data �û��Զ�������ݵ�ָ�룬�ڳɹ���ʧ�ܵĻص�������ԭ�ⲻ���ط���;
		@remark ֹͣ¼�Ƴɹ��ص�������¼����Ƶ�ļ���ID�б�; ҵ��࿪���Զ�¼��ʱ�������ؿ��б��û���ֱ�ӵ���̨��ѯ��
		*/
		void					stopRecordVideo( Type<std::list<std::string>&>::VlaueSuccessCallback suc, ErrorCallback err, void* data );
		/**
		@brief ��ȡ��ǰ����ͷ״̬
		@return true:�� false���ر�
		*/
		bool					getCurCameraState();
		/**
		@brief ��ȡ�Զ���ɼ�״̬��
		@return true:�� false���ر�
		*/
		bool					getExternalCaptureState();
		/**
		@brief ��ȡ��ǰ��˷�״̬
		@return true:�� false���ر�
		*/
		bool					getCurMicState();
		/**
		@brief ��ȡ��ǰ������״̬
		@return true:�� false���ر�
		*/
		bool					getCurPlayerState();
		/**
		@brief ��ȡ��ǰ��Ļ����״̬
		@return ��ǰ��Ļ����״̬
		*/
		E_ScreenShareState		getScreenShareState();
		/**
		@brief ��ȡ��ǰ����״̬
		@return true:�� false���ر�
		*/
		bool					getPushStreamState();
		/**
		@brief ��ȡ��ǰ��Ƶ¼��״̬
		@return true:�� false���ر�
		*/
		bool					getRecordState();

	private:
		iLiveRoomMgr();
		~iLiveRoomMgr();

		void					ResetAllState();
		int						SetupAVRoom();

		void					CommentViewList(bool isCancelView);
		void					UpdateViewList(std::vector<std::string>& identifierList, std::vector<View>& viewList);

		void					OnEnterAVRoomSuc();
		void					OnEnterAVRoomErr(int code, const char* desc);

		void					OnQuitAVRoomComplete();

		static void				OnCreateIMGroupSuccess(const char* group_id, void* data);
		static void				OnCreateIMGroupError(int code, const char* desc, void* data);

		static void				OnJoinIMGroupSuccess(void* data);
		static void				OnJoinIMGroupError(int code, const char* desc, void* data);

		static void				OnQuitIMGroupSuccess(void* data);
		static void				OnQuitIMGroupError(int code, const char* desc, void* data);

		static void				OnAudioDeviceOperationCallback(AVDeviceMgr *pAudMgr, AVDevice::DeviceOperation oper, const std::string &deviceId, int retCode, void *pCustomData);
		static void				OnAudioDeviveDetectNotify(AVDeviceMgr* device_mgr, DetectedDeviceInfo& info, bool*pbSelect, void* custom_data);

		static void				OnVideoDeviceOperationCallback(AVDeviceMgr *pVidMgr, AVDevice::DeviceOperation oper, const std::string &deviceId, int retCode, void *pCustomData);
		static void				OnVideoDeviceChangeCallback(AVDeviceMgr *pVidMgr, void *pCustomData);

		static void				OnRequestViewListCompleteCallback(std::vector<std::string> identifierList, std::vector<View> viewList, int32 result, const std::string& error_info, void *pCustomData);
		static void				OnCancelViewListCompleteCallback(std::vector<std::string> identifierList, std::vector<View> viewList, int32 result, const std::string& error_info, void *pCustomData);
		static void				OnCancelAllViewCompleteCallback(int32 result, const std::string& error_info, void* custom_data);

		static void				OnChangeAuthCompleteCallback(int32 result, const std::string& error_info, void* custom_data);
		static void				OnChangeRoleCompleteCallback(int32 result, const std::string& error_info, void* custom_data);
	
	private:
		//IM
		TIMNewGroupInfoHandle		m_handleTIMNewGroupInfo;

		MessageCallBack				m_messageCallBack;
		GropuMessageCallback		m_pGropuMessageCallback;
		C2CMessageCallback			m_pC2CMessageCallback;
		SysemMessageCallback		m_pSysemMessageCallback;

		TIMCreateGroupCB			m_timCreateGroupCB;
		TIMCommCB					m_timJoinGroupCB;
		TIMCommCB					m_timQuitGroupCB;

		SendC2CMessageCB			m_sendC2CMessageCB;
		SendGroupMessageCB			m_sendGroupMessageCB;
		StartPushStreamCB			m_startPushStreamCB;
		StopPushStreamCB			m_stopPushStreamCB;
		StartRecordCB				m_startRecordCB;
		StopRecordCB				m_stopRecordCB;

		//AV
		E_EnterRoomType				m_EnterRoomType;

		AVRoomMultiDelegate			m_AVRoomMultiDelegate;
		
		iLiveRoomOption				m_roomOption;
		iLivePushOption				m_pushOption;
		iLiveRecordOption			m_recordOption;
		
		std::string					m_szCurCameraId;
		std::string					m_szCurMicId;
		std::string					m_szCurPlayerId;

		bool						m_bCurCameraState;
		bool						m_bExternalCaptureState;
		bool						m_bCurMicState;
		bool						m_bCurPlayerState;
		E_ScreenShareState			m_eScreenShareState;
		bool						m_bPushStreamState;
		bool						m_bRecordState;

		std::vector<sRequestPair>	m_curRequestViews;

		AVRoomMulti*				m_pRoom;
		AVDeviceMgr*				m_pAudMgr;
		AVDeviceMgr*				m_pVidMgr;
		AVAudioCtrl*				m_pAudCtrl;
		AVVideoCtrl*				m_pVidCtrl;
		AVLocalScreenVideoDevice*	m_pLocalScreenVideoDevice;
		AVExternalCapture*			m_pExternalCapture;

		AVSupportVideoPreTreatment::PreTreatmentFun	m_pPreTreatmentFun;
		void*										m_pPreTreatmentFunData;

		AVSupportVideoPreview::PreviewCallback	m_pLocalVideoCB;
		void*									m_pLocalVideoData;

		AVSupportVideoPreview::PreviewCallback	m_pRemoteVideoCB;
		void*									m_pRemoteVideoData;

		//ҵ��ഫ��Ļص�����ָ��
		SuccessCalllback			m_pCreateRoomSuccessCB;
		ErrorCallback				m_pCreateRoomErrorCB;
		void*						m_pCreateRoomData;

		SuccessCalllback			m_pJoinRoomSuccessCB;
		ErrorCallback				m_pJoinRoomErrorCB;
		void*						m_pJoinRoomData;

		SuccessCalllback			m_pQuitRoomSuccessCB;
		ErrorCallback				m_pQuitRoomErrorCB;
		void*						m_pQuitRoomData;

		SuccessCalllback			m_pSendC2CMsgSucCB;
		ErrorCallback				m_pSendC2CMsgErrCB;
		void*						m_pSendC2CMsgData;

		SuccessCalllback			m_pSendGroupMsgSucCB;
		ErrorCallback				m_pSendGroupMsgErrCB;
		void*						m_pSendGroupMsgData;

		SuccessCalllback			m_pRequestViewListSucCB;
		ErrorCallback				m_pRequestViewListErrCB;
		void*						m_pRequestViewListData;

		SuccessCalllback			m_pCancelViewListSucCB;
		ErrorCallback				m_pCancelViewListErrCB;
		void*						m_pCancelViewListData;

		SuccessCalllback			m_pCancelAllViewSucCB;
		ErrorCallback				m_pCancelAllViewErrCB;
		void*						m_pCancelAllViewData;

		SuccessCalllback			m_pChangeAuthoritySucCB;
		ErrorCallback				m_pChangeAuthorityErrCB;
		void*						m_pChangeAuthorityData;

		SuccessCalllback			m_pChangeRoleSucCB;
		ErrorCallback				m_pChangeRoleErrCB;
		void*						m_pChangeRoleData;

		Type<TIMStreamRsp&>::VlaueSuccessCallback	m_pStartPushStreamSucCB;
		ErrorCallback								m_pStartPushStreamErrCB;
		void*										m_pStartPushStreamData;

		SuccessCalllback			m_pStopPushStreamSucCB;
		ErrorCallback				m_pStopPushStreamErrCB;
		void*						m_pStopPushStreamData;

		SuccessCalllback			m_pStartRecordVideoSucCB;
		ErrorCallback				m_pStartRecordVideoErrCB;
		void*						m_pStartRecordVideoData;

		Type<std::list<std::string>&>::VlaueSuccessCallback	m_pStopRecordVideoSucCB;
		ErrorCallback										m_pStopRecordVideoErrCB;
		void*												m_pStopRecordVideoData;
	};
}

#endif //iLiveRoomMgr_h_