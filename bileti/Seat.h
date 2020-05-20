#pragma once
#include "Event.h"
class Seat {
	const Event* forEvent; //лоша практика. всеки знае само за себе си
	int row;
	int seat;
public:
	virtual ~Seat();
	virtual const char* type()const=0; //махай type. само трябва да знаеш какво създаваш и после няма нужда да знаеш. правиш проверки в сетърите
	Seat(int _row, int _seat, const Event* _forEvent);
	bool isTheSameAs(int _row,int _seat,const char* _date,const char* _eventName)const;
};