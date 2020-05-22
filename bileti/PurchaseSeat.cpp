#include "PurchaseSeat.h"

PurchaseSeat::PurchaseSeat(int _row, int _seat, const char* _forEvent,const char* _date, int _hallId) : Seat(_row, _seat, _forEvent,_date, _hallId)
{
	//Създаване на уникален сложен код за закупен билет, който съдържа информация за съответното място
	int sizeOfTicketId = sizeOfInt(_row) + sizeOfInt(_seat) + strlen(_date)+sizeOfInt(_hallId) + 3;
	ticketId = new char[sizeOfTicketId + 1];
	strcat(ticketId, intToChar(_row));
	strcat(ticketId, ".");
	strcat(ticketId, intToChar(_seat));
	strcat(ticketId, ".");
	strcat(ticketId, _date);
	strcat(ticketId, ".");
	strcat(ticketId, intToChar(_hallId));
}

const char* PurchaseSeat::intToChar(int _a) const
{
	//Помощна функция за приемане на реално число и връщане на това число в тип текст
	int temp = _a;
	int counter = sizeOfInt(_a);
	char* dd = new char[counter + 1];
	temp = _a;
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

const int PurchaseSeat::sizeOfInt(int _a) const
{
	//Помощна функция, която казва какъв е размерът на едно реално число
	int temp = _a;
	int counter = 0;
	while (temp != 0) {
		counter++;
		temp /= 10;
	}
	return counter;
}
