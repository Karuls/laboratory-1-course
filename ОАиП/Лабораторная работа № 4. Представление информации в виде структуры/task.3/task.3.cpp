//������� ��������� � ������ TRAIN, ���������� ���� :
//  �������� ������ ����������, ����� ������, ����� 
// �����������.�������� ���������, ����������� ����
//  � ���������� ������ � ������, ��������� �� ������
//  ��������� ���� TRAIN(������ ������ ���� ���������
//  � ���������� ������� �� ��������� ������� ����������); 
// ����� �� ����� ���������� � �������, �������������� 
// ����� ���������� � ���������� �������(���� ����� ������� ���,	
//  �� ������� ��������� �� ����).
#include<iostream>
#include<Windows.h>
#include<stdio.h>

using namespace std;
#define size 8
struct TRAIN {
	char name[20];
	int number;
	int time;
};
TRAIN train_mass[size];
int choice;
int now_size = 0;

void enter();
void out();
void sort();
void all_out();

int main() {
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);


	cout << "�������: " << endl;
	cout << "1 - ���� ������" << endl;
	cout << "2 - ����� �� ����� ���������� � �������, �������������� ����� ���������� � ���������� ������" << endl;
	cout << "3 - ���������� ������� �� ��������" << endl;
	cout << "4 - ����� ���� ����������" << endl;
	cout << "5 - �����" << endl;
	
	cin >> choice;

	do {
		switch (choice) {
		case 1: enter(); break;
		case 2: out(); break;
		case 3: sort(); break;
		case 4: all_out(); break;
		}
	} while (choice != 5);

}

void enter() {
	int answer;
	do{
	if (now_size >= size) { // �������� �� �����
		cout << "������: ������ ������� ��������." << endl;
		return;
	}

	cout << "������� �������� ������ ����������: ";
	cin.ignore(); // ������ ������
	cin.getline(train_mass[now_size].name, 20);

	cout << "������� ����� ������: ";
	cin >> train_mass[now_size].number;

	cout << "������� ����� �����������: ";
	cin >> train_mass[now_size].time;

	now_size++;


	cout << "���������� ����? (1 - ��, 0 - ���): ";
	cin >> answer;

	} while (answer == 1);


	cout << "��� ������?" << endl;
	cin >> choice;

}

void out() { //������� 
	int enter_time;
	int hours;
	int min;
	bool flag = false;
	cout << "������� �����: " << endl;
	cin >> enter_time;

	hours = enter_time / 100;
	min = enter_time % 100;

	for (int i = 0; i < now_size; i++) {

		if ( (hours*60 +min) <  ((train_mass[i].time/100)*60) + (train_mass[i].time%100)) {
			
			cout << "��� �������: ";
			cout << train_mass[i].name << endl;

			cout << "����� ������: ";
			cout << train_mass[i].number << endl;

			cout << "����� �����������: ";
			cout << train_mass[i].time << endl;
			cout << endl;
			flag = true;

			
	 }

		if (flag == false) {
			cout << "����� ������� ����" << endl;
		}

	}
	cout << "��� ������?" << endl;
	cin >> choice;
}

void sort() {// ����������
	cout << "���������� �� ��������..." << endl;
	for (int i = 0; i < now_size - 1; i++) {
		for (int j = 0; j < now_size - i - 1; j++) {
			if (strcmp(train_mass[j].name, train_mass[j + 1].name) > 0) {
				swap(train_mass[j], train_mass[j + 1]);
			}
		}
	}
	cout << "��� ������?" << endl;
	cin >> choice;
}

void all_out() {// ����� ����� �����������
	for (int i = 0; i < now_size; i++) {
		cout << "��� �������: ";
		cout << train_mass[i].name << endl;

		cout << "����� ������: ";
		cout << train_mass[i].number << endl;

		cout << "����� �����������: ";
		cout << train_mass[i].time << endl;
		cout << endl;
	}

	cout << "��� ������?" << endl;
	cin >> choice;
}