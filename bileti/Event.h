/**
 * \class Event
 *
 * \brief �������������. ����� ������������� �� �������� �� ����, ��� � ����� �� ���� � ����� �� �� �������.
 *
 */
#pragma once
#include "Hall.h"
#include <cstring>
#include <fstream>

class Event {
	///����� �� ���� � ����� �� �� ������� ���������������
	int hallId;
	///������ �� ����: yyyy-mm-dd
	char date[11];
	///��� �� �������������
	char* eventName;
	void free();
	void copyFrom(const Event& other);
public:
	Event();
	Event& operator=(const Event& other);
	Event(const Event& other);
	~Event();
	//Big 4

	Event(const char* _date,const char* _eventName,int _hallId);
	bool isTheSameAs(const char* _date, int _hallId)const;
	bool isTheSameAs(const char* _date, const char* _eventName)const;
	int getHallId()const;
	int compareDate(const char* _date)const;
	bool print()const;
	const char* getDate()const;
	const char* getEventName()const;
	bool save(std::ofstream& outfile);
	bool open(std::ifstream& infile);
};