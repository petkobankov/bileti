#include "System.h"
#include <iostream>
#include "BookSeat.h"
System::System()
{
	halls[0] = Hall(0,10,12); // ���� � ����� 0, ��� 10 ���� �� 12 ����� �� ���
	halls[1] = Hall(1, 5, 12); // ���� � ����� 1, ��� 5 ���� �� 12 ����� �� ���
	eventsCapacity=4;
	eventsCurrent=0;
	events = new Event * [eventsCapacity];
	for (int i = 0; i < eventsCapacity; i++) {
		events[i] = nullptr;
	}
	databaseCapacity=4;
	databaseCurrent=0;
	seatsDatabase = new Seat * [databaseCapacity];
	for (int i = 0; i < databaseCapacity; i++) {
		seatsDatabase[i] = nullptr;
	}
}

bool System::addevent(const char* _date, const char* _eventName, int _hallId)
{
	//������ ���� ������������� ��� ��� �������� ���� �� ���� ����. ��� ���� �������� ���� ����� ����.
	if (!isDateFree(_date, _hallId))
		return false;
	if (eventsCurrent == eventsCapacity)
		;//resizeEvents();
	events[eventsCurrent++] = new Event(_date, _eventName, _hallId);
	return true;
}
bool System::isDateFree(const char* _date, int _hallId)const {
	//��������� ���� ��� �������� ���� �� ���������� ���� � ��� ���� ����� ����
	for (int i = 0; i < eventsCapacity; i++) {
		if (events[i]->isTheSameAs(_date, _hallId))
			return false;
	}
	return true;
}
bool System::freeseats(const char* _date, const char* _eventName)
{
	const Event* foundEvent = findEvent(_date, _eventName);
	if (foundEvent == nullptr)
		return false;
	int hallId = foundEvent->getHallId();
	int seatsPerRow = halls[hallId].getSeatsPerRow();
	int rows = halls[hallId].getRows();
	int** seatsForEvent = new int* [rows];
	for (int i = 0; i < rows; i++) {
		seatsForEvent[i] = new int[seatsPerRow];
	}
	return true;
}
bool System::book(int _row, int _seat, const char* _date, const char* _eventName, const char* _note)
{
	//������� �� ������ ������������� ����� ���� ��� � ���������
	const Event* foundEvent = findEvent(_date, _eventName);
	if (foundEvent == nullptr)
		return false;
	if (!seatIsFree(foundEvent, _row, _seat))
		return false;
	if (databaseCapacity == databaseCurrent)
		;//resizeDatabase();
	seatsDatabase[databaseCurrent++] = new BookSeat(_row,_seat,foundEvent,_note);
	return true;
}

const Event* System::findEvent(const char* _date, const char* _eventName) const
{
	//����� ���� ��� ������������� � ������ ��� � ���� � ��� ���� ����� ������ ��������
	for (int i = 0; i < eventsCapacity; i++) {
		if (events[i]->isTheSameAs(_date, _eventName))
			return events[i];
	}
	return nullptr;
}

bool System::unbook(int _row, int _seat, const char* _date, const char* _eventName)
{
	//���� ���������� �����
	int seatId = -1;
	for (int i = 0; i < databaseCurrent && seatId == -1; i++) {
		if (seatsDatabase[i]->isTheSameAs(_row, _seat, _date, _eventName) && strcmp(seatsDatabase[i]->type(),"booking")==0)
			seatId = i;
	}
	if (seatId == -1)
		return false;
	popSeat(seatId);
	return true;
}

bool System::popSeat(int seatId)
{
	if (seatId >= databaseCurrent)
		return false;
	for (int i = seatId; i < databaseCurrent-1; i++) {
		seatsDatabase[i] = seatsDatabase[i + 1];
	}
	databaseCurrent--;
	return true;
}
