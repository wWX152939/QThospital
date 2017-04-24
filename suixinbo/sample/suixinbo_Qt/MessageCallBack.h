#ifndef MessageCallBack_h_
#define MessageCallBack_h_

#include <imsdk/tim_msg.h>

#define ILVLIVE_IMCMD_CUSTOM_LOW_LIMIT 0x800
#define ILVLIVE_IMCMD_CUSTOM_UP_LIMIT 0x900

#define LiveNoti "LiveNotification" //�Զ���������

enum E_CustomCmd
{
	AVIMCMD_None,               // ���¼���0

	AVIMCMD_EnterLive,          // �û�����ֱ��, Group��Ϣ �� 1
	AVIMCMD_ExitLive,           // �û��˳�ֱ��, Group��Ϣ �� 2
	AVIMCMD_Praise,             // ������Ϣ, Demo��ʹ��Group��Ϣ �� 3
	AVIMCMD_Host_Leave,         // �����򻥶������뿪, Group��Ϣ �� 4
	AVIMCMD_Host_Back,          // �����򻥶����ڻ���, Group��Ϣ �� 5

	AVIMCMD_Multi = ILVLIVE_IMCMD_CUSTOM_LOW_LIMIT,  // ���˻�����Ϣ���� �� 2048

	AVIMCMD_Multi_Host_Invite,          // ������������������Ϣ, C2C��Ϣ �� 2049
	AVIMCMD_Multi_CancelInteract,       // �ѽ��뻥��ʱ���Ͽ�������Group��Ϣ�����Ͽ��ߵ�imUsreid���� �� 2050
	AVIMCMD_Multi_Interact_Join,        // ���˻������յ�AVIMCMD_Multi_Host_Invite���������ͬ�⣬C2C��Ϣ �� 2051
	AVIMCMD_Multi_Interact_Refuse,      // ���˻������յ�AVIMCMD_Multi_Invite��������󣬾ܾ���C2C��Ϣ �� 2052
};

void sendC2CCustomCmd( QString dstUser, E_CustomCmd userAction, QString actionParam, SuccessCalllback suc = NULL, ErrorCallback err = NULL, void* data = NULL );
void sendGroupCustomCmd( E_CustomCmd userAction, QString actionParam, SuccessCalllback suc = NULL, ErrorCallback err = NULL, void* data = NULL );

class MessageCallBack
{
public:
	static void OnGropuMessage( const TIMMessage& msg );
	static void OnC2CMessage( const TIMMessage& msg );

	static 	QQueue<TIMMessage>	ms_messageQueue;
};

#endif//MesageCallBack_h_