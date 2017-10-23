#include "MemberType.h"
#include <iostream>
#include <string>
using namespace std;


MemberType::MemberType()
{
}


MemberType::~MemberType() {
}

void MemberType::GenerateMessage(MessageType & message, string body, string reciever_id)
{
	message.sender = ID;
	message.reciever = reciever_id;
	message.message = body;
}

void MemberType::AddMessageToChatList(MessageType & message)
{
	chatList.Add(message);
}

void MemberType::GetMessage(MessageType & message, string body, string reciever_id)
{
	GenerateMessage(message, body, reciever_id);
	AddMessageToChatList(message);
}

bool MemberType::operator<(MemberType & rhs)
{
	return ID < rhs.ID;
}

bool MemberType::operator>(MemberType & rhs)
{
	return ID > rhs.ID;
}
