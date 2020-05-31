/**
 * \class Hall
 *
 * \brief Зала .Клас използван за да се фиксират две зали. Първата е 5 реда по 10 места, а втората 10 реда по 10 места
 *
 */
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