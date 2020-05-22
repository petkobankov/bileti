#pragma once
#include "Hall.h"
#include "Event.h"
#include "Seat.h"
#include "Ticket.h"
const int HALL_COUNT = 2;
class System {
	Hall halls[HALL_COUNT];
	int eventsCapacity;
	int eventsCurrent;
	int purchaseCapacity;
	int purchaseCurrent;
	int bookingCapacity;
	int bookingCurrent;
	Event** events;
	Ticket** purchases;
	Ticket** booking;
	//booking - subitie zala i mestata
public:
	System();
	//bool saveTicket(int row, int seat, const char* date, int hallId, const char* note);
	//Event* findEvent(const char* date, const char* eventName);
	bool addevent(const char* _date, const char* _eventName, int _hallId);
	bool isDateFree(const char* _date, int _hallId)const;
	bool freeseats(const char* _date, const char* _eventName)const;
	bool book(int _row, int _seat, const char* _date, const char* _eventName, const char* _note);
	const Event* findEvent(const char*_date, const char*_eventName)const;
	bool seatIsFree(const char* _event, int _row,int _seat)const; //TO-DO
	bool unbook(int _row, int _seat, const char* _date, const char* _eventName);
	bool popBooking(int bookingId);
	bool buy(int _row, int _seat, const char* _date, const char* _eventName);
	bool bookings(const char* _date, const char* _name)const;
	bool bookings(const char* _nameOrDate)const;
	bool bookingsForDate(const char* _date)const;
	bool bookingsForName(const char* _name)const;
	//bool check(int code);
	//bool report(const char* fromDate, const char* toDate, const Hall& hall);
	//bool report(const char* fromDate, const char* toDate);
	//bool removeTicket(int ticketId);
};