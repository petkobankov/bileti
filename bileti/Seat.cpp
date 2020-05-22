#include "Seat.h"


Seat::Seat(int _row, int _seat, const char* _forEvent,int _hallId)
{
	row = _row;
	seat = _seat;
	hallId = _hallId;
	forEvent = new char[strlen(_forEvent)+1];
	strcpy(forEvent, _forEvent);
}

bool Seat::isForEvent(const char* _event) const
{
	if (strcmp(forEvent, _event) == 0)
		return true;
	return false;
}

int Seat::getRow() const
{
	return row;
}

int Seat::getSeat() const
{
	return seat;
}

bool Seat::isTheSameAs(int _row, int _seat, const char* _date, const char* _eventName) const
{
	//return forEvent->isTheSameAs(_date,_eventName) && _row==row && seat==_seat;
	return true;
}
