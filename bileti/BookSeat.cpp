#include "BookSeat.h"
#include <cstring>
BookSeat::BookSeat(int _row, int _seat, const Event* _forEvent, const char* _note):Seat(_row,_seat,_forEvent)
{
	note = new char[strlen(_note) + 1];
	strcpy(note, _note);
}

const char* BookSeat::type() const
{
	return "booking";
}
