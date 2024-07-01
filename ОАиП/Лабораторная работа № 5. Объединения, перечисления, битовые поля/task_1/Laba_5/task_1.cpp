//Список клиентов гостиницы. Паспортные данные, даты приезда и отъезда, номер,
//  тип размещения (люкс, одноместный, двухместный, трехместный, апартаменты). 
// Поиск гостя по дате приезда. Даты приезда и отъезда реализовать с помощью
//  битового поля, тип размещения ? с помощью перечисления

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
    string data; // заменил name на data
    string allocation;
    int number;
    unsigned day_Arrival : 5;// Для дня 5 битов
    unsigned month_Arrival : 4;// Для месяца 4 бита
    unsigned year_Arrival : 11;// Для года 11 битов
    unsigned day_departure : 5;
    unsigned month_departure : 4;
    unsigned year_departure : 11;
};
Clients list_of_clients[size];
Clients bad; // Для удаления
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
    cout << "3 - Поиск гостя по дате приезда." << endl;
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

        cout << "Введите паспортные данные: ";
        cin.ignore(); // Чистка буфера
        getline(cin, list_of_clients[now_size].data);


        cout << "Введите номер: ";
        cin >> list_of_clients[now_size].number;
        do {
            cout << "Введите тип размещения (1 - люкс, 2 - одноместный, 3 - двухместный, 4 - трехместный, 5 - апартаменты)";
            cin >> num;
            if (num == (int)Luxury) list_of_clients[now_size].allocation = "Luxury"; // Проверка последовательности и присвоение
            else if (num == (int)Single) list_of_clients[now_size].allocation = "Single";
            else if (num == (int)Double) list_of_clients[now_size].allocation = "Double";
            else if (num == (int)triple_room) list_of_clients[now_size].allocation = "Triple room";
            else if (num == (int)apartment) list_of_clients[now_size].allocation = "Apartment";
        } while (num != 1 && num != 2 && num != 3 && num != 4 && num != 5);

        cout << "Введите дату приеда: ";
        cin >> datа;
        list_of_clients[now_size].day_Arrival = (datа / 1000000); // Запись для битового поля
        list_of_clients[now_size].month_Arrival = ((datа / 10000) % 100);
        list_of_clients[now_size].year_Arrival = (datа % 10000);

        cout << "Введите дату отъезда: ";
        cin >> datа;
        list_of_clients[now_size].day_departure = (datа / 1000000);// Запись для битового поля
        list_of_clients[now_size].month_departure = ((datа / 10000) % 100);
        list_of_clients[now_size].year_departure = (datа % 10000);

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

        cout << "Паспортные данные: " << list_of_clients[i].data << endl;
        cout << "Тип размещения: " << list_of_clients[i].allocation << endl;
        cout << "Номер: " << list_of_clients[i].number << endl;
        cout << "Дата заезда: " << list_of_clients[i].day_Arrival << "." << list_of_clients[i].month_Arrival << "." << list_of_clients[i].year_Arrival << endl;
        cout << "Дата выезда: " << list_of_clients[i].day_departure << "." << list_of_clients[i].month_departure << "." << list_of_clients[i].year_departure << endl;
    }
    cout << "Что дальше?" << endl;
    cin >> choice;
}

void found() { // Поиск
    int buffer, buffer_day, buffer_month, buffer_year;
    cout << "Введите день приезда: ";
    cin >> buffer;
    buffer_day = buffer / 1000000;// Деление на дни и тд
    buffer_month = ((buffer / 10000) % 100);
    buffer_year = (buffer % 10000);
    for (int i = 0; i < now_size; i++) {
        if (buffer_day == list_of_clients[i].day_Arrival && buffer_month == list_of_clients[i].month_Arrival && buffer_year == list_of_clients[i].year_Arrival) {
            cout << "Паспортные данные: " << list_of_clients[i].data << endl;
            cout << "Тип размещения: " << list_of_clients[i].allocation << endl;
            cout << "Номер: " << list_of_clients[i].number << endl;
            cout << "Дата заезда: " << list_of_clients[i].day_Arrival << "." << list_of_clients[i].month_Arrival << "." << list_of_clients[i].year_Arrival << endl;
            cout << "Дата выезда: " << list_of_clients[i].day_departure << "." << list_of_clients[i].month_departure << "." << list_of_clients[i].year_departure << endl;
        }
    }

    cout << "Что дальше?" << endl;
    cin >> choice;
}

void delet(){ // Удаление строки структуры
    int answer;
    int select;
    int number;
    do{
    cout << "1 - Удалить введенную строку" << endl;
    cout << "2 - Удалить все" << endl;
    cin >> select;
    if (select == 1) {
        cout << "Какую строку хотите удалить?" << endl;
        cin >> number;
        list_of_clients[number] = bad;
    }

    if (select == 2) {
        for (int i = 0; i < now_size; i++) {
            list_of_clients[i] = bad;
        }
    }
    cout << "Продолжить ввод? (1 - да, 0 - нет): ";
    cin >> answer;

    } while (answer == 1);

    cout << "Что дальше?" << endl;
    cin >> choice;
}
//unsigned day_Arrival : 5; Т.к. 31 = 5 битов
