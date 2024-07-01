//������ �������� ���������. ���������� ������, ���� ������� � �������, �����,
//  ��� ���������� (����, �����������, �����������, �����������, �����������). 
// ����� ����� �� ���� �������. ���� ������� � ������� ����������� � �������
//  �������� ����, ��� ���������� ? � ������� ������������

#include<iostream>
#include<Windows.h>
#include<stdio.h>
#include <string>
#include<fstream> 
#define size 8

using namespace std;

enum Type_of_allocation
{
    Luxury = 1, Single, Double, triple_room, apartment
}allocation;

struct Clients {
    string data; // ������� name �� data
    string allocation;
    int number;
    unsigned day_Arrival : 5;// ��� ��� 5 �����
    unsigned month_Arrival : 4;// ��� ������ 4 ����
    unsigned year_Arrival : 11;// ��� ���� 11 �����
    unsigned day_departure : 5;
    unsigned month_departure : 4;
    unsigned year_departure : 11;
};
Clients list_of_clients[size];
Clients bad; // ��� ��������
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
    cout << "3 - ����� ����� �� ���� �������." << endl;
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

        cout << "������� ���������� ������: ";
        cin.ignore(); // ������ ������
        getline(cin, list_of_clients[now_size].data);


        cout << "������� �����: ";
        cin >> list_of_clients[now_size].number;
        do {
            cout << "������� ��� ���������� (1 - ����, 2 - �����������, 3 - �����������, 4 - �����������, 5 - �����������)";
            cin >> num;
            if (num == (int)Luxury) list_of_clients[now_size].allocation = "Luxury"; // �������� ������������������ � ����������
            else if (num == (int)Single) list_of_clients[now_size].allocation = "Single";
            else if (num == (int)Double) list_of_clients[now_size].allocation = "Double";
            else if (num == (int)triple_room) list_of_clients[now_size].allocation = "Triple room";
            else if (num == (int)apartment) list_of_clients[now_size].allocation = "Apartment";
        } while (num != 1 && num != 2 && num != 3 && num != 4 && num != 5);

        cout << "������� ���� ������: ";
        cin >> dat�;
        list_of_clients[now_size].day_Arrival = (dat� / 1000000); // ������ ��� �������� ����
        list_of_clients[now_size].month_Arrival = ((dat� / 10000) % 100);
        list_of_clients[now_size].year_Arrival = (dat� % 10000);

        cout << "������� ���� �������: ";
        cin >> dat�;
        list_of_clients[now_size].day_departure = (dat� / 1000000);// ������ ��� �������� ����
        list_of_clients[now_size].month_departure = ((dat� / 10000) % 100);
        list_of_clients[now_size].year_departure = (dat� % 10000);

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

        cout << "���������� ������: " << list_of_clients[i].data << endl;
        cout << "��� ����������: " << list_of_clients[i].allocation << endl;
        cout << "�����: " << list_of_clients[i].number << endl;
        cout << "���� ������: " << list_of_clients[i].day_Arrival << "." << list_of_clients[i].month_Arrival << "." << list_of_clients[i].year_Arrival << endl;
        cout << "���� ������: " << list_of_clients[i].day_departure << "." << list_of_clients[i].month_departure << "." << list_of_clients[i].year_departure << endl;
    }
    cout << "��� ������?" << endl;
    cin >> choice;
}

void found() { // �����
    int buffer, buffer_day, buffer_month, buffer_year;
    cout << "������� ���� �������: ";
    cin >> buffer;
    buffer_day = buffer / 1000000;// ������� �� ��� � ��
    buffer_month = ((buffer / 10000) % 100);
    buffer_year = (buffer % 10000);
    for (int i = 0; i < now_size; i++) {
        if (buffer_day == list_of_clients[i].day_Arrival && buffer_month == list_of_clients[i].month_Arrival && buffer_year == list_of_clients[i].year_Arrival) {
            cout << "���������� ������: " << list_of_clients[i].data << endl;
            cout << "��� ����������: " << list_of_clients[i].allocation << endl;
            cout << "�����: " << list_of_clients[i].number << endl;
            cout << "���� ������: " << list_of_clients[i].day_Arrival << "." << list_of_clients[i].month_Arrival << "." << list_of_clients[i].year_Arrival << endl;
            cout << "���� ������: " << list_of_clients[i].day_departure << "." << list_of_clients[i].month_departure << "." << list_of_clients[i].year_departure << endl;
        }
    }

    cout << "��� ������?" << endl;
    cin >> choice;
}

void delet(){ // �������� ������ ���������
    int answer;
    int select;
    int number;
    do{
    cout << "1 - ������� ��������� ������" << endl;
    cout << "2 - ������� ���" << endl;
    cin >> select;
    if (select == 1) {
        cout << "����� ������ ������ �������?" << endl;
        cin >> number;
        list_of_clients[number] = bad;
    }

    if (select == 2) {
        for (int i = 0; i < now_size; i++) {
            list_of_clients[i] = bad;
        }
    }
    cout << "���������� ����? (1 - ��, 0 - ���): ";
    cin >> answer;

    } while (answer == 1);

    cout << "��� ������?" << endl;
    cin >> choice;
}
//unsigned day_Arrival : 5; �.�. 31 = 5 �����
