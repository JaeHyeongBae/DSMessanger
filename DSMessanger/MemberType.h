#pragma once
#include <string>
#include <vector>
#include "SortedLinkedList.h"
#include "FriendType.h"
#include "MessageType.h"
#include "UnsortedLinkedList.h"

class MemberType
{
public:
	MemberType();
	~MemberType();
	
public: std::string ID;
public: std::string Password;
public: std::string Birthdate;
public: std::string Name;
public: std::string ProfileMessage;
public: std::string PhoneNumber;
public: bool IsLoggedIn = false;

public: SortedLinkedList<FriendType> friendList;
public: UnsortedLinkedList<MessageType> chatList;

		/**
		*	@brief	Generated a message type with input parameters
		*	@pre	None
		*	@post	A message content is filled into the refernce message
		*/
		void GenerateMessage(MessageType & message, std::string body, std::string reciever_id);

		/**
		*	@brief	Adds message to chat list.
		*	@pre	Message is generated.
		*	@post	A message is added to chat list
		*/
		void AddMessageToChatList(MessageType& message);

		/**
		*	@brief	Generates a message and adds it to chat list.
		*	@pre	body and reciever of the message is specified.
		*	@post	A message is generated and added to chat list.
		*/
		void GetMessage(MessageType & message, std::string body, std::string reciever_id);

		// Comprare items with ID;
		bool operator<(MemberType& rhs);
		bool operator>(MemberType& rhs);
};

