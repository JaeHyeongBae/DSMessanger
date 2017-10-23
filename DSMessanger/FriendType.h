#pragma once
#include <string>
//#include "MemberType.h"

class MemberType;

class FriendType
{
public:
	FriendType();
	~FriendType();
public: std::string ID;
public: std::string Name;
public: MemberType* Pmem;

//Sort based on ID
public: bool operator>(FriendType& rhs)
{
	return ID > rhs.ID;
}
public: bool operator<(FriendType& rhs)
{
	return ID < rhs.ID;
}
};

