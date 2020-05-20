#pragma once
#include "Hall.h"
#include "Event.h"
#include "Seat.h"
const int HALL_COUNT = 2;
class System {
	Hall halls[HALL_COUNT];
	int eventsCapacity;
	int eventsCurrent;
	int databaseCapacity;
	int databaseCurrent;
	Event** events;
	Seat** seatsDatabase;
	//booking - subitie zala i mestata
public:
	System();
	//bool saveTicket(int row, int seat, const char* date, int hallId, const char* note);
	//Event* findEvent(const char* date, const char* eventName);
	bool addevent(const char* _date, const char* _eventName, int _hallId);
	bool isDateFree(const char* _date, int _hallId)const;
	bool freeseats(const char* _date, const char* _eventName);
	bool book(int _row, int _seat, const char* _date, const char* _eventName, const char* _note);
	const Event* findEvent(const char*_date, const char*_eventName)const;
	bool seatIsFree(const Event* event, int _row,int _seat)const; //TO-DO
	bool unbook(int _row, int _seat, const char* _date, const char* _eventName);
	bool popSeat(int seatId);
	//bool buy(int row, int seat, const char* date, const char* eventName);
	//bool bookings(const char* date, const char* name);
	//bool bookings(const char* name);
	////bool bookings(const char* date);
	//bool check(int code);
	//bool report(const char* fromDate, const char* toDate, const Hall& hall);
	//bool report(const char* fromDate, const char* toDate);
	//bool removeTicket(int ticketId);
};