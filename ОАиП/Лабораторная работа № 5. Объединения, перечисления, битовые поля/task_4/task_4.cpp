//Записная книжка. Ф.И.О, дата рождения, адрес, телефон, место работы или учебы, должность. Поиск по фамилии.
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


    cout << "Введите: " << endl;
    cout << "1 - Ввод данных" << endl;
    cout << "2 - Вывод на экран информации" << endl;
    cout << "3 - Поиск по Фамилии." << endl;
    cout << "4 - Запись в файл" << endl;
    cout << "5 - Чтение из файла" << endl;
    cout << "6 - Выход" << endl;

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

void enter() { // Ввод
    int answer;
    int datа;
    do {
        if (now_size >= size) { // проверка на место
            cout << "Ошибка: массив поездов заполнен." << endl;
            return;
        }
        cin.ignore(); // Чистка буфера
        cout << "Введите ФИО: ";
        gets_s(list_of_clients[now_size].name.full_name, 50);

        cout << "Введите дату рождения: ";
        gets_s(list_of_clients[now_size].birth.birth_time, 50);

        cout << "Введите адрес ";
        gets_s(list_of_clients[now_size].place.location, 50);

        cout << "Введите номер: ";
        gets_s(list_of_clients[now_size].phone.number, 50);

        cout << "Введите место работы или учебы: ";
        gets_s(list_of_clients[now_size].spot.work_place, 50);

        now_size++;
        cout << "Продолжить ввод? (1 - да, 0 - нет): ";
        cin >> answer;
    } while (answer == 1);


    cout << "Что дальше?" << endl;
    cin >> choice;
}

void out() {
    cout << "Вывод информации..." << endl;

    for (int i = 0; i < now_size; i++) {

        cout << "ФИО: " << list_of_clients[i].name.full_name << endl;
        cout << "Дата рождения: " << list_of_clients[i].birth.birth_time << endl;
        cout << "Тип размещения: " << list_of_clients[i].place.location << endl;
        cout << "Номер: " << list_of_clients[i].phone.number << endl;
        cout << "Место работы или учебы: " << list_of_clients[i].spot.work_place << endl;
   
    }
    cout << "Что дальше?" << endl;
    cin >> choice;
}

void found() {
    char buffer[50];
    cout << "Введите нужную фамилию: ";
    cin.ignore(); // Очистка 
    gets_s(buffer, 50);
    for (int i = 0; i < now_size; i++) {
        if (strcmp(buffer, list_of_clients[i].name.full_name) == 0) { // Сравнение строк
            cout << "ФИО: " << list_of_clients[i].name.full_name << endl;
            cout << "Дата рождения: " << list_of_clients[i].birth.birth_time << endl;
            cout << "Тип размещения: " << list_of_clients[i].place.location << endl;
            cout << "Номер: " << list_of_clients[i].phone.number << endl;
            cout << "Место работы или учебы: " << list_of_clients[i].spot.work_place << endl;
        }
    }
    cout << "Что дальше?" << endl;
    cin >> choice;
}

void file_write() { // Запись в файл
    ofstream write("task2.txt");
    for (int i = 0; i < now_size; i++) {

        write << "ФИО: " << list_of_clients[i].name.full_name << endl;
        write << "Дата рождения: " << list_of_clients[i].birth.birth_time << endl;
        write << "Тип размещения: " << list_of_clients[i].place.location << endl;
        write << "Номер: " << list_of_clients[i].phone.number << endl;
        write << "Место работы или учебы: " << list_of_clients[i].spot.work_place << endl;

    }
    write.close();
    cout << "Данные записанны " << endl;
    cout << "Что дальше?" << endl;
    cin >> choice;
}

void file_read() {
    char buf[250];
    ifstream file_read("task2.txt");// Для чтения файла
    cout << "Содержимое файла: " << endl;
    while (file_read.getline(buf, 250)) { // читаем каждую строку
        cout << buf << endl;
    }
    cout << "Что дальше?" << endl;
    cin >> choice;
}