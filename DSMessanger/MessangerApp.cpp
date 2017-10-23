#include "MessangerApp.h"
#include <iostream>
using namespace std;

bool MessangerApp::instanceFlag = false;
MessangerApp* MessangerApp::instance = nullptr;

MessangerApp::MessangerApp()
{
	//For easy testing
	MemberType mem1;
	mem1.ID = "twinklewave";
	mem1.Name = "David";
	mem1.Password = "1234";
	mem1.Birthdate = "971212";
	mem1.ProfileMessage = "What a nice life!";
	mem1.PhoneNumber = "01065985959";
	memberList.Add(mem1);
	mem1.ID = "transit";
	mem1.Name = "John";
	mem1.Password = "1234";
	mem1.Birthdate = "971213";
	mem1.ProfileMessage = "What a bad life!";
	mem1.PhoneNumber = "01065983423";
	memberList.Add(mem1);
	mem1.ID = "teamreports";
	mem1.Name = "Jeff";
	mem1.Password = "1234";
	mem1.Birthdate = "921212";
	mem1.ProfileMessage = "Hello world";
	mem1.PhoneNumber = "01065923222";
	memberList.Add(mem1);
	mem1.ID = "sonetergo";
	mem1.Name = "Jessica";
	mem1.Password = "1234";
	mem1.Birthdate = "881212";
	mem1.ProfileMessage = "OTL";
	mem1.PhoneNumber = "0101231211";
	memberList.Add(mem1);
}


MessangerApp::~MessangerApp()
{
}

bool MessangerApp::Login(std::string id, std::string pw)
{
	MemberType* pmem = memberList.Retrieve(id);
	if (pmem != nullptr && pmem->Password == pw)
	{
		pmem->IsLoggedIn = true;
		return true;
	}
	return false;
}

bool MessangerApp::Logout(std::string id)
{
	MemberType* pmem = memberList.Retrieve(id);
	if (pmem->IsLoggedIn)
	{
		pmem->IsLoggedIn = false;
		return true;
	}
	return false;
}

void MessangerApp::GetMessageFromClient(string body, string reciever_id, string sender_id)
{
	MessageType message;
	memberList.Retrieve(sender_id)->GetMessage(message, body, reciever_id);
	messageQ.EnQueue(message);
}

bool MessangerApp::SendMessageToClient()
{
	MessageType message;
	messageQ.DeQueue(message);
	MemberType* pm = memberList.Retrieve(message.reciever);
	if (pm != nullptr) { pm->AddMessageToChatList(message); return true; }
	return false;
}


bool MessangerApp::CreateAccount(string id, string pw, string name, string birthdate, string phone_number, string profile_message)
{
	MemberType mem;
	mem.ID = id;
	if (memberList.Retrieve(mem) != nullptr)
	{
		return false;
	}

	mem.Password = pw;
	mem.Name = name;
	mem.Birthdate = birthdate;
	mem.PhoneNumber = phone_number;
	memberList.Add(mem);
	return true;
}

bool MessangerApp::AddFriend(std::string my_id, std::string friend_id)
{
	FriendType fr;
	fr.ID = friend_id;
	MemberType* mem = memberList.Retrieve(friend_id);
	if (mem != nullptr) {
		fr.Name = mem->Name;
		fr.Pmem = mem;
		memberList.Retrieve(my_id)->friendList.Add(fr);
		mem = memberList.Retrieve(my_id);
		fr.ID = my_id;
		fr.Name = mem->Name;
		fr.Pmem = mem;
		memberList.Retrieve(friend_id)->friendList.Add(fr);
	}
	else
		return false;
	
	return true;
}

bool MessangerApp::DeleteAccount(string id)
{
	MemberType* my_mem = memberList.Retrieve(id);
	my_mem->friendList.ResetList();
	FriendType fr;
	FriendType me_fr;
	me_fr.ID = my_mem->ID;
	for (int i = 0; i < my_mem->friendList.GetLength(); i++)
	{
		my_mem->friendList.GetNextItem(fr);
		fr.Pmem->friendList.Delete(me_fr);
	}
	memberList.Delete(*my_mem);
	return true;
}

bool MessangerApp::DeleteFriend(std::string my_id, std::string friend_id)
{
	FriendType* fr;
	MemberType* my_mem = memberList.Retrieve(my_id);
	fr = my_mem->friendList.RetrieveByName(friend_id);
	my_mem->friendList.Delete(*fr);
	return true;
}

