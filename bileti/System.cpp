#include "System.h"
#include <iostream>
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
}

bool System::addevent(const char* _date, const char* _eventName, int _hallId)
{
	//������ ���� ������������� ��� ��� �������� ���� �� ���� ����. ��� ���� �������� ���� ����� ����.
	if (!isDateFree(_date, _hallId))
		return false;
	if (eventsCurrent == eventsCapacity)
		;//resize();
	events[eventsCurrent++] = new Event(_date, _eventName, _hallId);
	return true;
}
bool System::isDateFree(const char* _date, int _hallId) {
	//��������� ���� ��� �������� ���� �� ���������� ���� � ��� ���� ����� ����
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
