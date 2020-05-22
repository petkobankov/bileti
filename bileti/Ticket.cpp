#include "Ticket.h"
#include <string.h>
#include <iostream>

Ticket::Ticket(int _row, int _seat, const char* _forEvent, const char* _date, int _hallId)
{
	row = _row;
	seat = _seat;
	hallId = _hallId;
	forEvent = new char[strlen(_forEvent) + 1];
	strcpy(forEvent, _forEvent);
	date = new char[strlen(_date) + 1];
	strcpy(date, _date);
	generateTicketId();
	note = new char[1];
	note[0] = '\0';
}
Ticket::Ticket(int _row, int _seat, const char* _forEvent, const char* _date, int _hallId, const char* _note)
{
	row = _row;
	seat = _seat;
	hallId = _hallId;
	forEvent = new char[strlen(_forEvent) + 1];
	strcpy(forEvent, _forEvent);
	date = new char[strlen(_date) + 1];
	strcpy(date, _date);
	generateTicketId();
	note = new char[strlen(_note) + 1];
	strcpy(note, _note);
}
bool Ticket::generateTicketId()
{
	//Създаване на уникален сложен код за билет, който съдържа информация за съответното място
	int sizeOfTicketId = sizeOfInt(row) + sizeOfInt(seat) + strlen(date) + sizeOfInt(hallId) + 3;
	ticketId = new char[sizeOfTicketId + 1];
	strcat(ticketId, intToChar(row));
	strcat(ticketId, ".");
	strcat(ticketId, intToChar(seat));
	strcat(ticketId, ".");
	strcat(ticketId, date);
	strcat(ticketId, ".");
	strcat(ticketId, intToChar(hallId));
	return true;
}
bool Ticket::isForEvent(const char* _event) const
{
	if (strcmp(forEvent, _event) == 0)
		return true;
	return false;
}
bool Ticket::isForDate(const char* _date) const
{
	if (strcmp(date, _date) == 0)
		return true;
	return false;
}
bool Ticket::hasTheSameCode(const char* _code) const
{
	if (strcmp(ticketId, _code) == 0)
		return true;
	return false;
}
int Ticket::getRow() const
{
	return row;
}
int Ticket::getSeat() const
{
	return seat;
}
bool Ticket::isTheSameAs(int _row, int _seat, const char* _date, const char* _eventName) const
{
	return false;
}
const char* Ticket::intToChar(int _a) const
{
	//Помощна функция за приемане на реално число и връщане на това число в тип текст
	int temp = _a;
	int counter = sizeOfInt(_a);
	char* dd = new char[counter + 1];
	temp = _a;
	for (int i = 0; i < counter; i++) {
		dd[i] = '0' + temp % 10;
		temp /= 10;
	}
	dd[counter] = '\0';
	char* newString = new char[counter + 1];
	for (int i = 0; i < counter; i++) {
		newString[i] = dd[counter - i - 1];
	}
	newString[counter] = '\0';
	delete[]dd;
	return newString;
}
const int Ticket::sizeOfInt(int _a) const
{
	//Помощна функция, която казва какъв е размерът на едно реално число
	int temp = _a;
	int counter = 0;
	while (temp != 0) {
		counter++;
		temp /= 10;
	}
	return counter;
}
bool Ticket::print() const
{
	std::cout << "For event: " << forEvent << ", date: " << date << ", hall id: " << hallId << ", row: " << row << ", seat: " << seat << std::endl;
	return true;
}
