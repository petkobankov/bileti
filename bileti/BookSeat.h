#pragma once
#include "Seat.h"
class BookSeat: public Seat {
	char* note;
public:
	BookSeat(int _row, int _seat, const char* _forEvent,int _hallId,const char* _note);
};