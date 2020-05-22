#include "System.h"
#include <iostream>
#include "BookSeat.h"
System::System()
{
	halls[0] = Hall(0,2,4); // ���� � ����� 0, ��� 2 ���� �� 4 ����� �� ���
	halls[1] = Hall(1,1,4); // ���� � ����� 1, ��� 1 ���� �� 4 ����� �� ���
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
	purchases = new Ticket * [purchaseCapacity];
	for (int i = 0; i < purchaseCapacity; i++) {
		purchases[i] = nullptr;
	}
	booking = new Ticket * [bookingCapacity];
	for (int i = 0; i < bookingCapacity; i++) {
		booking[i] = nullptr;
	}
}
bool System::addevent(const char* _date, const char* _eventName, int _hallId)
{
	//������ ���� ������������� ��� ��� �������� ���� �� ���� ����. ��� ���� �������� ���� ����� ����.
	if (!isDateFree(_date, _hallId))
		return false;
	if (eventsCurrent == eventsCapacity)
		;//resizeEvents();
	events[eventsCurrent++] = new Event(_date, _eventName, _hallId);
	return true;
}
bool System::isDateFree(const char* _date, int _hallId)const {
	//��������� ���� ��� �������� ���� �� ���������� ���� � ��� ���� ����� ����
	for (int i = 0; i < eventsCapacity; i++) {
		if (events[i]->isTheSameAs(_date, _hallId))
			return false;
	}
	return true;
}
bool System::freeseats(const char* _date, const char* _eventName)const
{
	//������� �� ��������� ��� ����� �� ��������, ��� ������, ��� ��������
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
			seatsForEvent[booking[i]->getRow()][booking[i]->getSeat()] = 'o';
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
	//������� �� ������ ������������� ����� ���� ��� � ���������
	const Event* foundEvent = findEvent(_date, _eventName);
	if (foundEvent == nullptr)
		return false;
	if (!seatIsFree(_eventName, _row, _seat))
		return false;
	if (bookingCapacity == bookingCurrent)
		;//resizeBookings();
	int hallId = foundEvent->getHallId();
	booking[bookingCurrent++] = new Ticket(_row,_seat,_eventName,_date,hallId,_note);
	return true;
}
const Event* System::findEvent(const char* _date, const char* _eventName) const
{
	//����� ���� ��� ������������� � ������ ��� � ���� � ��� ���� ����� ������ ��������
	for (int i = 0; i < eventsCapacity; i++) {
		if (events[i]->isTheSameAs(_date, _eventName))
			return events[i];
	}
	return nullptr;
}
bool System::seatIsFree(const char* _event, int _row, int _seat) const
{
	//��������� ���� �� ������ �������������, ���������� ����� � ��������
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
	//������ ������ �� ���������� ����� � ������ � ��������� ������� ��������� �� �������� ��
	int bookingId = -1;
	if (bookingId == -1)
		return false;
	return popBooking(bookingId);
}
bool System::popBooking(int bookingId)
{
	//���� ���������� �����
	if (bookingId >= bookingCurrent)
		return false;
	delete booking[bookingId];
	for (int i = bookingId; i < bookingCurrent -1; i++) {
		booking[i] = booking[i + 1];
	}
	booking[bookingCurrent] = nullptr;
	bookingCurrent--;
	return true;
}
bool System::buy(int _row, int _seat, const char* _date, const char* _eventName)
{
	//������� ����� �� ������������� � ������ �������� ������ ���, ����� ������� ���������� �� ����������� �����
	const Event* foundEvent = findEvent(_date, _eventName);
	if (foundEvent == nullptr)
		return false;
	if (!seatIsFree(_eventName, _row, _seat)) {
		int bookingId = findSeatBookingId(_eventName, _row, _seat);
		if (bookingId == -1)
			return false;
		return buyBooking(bookingId);
	}
	if (purchaseCapacity == purchaseCurrent)
		;//resizePurchases();
	int hallId = foundEvent->getHallId();
	purchases[purchaseCurrent++] = new Ticket(_row,_seat,_eventName,_date,hallId);
	return true;
}
const int System::findSeatBookingId(const char* _eventName, int _row, int _seat) const
{
	//����� ���� �� ���������� �������������, ������ ����� � �������� � ��� ��, ����� ������ �� ������ � ������ ��� �������� �����
	for (int i = 0; i < bookingCurrent; i++) {
		if (booking[i]->isForEvent(_eventName))
			if (booking[i]->getRow() == _row && booking[i]->getSeat() == _seat)
				return i;
	}
	return -1;
}
bool System::buyBooking(int _bookingId)
{
	//������� �������. �������� �� ������ ������� ����� ���� �� ���� ������ � ��������. ��������, �� � ��� � ������� ���� �����.
	if (_bookingId >= bookingCurrent)
		return false;
	if (purchaseCapacity == purchaseCurrent)
		;//resizePurchases();
	purchases[purchaseCurrent++] = booking[_bookingId];
	for (int i = _bookingId; i < bookingCurrent - 1; i++) {
		booking[i] = booking[i + 1];
	}
	booking[bookingCurrent]=nullptr;
	bookingCurrent--;
	return true;
}
bool System::bookings(const char* _date, const char* _name) const
{
	//������� �� ��������� ������ �������� ������ �� ���������� ���� � ��� �� �������������
	int counter = 0;
	for (int i = 0; i < bookingCurrent; i++) {
		if (booking[i]->isForEvent(_name) && booking[i]->isForDate(_date)) {
			std::cout << counter << ")";
			booking[i]->print();
			counter++;
		}
	}
	return true;
}
bool System::bookings(const char* _nameOrDate) const
{
	//��������� ���� ��������� � ���� ��� ��� ������ � ����� �� �� ���� � ��� ���
	int lenOfValue = strlen(_nameOrDate);
	if (lenOfValue > 10)
		return bookingsForName(_nameOrDate); //��� � ������ �� 10 ������� ����� 100% �� � ����
	char* check = new char[lenOfValue + 1];
	strcpy(check, _nameOrDate);
	for (int i = 0; i < 2; i++) {
		//���� � ������ ��� ��� ������ � ���� ���� � ����� ��� �� ������ �� ��� � ����� �����
		check = strchr(check, '-');
		if (check == nullptr)
			delete[] check; return bookingsForName(_nameOrDate);
		check += 1;
	}
	delete[] check;
	return bookingsForDate(_nameOrDate);
}
bool System::bookingsForDate(const char* _date) const
{
	//������� �� ��������� ������ �������� ������ �� ���������� ����
	int counter = 0;
	for (int i = 0; i < bookingCurrent; i++) {
		if (booking[i]->isForDate(_date)) {
			std::cout << counter << ")";
			booking[i]->print();
			counter++;
		}
	}
	return true;
}
bool System::bookingsForName(const char* _name) const
{
	//������� �� ��������� ������ �������� ������ �� ���������� ��� �� �������������
	int counter = 0;
	for (int i = 0; i < bookingCurrent; i++) {
		if (booking[i]->isForEvent(_name)) {
			std::cout << counter << ")";
			booking[i]->print();
			counter++;
		}
	}
	return true;
}
bool System::check(const char* _code) const
{
	//��������� ���� ����� ��� �� ����� � ������� � ��� � ������� ������� �� ����� � ������
	const Ticket* ticket = nullptr;
	for (int i = 0; i < bookingCurrent; i++) {
		if (booking[i]->hasTheSameCode(_code))
			ticket = booking[i];
	}
	for (int i = 0; i < purchaseCurrent; i++) {
		if (purchases[i]->hasTheSameCode(_code))
			ticket = purchases[i];
	}
	if (ticket == nullptr)
		return false;
	std::cout << "Row: " << ticket->getRow << "Seat: " << ticket->getSeat << std::endl;
	return true;
}
bool System::report(const char* _fromDate, const char* _toDate, const char* hallId)const
{
	//������� ������� �� �������� ������ �� ���� �� ����� ���� � ���������� ����.
	for (int i = 0; i < eventsCurrent; i++) {
		if (events[i]->compareDate(_fromDate) >= 0 &&
			events[i]->compareDate(_toDate) <= 0 &&
			events[i]->getHallId==hallId)
			events[i]->print(); printSoldTicketsFor(events[i]->getEventName(), events[i]->getDate());
	}
	return true;
}
bool System::report(const char* _fromDate, const char* _toDate) const
{
	//������� ������� �� �������� ������ �� ���� �� ����� ����.
	for (int i = 0; i < eventsCurrent; i++) {
		if (events[i]->compareDate(_fromDate) >= 0 &&
			events[i]->compareDate(_toDate) <= 0)
			events[i]->print(); printSoldTicketsFor(events[i]->getEventName(), events[i]->getDate());
	}
	return true;
}
bool System::printSoldTicketsFor(const char* _eventName, const char* _date) const
{
	//������� �������. ������� ���� �� ��������� ������ �� ������������� � ���������� ��� � ����.
	int counter = 0;
	for (int i = 0; i < purchaseCurrent; i++) {
		if (purchases[i]->isForEvent(_eventName) && purchases[i]->isForDate(_date))
			counter++;
	}
	std::cout << "Tickets sold: " << counter << std::endl;
	return true;
}
