#pragma once
#include "Event.h"
class Seat {
protected:
	char* forEvent;
	int hallId;
	int row;
	int seat;
public:
	Seat(int _row, int _seat, const char* _forEvent, int _hallId);
	bool isForEvent(const char* _event)const;
	int getRow()const;
	int getSeat()const;
	bool isTheSameAs(int _row,int _seat,const char* _date,const char* _eventName)const;
};