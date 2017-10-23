#pragma once
#include <string>
class MessageType
{
public:
	MessageType();
	~MessageType();
public: std::string message; // message body
public: std::string sender; // id of sender
public: std::string reciever; //id of reciever
};

