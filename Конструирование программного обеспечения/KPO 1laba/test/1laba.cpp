#include <iostream>
#include <stdio.h>
void calculate_day_number(int);
int calculate_birthday(int, int, int, int);
int months1[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int months2[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int main() {
	using namespace std;
	setlocale(LC_ALL, "rus");
	int data, year, day = 0, month, number{};
	int year2{}, day2{}, month2{}, birthday, diffiernce = 0;
	int birthcount = 0;  //���������� ����� ��� ��������

	cout << "������� ���� ������� ��������" << endl;
	cin >> data;

	year = data % 10000;
	day = data / 1000000;
	month = data / 10000 % 100;

	/*cout << "����: " << day << endl;
	cout << "�����: " << month << endl;
	cout << "���: " << year << endl;*/

	if (year <= 0 || month > 12 || month < 1 || day>31 || day < 1) {
		cout << "�������� ��� �������� � ������� ��������" << endl;
	}
	else {

		calculate_day_number(year);
		calculate_birthday(year, number, day, month);
		number = calculate_birthday(year, number, day, month);

		cout << "������� ���� ���� ��������" << endl;
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
		cout << "���� �������� �� ���������� ��� ������ ��������: " << diffiernce << endl;
	}
}

//void calculate_day_number(int year) {
//	using namespace std;
//	if (year % 4 == 0)
//	{
//		cout << "��������� ��� ���� �������� ����������" << endl;
//	}
//	else {
//		cout << "��������� ��� ���� �� �������� ����������" << endl;
//	}
//}

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
	std::cout << "���������� ����� ���������� ��� � ����: " << number << std::endl;
	return number;

}






