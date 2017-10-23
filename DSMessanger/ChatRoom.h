#pragma once
#include "DSMessage.h"
#include <time.h>
using namespace System::Collections::Generic;
using namespace System;
namespace DSMessanger {

	public ref class ChatRoom
	{
	public:
		ChatRoom(){
			message_list = gcnew List<DSMessage^>;
		}
		~ChatRoom() {}
		int GetSortIndex()
		{
			return id;
		}
		void AddMessage(String^ body)
		{
			DSMessage^ msg = gcnew DSMessage;
			msg->body = body;
			msg->sender_id = 0;
			msg->timestamp = time(NULL);
			message_list->Add(msg);
		}
	public: int id = 0;
	public: List<DSMessage^>^ message_list;

	};
}