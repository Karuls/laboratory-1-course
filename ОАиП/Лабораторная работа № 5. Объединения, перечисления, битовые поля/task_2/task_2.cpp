//Список клиентов гостиницы. Паспортные данные, даты приезда
//  и отъезда, номер, тип размещения(люкс, одноместный, двухместный, трехместный, апартаменты).
// Поиск гостя по фамилии..
//Реализовать функции ввода с клавиатуры, записи в файл, вывода на экран, чтения из файла и поиска. 
#include<iostream>
#include<Windows.h>
#include<stdio.h>
#include<string>
#include<fstream> 
#define size 8

using namespace std;

union person {
    char last_name[30];
    char data[30];
    char allocation[30];
    int number;
    char time_arrival[15];
    char time_departure[15];
};

struct Clients {
    person lastname; 
    person pasport_data;
    person place;
    person room;
    person time_arr;
    person time_dep;
    
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
    cout << "2 - Вывод на экран информации о поездах" << endl;
    cout << "3 - Поиск гостя по Фамилии." << endl;
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
        cout << "Введите фамилию клиента: ";
        gets_s(list_of_clients[now_size].lastname.last_name, 50);

        cout << "Введите паспортные данные: ";
        gets_s(list_of_clients[now_size].pasport_data.data, 50);

        cout << "Введите тип размещения (Люкс, Одноместный, Двухместный, Трехместный, Апартаменты): ";
        gets_s(list_of_clients[now_size].place.allocation, 50);

        cout << "Введите номер: ";
        cin >> list_of_clients[now_size].room.number;
        cin.ignore(); // Чистка буфера
        cout << "Введите дату приеда: ";
        gets_s(list_of_clients[now_size].time_arr.time_arrival, 15);
        
        cout << "Введите дату отъезда: ";
        gets_s(list_of_clients[now_size].time_dep.time_departure, 15);
      
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

        cout << "Фамилия: " << list_of_clients[i].lastname.last_name << endl;
        cout << "Паспортные данные: " << list_of_clients[i].pasport_data.data << endl;
        cout << "Тип размещения: " << list_of_clients[i].place.allocation << endl;
        cout << "Номер: " << list_of_clients[i].room.number << endl;
        cout << "Дата заезда: " << list_of_clients[i].time_arr.time_arrival << endl;
        cout << "Дата выезда: " << list_of_clients[i].time_dep.time_departure << endl;
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
        if (strcmp(buffer,list_of_clients[i].lastname.last_name) == 0){ // Сравнение строк
        cout << "Фамилия: " << list_of_clients[i].lastname.last_name << endl;
        cout << "Паспортные данные: " << list_of_clients[i].pasport_data.data << endl;
        cout << "Тип размещения: " << list_of_clients[i].place.allocation << endl;
        cout << "Номер: " << list_of_clients[i].room.number << endl;
        cout << "Дата заезда: " << list_of_clients[i].time_arr.time_arrival << endl;
        cout << "Дата выезда: " << list_of_clients[i].time_dep.time_departure << endl;
        }
    }
    cout << "Что дальше?" << endl;
    cin >> choice;
}

void file_write() { // Запись в файл
    ofstream write("task2.txt");
    for (int i = 0; i < now_size; i++) {
        
            write << "Фамилия: " << list_of_clients[i].lastname.last_name << endl;
            write << "Паспортные данные: " << list_of_clients[i].pasport_data.data << endl;
            write << "Тип размещения: " << list_of_clients[i].place.allocation << endl;
            write << "Номер: " << list_of_clients[i].room.number << endl;
            write << "Дата заезда: " << list_of_clients[i].time_arr.time_arrival << endl;
            write << "Дата выезда: " << list_of_clients[i].time_dep.time_departure << endl;
        
    }
    write.close();
    cout<< "Данные записанны " << endl;
    cout << "Что дальше?" << endl;
    cin >> choice;
}

void file_read() {
    char buf[250];
    ifstream file_read("task2.txt");
    cout << "Содержимое файла: " << endl;
    while (file_read.getline(buf, 250)) { // читаем каждую строку
        cout << buf << endl;
    }
    cout << "Что дальше?" << endl;
    cin >> choice;
}