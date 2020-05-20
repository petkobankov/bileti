#pragma once
#include "Seat.h"
class PurchaseSeat: public Seat {
	int id;
public:
	const char* type()const;
};