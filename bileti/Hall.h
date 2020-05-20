#pragma once
class Hall {
private:
	int id;
	int rows;
	int seatsPerRow;
	int seats;
public:
	Hall();
	Hall(int id, int rows, int seatsPerRow);
	int getRows()const;
	int getSeatsPerRow()const;
};