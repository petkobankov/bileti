#include "Event.h"

Event::Event(const char* _date, const char* _eventName, int _hallId)
{
	strcpy(date, _date);
	eventName = new char[strlen(_eventName) + 1];
	strcpy(eventName, _eventName);
	hallId = _hallId;
}

bool Event::isTheSameAs(const char* _date, int _hallId)const
{
	//Проверява дали представлението е на тази дата и дали е в тази зала
	return strcmp(date,_date)==0 && hallId== _hallId;
}
bool Event::isTheSameAs(const char* _date, const char* _eventName)const
{
	//Проверява дали представлението има същото име и е на същата дата
	return strcmp(date, _date) == 0 && strcmp(eventName, _eventName) == 0;
}

int Event::getHallId() const
{
	return hallId;
}
