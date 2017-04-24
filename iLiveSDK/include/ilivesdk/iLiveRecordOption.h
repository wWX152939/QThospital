#ifndef iLiveRecordOption_h_
#define iLiveRecordOption_h_

#include <ilivesdk/iLiveCommon.h>

namespace ilivesdk
{
	/**
	@brief ¼���������� 
	*/
	enum E_RecordDataType
	{
		E_RecordCamera = 0, ///< ¼������ͷ
		E_RecordScreen,		///< ¼�Ƹ���(��Ļ����)
	};

	/**
	@brief ¼�������
	@details ¼�Ʋ�����Ҫ��������͵Ĳ�����
	*/
	struct iLiveRecordOption
	{
		/**
		@brief ���캯������ʼ����Ա����ֵ��
		*/
		iLiveRecordOption()
			:record_data_type(E_RecordCamera)
			,filename("")
			,class_id(0)
		{
		}

		E_RecordDataType record_data_type; ///< ¼�Ƶ���������,�μ�E_RecordDataType���塣
		std::string		 filename;		  ///< ¼�ƺ���ļ�����
		int				 class_id;		  ///< ��Ƶ����ID(����Ч)��
	};
}

#endif //iLiveRecordOption_h_