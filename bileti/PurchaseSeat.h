#pragma once
#include "Seat.h"
class PurchaseSeat: public Seat {
	char ticketId;
public:
	PurchaseSeat(int _row, int _seat, const char* _forEvent, int _hallId);
};