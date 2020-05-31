#include "Event.h"
#include <iostream>
void Event::free()
{
	delete[] eventName;
}
void Event::copyFrom(const Event& other)
{
	hallId = other.hallId;
	strcpy(date, other.date);
	eventName = new char[strlen(other.eventName) + 1];
	strcpy(eventName, other.eventName);
}
Event::Event()
{
	hallId = -1;
	strcpy(date, "0000-00-00");
	eventName = new char[1];
	eventName[0] = '\0';
}
Event& Event::operator=(const Event& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}
Event::Event(const Event& other)
{
	copyFrom(other);
}
Event::~Event()
{
	free();
}
Event::Event(const char* _date, const char* _eventName, int _hallId)
{
	strcpy(date, _date);
	eventName = new char[strlen(_eventName) + 1];
	strcpy(eventName, _eventName);
	hallId = _hallId;
}
//Проверява дали представлението е на тази дата и дали е в тази зала
bool Event::isTheSameAs(const char* _date, int _hallId)const
{
	return strcmp(date,_date)==0 && hallId== _hallId;
}
bool Event::isTheSameAs(const char* _date, const char* _eventName)const
{
	//Проверява дали представлението има същото име и е на същата дата
	return strcmp(date, _date) == 0 && strcmp(eventName, _eventName) == 0;
}
int Event::getHallId() const
{
	return hallId;
}
int Event::compareDate(const char* _date) const
{
	//Сравнява дадена дата с тази на представлението. Ако дадена дата е същата то връща 0. Ако е преди нашата дата връща -1 ако е след нашата дата връща 1;
	//date format 2020-05-19
	if (strcmp(date, _date) == 0)
		return 0;
	//Променям типът на датата за представлението към реални числа сравнява с дадената дата
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

bool Event::save(std::ofstream& outfile)
{
	outfile.write((const char*)&hallId, sizeof(int));
	outfile.write((const char*)&date, sizeof(date));
	int nameLen = strlen(eventName);
	outfile.write((const char*)&nameLen, sizeof(int));
	outfile.write((const char*)&eventName, nameLen);
	return true;
}

bool Event::open(std::ifstream& infile)
{
	free();
	infile.read((char*)&hallId, sizeof(int));
	infile.read((char*)&date, sizeof(date));
	int nameLen;
	infile.read((char*)&nameLen, sizeof(int));
	eventName = new char[nameLen+1];
	char* _eventName = new char[nameLen+1];
	infile.read((char*)&_eventName, nameLen);
	_eventName[nameLen] = '\0';
	strcpy(eventName, _eventName);
	return true;
}
