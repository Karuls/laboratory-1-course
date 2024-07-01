//�������� ������. �.�.�, ���� ��������, �����, �������, ����� ������ ��� �����, ���������. ����� �� �������.
#include<iostream>
#include<Windows.h>
#include<stdio.h>
#include<string>
#include<fstream> 
#define size 8

using namespace std;

union person {
    char full_name[50];
    char birth_time[50];
    char location[50];
    char number[50];
    char work_place[50];
};

struct Clients {
    person name;
    person birth;
    person place;
    person phone;
    person spot;
};
Clients list_of_clients[size];
int num;
int choice;
int now_size = 0;

void enter();
void out();
void found();
void file_write();
void file_read();

int main() {
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);


    cout << "�������: " << endl;
    cout << "1 - ���� ������" << endl;
    cout << "2 - ����� �� ����� ����������" << endl;
    cout << "3 - ����� �� �������." << endl;
    cout << "4 - ������ � ����" << endl;
    cout << "5 - ������ �� �����" << endl;
    cout << "6 - �����" << endl;

    cin >> choice;

    do {
        switch (choice) {
        case 1: enter(); break;
        case 2: out(); break;
        case 3: found(); break;
        case 4: file_write(); break;
        case 5: file_read(); break;
        }
    } while (choice != 6);

}

void enter() { // ����
    int answer;
    int dat�;
    do {
        if (now_size >= size) { // �������� �� �����
            cout << "������: ������ ������� ��������." << endl;
            return;
        }
        cin.ignore(); // ������ ������
        cout << "������� ���: ";
        gets_s(list_of_clients[now_size].name.full_name, 50);

        cout << "������� ���� ��������: ";
        gets_s(list_of_clients[now_size].birth.birth_time, 50);

        cout << "������� ����� ";
        gets_s(list_of_clients[now_size].place.location, 50);

        cout << "������� �����: ";
        gets_s(list_of_clients[now_size].phone.number, 50);

        cout << "������� ����� ������ ��� �����: ";
        gets_s(list_of_clients[now_size].spot.work_place, 50);

        now_size++;
        cout << "���������� ����? (1 - ��, 0 - ���): ";
        cin >> answer;
    } while (answer == 1);


    cout << "��� ������?" << endl;
    cin >> choice;
}

void out() {
    cout << "����� ����������..." << endl;

    for (int i = 0; i < now_size; i++) {

        cout << "���: " << list_of_clients[i].name.full_name << endl;
        cout << "���� ��������: " << list_of_clients[i].birth.birth_time << endl;
        cout << "��� ����������: " << list_of_clients[i].place.location << endl;
        cout << "�����: " << list_of_clients[i].phone.number << endl;
        cout << "����� ������ ��� �����: " << list_of_clients[i].spot.work_place << endl;
   
    }
    cout << "��� ������?" << endl;
    cin >> choice;
}

void found() {
    char buffer[50];
    cout << "������� ������ �������: ";
    cin.ignore(); // ������� 
    gets_s(buffer, 50);
    for (int i = 0; i < now_size; i++) {
        if (strcmp(buffer, list_of_clients[i].name.full_name) == 0) { // ��������� �����
            cout << "���: " << list_of_clients[i].name.full_name << endl;
            cout << "���� ��������: " << list_of_clients[i].birth.birth_time << endl;
            cout << "��� ����������: " << list_of_clients[i].place.location << endl;
            cout << "�����: " << list_of_clients[i].phone.number << endl;
            cout << "����� ������ ��� �����: " << list_of_clients[i].spot.work_place << endl;
        }
    }
    cout << "��� ������?" << endl;
    cin >> choice;
}

void file_write() { // ������ � ����
    ofstream write("task2.txt");
    for (int i = 0; i < now_size; i++) {

        write << "���: " << list_of_clients[i].name.full_name << endl;
        write << "���� ��������: " << list_of_clients[i].birth.birth_time << endl;
        write << "��� ����������: " << list_of_clients[i].place.location << endl;
        write << "�����: " << list_of_clients[i].phone.number << endl;
        write << "����� ������ ��� �����: " << list_of_clients[i].spot.work_place << endl;

    }
    write.close();
    cout << "������ ��������� " << endl;
    cout << "��� ������?" << endl;
    cin >> choice;
}

void file_read() {
    char buf[250];
    ifstream file_read("task2.txt");// ��� ������ �����
    cout << "���������� �����: " << endl;
    while (file_read.getline(buf, 250)) { // ������ ������ ������
        cout << buf << endl;
    }
    cout << "��� ������?" << endl;
    cin >> choice;
}