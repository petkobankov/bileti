#pragma once
#include "Hall.h"
#include <cstring>
class Event {
	//date format 2020-05-19
	int hallId;
	char date[11];
	char* eventName;
public:
	Event(const char* _date,const char* _eventName,int _hallId);
	//Проверява дали представлението е на тази дата и дали е в тази зала
	bool isTheSameAs(const char* _date, int _hallId)const;
	bool isTheSameAs(const char* _date, const char* _eventName)const;
	int getHallId()const;
	int compareDate(const char* _date)const;
	bool print()const;
	const char* getDate()const;
	const char* getEventName()const;
};