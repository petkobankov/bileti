#pragma once
#include "Seat.h"
class PurchaseSeat: public Seat {
	char* ticketId;
public:
	PurchaseSeat(int _row, int _seat, const char* _forEvent,const char* _date, int _hallId);
	const char* intToChar(int _a)const;
	const int sizeOfInt(int _a)const;
};