//�������� ������. �.�.�, ���� ��������, �����, ������� .
//  ����� �� �������. ���� �������� ����������� � ������� �������� ����.
#include<iostream>
#include<Windows.h>
#include<stdio.h>
#include <string>
#include<fstream> 
#define size 8

using namespace std;

struct peoples_book {
    string full_name; 
    unsigned day_birthday : 5;// ��� ��� 5 �����
    unsigned month_birthday : 4;// ��� ������ 4 ����
    unsigned year_birthday : 11;// ��� ���� 11 �����
    string living_place;
    char personal_number[15];

};
peoples_book list_of_peoples[size];
peoples_book bad; // ��� ��������
int num;
int choice;
int now_size = 0;

void enter();
void out();
void found();
void delet();

int main() {
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);


    cout << "�������: " << endl;
    cout << "1 - ���� ������" << endl;
    cout << "2 - ����� �� ����� ����������" << endl;
    cout << "3 - ����� ����� �� �������" << endl;
    cout << "4 - �������� �������" << endl;

    cout << "5 - �����" << endl;

    cin >> choice;

    do {
        switch (choice) {
        case 1: enter(); break;
        case 2: out(); break;
        case 3: found(); break;
        case 4: delet(); break;
        }
    } while (choice != 5);

}

void enter() {
    int answer;
    int dat�;
    do {
        if (now_size >= size) { // �������� �� �����
            cout << "������: ������ ������� ��������." << endl;
            return;
        }

        cout << "������� ���: ";
        cin.ignore(); // ������ ������
        getline(cin, list_of_peoples[now_size].full_name);

        cout << "������� ���� ��������: ";
        cin >> dat�;
        list_of_peoples[now_size].day_birthday = (dat� / 1000000); // ������ ��� �������� ����
        list_of_peoples[now_size].month_birthday = ((dat� / 10000) % 100);
        list_of_peoples[now_size].year_birthday = (dat� % 10000);

        cout << "������� �����: ";
        cin.ignore(); // ������ ������
        getline(cin, list_of_peoples[now_size].living_place);
       
        cout << "������� �������: ";
        gets_s(list_of_peoples[now_size].personal_number, 15);
      
        now_size++;
            
        cout << "���������� ����? (1 - ��, 0 - ���): ";
        cin >> answer;
    } while (answer == 1);


    cout << "��� ������?" << endl;
    cin >> choice;
}

void out() { // �����
    cout << "����� ����������..." << endl;

    for (int i = 0; i < now_size; i++) {

        cout << "���: " << list_of_peoples[i].full_name << endl;
        cout << "���� ��������: " << list_of_peoples[i].day_birthday << "." << list_of_peoples[i].month_birthday << "." << list_of_peoples[i].year_birthday << endl;
        cout << "�����: " << list_of_peoples[i].living_place << endl;
        cout << "�����: " << list_of_peoples[i].personal_number << endl;
    }
    cout << "��� ������?" << endl;
    cin >> choice;
}

void found() { // �����
    string buffer;

    cout << "������� �������: ";
    cin.ignore();
    getline(cin, buffer);
    
    for (int i = 0; i < now_size; i++) {
        if ( buffer == list_of_peoples[i].full_name) {
            cout << "���: " << list_of_peoples[i].full_name << endl;
            cout << "���� ��������: " << list_of_peoples[i].day_birthday << "." << list_of_peoples[i].month_birthday << "." << list_of_peoples[i].year_birthday << endl;
            cout << "�����: " << list_of_peoples[i].living_place << endl;
            cout << "�����: " << list_of_peoples[i].personal_number << endl;
        }
    }

    cout << "��� ������?" << endl;
    cin >> choice;
}

void delet() { // �������� ������ ���������
    int answer;
    int select;
    int number;
    do {
        cout << "1 - ������� ��������� ������" << endl;
        cout << "2 - ������� ���" << endl;
        cin >> select;
        if (select == 1) {
            cout << "����� ������ ������ �������?" << endl;
            cin >> number;
            list_of_peoples[number] = bad;
        }

        if (select == 2) {
            for (int i = 0; i < now_size; i++) {
                list_of_peoples[i] = bad;
            }
        }
        cout << "���������� ����? (1 - ��, 0 - ���): ";
        cin >> answer;

    } while (answer == 1);

    cout << "��� ������?" << endl;
    cin >> choice;
}
//unsigned day_birthday : 5; �.�. 31 = 5 �����
