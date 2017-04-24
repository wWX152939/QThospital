#ifndef iLivePushOption_h_
#define iLivePushOption_h_

#include <imsdk/tim_int.h>

namespace ilivesdk
{
	/**
	@brief ������������
	*/
	enum E_PushDataType
	{
		E_PushCamera = 0,///< ����ͷ
		E_PushScreen,	 ///< ����(��Ļ����)
	};

	/**
	@brief ���������
	@details ����������Ҫ��������͵Ĳ�����
	*/
	struct iLivePushOption
	{
		/**
		@brief ���캯������ʼ����Ա������
		*/
		iLivePushOption()
			:push_data_type(E_PushCamera)
			,encode(imcore::HLS)
		{
		}

		std::string					channel_name;///< Ƶ������.
		std::string					channel_desc;///< Ƶ������.
		E_PushDataType				push_data_type;///< �����������ͣ��μ�E_PushDataType����.
		imcore::E_TIMStreamEncode	encode;///< �������ݱ��뷽ʽ���μ�E_TIMStreamEncode����.
	};
}

#endif//iLivePushOption_h_