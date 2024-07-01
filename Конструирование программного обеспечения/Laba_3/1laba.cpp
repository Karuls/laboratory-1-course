#include"stdafx.h"
#include <iostream>
#include <stdio.h>
void calculate_day_number(int);
int calculate_birthday(int, int, int, int);
void enums(int);
void checking_for_holidays(int);
int months1[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int months2[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int programmers_day = 255;
int first_summer_day = 152;
int mums_day = 67;
using namespace std;

int main() {
	
	setlocale(LC_ALL, "rus");
	int data, year, day = 0, month, number{};
	int year2{}, day2{}, month2{}, birthday, diffiernce = 0;
	int birthcount = 0;  //порядковый номер дня рождения

	cout << "Введите дату формата ДДММГГГГ" << endl;
	cin >> data;

	year = data % 10000; 
	day = data / 1000000;
	month = data / 10000 % 100;

	
	

	if (year <= 0 || month > 12 || month <=0 || day >= 32 || day <= 0) {
		cout << "Напишите в формате ДДММГГГГ" << endl;
		return 0;
	}
	else {
		cout << "День: " << day << endl;
		cout << "Месяц: " << month <<endl; 
		cout << "Год: " << year << endl;

		enums(month);
		calculate_day_number(year);
		number = calculate_birthday(year, number, day, month);
		checking_for_holidays(number);
		
		cout << "Введите свой день рождения" << endl;
		cin >> birthday;

			year2 = birthday % 10000;
			day2 = birthday / 1000000;
			month2 = birthday / 10000 % 100;

		if (year % 4 == 0) {
			for (int i = 0; i < month2 - 1; i++) {
				birthcount += months2[i];
			}
			birthcount += day2;
		}
		else {
			for (int i = 0; i < month2 - 1; i++) {
				birthcount += months1[i];
			}
			birthcount += day2;
		}

		diffiernce = birthcount - number;
		cout << "Дней осталось до ближайшего дня вашего рождения: " << diffiernce << endl;
	}
}

int calculate_birthday(int year, int number, int day, int month) {
	if (year % 4 == 0) {
		for (int i = 0; i < month - 1; i++) {
			number += months2[i];
		}
		number += day;
	}
	else {
		for (int i = 0; i < month - 1; i++) {
			number += months1[i];
		}
		number += day;
	}
	std::cout << "Порядковый номер введенного дня в году: " << number << std::endl;
	return number;

}

void enums(int month) {

	const char* months_num[12] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };

	for (int i = 1; i < 12; i++)
		if (month == i) {
			cout << "(" << months_num[i-1] << ")" << endl;
			break;
		}
}

void checking_for_holidays(int number) {
	if (number == programmers_day) cout << "В этот день отмечается день программистов" << endl;
	if (number == first_summer_day) cout << "В этот день отмечается первый день лета" << endl;
	if (number == mums_day) cout << "В этот день отмечается 8 марта" << endl;
}




