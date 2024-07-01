#include "stdafx.h"
#include "function1.h"


void calculate_day_number(int year) {
	using namespace std;
	if (year % 4 == 0)
	{
		cout << "Введенный год ГГГГ является високосным" << endl;
	}
	else {
		cout << "Введенный год ГГГГ не является високосным" << endl;
	}
}