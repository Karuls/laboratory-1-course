#include<iostream>
#include<Windows.h>
#include<stdio.h>
#include <string>
#include<fstream> 
using namespace std;

#define size 55
void enter();// ������� �����
void out(); // ������� ������
void delet();// ������� ��������
void found();// ������� ������
void write_file();// ������� ������ � ����
void read_file();// ������� ������ ����
void choice_specialties();//

struct applicant { //���������
    string university;
    string location;
    string specialties;
    string contest;
    string cost;
};
struct applicant applicants_guide[size];
struct applicant bad;
int current_size = 0; //��� �������� ���������� ����������
int choice;

int main() {
    SetConsoleCP(1251);
    setlocale(LC_CTYPE, "Russian");

    cout << "�������:" << endl;
    cout << "1 - ��� ����� ����� ������" << endl;
    cout << "2 - ��� ������ ������(��)" << endl;
    cout << "3 - ��� �������� ������" << endl;
    cout << "4 - ����� �������" << endl;
    cout << "5 - ������ ���������� � ����" << endl;
    cout << "6 - ������ ������ �� �����" << endl;
    cout << "7 - ����� �� �������������" << endl;
    cout << "8 - ��� ������" << endl;
    cin >> choice;
    do
    {
        switch (choice) {
        case 1:  enter();    break;
        case 2:  out();      break;
        case 3:  delet();    break;
        case 4:  found();    break;
        case 5:  write_file();   break;
        case 6:  read_file();    break;
        case 7:  choice_specialties(); break;
        }
    } while (choice != 8);
}

void enter() {
    cout << "���� ����������" << endl;

    string choice_str;
    do {
        if (current_size < size) {
            cout << "������ ����� " << current_size + 1 << endl;
            cout << "������������ ����: ";
            cin.ignore(); // ������� ������ �����
            getline(cin, applicants_guide[current_size].university);
            cout << "�����: ";
            getline(cin, applicants_guide[current_size].location);
            cout << "�������� ��������������: ";
            getline(cin, applicants_guide[current_size].specialties);
            cout << "������� �������� ���� �� ������ �������������: ";
            getline(cin, applicants_guide[current_size].contest);
            cout << "������ ������ ��� ���������� ��������: ";
            getline(cin, applicants_guide[current_size].cost);
            current_size++;
        }
        else {
            cout << "������� ������������ ���������� �����" << endl;
            break;
        }

        cout << "���������� ����? (1 - ��, 0 - ���): ";
        cin >> choice_str;
        // ���������, ������� �� "0" ��� ���������� �����
    } while (choice_str == "1");

    cout << "��� ������?" << endl;
    cin >> choice;
}


void out() {
    int answer, number;
    cout << "1 - ����� ���� �����" << endl;
    cout << "2 - ����� ����� ������" << endl;
    cin >> answer;
    if (answer == 2) {

        cout << "����� ��������� ������? " << endl;
        cin >> number;
        cout << endl << "������������ ���� " << endl;
        cout << applicants_guide[number - 1].university;
        cout << "����� " << endl;
        cout << applicants_guide[number - 1].location;
        cout << "�������� �������������� " << endl;
        cout << applicants_guide[number - 1].specialties;
        cout << "������� �������� ���� �� ������ ������������� " << endl;
        cout << applicants_guide[number - 1].contest;
        cout << "������ ������ ��� ���������� �������� " << endl;
        cout << applicants_guide[number - 1].cost;

    }

    if (answer == 1) {
        for (int i = 0; i < current_size; i++) {
            cout << endl << "������������ ����: ";
            cout << applicants_guide[i].university << endl;
            cout << "�����: ";
            cout << applicants_guide[i].location << endl;
            cout << "�������� ��������������: ";
            cout << applicants_guide[i].specialties << endl;
            cout << "������� �������� ���� �� ������ �������������: ";
            cout << applicants_guide[i].contest << endl;
            cout << "������ ������ ��� ���������� ��������: ";
            cout << applicants_guide[i].cost << endl;
        }

        cout << "��� ������?" << endl;
        cin >> choice;
    }
}

void delet() {
    int number, digit;
    cout << "1 - ���� ������� ��� ������" << endl;
    cout << "2 - ���� ������� ���� ������" << endl;
    cin >> number;

    if (number == 2) {
        cout << "����� ������ ������ �������? " << endl;
        cin >> digit;
        applicants_guide[digit] = bad; //������������ ������ ���������
        cout << "������ ������� " << endl;
    }

    if (number == 1) {
        for (int i = 0; i < current_size; i++) {
            applicants_guide[i] = bad; //������������ ������ ���������
        }
        cout << "������ ������� " << endl;
    }

    cout << "��� ������?" << endl;
    cin >> choice;
}

void found() {
    int count;
    cout << "��� �� �� ������ �����? " << endl;
    cout << "1 - ������������ �����" << endl;
    cout << "2 - ������" << endl;
    cout << "3 - ������� ��������������" << endl;
    cout << "4 - ������� �������� ���� �� ������ �������������" << endl;
    cout << "5 - ������ ����� ��� ���������� ��������" << endl;
    cin >> count;

    if (count < 1 || count > 5) {
        cout << "������������ �����. " << endl;
    }

    else {
        if (count == 1) {
            cout << endl << "������������ ���� " << endl;
            for (int i = 0; i < current_size; i++) {
                cout << applicants_guide[i].university << endl;
            }
        }

        if (count == 2) {
            cout << "������ " << endl;
            for (int i = 0; i < current_size; i++) {
                cout <<  applicants_guide[i].location << endl;
                
            }
        }

        if (count == 3) {
            cout << "�������� �������������� " << endl;
            for (int i = 0; i < current_size; i++) {
                cout << applicants_guide[i].specialties << endl;

            }
        }

        if (count == 4) {
            cout << "������� �������� ���� �� ������ ������������� " << endl;
            for (int i = 0; i < current_size; i++) {
                cout << applicants_guide[i].contest << endl;

            }
        }

        if (count == 5) {
            cout << "������� ������ ��� ���������� ��������: " << endl;
            for (int i = 0; i < current_size; i++) {
                cout << applicants_guide[i].cost << endl;

            }
        }

    }
    
    cout << "��� ������?" << endl;
    cin >> choice;
}

void write_file() {
    ofstream file_write("applicant.txt"); 
    int num;
    cout << "������ ���������� � ���� ..." << endl;
    cout << "��� ������ ��������?" << endl;
    cout << "1 - ���" << endl;
    cout << "2 - ���� ������" << endl;
    cin >> num;

    if (num != 1 && num != 2) { 
        cout << "������������ ����" << endl;
        return; // ������� �� �������, ��� ��� ������ ������������ �����
    }

    if (num == 1) {
        for (int i = 0; i < current_size; i++) {
            file_write << "������������ ����: " << applicants_guide[i].university << endl;
            file_write << "�����: " << applicants_guide[i].location << endl;
            file_write << "�������� ��������������: " << applicants_guide[i].specialties << endl;
            file_write << "������� �������� ���� �� ������ �������������: " << applicants_guide[i].contest << endl;
            file_write << "������ ������ ��� ���������� ��������: " << applicants_guide[i].cost << endl;
            file_write << endl; 
            cout << "������ ��������." << endl;
        }
    }

    if (num == 2) {
        int g;
        cout << "����� ������ ������ ��������? " << endl;
        cin >> g;

        if (g >= 1 && g <= current_size) {
            file_write << "������������ ����: " << applicants_guide[g - 1].university << endl;
            file_write << "�����: " << applicants_guide[g - 1].location << endl;
            file_write << "�������� ��������������: " << applicants_guide[g - 1].specialties << endl;
            file_write << "������� �������� ���� �� ������ �������������: " << applicants_guide[g - 1].contest << endl;
            file_write << "������ ������ ��� ���������� ��������: " << applicants_guide[g - 1].cost << endl;
            file_write << endl; 
            cout << "������ ��������." << endl;
        }
        else {
            cout << "������������ ����� ������" << endl;
        }
    }
    file_write.close();

    cout << "��� ������?" << endl;
    cin >> choice;

}
void read_file() {
    ifstream file_read("applicant.txt");
    int num;
    string buffer;

    cout << "1 - �������� ���� ���� " << endl;
    cout << "2 - �������� ���� ���������� ����������� " << endl;
    cin >> num; cout << endl;

    if (num != 1 && num != 2) {
        cout << "������������ ����" << endl;
        return; // ������� �� �������, ��� ��� ������ ������������ �����
    }

    if (num == 1) {
        int count = 1;
        while (getline(file_read, buffer)) {
            cout << buffer << endl; // ������� ���������� ������ ������ �����
            count++;
            if (count == 6) {
                cout << endl << endl;
            }
        }
    }

    if (num == 2) {
        int coin, count = 0;
        bool flag = true; 
        int near_coin; int helper = 6;
        cout << "����� ������ ����������� �� �� ������ ��������?" << endl;
        cin >> coin;
        
       near_coin = abs(1 - coin)*6;

        while (getline(file_read, buffer)) {
            near_coin--;
            if (coin == 1) {
                flag = false;
                helper--;
                cout << buffer << endl;
                if (helper == 6) {
                    break;
                }
            }

            if (near_coin <= 0 && helper != 0 && flag == true) {
                cout << buffer << endl; // ������� ���������� ������ ������ �����
                helper--;
            } 
        }
    }

    cout << "��� ������?" << endl;
    cin >> choice;

}

void choice_specialties() {
    string spec;
    cout << "������� �������������" << endl;
    cin.ignore(); // ������� ������ �����
    getline(cin, spec);
    for (int i = 0; i < current_size; i++) {
        if (applicants_guide[i].specialties == spec) { //�������� �� �������������
            cout << "������������ ����: " << applicants_guide[i].university << endl;
            cout << "�����: " << applicants_guide[i].location << endl;
            cout << "�������� ��������������: " << applicants_guide[i].specialties << endl;
            cout << "������� �������� ���� �� ������ �������������: " << applicants_guide[i].contest << endl;
            cout << "������ ������ ��� ���������� ��������: " << applicants_guide[i].cost << endl;
            cout << endl;
        }
    }

    cout << "��� ������?" << endl;
    cin >> choice;
}
