/**
 * \class System
 *
 * \brief Система. Това е главния клас който контролира всички останали. В него има две фиксирани зали, масив от представления, масив от купени билети и масив от запазени билети. Останалото са помощни член данни.
 *
 */
#pragma once
#include "Hall.h"
#include "Event.h"
#include "Seat.h"
#include "Ticket.h"
const int HALL_COUNT = 2;
class System {
	///2 фиксирани зали. Едната е с 5 реда по 10 места, а втората е с 10 реда по десет места.
	Hall halls[HALL_COUNT];
	int eventsCapacity;
	int eventsCurrent;
	int purchaseCapacity;
	int purchaseCurrent;
	int bookingCapacity;
	int bookingCurrent;
	///Това го ползвам за запазване на локацията на файла след като е отворен или запазен.
	char* location;
	///Масив от представления
	Event** events;
	///Масив от купени билети
	Ticket** purchases;
	///Масив от запазени билети
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
	///Добавяне на представление
	bool addevent(const char* _date, const char* _eventName, int _hallId);
	///Изписва на екрана кои места са свободни
	bool freeseats(const char* _date, const char* _eventName)const;
	///Запазва билет за дадено място
	bool book(int _row, int _seat, const char* _date, const char* _eventName, const char* _note);
	///Освобождава дадено място
	bool unbook(int _row, int _seat, const char* _date, const char* _eventName);
	///Копува билет за дадено място
	bool buy(int _row, int _seat, const char* _date, const char* _eventName);
	///Извежда справка за запазените, но неплатени билети за дадено представление и дата
	bool bookings(const char* _date, const char* _name)const;
	///Като горното ама или дата или име е изпуснато и целта му е да определи кое от двете е и да извика правилната функция
	bool bookings(const char* _nameOrDate)const;
	///Проверява дали код на билет е валиден и връща съответното ред и място. Всеки код е уникален.
	bool check(const char* _code)const;
	///Извежда справка за закупени билети от дадена дата до друга и номер на зала
	bool report(const char* _fromDate, const char* _toDate, int hallId)const;
	///Като горната обаче извежда за всяка зала.
	bool report(const char* _fromDate, const char* _toDate)const;

	bool saveas(const char* _location);
	bool open(const char* _location);
	bool close();
	bool save();
	bool help()const;
	const bool isLoaded()const;
};