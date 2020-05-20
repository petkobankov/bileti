#include "System.h"
#include <iostream>
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
}

bool System::addevent(const char* _date, const char* _eventName, int _hallId)
{
	//Добавя ново представление ако има свободна зала за тази дата. Ако няма свободна зала връща лъжа.
	if (!isDateFree(_date, _hallId))
		return false;
	if (eventsCurrent == eventsCapacity)
		;//resize();
	events[eventsCurrent++] = new Event(_date, _eventName, _hallId);
	return true;
}
bool System::isDateFree(const char* _date, int _hallId) {
	//Проверява дали има свободна зала на определена дата и ако няма връща лъжа
	for (int i = 0; i < eventsCapacity; i++) {
		if (events[i]->isTheSameAs(_date, _hallId))
			return false;
	}
	return true;
}
bool System::book(int _row, int _seat, const char* _date, const char* _eventName, const char* _note)
{
	Event* event = findEvent(_date, _eventName);
	return true;
}
