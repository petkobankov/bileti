#pragma once
class Ticket {
	char* forEvent;
	char* date;
	char* ticketId;
	char* note;
	int hallId;
	int row;
	int seat;
public:
	Ticket(int _row, int _seat, const char* _forEvent, const char* _date, int _hallId);
	Ticket(int _row, int _seat, const char* _forEvent, const char* _date, int _hallId, const char* _note);
	bool generateTicketId();
	bool isForEvent(const char* _event)const;
	bool isForDate(const char* _date)const;
	bool hasTheSameCode(const char* _code)const;
	int getRow()const;
	int getSeat()const;
	bool isTheSameAs(int _row, int _seat, const char* _date, const char* _eventName)const;
	const char* intToChar(int _a)const;
	const int sizeOfInt(int _a)const;
	bool print()const;
};