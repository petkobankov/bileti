#include "Seat.h"

Seat::~Seat()
{
}

Seat::Seat(int _row, int _seat, const Event* _forEvent)
{
	row = _row;
	seat = _seat;
	forEvent = _forEvent;
}

bool Seat::isTheSameAs(int _row, int _seat, const char* _date, const char* _eventName) const
{
	return forEvent->isTheSameAs(_date,_eventName) && _row==row && seat==_seat;
}
