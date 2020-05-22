#include "System.h"
#include <iostream>
#include "BookSeat.h"
System::System()
{
	halls[0] = Hall(0,2,4); // зала с номер 0, има 2 реда по 4 места на ред
	halls[1] = Hall(1,1,4); // зала с номер 1, има 1 реда по 4 места на ред
	eventsCapacity=4;
	eventsCurrent=0;
	events = new Event * [eventsCapacity];
	for (int i = 0; i < eventsCapacity; i++) {
		events[i] = nullptr;
	}
	purchaseCapacity=4;
	purchaseCurrent=0;
	bookingCapacity=4;
	bookingCurrent=0;
	purchases = new PurchaseSeat * [purchaseCapacity];
	for (int i = 0; i < purchaseCapacity; i++) {
		purchases[i] = nullptr;
	}
	booking = new BookSeat * [bookingCapacity];
	for (int i = 0; i < bookingCapacity; i++) {
		booking[i] = nullptr;
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
	//Извежда на конзолата кои места са свободни, кои купени, кои запазени
	//' ' - free // 'o'-booked // 'x'-purchased
	const Event* foundEvent = findEvent(_date, _eventName);
	if (foundEvent == nullptr)
		return false;
	int hallId = foundEvent->getHallId();
	int seatsPerRow = halls[hallId].getSeatsPerRow();
	int rows = halls[hallId].getRows();
	char** seatsForEvent = new char* [rows];
	for (int i = 0; i < rows; i++) {
		seatsForEvent[i] = new char[seatsPerRow];
	}
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < seatsPerRow; j++) {
			seatsForEvent[i][j] = ' ';
		}
	}
	for (int i = 0; i < bookingCurrent; i++) {
		if (booking[i]->isForEvent(_eventName))
			seatsForEvent[booking[i]->getRow()][booking[i]->getSeat()] = "o";
	}
	for (int i = 0; i < purchaseCurrent; i++) {
		if (purchases[i]->isForEvent(_eventName))
			seatsForEvent[purchases[i]->getRow()][purchases[i]->getSeat()] = 'x';
	}
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < seatsPerRow; j++) {
			std::cout << "[" << seatsForEvent[i][j] << "]" << std::endl;
		}
		std::cout << std::endl;
	}
	for (int i = 0; i < rows; i++) {
		delete seatsForEvent[i];
	}
	delete[] seatsForEvent;
	return true;
}
bool System::book(int _row, int _seat, const char* _date, const char* _eventName, const char* _note)
{
	//Запазва за дадено представление място като има и забележка
	const Event* foundEvent = findEvent(_date, _eventName);
	if (foundEvent == nullptr)
		return false;
	if (!seatIsFree(_eventName, _row, _seat))
		return false;
	if (bookingCapacity == bookingCurrent)
		;//resizeBookings();
	booking[bookingCurrent++] = new BookSeat(_row,_seat, _eventName,_note);
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

bool System::seatIsFree(const char* _event, int _row, int _seat) const
{
	//Проверява дали за дадено представление, определено място е свободно
	for (int i = 0; i < bookingCurrent; i++) {
		if (booking[i]->isForEvent(_event))
			if (booking[i]->getRow() == _row && booking[i]->getSeat() == _seat)
				return false;
	}
	for (int i = 0; i < purchaseCurrent; i++) {
		if (purchases[i]->isForEvent(_event))
			if (purchases[i]->getRow() == _row && purchases[i]->getSeat() == _seat)
				return false;
	}
	return true;
}

bool System::unbook(int _row, int _seat, const char* _date, const char* _eventName)
{
	//Намира номера на запазеното място в масива и изпълнява помощна функцията за махането му
	int bookingId = -1;
	if (bookingId == -1)
		return false;
	return popBooking(bookingId);
}

bool System::popBooking(int bookingId)
{
	//Маха запазеното място
	if (bookingId >= bookingCurrent)
		return false;
	for (int i = bookingId; i < bookingCurrent -1; i++) {
		booking[i] = booking[i + 1];
	}
	bookingCurrent--;
	return true;
}

bool System::buy(int _row, int _seat, const char* _date, const char* _eventName)
{
	//Закупва билет за представление и издава уникален сложен код, който съдържа информация за съответното място
	const Event* foundEvent = findEvent(_date, _eventName);
	if (foundEvent == nullptr)
		return false;
	if (!seatIsFree(_eventName, _row, _seat))
		return false;
	if (purchaseCapacity == purchaseCurrent)
		;//resizePurchases();
	int hallId = foundEvent->getHallId();
	purchases[purchaseCurrent++] = new PurchaseSeat(_row, _seat, _eventName, hallId);
	return true;
}
