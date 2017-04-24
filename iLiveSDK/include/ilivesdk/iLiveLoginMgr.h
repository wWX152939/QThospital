#ifndef iLiveLoginMgr_h_
#define iLiveLoginMgr_h_

#include <imsdk/tim_comm.h>
#include <avsdk/av_callback.h>
#include <ilivesdk/iLiveCommon.h>

namespace ilivesdk
{
	typedef void (*ForceOfflineCallback)(); ///< �������߻ص�����ָ������;

	/**
	@brief ��¼���ǳ��ķ�װ;
	*/
	class iLiveAPI iLiveLoginMgr
	{
		friend class iLiveSDK;
		class IMLoginCallBack : public TIMCallBack
		{
		public:
			virtual void	OnSuccess();
			virtual void	OnError(int code, const std::string &desc);
		};

		class IMLogoutCallBack : public TIMCallBack
		{
		public:
			virtual void	OnSuccess();
			virtual void	OnError(int code, const std::string &desc);
		};

		class StartAVContextCallBack : public AVCallback
		{
		public:
			virtual void OnComplete(int32 result, const std::string& error_info) override;
		};

	public:
		/**
		@brief ��ȡ��������
		@return ��������
		*/
		static iLiveLoginMgr*	getInstance();

		/**
		@brief ���ñ������ߵĻص���
		@param [in] cb �ص��ӿڵ�ָ��;
		@remark �˺��������ط���½ʱ�����յ��˻ص�;
		*/
		void					setForceOfflineCallback(ForceOfflineCallback cb);
		/**
		@brief ��¼
		@param [in] szUserId �û�id
		@param [in] szUserSig �û�Sig
		@param [in] suc �ɹ��Ļص�����ָ��
		@param [in] err ʧ�ܵĻص�����ָ��
		@param [in] data �û��Զ�������ݵ�ָ�룬�ڳɹ���ʧ�ܵĻص�������ԭ�ⲻ���ط���;
		*/
		void					iLiveLogin( const std::string szUserId, const std::string szUserSig, SuccessCalllback suc, ErrorCallback err, void* data );
		/**
		@brief �ǳ�
		@param [in] suc �ɹ��ص�����ָ��
		@param [in] err ʧ�ܻص�����ָ��
		@param [in] data �û��Զ�������ݵ�ָ�룬�ڳɹ���ʧ�ܵĻص�������ԭ�ⲻ���ط���;
		*/
		void					iLiveLogout( SuccessCalllback suc, ErrorCallback err, void* data );
		/**
		@brief ��ȡ�Ѿ���¼�û�ID(ֻ�е�¼�ɹ�����ܻ�ȡ)
		@return �����Ѿ���¼�û���ID
		*/
		std::string				getLoginId();
		/**
		@brief ��ȡ�Ѿ���¼�û�Sig(ֻ�е�¼�ɹ�����ܻ�ȡ)
		@return �����Ѿ���¼�û���Sig
		*/
		std::string				getUserSig();

	private:
		iLiveLoginMgr();
		void					OnIMLoginSuc();
		void					OnIMLoginErr(int code, const std::string& desc);
		void					OnIMLogoutSuc();
		void					OnIMLogoutErr(int code, const std::string& desc);
		void					OnStartContextCompleteCallback(int result, const std::string& error_info);
		
	private:
		IMLoginCallBack				m_timLoginCallback;
		IMLogoutCallBack			m_timLogoutCallBack;
		StartAVContextCallBack		m_startAVContextCallBack;

		ForceOfflineCallback		m_pForceOfflineCB;

		SuccessCalllback			m_pLoginSuccessCB;
		ErrorCallback				m_pLoginErrorCB;
		void*						m_pLoginData;

		SuccessCalllback			m_pLogoutSuccessCB;
		ErrorCallback				m_pLogoutErrorCB;
		void*						m_pLogoutData;

		std::string					m_szUserId;
		std::string					m_szUserSig;
	};
}


#endif //iLiveLoginMgr_h_