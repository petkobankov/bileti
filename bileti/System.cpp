#include "System.h"
#include <iostream>
#include "BookSeat.h"
System::System()
{
	halls[0] = Hall(0,10,12); // зала с номер 0, има 10 реда по 12 места на ред
	halls[1] = Hall(1, 5, 12); // зала с номер 1, има 5 реда по 12 места на ред
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
	//Добавя ново представление ако има свободна зала за тази дата. Ако няма свободна зала връща лъжа.
	if (!isDateFree(_date, _hallId))
		return false;
	if (eventsCurrent == eventsCapacity)
		;//resizeEvents();
	events[eventsCurrent++] = new Event(_date, _eventName, _hallId);
	return true;
}
bool System::isDateFree(const char* _date, int _hallId)const {
	//Проверява дали има свободна зала на определена дата и ако няма връща лъжа
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
	//Запазва за дадено представление място като има и забележка
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
	//Търси дали има представление с такова име и дата и ако няма връща празен указател
	for (int i = 0; i < eventsCapacity; i++) {
		if (events[i]->isTheSameAs(_date, _eventName))
			return events[i];
	}
	return nullptr;
}

bool System::unbook(int _row, int _seat, const char* _date, const char* _eventName)
{
	//Маха запазеното място
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
