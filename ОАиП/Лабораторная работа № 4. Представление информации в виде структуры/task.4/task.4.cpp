//���������� ��������� ��� ������������� ���������� � �������
//  ���������� �������, ���������� ��������� ���� :
//  �������� ���������, ����� ������������, �������� �������, ���������� �������.
// ����������� ��������� ������ � ���� �������, ������������ 
// �� �� �������� �������� ����������.� �������� ������ ������ 
// ������ ������������� �� ��������� ����������.������������ ����� ���������� � ����� �����������.

#include<iostream>
#include<Windows.h>
#include<stdio.h>
#include <string>
#include<fstream> 

using namespace std;
#define size 8
struct healing {
	string name;
	string place;
	char healing[50];
	int travel_packages;
};
healing health_center[size];
int choice;
int now_size = 0;

void enter();
void all_out();
void found();

int main() {
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);


	cout << "�������: " << endl;
	cout << "1 - ���� ������" << endl;
	cout << "2 - ����� ���� ����������" << endl;
	cout << "3 - ����� ����������" << endl;

	cout << "5 - �����" << endl;

	cin >> choice;

	do {
		switch (choice) {
		case 1: enter(); break; // ������� �����
		case 2: all_out(); break;// ������� ������ � �����������
		case 3: found(); break; // ������� ������
		}
	} while (choice != 5);

}

void enter() {
	int answer;
	do {
		if (now_size >= size) { // �������� �� �����
			cout << "������: ������ ������� ��������." << endl;
			return;
		}

		cout << "�������� ��������� : ";
		cin.ignore(); // ������ ������
		getline(cin, health_center[now_size].name);

		cout << "��������������� : ";
		getline(cin, health_center[now_size].place);

		cout << "�������� �������: ";
		cin.getline(health_center[now_size].healing,50);

		cout << "���������� �������: ";
		cin >> health_center[now_size].travel_packages;

		now_size++;


		cout << "���������� ����? (1 - ��, 0 - ���): ";
		cin >> answer;

	} while (answer == 1);
	cout << "��� ������?" << endl;
	cin >> choice;

}

void all_out() {
	
	//���������� �� ��������...
	for (int i = 0; i < now_size - 1; i++) {
		for (int j = 0; j < now_size - i - 1; j++) {
			if (strcmp(health_center[j].healing, health_center[j + 1].healing) > 0) {
				swap(health_center[j], health_center[j + 1]);
			}
		}
	}


	for (int i = 0; i < now_size; i++) { // �����

		cout << "�������� ��������� : ";
		cout << health_center[i].name << endl;
		
		cout << "��������������� : ";
		cout << health_center[i].place << endl;

		cout << "�������� �������: ";
		cout << health_center[i].healing << endl;

		cout << "���������� �������: ";
		cout << health_center[i].travel_packages << endl;
		cout << endl;
	}

	cout << "��� ������?" << endl;
	cin >> choice;
}

void found() {
	int ans, answer_found;
	string buffer; bool flag = false;

	do{
	cout << "����� ��:" << endl;
	cout << "1 - �������� ��������� : ";
	cout << "2 - ��������������� : ";
	cout << "3 - �������� �������: ";
	cout << "4 - ���������� �������: ";
	cin >> ans;
	
	switch (ans) {
	case 1: 
		cout << "������� �������� ��������� : ";
		cin >> buffer;
		for (int i = 0; i < now_size; i++) {
			if (buffer == health_center[i].name) {
				cout << "�������� ��������� : "<< health_center[i].name << endl;
				cout << "��������������� : "<<  health_center[i].place << endl;
				cout << "�������� �������: "<< health_center[i].healing << endl;
				cout << "���������� �������: " << health_center[i].travel_packages << endl;
				cout << endl;
			}
		}; break;

		case 2:
			cout << "������� ���������������: ";
			cin >> buffer;
			for (int i = 0; i < now_size; i++) {
				if (buffer == health_center[i].place) {
					cout << "�������� ��������� : " << health_center[i].name << endl;
					cout << "��������������� : " << health_center[i].place << endl;
					cout << "�������� �������: " << health_center[i].healing << endl;
					cout << "���������� �������: " << health_center[i].travel_packages << endl;
					cout << endl;
				}
			}; break;
		case 3: 
			char buf[50];
			cout << "������� �������� ������� : ";
			cin.ignore(); // ������ ������
			cin.getline(buf,50);

			for (int i = 0; i < now_size; i++) {
				if (strcmp (buf, health_center[i].healing) ==0) {
					cout << "�������� ��������� : " << health_center[i].name << endl;
					cout << "��������������� : " << health_center[i].place << endl;
					cout << "�������� �������: " << health_center[i].healing << endl;
					cout << "���������� �������: " << health_center[i].travel_packages << endl;
					cout << endl;
				}
			}; break;

		case 4: 
			int reg;
			cout << "������� ���������� �������: ";
			cin >> reg;
			for (int i = 0; i < now_size; i++) {
				if (reg == health_center[i].travel_packages ) {
					cout << "�������� ��������� : " << health_center[i].name << endl;
					cout << "��������������� : " << health_center[i].place << endl;
					cout << "�������� �������: " << health_center[i].healing << endl;
					cout << "���������� �������: " << health_center[i].travel_packages << endl;
					cout << endl;
				}
			}; break;
	}

	cout << "������ ���������� �����?(1 - ��, 2 - ���)" << endl;
	cin >> answer_found;
	} while (answer_found == 1);
	cout << "��� ������?" << endl;
	cin >> choice;

}
