#pragma once
#include "Event.h"
class Seat {
	const Event* forEvent; //���� ��������. ����� ���� ���� �� ���� ��
	int row;
	int seat;
public:
	virtual ~Seat();
	virtual const char* type()const=0; //����� type. ���� ������ �� ����� ����� �������� � ����� ���� ����� �� �����. ������ �������� � ��������
	Seat(int _row, int _seat, const Event* _forEvent);
	bool isTheSameAs(int _row,int _seat,const char* _date,const char* _eventName)const;
};