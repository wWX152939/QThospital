#ifndef iLiveSDK_h_
#define iLiveSDK_h_

#include <imsdk/tim.h>
#include <imsdk/tim_comm.h>
#include <avsdk/av_context.h>
#include <ilivesdk/iLiveCommon.h>

namespace ilivesdk
{
	using namespace imcore;
	using namespace tencent::av;

	/**
	@brief iLiveSDK���������һ��SDK����ʵ����
	@note ʹ��iLiveSDKǰ���������initSdk()������ʼ��SDK��
	*/
	class iLiveAPI iLiveSDK
	{
		class ForceOfflineCallBack : public TIMForceOfflineCallBack
		{
		public:
			virtual void OnForceOffline() override;
		};

	public:
		/**
		@brief ��ȡ��������
		@return ��������
		*/
		static iLiveSDK*	getInstance();

		/**
		@brief ��ʼ��iLiveSDK��
		@note ʹ��iLiveSDKǰ��������ô˺�����ʼ��SDK��
		@param [in] appId ��ѶΪÿ�����뷽������˺�id
		@param [in] accountType ��ѶΪÿ�����뷽������˺�����
		@return ���ز������,�ɹ��򷵻�NO_ERR
		*/
		int					initSdk(const int appId, const int accountType);
		/**
		@brief �ͷ��ڲ���Դ,�����˳�ʱ��Ҫ���á�
		@remark �˺���������7��ǰ��iLiveSDK��־�ļ���
		*/
		void				destroy();
		/**
		@brief ��ȡTIMManager�൥������
		@details �û����Ի�ȡTIMManager���󣬴Ӷ�����һЩ�Զ�������;
		@return ����TIMManager�������������;
		*/
		TIMManager&			getTIMManager();
		/**
		@brief ��ȡAppId��
		@details ��ȡ�ڳ�ʼ�������д����appId
		@return ����appId
		*/
		int					getAppId();
		/**
		@brief ��ȡApp���˺����͡�
		@details ��ȡ�ڳ�ʼ�������д����accountType
		@return ����accountType
		*/
		int					getAccountType();
		/**
		@brief ��ȡAVContext����
		@details ��ȡAVContext����;
		@return ����iLiveSDK�ڲ�������ά����AVContext����ָ��;
		*/
		AVContext*			getAVContext();
		/**
		@brief ��ȡ�汾�š�
		@return ���ذ汾���ַ���;
		*/
		const char*			getVersion();

	private:
		iLiveSDK();
		~iLiveSDK();

	private:
		int					m_appId;
		int					m_accountType;
		AVContext*			m_pAVContext;
		std::string			m_szVersion;
		ForceOfflineCallBack m_forceOfflineCB;

		HMODULE							m_hMoude;
		PROC_AVAPI_GetVersion			m_funcGetVersion;
		PROC_AVAPI_CreateContext		m_funcCreateContext;	
		PROC_AVAPI_EnableCrashReport	m_funcEnableCrashReport;
	};
}

#endif //iLiveSDK_h_