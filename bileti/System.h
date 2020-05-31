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
	char* location;
	Event** events;
	Ticket** purchases;
	Ticket** booking;
	
	void free();
	void copyFrom(const System& other);
	bool resizeBookings();
	bool resizePurchases();
	bool resizeEvents();
	bool printSoldTicketsFor(const char* _eventName, const char* _date)const;
	bool isDateFree(const char* _date, int _hallId)const;
	const Event* findEvent(const char* _date, const char* _eventName)const;
	bool seatIsFree(const char* _event, int _row, int _seat)const; 
	const int findSeatBookingId(const char* _eventName, int _row, int _seat)const;
	bool popBooking(int bookingId);
	bool buyBooking(int _bookingId);
	bool bookingsForDate(const char* _date)const;
	bool bookingsForName(const char* _name)const;
	const char* getFileName(const char* _location)const;
public:
	System();
	System(const System& other);
	System& operator=(const System& other);
	~System();
	//Big 4
	bool addevent(const char* _date, const char* _eventName, int _hallId);
	bool freeseats(const char* _date, const char* _eventName)const;
	bool book(int _row, int _seat, const char* _date, const char* _eventName, const char* _note);
	bool unbook(int _row, int _seat, const char* _date, const char* _eventName);
	bool buy(int _row, int _seat, const char* _date, const char* _eventName);
	bool bookings(const char* _date, const char* _name)const;
	bool bookings(const char* _nameOrDate)const;
	bool check(const char* _code)const;
	bool report(const char* _fromDate, const char* _toDate, int hallId)const;
	bool report(const char* _fromDate, const char* _toDate)const;

	bool saveas(const char* _location);
	bool open(const char* _location);
	bool close();
	bool save();
	bool help()const;
	const bool isLoaded()const;
};