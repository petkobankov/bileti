using namespace std;
#include <iostream>
#include "System.h"
const int LENGTH = 13;
int main()
{
	//halls[0] = Hall(0,5,10); // зала с номер 0, има 5 реда по 10 места на ред
	//halls[1] = Hall(1, 10, 10); // зала с номер 1, има 10 реда по 10 места на ред
	char command[LENGTH];
	System* sys = new System();
	
	cin >> command;
	while (strcmp(command, "exit") != 0) {
		while (strcmp(command, "open") != 0 && !sys->isLoaded() && strcmp(command, "exit") != 0) {
			cout << "You need to first open a file. If the file does not exist, the program will create one with that name. It should end in .bin" << endl;
			cin >> command;
		}
		if (strcmp(command, "open") == 0) {
			char location[1024];
			cin.ignore();
			cin.getline(location, 1024);
			try {
				if (!sys->close())
					cout << "Something went wrong" << endl;
				if (!sys->open(location))
					cout << "Something went wrong" << endl;
			}
			catch (const char* msg) {
				cout << msg << endl;
			}

		}
		else if (strcmp(command, "close") == 0) {
			try {
				if (!sys->close())
					cout << "Something went wrong" << endl;
				delete sys;
				sys = new System();
			}
			catch (const char* msg) {
				cout << msg << endl;
			}
		}
		else if (strcmp(command, "save") == 0) {
			try {
				if (!sys->save())
					cout << "Something went wrong" << endl;
			}
			catch (const char* msg) {
				cout << msg << endl;
			}
		}
		else if (strcmp(command, "saveas") == 0) {
			char location[1024];
			cin.ignore();
			cin.getline(location, 1024);
			try {
				if (!sys->saveas(location))
					cout << "Something went wrong" << endl;
			}
			catch (const char* msg) {
				cout << msg << endl;
			}
		}
		else if (strcmp(command, "help") == 0) {
			try {
				if (!sys->help())
					cout << "Something went wrong" << endl;
			}
			catch (const char* msg) {
				cout << msg << endl;
			}
		}
		else if (strcmp(command, "addevent") == 0) {
			char date[1024];
			int hallId;
			char name[1024];

			cin >> date;
			cin >> hallId;
			cin >> name;
			try {
				if (!sys->addevent(date, name, hallId))
					cout << "Something went wrong" << endl;
			}
			catch (const char* msg) {
				cout << msg << endl;
			}
		}
		else if (strcmp(command, "freeseats") == 0) {
			char date[1024];
			char name[1024];

			cin >> date;
			cin >> name;
			try {
				if (!sys->freeseats(date, name))
					cout << "Something went wrong" << endl;
			}
			catch (const char* msg) {
				cout << msg << endl;
			}
		}
		else if (strcmp(command, "book") == 0) {
			int row;
			int seat;
			char date[1024];
			char name[1024];
			char note[1024];
			cin >> row;
			cin >> seat;
			cin >> date;
			cin >> name;
			cin >> note;
			try {
				if (!sys->book(row, seat, date, name, note))
					cout << "Something went wrong" << endl;
			}
			catch (const char* msg) {
				cout << msg << endl;
			}
		}
		else if (strcmp(command, "unbook") == 0) {
			int row;
			int seat;
			char date[1024];
			char name[1024];
			cin >> row;
			cin >> seat;
			cin >> date;
			cin >> name;
			try {
				if (!sys->unbook(row, seat, date, name))
					cout << "Something went wrong" << endl;
			}
			catch (const char* msg) {
				cout << msg << endl;
			}
		}
		else if (strcmp(command, "buy") == 0) {
			int row;
			int seat;
			char date[1024];
			char name[1024];
			cin >> row;
			cin >> seat;
			cin >> date;
			cin >> name;
			try {
				if (!sys->buy(row, seat, date, name))
					cout << "Something went wrong" << endl;
			}
			catch (const char* msg) {
				cout << msg << endl;
			}
		}
		else if (strcmp(command, "bookings") == 0) {
			char value[1024];
			cin.ignore();
			cin.getline(value, 1024);
			try {
				if (strchr(value, ' ') == nullptr) {
					if (!sys->bookings(value))
						cout << "Something went wrong" << endl;
				}
				else {
					int locationOfSpace = strcspn(value, " ");
					char* _date = new char[locationOfSpace + 1];
					for (int i = 0; i < locationOfSpace; i++) {
						_date[i] = value[i];
					}
					_date[locationOfSpace] = '\0';

					if (!sys->bookings(_date, strchr(value, ' ') + 1))
						cout << "Something went wrong" << endl;
				}
			}
			catch (const char* msg) {
				cout << msg << endl;
			}
		}
		else if (strcmp(command, "check") == 0) {

			char code[1024];
			cin >> code;
			try {
				if (!sys->check(code))
					cout << "Something went wrong" << endl;
			}
			catch (const char* msg) {
				cout << msg << endl;
			}
		}
		else if (strcmp(command, "report") == 0) {

			char from[1024];
			char value[1024];
			cin >> from;
			cin.ignore();
			cin.getline(value, 1024);
			try {
				if (strchr(value, ' ') == nullptr) {
					if (!sys->report(from,value))
						cout << "Something went wrong" << endl;
				}
				else {
					int locationOfSpace = strcspn(value, " ");
					char* _date = new char[locationOfSpace + 1];
					for (int i = 0; i < locationOfSpace; i++) {
						_date[i] = value[i];
					}
					_date[locationOfSpace] = '\0';

					if (!sys->report(from,_date, atoi(strchr(value, ' ') + 1)))
						cout << "Something went wrong" << endl;
				}
			}
			catch (const char* msg) {
				cout << msg << endl;
			}
		}
		else if (strcmp(command, "exit") == 0) {
			delete sys;
			return 1;
		}
		else {
			cout << "Invalid command" << endl;
		}
		cout << endl;
		cin >> command;

	}
	cout << "Exiting the program..." << endl;
	delete sys;
}


