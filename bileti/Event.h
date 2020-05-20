#pragma once
#include "Hall.h"
#include <cstring>
class Event {
	//2020-05-19
	int hallId;
	char date[11];
	char* eventName;
public:
	Event(const char* _date,const char* _eventName,int _hallId);
	bool isTheSameAs(const char* _date, int _hallId)const;
	bool isTheSameAs(const char* _date, const char* _eventName)const;
	int getHallId()const;
};