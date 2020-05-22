#include "BookSeat.h"
#include <cstring>
BookSeat::BookSeat(int _row, int _seat, const char* _forEvent,int _hallId, const char* _note):Seat(_row,_seat,_forEvent,_hallId)
{
	note = new char[strlen(_note) + 1];
	strcpy(note, _note);
}
