#ifndef iLiveLog_h_
#define iLiveLog_h_
#include <ilivesdk/iLiveCommon.h>

namespace ilivesdk
{
	/**
	@brief ��־����
	*/
	enum E_iLiveLogLevel
	{
		E_LogNone = 0,	///< ����־
		E_LogError,		///< ����
		E_LogWarn,		///< ����
		E_LogInfo,		///< ��Ϣ
		E_LogDebug		///< ����
	};

	/**
	@brief ������־Ŀ¼��
	@param [in] szLogPath ��־Ŀ¼;
	@note Ĭ��·��Ϊ��ǰĿ¼; ����ʾ��: SetiLiveLogPath("./log/");
	*/
	iLiveAPI void SetiLiveLogPath(std::string szLogPath);
	/**
	@brief ������־����.
	@param [in] logLevel ��־����
	@note ������־�����ֻ�и��ڴ˼������־�Ż�������磬��־����ΪE_LogWarnʱ��ֻ���ӡE_LogError
	��E_LogWarn�������־��Ĭ����־����ΪE_LogDebug;
	*/
	iLiveAPI void SetiLiveLogLevel(E_iLiveLogLevel logLevel);

	/**
	@brief ���Error��־��Ϣ.
	@param [in] szModule ģ����.
	@param [in] szFormat ��־���ݸ�ʽ.
	@note ʹ�÷�������prinf()����.
	*/
	iLiveAPI void iLiveLog_e(const char* szModule, const char* szFormat, ...);
	/**
	@brief ���Error��־��Ϣ(˫�ֽڰ汾).
	@param [in] szModule ģ����.
	@param [in] szFormat ��־���ݸ�ʽ.
	@note ʹ�÷�������wprintf()����.
	*/
	iLiveAPI void iLiveLog_e(const wchar_t* szModule, const wchar_t* szFormat, ...);

	/**
	@brief ���Warn��־��Ϣ.
	@param [in] szModule ģ����.
	@param [in] szFormat ��־���ݸ�ʽ.
	@note ʹ�÷�������prinf()����.
	*/
	iLiveAPI void iLiveLog_w(const char* szModule, const char* szFormat, ...);
	/**
	@brief ���Warn��־��Ϣ(˫�ֽڰ汾).
	@param [in] szModule ģ����.
	@param [in] szFormat ��־���ݸ�ʽ.
	@note ʹ�÷�������wprintf()����.
	*/
	iLiveAPI void iLiveLog_w(const wchar_t* szModule, const wchar_t* szFormat, ...);

	/**
	@brief ���Info��־��Ϣ.
	@param [in] szModule ģ����.
	@param [in] szFormat ��־���ݸ�ʽ.
	@note ʹ�÷�������prinf()����.
	*/
	iLiveAPI void iLiveLog_i(const char* szModule, const char* szFormat, ...);
	/**
	@brief ���Info��־��Ϣ(˫�ֽڰ汾).
	@param [in] szModule ģ����.
	@param [in] szFormat ��־���ݸ�ʽ.
	@note ʹ�÷�������wprintf()����.
	*/
	iLiveAPI void iLiveLog_i(const wchar_t* szModule, const wchar_t* szFormat, ...);

	/**
	@brief ���Debug��־��Ϣ.
	@param [in] szModule ģ����.
	@param [in] szFormat ��־���ݸ�ʽ.
	@note ʹ�÷�������prinf()����.
	*/
	iLiveAPI void iLiveLog_d(const char* szModule, const char* szFormat, ...);
	/**
	@brief ���Debug��־��Ϣ(˫�ֽڰ汾).
	@param [in] szModule ģ����.
	@param [in] szFormat ��־���ݸ�ʽ.
	@note ʹ�÷�������wprintf()����.
	*/
	iLiveAPI void iLiveLog_d(const wchar_t* szModule, const wchar_t* szFormat, ...);
}

#endif //iLiveLog_h_