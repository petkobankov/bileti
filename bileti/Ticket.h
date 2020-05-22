#pragma once
class Ticket {
	char* forEvent;
	char* date;
	char* ticketId;
	char* note;
	int hallId;
	int row;
	int seat;
	void free();
	void copyFrom(const Ticket& other);
	bool generateTicketId();
public:
	Ticket();
	Ticket(const Ticket& other);
	Ticket& operator=(const Ticket& other);
	~Ticket();
	//Big 4
	Ticket(int _row, int _seat, const char* _forEvent, const char* _date, int _hallId);
	Ticket(int _row, int _seat, const char* _forEvent, const char* _date, int _hallId, const char* _note);
	
	bool isForEvent(const char* _event)const;
	bool isForDate(const char* _date)const;
	bool hasTheSameCode(const char* _code)const;
	int getRow()const;
	int getSeat()const;
	bool isTheSameAs(int _row, int _seat, const char* _date, const char* _eventName)const;
	const char* intToChar(int _a)const;
	const int sizeOfInt(int _a)const;
	bool print()const;
	bool printSeatNumbers()const;
};