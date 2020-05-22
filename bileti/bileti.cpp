using namespace std;
#include <iostream>
#include "System.h"
const int LENGTH = 10;
int main()
{
	/*char command[LENGTH];

	cin >> command;
	System sys;


	while (strcmp(command, "exit") != 0) {

		if (strcmp(command, "open") == 0) {
			char location[1024];
			cin >> location;
			sys.open(location);
		}
		else {
			cout << "Error" << endl;
			return 0;
		}

		cin >> command;

	}*/
	//halls[0] = Hall(0,2,4); // зала с номер 0, има 2 реда по 4 места на ред
	//halls[1] = Hall(1, 1, 4); // зала с номер 1, има 1 реда по 4 места на ред
	
	System sys;
	sys.addevent("2020-05-22","Rojden den",0);
	sys.addevent("2020-05-27", "Predavane na oop domashno", 1);
	sys.freeseats("2020-05-22","Rojden den");
	sys.freeseats("2020-05-27", "Predavane na oop domashno");
	sys.book(0,1, "2020-05-22", "Rojden den","lala");
	sys.book(0,2, "2020-05-22", "Rojden den", "lala");
	sys.book(0, 3, "2020-05-22", "Rojden den", "lala");
	sys.book(1, 1, "2020-05-22", "Rojden den", "lala");
	sys.book(1, 0, "2020-05-22", "Rojden den", "lala");
	sys.book(1, 2, "2020-05-22", "Rojden den", "lala");
	sys.book(1, 3, "2020-05-22", "Rojden den", "lala");
	sys.unbook(1, 3, "2020-05-22", "Rojden den");

	sys.buy(0, 3, "2020-05-27", "Predavane na oop domashno");
	sys.buy(0, 1, "2020-05-22", "Rojden den");
	sys.buy(0, 2, "2020-05-22", "Rojden den");
	sys.buy(1, 0, "2020-05-22", "Rojden den");
	sys.buy(1, 2, "2020-05-22", "Rojden den");
	sys.buy(1, 3, "2020-05-22", "Rojden den");
	sys.freeseats("2020-05-22", "Rojden den");
	sys.freeseats("2020-05-27", "Predavane na oop domashno");
	sys.bookings("2020-05-22");
}

