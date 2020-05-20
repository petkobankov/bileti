#pragma once
#include "Hall.h"
#include "Event.h"
#include "Seat.h"
const int HALL_COUNT = 2;
class System {
	Hall halls[HALL_COUNT];
	int eventsCapacity;
	int eventsCurrent;
	Event** events;
	Seat** seatsDatabase;
	//booking - subitie zala i mestata
public:
	System();
	//bool saveTicket(int row, int seat, const char* date, int hallId, const char* note);
	//Event* findEvent(const char* date, const char* eventName);
	bool addevent(const char* _date, const char* _eventName, int _hallId);
	bool isDateFree(const char* _date, int _hallId);
	//bool freeseats(const char* date, const char* eventName);
	bool book(int _row, int _seat, const char* _date, const char* _eventName, const char* _note);
	//bool unbook(int row, int seat, const char* date, const char* eventName);
	//bool buy(int row, int seat, const char* date, const char* eventName);
	//bool bookings(const char* date, const char* name);
	//bool bookings(const char* name);
	////bool bookings(const char* date);
	//bool check(int code);
	//bool report(const char* fromDate, const char* toDate, const Hall& hall);
	//bool report(const char* fromDate, const char* toDate);
	//bool removeTicket(int ticketId);
};