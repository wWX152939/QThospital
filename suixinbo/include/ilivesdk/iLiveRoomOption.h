#ifndef iLiveRoomOption_h_
#define iLiveRoomOption_h_

#include <ilivesdk/iLiveCommon.h>
#include <avsdk/av_common.h>
#include <avsdk/av_room_multi.h>

namespace ilivesdk
{
	/**
	@brief SDK�����˳������������ָ�롣
	@details SDK�ڲ�����Ϊ30s��������ʱ��ԭ�������˳����䣬APP��Ҫ�������˳������¼����Ը��¼�������Ӧ����
	@param [in] reason �˳�ԭ��, �ο�av_error.h��
	@param [in] errorinfo �˳�ԭ��������
	@param [in] data �û��Զ��������ͣ��ص�������ԭ�ⲻ�����ظ�ҵ��ࡣ
	*/
	typedef void (*iLiveRoomDisconnectListener)(int32 reason, std::string errorinfo, void* data);
	/**
	@brief �����ڳ�Ա�仯��������ָ�롣
	@details �������Ա����״̬�仯(���Ƿ���Ƶ���Ƿ���Ƶ��)ʱ����ͨ���ú���ָ��֪ͨҵ��ࡣ
	@param [in] event_id ״̬�仯id�����EndpointEventId�Ķ��塣
	@param [in] identifier_list ����״̬�仯�ĳ�Աid�б�
	@param [in] data �û��Զ��������ͣ��ص�������ԭ�ⲻ�����ظ�ҵ��ࡣ
	*/
	typedef void (*iLiveMemStatusListener)(AVRoomMulti::EndpointEventId event_id, std::vector<std::string> identifier_list, void* data);
	/**
    @brief ���Զ�ģʽ��������ͷ��Ƶ���¼�֪ͨ��
    @details ���Զ�ģʽ��������ͷ��Ƶ���¼�֪ͨ��Ҳ���ǵ����뷿��ʱ������Ѿ����˷�������Ƶ������Զ�������Щ��Ƶ�������ֶ�ȥ���󡣵�Ȼ�����뷿�������������ٷ�����Ƶ���򲻻��Զ����ա�
	@param [in] identifier_list �Զ����յ�����ͷ��Ƶ����Ӧ�ĳ�Աid�б�
	@param [in] data �û��Զ��������ͣ��ص�������ԭ�ⲻ�����ظ�ҵ��ࡣ
    */
	typedef	void (*iLiveSemiAutoRecvCameraVideoListener)(std::vector<std::string> identifier_list, void* data);
	/**
    @brief ���Զ�ģʽ������Ļ������¼�֪ͨ��
    @details ���Զ�ģʽ������Ļ������¼�֪ͨ��Ҳ���ǵ����뷿��ʱ������Ѿ����˿�������Ļ��������Զ�������Ļ���������ֶ�ȥ���󡣵�Ȼ�����뷿�������������ٿ�����Ļ�����򲻻��Զ����ա�
	@param [in] identifier_list �Զ�������Ļ��������Ӧ�ĳ�Աid�б�
	@param [in] data �û��Զ��������ͣ��ص�������ԭ�ⲻ�����ظ�ҵ��ࡣ
    */
	typedef	void (*iLiveSemiAutoRecvScreenVideoListener)(std::vector<std::string> identifier_list, void* data);
	/**
    @brief ���Զ�ģʽ���ղ�Ƭ���¼�֪ͨ��
    @details ���Զ�ģʽ���ղ�Ƭ���¼�֪ͨ��Ҳ���ǵ����뷿��ʱ������Ѿ������ڲ�Ƭ������Զ����ղ�Ƭ�������ֶ�ȥ���󡣵�Ȼ�����뷿�������������ٿ�ʼ��Ƭ���򲻻��Զ����ա�
	@param [in] identifier_list �Զ����ղ�Ƭ����Ӧ�ĳ�Աid�б�
	@param [in] data �û��Զ��������ͣ��ص�������ԭ�ⲻ�����ظ�ҵ��ࡣ
    */
	typedef	void (*iLiveSemiAutoRecvMediaFileVideoListener)(std::vector<std::string> identifier_list, void* data);

	/**
	@brief iLiveRoom�����
	@details �ڴ������߼��뷿��ʱ����Ҫ����д�˽ṹ��Ϊ��������;
	*/
	struct iLiveRoomOption
	{
		/**
		@brief ���캯������ʼ����Ա����ֵ��
		*/
		iLiveRoomOption()
			:roomId(0)
			,audio_category(tencent::av::AUDIO_CATEGORY_MEDIA_PLAY_AND_RECORD)//����ֱ������
			,video_recv_mode(tencent::av::VIDEO_RECV_MODE_SEMI_AUTO_RECV_CAMERA_VIDEO)//���Զ�ģʽ
			,screen_recv_mode(tencent::av::SCREEN_RECV_MODE_SEMI_AUTO_RECV_SCREEN_VIDEO)//���Զ�ģʽ
			,m_roomDisconnectListener(NULL)
			,m_memberStatusListener(NULL)
			,m_autoRecvCameraListener(NULL)
			,m_autoRecvScreenListener(NULL)
			,m_autoRecvMediaFileListener(NULL)
			,data(NULL)
		{
		}

		uint32			roomId;				///< ����ID,��ҵ��ഴ����ά���ķ���ID
		std::string		auth_buffer;		///< ͨ������Ȩ��λ�ļ��ܴ�
		std::string		control_role;		///< ��ɫ����web������Ƶ�������ù��������õĽ�ɫ��
		AudioCategory	audio_category;		///< ���ӳ�������,��ϸ��Ϣ��AudioCategory�Ķ���.
		VideoRecvMode	video_recv_mode;	///< ��Ƶ����ģʽ
		ScreenRecvMode	screen_recv_mode;	///< ��Ļ�������ģʽ

		iLiveRoomDisconnectListener				m_roomDisconnectListener; ///< SDK�����˳�������ʾ,�μ�iLiveRoomDisconnectListener���塣
		iLiveMemStatusListener					m_memberStatusListener;	  ///< �����Ա״̬�仯֪ͨ���μ�iLiveMemStatusListener���塣
		iLiveSemiAutoRecvCameraVideoListener	m_autoRecvCameraListener; ///< ���Զ�ģʽ��������ͷ��Ƶ��֪ͨ���μ�iLiveSemiAutoRecvCameraVideoListener���塣
		iLiveSemiAutoRecvScreenVideoListener	m_autoRecvScreenListener; ///< ���Զ�ģʽ������Ļ�����֪ͨ���μ�iLiveSemiAutoRecvScreenVideoListener���塣
		iLiveSemiAutoRecvMediaFileVideoListener m_autoRecvMediaFileListener;///< ���Զ�ģʽ���ղ�Ƭ��֪ͨ���μ�iLiveSemiAutoRecvMediaFileVideoListener���塣
		void*									data;					  ///< �û��Զ����������ͣ���m_roomDisconnectListener��m_memberStatusListener��m_autoRecvCameraListener��m_autoRecvScreenListener��m_autoRecvMediaFileListener��ԭ�ⲻ�����ء�
	};
}

#endif//iLiveRoomOption_h_