#ifndef iLiveCommon_h_
#define iLiveCommon_h_

#include <string>
#include <map>
#include <assert.h>
#include <winsock2.h> //����avsdk��ʹ�õ���winsock2.h����windows.h�а�����winsock.h,������ǰ����winsock2.h;����Ҳ���Զ���WIN32_LEAN_AND_MEAN��������windows.h�ж�winsock.h������;
#include <windows.h>

#pragma comment(lib, "libtim.lib")

#ifdef iLiveSDKImpl
	#define iLiveAPI __declspec(dllexport)
#else
	#define iLiveAPI __declspec(dllimport)
#endif

namespace ilivesdk
{
	/**
	@brief iLiveSDK�����뼯��
	*/
	enum E_iLiveError
	{
		INVALID_INTETER_VALUE   = -1,   ///< ��Ч�����ͷ���ֵ(ͨ��)
		NO_ERR                  = 0,    ///< �ɹ�
		ERR_IM_NOT_READY        = 8001, ///< IMģ��δ������δ����
		ERR_AV_NOT_READY        = 8002, ///< AVģ��δ������δ����
		ERR_NO_ROOM             = 8003, ///< ����Ч�ķ���
		ERR_ALREADY_EXIST       = 8004, ///< Ŀ���Ѵ���
		ERR_NULL_POINTER        = 8005, ///< ��ָ�����
		ERR_ENTER_AV_ROOM_FAIL  = 8006, ///< ����AV����ʧ��
		ERR_USER_CANCEL         = 8007, ///< �û�ȡ��
		ERR_WRONG_STATE         = 8008, ///< ״̬�쳣
		ERR_NOT_LOGIN			= 8009, ///< δ��¼
		ERR_ALREADY_IN_ROOM		= 8010, ///< ���ڷ�����
		ERR_BUSY_HERE			= 8011,	///< �ڲ�æ(��һ����δ���)
		ERR_NET_UNDEFINE		= 8012, ///< ����δʶ������粻�ɴ�
		ERR_SDK_FAILED          = 8020, ///< iLiveSDK����ʧ��(ͨ��)
		ERR_INVALID_PARAM       = 8021, ///< ��Ч�Ĳ���
		ERR_NOT_FOUND           = 8022, ///< �޷��ҵ�Ŀ��
		ERR_NOT_SUPPORT         = 8023, ///< ����֧��
		ERR_ALREADY_STATE       = 8024, ///< ״̬�ѵ�λ(һ��Ϊ�ظ���������)
		ERR_KICK_OUT            = 8050, ///< ��������
		ERR_EXPIRE              = 8051, ///< Ʊ�ݹ���(�����Ʊ��userSig)
	};

	/**
	@brief �ɹ���ֵ�ص�����ָ�����͵ķ�װ��
	*/
	template <typename T>
	struct Type
	{
		/**
		@brief ͨ�õĳɹ���ֵ�ص�����ָ������;
		@param [in] value �����ɹ���SDK���ظ�ҵ�����Ӧ���͵�ֵ;
		@param [in] data SDK����ҵ����Զ��������ָ��;
		*/
		typedef void (*VlaueSuccessCallback)(T value, void* data);
	};
	/**
	@brief ͨ�õĳɹ��ص�����ָ������;
	@param [in] data SDK����ҵ����Զ��������ָ��;
	*/
	typedef void (*SuccessCalllback)(void* data);
	/**
	@brief ͨ�õ�ʧ�ܻص�����ָ������;
	@param [in] code ������
	@param [in] desc ����ԭ������
	@param [in] data SDK����ҵ����Զ��������ָ��;
	*/
	typedef void (*ErrorCallback)(int code, const std::string& desc, void* data);
}

#endif//iLiveCommon_h_
