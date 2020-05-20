#pragma once
#include "Seat.h"
class BookSeat: public Seat {
	char* note;
public:
	BookSeat(int _row, int _seat, const Event* _forEvent,const char* _note);
	const char* type()const;
};