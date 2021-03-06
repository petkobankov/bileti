#include "Ticket.h"
#include <string.h>
#include <iostream>
#include <fstream>
void Ticket::free()
{
	delete[] forEvent;
	delete[] date;
	delete[] ticketId;
	delete[] note;
}
void Ticket::copyFrom(const Ticket& other)
{
	row = other.row;
	seat = other.seat;
	hallId = other.hallId;
	forEvent = new char[strlen(other.forEvent) + 1];
	strcpy(forEvent, other.forEvent);
	date = new char[strlen(other.date) + 1];
	strcpy(date, other.date);
	ticketId = new char[strlen(other.ticketId)+1];
	strcpy(ticketId, other.ticketId);
	note = new char[strlen(other.note)+1];
	strcpy(note,other.note);
}
Ticket::Ticket()
{
	row = -1;
	seat = -1;
	hallId = -1;
	forEvent = new char[1];
	forEvent[0] = '\0';
	date = new char[1];
	date[0] = '\0';
	ticketId = new char[1];
	ticketId[0] = '\0';
	note = new char[1];
	note[0] = '\0';
}
Ticket::Ticket(const Ticket& other)
{
	copyFrom(other);
}
Ticket& Ticket::operator=(const Ticket& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}
Ticket::~Ticket()
{
	free();
}
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
	//��������� �� �������� ������ ��� �� �����, ����� ������� ���������� �� ����������� �����
	int sizeOfTicketId = sizeOfInt(row) + sizeOfInt(seat) + strlen(date) + sizeOfInt(hallId) + 3;
	ticketId = new char[sizeOfTicketId + 1];
	ticketId[0] = '\0';
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
	return _row == row && _seat == seat && strcmp(date, _date) == 0 && strcmp(forEvent, _eventName)==0;
}
const char* Ticket::intToChar(int _a) const
{
	//������� ������� �� �������� �� ������ ����� � ������� �� ���� ����� � ��� �����
	int temp = _a;
	int counter = sizeOfInt(_a);
	char* dd = new char[counter + 1];
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
	//������� �������, ����� ����� ����� � �������� �� ���� ������ �����
	if (_a == 0)
		return 1;
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
	std::cout << "For event: " << forEvent << ", date: " << date << ", hall id: " << hallId << ", row: " << row << ", seat: " << seat << ", code: " << ticketId << std::endl;
	return true;
}

bool Ticket::printSeatNumbers() const
{
	std::cout << "This ticket is for row: " << row << ", seat: " << seat << std::endl;
	return true;
}

bool Ticket::save(std::ofstream& outfile)
{
	outfile.write((const char*)&hallId, sizeof(int));
	outfile.write((const char*)&row, sizeof(int));
	outfile.write((const char*)&seat, sizeof(int));
	int eventLen = strlen(forEvent);
	int dateLen = strlen(date);
	int ticketLen = strlen(ticketId);
	int noteLen = strlen(note);
	outfile.write((const char*)&eventLen, sizeof(int));
	outfile.write((const char*)&dateLen, sizeof(int));
	outfile.write((const char*)&ticketLen, sizeof(int));
	outfile.write((const char*)&noteLen, sizeof(int));
	outfile.write((const char*)forEvent, eventLen);
	outfile.write((const char*)date, dateLen);
	outfile.write((const char*)ticketId, ticketLen);
	outfile.write((const char*)note, noteLen);

	return true;
}

bool Ticket::open(std::ifstream& infile)
{
	free();
	infile.read((char*)&hallId, sizeof(int));
	infile.read((char*)&row, sizeof(int));
	infile.read((char*)&seat, sizeof(int));
	int eventLen;
	int dateLen;
	int ticketLen;
	int noteLen;
	infile.read((char*)&eventLen, sizeof(int));
	infile.read((char*)&dateLen, sizeof(int));
	infile.read((char*)&ticketLen, sizeof(int));
	infile.read((char*)&noteLen, sizeof(int));

	char* _forEvent = new char[eventLen + 1];
	char* _date = new char[dateLen + 1];
	char* _ticketId = new char[ticketLen + 1];
	char* _note = new char[noteLen + 1];

	infile.read(_forEvent, eventLen);
	infile.read(_date, dateLen);
	infile.read(_ticketId, ticketLen);
	infile.read(_note, noteLen);

	_forEvent[eventLen] = '\0';
	_date[dateLen] = '\0';
	_ticketId[ticketLen] = '\0';
	_note[noteLen] = '\0';

	forEvent = _forEvent;
	date = _date;
	ticketId = _ticketId;
	note = _note;
	return true;
}
