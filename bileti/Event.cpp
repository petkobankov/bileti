#include "Event.h"
#include <iostream>
Event::Event(const char* _date, const char* _eventName, int _hallId)
{
	strcpy(date, _date);
	eventName = new char[strlen(_eventName) + 1];
	strcpy(eventName, _eventName);
	hallId = _hallId;
}
//��������� ���� ��������������� � �� ���� ���� � ���� � � ���� ����
bool Event::isTheSameAs(const char* _date, int _hallId)const
{
	
	return strcmp(date,_date)==0 && hallId== _hallId;
}
bool Event::isTheSameAs(const char* _date, const char* _eventName)const
{
	//��������� ���� ��������������� ��� ������ ��� � � �� ������ ����
	return strcmp(date, _date) == 0 && strcmp(eventName, _eventName) == 0;
}
int Event::getHallId() const
{
	return hallId;
}
int Event::compareDate(const char* _date) const
{
	//�������� ������ ���� � ���� �� ���������������. ��� ������ ���� � ������ �� ����� 0. ��� � ����� ������ ���� ����� -1 ��� � ���� ������ ���� ����� 1;
	//date format 2020-05-19
	if (strcmp(date, _date) == 0)
		return 0;
	//�������� ����� �� ������ �� ��������������� ��� ������ ����� �������� � �������� ����
	int eventYear = atoi(date);
	int _eventYear = atoi(_date);
	if (eventYear < _eventYear)
		return -1;
	if (eventYear > _eventYear)
		return 1;
	const char* monthAndDay = strchr(date, '-');
	int eventMonth = atoi(monthAndDay + 1);
	const char* _monthAndDay = strchr(_date, '-');
	int _eventMonth = atoi(_monthAndDay + 1);

	if (eventMonth < _eventMonth)
		return -1;
	if (eventMonth > _eventMonth)
		return 1;

	const char* charDay = strchr(monthAndDay + 1, '-');
	int eventDay = atoi(charDay + 1);
	const char* _charDay = strchr(_monthAndDay + 1, '-');
	int _eventDay = atoi(_charDay + 1);
	if (eventDay < _eventDay)
		return -1;
	if (eventDay > _eventDay)
		return 1;
	return 0;
}

bool Event::print() const
{
	std::cout << "Event name: " << eventName << ", on date: " << date << ", for hall: " << hallId << std::endl;
	return true;
}

const char* Event::getDate() const
{
	return date;
}

const char* Event::getEventName() const
{
	return eventName;
}
