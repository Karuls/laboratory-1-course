//Записная книжка. Ф.И.О, дата рождения, адрес, телефон .
//  Поиск по фамилии. Дату рождения реализовать с помощью битового поля.
#include<iostream>
#include<Windows.h>
#include<stdio.h>
#include <string>
#include<fstream> 
#define size 8

using namespace std;

struct peoples_book {
    string full_name; 
    unsigned day_birthday : 5;// Для дня 5 битов
    unsigned month_birthday : 4;// Для месяца 4 бита
    unsigned year_birthday : 11;// Для года 11 битов
    string living_place;
    char personal_number[15];

};
peoples_book list_of_peoples[size];
peoples_book bad; // Для удаления
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


    cout << "Введите: " << endl;
    cout << "1 - Ввод данных" << endl;
    cout << "2 - Вывод на экран информации" << endl;
    cout << "3 - Поиск гостя по фамилии" << endl;
    cout << "4 - Удаление записей" << endl;

    cout << "5 - Выход" << endl;

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
    int datа;
    do {
        if (now_size >= size) { // проверка на место
            cout << "Ошибка: массив поездов заполнен." << endl;
            return;
        }

        cout << "Введите ФИО: ";
        cin.ignore(); // Чистка буфера
        getline(cin, list_of_peoples[now_size].full_name);

        cout << "Введите дату рожления: ";
        cin >> datа;
        list_of_peoples[now_size].day_birthday = (datа / 1000000); // Запись для битового поля
        list_of_peoples[now_size].month_birthday = ((datа / 10000) % 100);
        list_of_peoples[now_size].year_birthday = (datа % 10000);

        cout << "Введите адрес: ";
        cin.ignore(); // Чистка буфера
        getline(cin, list_of_peoples[now_size].living_place);
       
        cout << "Введите телефон: ";
        gets_s(list_of_peoples[now_size].personal_number, 15);
      
        now_size++;
            
        cout << "Продолжить ввод? (1 - да, 0 - нет): ";
        cin >> answer;
    } while (answer == 1);


    cout << "Что дальше?" << endl;
    cin >> choice;
}

void out() { // Вывод
    cout << "Вывод информации..." << endl;

    for (int i = 0; i < now_size; i++) {

        cout << "ФИО: " << list_of_peoples[i].full_name << endl;
        cout << "Дата рождения: " << list_of_peoples[i].day_birthday << "." << list_of_peoples[i].month_birthday << "." << list_of_peoples[i].year_birthday << endl;
        cout << "Адрес: " << list_of_peoples[i].living_place << endl;
        cout << "Номер: " << list_of_peoples[i].personal_number << endl;
    }
    cout << "Что дальше?" << endl;
    cin >> choice;
}

void found() { // Поиск
    string buffer;

    cout << "Введите фамилию: ";
    cin.ignore();
    getline(cin, buffer);
    
    for (int i = 0; i < now_size; i++) {
        if ( buffer == list_of_peoples[i].full_name) {
            cout << "ФИО: " << list_of_peoples[i].full_name << endl;
            cout << "Дата рождения: " << list_of_peoples[i].day_birthday << "." << list_of_peoples[i].month_birthday << "." << list_of_peoples[i].year_birthday << endl;
            cout << "Адрес: " << list_of_peoples[i].living_place << endl;
            cout << "Номер: " << list_of_peoples[i].personal_number << endl;
        }
    }

    cout << "Что дальше?" << endl;
    cin >> choice;
}

void delet() { // Удаление строки структуры
    int answer;
    int select;
    int number;
    do {
        cout << "1 - Удалить введенную строку" << endl;
        cout << "2 - Удалить все" << endl;
        cin >> select;
        if (select == 1) {
            cout << "Какую строку хотите удалить?" << endl;
            cin >> number;
            list_of_peoples[number] = bad;
        }

        if (select == 2) {
            for (int i = 0; i < now_size; i++) {
                list_of_peoples[i] = bad;
            }
        }
        cout << "Продолжить ввод? (1 - да, 0 - нет): ";
        cin >> answer;

    } while (answer == 1);

    cout << "Что дальше?" << endl;
    cin >> choice;
}
//unsigned day_birthday : 5; Т.к. 31 = 5 битов
