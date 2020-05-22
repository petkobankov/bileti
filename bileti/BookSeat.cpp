#include "BookSeat.h"
#include <cstring>
BookSeat::BookSeat(int _row, int _seat, const char* _forEvent,const char* _date,int _hallId, const char* _note):Seat(_row,_seat,_forEvent,_date,_hallId)
{
	note = new char[strlen(_note) + 1];
	strcpy(note, _note);
}
