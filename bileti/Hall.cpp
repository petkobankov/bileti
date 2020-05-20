#include "Hall.h"

Hall::Hall()
{
	id = -1;
	rows = 0;
	seatsPerRow = 0;
	seats = 0;
}

Hall::Hall(int _id, int _rows, int _seatsPerRow)
{
	id = _id;
	rows = _rows;
	seatsPerRow = _seatsPerRow;
	seats = rows*seatsPerRow;
}
