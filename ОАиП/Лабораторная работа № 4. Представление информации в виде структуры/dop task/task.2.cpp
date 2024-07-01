//1. ���������� ��������� ��� ������������� ���������� � ������� ��������� ���������,
//  ���������� ����: ��� ��������, ����� ���������, ���������� ������. 
// ���������� ������� ��� ��������� ���������� ������� (��������, ��� ��������,
//  ����� �� ��� �������� �� 4 � 5). �������� ������� ��� ��������� ������� ��������.
//  � ���������� ��������� ��������� ��������� �������������� ������������ ���������,
//  �� ���� ��������� ����� ���������, ������� �������� �� 4 � 5, � ������ ����� ���������, � ���������.
#include<iostream>
#include<Windows.h>
#include<stdio.h>
#include <string>
#include<fstream> 
using namespace std;

#define size 15 //������ ������� ���������
#define Max_rating 10

struct students { 
	string FIO;
	int count_of_exams;
    int rating[Max_rating];
};
struct students students_mass[size];
int enter_size = 0;  //��� �������� ���������� ���������� �������
int choice;

void enter(); //������� �����
void test_rating();// ������� �������� ������
void perfomance_calculation();// ������� �������������� ������������ ���������

int main() {
	SetConsoleCP(1251);
	setlocale(LC_ALL, "rus");

	cout << "�������: " << endl;
	cout << "1 - ���� ������" << endl;
	cout << "2 - �������� �� ������" << endl;
	cout << "3 - ��������� �������������� ������������ ���������" << endl;
	cout << "5 - �����" << endl;
	cin >> choice;

	do
	{
		switch (choice) {
		case 1: enter(); break;
		case 2: test_rating(); break;
		case 3: perfomance_calculation(); break;
		}
	} 
	while (choice != 5);
}

void enter() {
	int answer;
	cout << "���� ����������" << endl;
	do {

	
	if (enter_size < size) {
		cout << enter_size+1 <<" ������� " << endl;
		cout << "������� ��� ��������: " << endl;
		
		cin.ignore();
		getline(cin, students_mass[enter_size].FIO);
		cout << "������� ���-�� ���������: ";
		cin >> students_mass[enter_size].count_of_exams;
		cout << "������� ������: ";
		for (int i = 0; i < students_mass[enter_size].count_of_exams; ++i) {
			cin >> students_mass[enter_size].rating[i];
		}
		enter_size++;
	}
	else {
		cout << "�������� ����� ���������" << endl;
		break;
	}
	
	cout << "���������� ����? (1 - ��, 0 - ���): ";
	cin >> answer;

	} while (answer == 1);

	cout << "��� ������?" << endl;
	cin >> choice;
}

void test_rating() {
	int number; int answer;
	bool flag_exams;
	do{
		flag_exams = true;
	cout << "������� ������ �������� �� �� ������ �������?" << endl;
	cin >> number;
     
	for (int i = 0; i < students_mass[number - 1].count_of_exams; i++) {

		if (students_mass[number-1].rating[i] < 4) {
			flag_exams = false;
		}

	}
	if (flag_exams == true) {
		cout << "���� ������� ���� ��� �� �������" << endl;
	}
	else if (flag_exams == false) {
		cout << "� ����� �������� ���� ������ ���� 4 � 5" << endl;
	}
	cout << "���������� ����? (1 - ��, 0 - ���): ";
	cin >> answer;
	
	} while (answer == 1);

	cout << "��� ������?" << endl;
	cin >> choice;
}

void perfomance_calculation() { //
	bool flag;
	int clever_students = 0;
	int students; double percent;
	students = enter_size; // ���������� �������� ���������
	for (int i = 0; i < enter_size; i++) {
		
		flag = true;
		for (int g = 0; g < students_mass[i].count_of_exams; g++) { // ����� ��������
			if (students_mass[i].rating[g] < 4) { // ����� ������
				flag = false;	
			}
		}

		if (flag == true) { 
			clever_students++;
		}

	}
	 percent = (static_cast<double>(clever_students) / students) * 100;
	cout << "�������������� ������������ ���������: " << percent << "%" << endl;

	cout << "��� ������?" << endl;
	cin >> choice;

}