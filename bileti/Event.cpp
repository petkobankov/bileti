#include "Event.h"

Event::Event(const char* _date, const char* _eventName, int _hallId)
{
	strcpy(date, _date);
	eventName = new char[strlen(_eventName) + 1];
	strcpy(eventName, _eventName);
	hallId = _hallId;
}

bool Event::isTheSameAs(const char* _date, int _hallId)
{
	return strcmp(date,_date)==0 && hallId== _hallId;
}
