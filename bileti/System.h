#pragma once
#include "Hall.h"
#include "Event.h"
class System {
	Hall* halls;
	Event* events;
public:
	bool addevent(const char* date, const Hall& hall, const char* hallName);
	bool freeseats(const char* date, const char* eventName);
	bool book(int row, int seat, const char* date, const char* eventName, const char* note);
	bool unbook(int row, int seat, const char* date, const char* eventName);
	bool buy(int row, int seat, const char* date, const char* eventName);
	bool bookings(const char* date, const char* name);
	bool bookings(const char* name);
	bool bookings(const char* date);
	bool check(int code);
};