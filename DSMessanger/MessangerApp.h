#pragma once
#include "SortedLinkedList.h"
#include "MemberType.h"
#include "MessageType.h"
#include "CircularQueueType.h"

class MessangerApp
{
private:
	MessangerApp();
	~MessangerApp();
	static bool instanceFlag;
	static MessangerApp* instance;
	
public: static MessangerApp* GetInstance()
{
	if (instance == nullptr)
	{
		instance = new MessangerApp();
		instanceFlag = true;
	}
	return instance;
}
public: SortedLinkedList<MemberType> memberList;
public: MemberType* currentMember = nullptr;
public: CircularQueueType<MessageType> messageQ;

		/**
		*	@brief	Log In from information passed by parameter
		*	@pre	none
		*	@post	isLoggedIn is set to true for the rquested member.
		*	@return	returns true if successful
		*/
		bool Login(std::string id, std::string pw);

		/**
		*	@brief	Log Out
		*	@pre	Requested member's log in status is true;
		*	@post	Requested member's log in status is false;
		*	@return	returns true if successful
		*/
		bool Logout(std::string id);

		/**
		*	@brief	Generate Message from client
		*	@pre	None
		*	@post	a message is added to server message queue
		*/
		void GetMessageFromClient(string body, string reciever_id, string sender_id);

		/**
		*	@brief	Sends a single message to client from server message queue
		*	@pre	more than one message is queued
		*	@post	one message is dequed and sent to following client
		*	@return	returns true if successful
		*/
		bool SendMessageToClient();

		/**
		*	@brief	Create a new account
		*	@pre	none
		*	@post	A new account is made and added to member list
		*	@return	return true if successful.
		*/
		bool CreateAccount(string id, string pw, string name, string birthdate, string phone_number, string profile_message);

		/**
		*	@brief	Add each other in each other's friend list.
		*	@pre	
		*	@post	one message is dequed and sent to following client
		*	@return	returns true if successful
		*/
		bool AddFriend(std::string my_id, std::string friend_id);

		/**
		*	@brief	Add each other in each other's friend list.
		*	@pre
		*	@post	one message is dequed and sent to following client
		*	@return	returns true if successful
		*/
		bool DeleteAccount(string id);

		bool DeleteFriend(std::string my_id, std::string friend_id);
};

