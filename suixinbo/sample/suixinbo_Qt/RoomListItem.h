#ifndef RoomListItem_h_
#define RoomListItem_h_

#include "ui_RoomListItem.h"

struct Room
{
	QString szId;

	struct taglnfo
	{
		taglnfo():roomnum(0),thumbup(0),memsize(0){}
		int roomnum;
		QString title;
		QString type;
		QString groupid;
		QString cover;
		int thumbup;//������
		int memsize;//������Ա��
	}info;
};

class RoomListItem : public QWidget
{
	Q_OBJECT
public:
	RoomListItem(QWidget * parent = 0, Qt::WindowFlags f = 0);
	void setRoomParam(const Room& room);

private slots:
	void onBtnPic();

private:
	void sxbWatcherJoinRoom(); //��ͨ���ڼ��뷿��
	static void OnSxbWatcherJoinRoom(int errorCode, QString errorInfo, QVariantMap datamap, void* pCusData);

	void iLiveJoinRoom();
	static void OniLiveJoinRoomSuc(void* data);
	static void OniLiveJoinRoomErr(int code, const std::string& desc, void* data);
	
	void sendWatcherJoinRoom();

private:
	Ui::RoomListItem m_ui;
	Room m_room;
};

#endif//RoomListItem_h_