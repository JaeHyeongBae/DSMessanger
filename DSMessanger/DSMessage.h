#pragma once

namespace DSMessanger {
	public ref class DSMessage
	{
	public:
		DSMessage(){}
		~DSMessage(){}
		DSMessage(const DSMessage% msg)
		{
			sender_id = msg.sender_id;
			timestamp = msg.timestamp;
			body = msg.body;
		}

		System::String^ body;
		int sender_id;
		int timestamp;
	};

}