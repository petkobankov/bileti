#pragma once
#include "Event.h"
class Seat {
protected:
	char* forEvent;
	char* date;
	int hallId;
	int row;
	int seat;
public:
	Seat(int _row, int _seat, const char* _forEvent,const char* _date, int _hallId);
	bool isForEvent(const char* _event)const;
	int getRow()const;
	int getSeat()const;
	bool isTheSameAs(int _row,int _seat,const char* _date,const char* _eventName)const;
};