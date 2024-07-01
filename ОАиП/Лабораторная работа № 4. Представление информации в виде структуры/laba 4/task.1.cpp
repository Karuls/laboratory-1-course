#include<iostream>
#include<Windows.h>
#include<stdio.h>
#include <string>
#include<fstream> 
using namespace std;

#define size 55
void enter();// Функция ввода
void out(); // Функция вывода
void delet();// Функция удвления
void found();// Функция поиска
void write_file();// Функция записи в файл
void read_file();// Функция чтения фала
void choice_specialties();//

struct applicant { //Структура
    string university;
    string location;
    string specialties;
    string contest;
    string cost;
};
struct applicant applicants_guide[size];
struct applicant bad;
int current_size = 0; //Для подсчета количества введенного
int choice;

int main() {
    SetConsoleCP(1251);
    setlocale(LC_CTYPE, "Russian");

    cout << "Введите:" << endl;
    cout << "1 - Для ввода новой записи" << endl;
    cout << "2 - Для вывода записи(ей)" << endl;
    cout << "3 - Для удаления записи" << endl;
    cout << "4 - Поиск записей" << endl;
    cout << "5 - Запись информации в файл" << endl;
    cout << "6 - Чтение данных из файла" << endl;
    cout << "7 - Поиск по специальности" << endl;
    cout << "8 - Для выхода" << endl;
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
    cout << "Ввод информации" << endl;

    string choice_str;
    do {
        if (current_size < size) {
            cout << "Строка номер " << current_size + 1 << endl;
            cout << "Наименование вуза: ";
            cin.ignore(); // очистка буфера ввода
            getline(cin, applicants_guide[current_size].university);
            cout << "Адрес: ";
            getline(cin, applicants_guide[current_size].location);
            cout << "Перечень специальностей: ";
            getline(cin, applicants_guide[current_size].specialties);
            cout << "Конкурс прошлого года по каждой специальности: ";
            getline(cin, applicants_guide[current_size].contest);
            cout << "Размер оплаты при договорном обучении: ";
            getline(cin, applicants_guide[current_size].cost);
            current_size++;
        }
        else {
            cout << "Введено максимальное количество строк" << endl;
            break;
        }

        cout << "Продолжить ввод? (1 - да, 0 - нет): ";
        cin >> choice_str;
        // Проверяем, введено ли "0" для завершения ввода
    } while (choice_str == "1");

    cout << "Что дальше?" << endl;
    cin >> choice;
}


void out() {
    int answer, number;
    cout << "1 - Вывод всех строк" << endl;
    cout << "2 - Вывод одной строки" << endl;
    cin >> answer;
    if (answer == 2) {

        cout << "Номер выводимой строки? " << endl;
        cin >> number;
        cout << endl << "Наименование вуза " << endl;
        cout << applicants_guide[number - 1].university;
        cout << "Адрес " << endl;
        cout << applicants_guide[number - 1].location;
        cout << "Перечень специальностей " << endl;
        cout << applicants_guide[number - 1].specialties;
        cout << "конкурс прошлого года по каждой специальности " << endl;
        cout << applicants_guide[number - 1].contest;
        cout << "размер оплаты при договорном обучении " << endl;
        cout << applicants_guide[number - 1].cost;

    }

    if (answer == 1) {
        for (int i = 0; i < current_size; i++) {
            cout << endl << "Наименование вуза: ";
            cout << applicants_guide[i].university << endl;
            cout << "Адрес: ";
            cout << applicants_guide[i].location << endl;
            cout << "Перечень специальностей: ";
            cout << applicants_guide[i].specialties << endl;
            cout << "конкурс прошлого года по каждой специальности: ";
            cout << applicants_guide[i].contest << endl;
            cout << "размер оплаты при договорном обучении: ";
            cout << applicants_guide[i].cost << endl;
        }

        cout << "Что дальше?" << endl;
        cin >> choice;
    }
}

void delet() {
    int number, digit;
    cout << "1 - Хочу удалить все строки" << endl;
    cout << "2 - Хочу удалить одну строку" << endl;
    cin >> number;

    if (number == 2) {
        cout << "Какую строку хотите удалить? " << endl;
        cin >> digit;
        applicants_guide[digit] = bad; //Присваивание пустой структуры
        cout << "Строка удалена " << endl;
    }

    if (number == 1) {
        for (int i = 0; i < current_size; i++) {
            applicants_guide[i] = bad; //Присваивание пустой структуры
        }
        cout << "Строки удалены " << endl;
    }

    cout << "Что дальше?" << endl;
    cin >> choice;
}

void found() {
    int count;
    cout << "Что бы вы хотели найти? " << endl;
    cout << "1 - Наименование вузов" << endl;
    cout << "2 - Адреса" << endl;
    cout << "3 - Перечни специальностей" << endl;
    cout << "4 - Конкурс прошлого года по каждой специальности" << endl;
    cout << "5 - Размер оплат при договорном обучении" << endl;
    cin >> count;

    if (count < 1 || count > 5) {
        cout << "Неккоректный ответ. " << endl;
    }

    else {
        if (count == 1) {
            cout << endl << "Наименование вуза " << endl;
            for (int i = 0; i < current_size; i++) {
                cout << applicants_guide[i].university << endl;
            }
        }

        if (count == 2) {
            cout << "Адреса " << endl;
            for (int i = 0; i < current_size; i++) {
                cout <<  applicants_guide[i].location << endl;
                
            }
        }

        if (count == 3) {
            cout << "Перечень специальностей " << endl;
            for (int i = 0; i < current_size; i++) {
                cout << applicants_guide[i].specialties << endl;

            }
        }

        if (count == 4) {
            cout << "Конкурс прошлого года по каждой специальности " << endl;
            for (int i = 0; i < current_size; i++) {
                cout << applicants_guide[i].contest << endl;

            }
        }

        if (count == 5) {
            cout << "Размеры оплаты при договорном обучении: " << endl;
            for (int i = 0; i < current_size; i++) {
                cout << applicants_guide[i].cost << endl;

            }
        }

    }
    
    cout << "Что дальше?" << endl;
    cin >> choice;
}

void write_file() {
    ofstream file_write("applicant.txt"); 
    int num;
    cout << "Запись информации в файл ..." << endl;
    cout << "Что хотите записать?" << endl;
    cout << "1 - Все" << endl;
    cout << "2 - Одну строку" << endl;
    cin >> num;

    if (num != 1 && num != 2) { 
        cout << "Некорректный ввод" << endl;
        return; // Выходим из функции, так как введен некорректный номер
    }

    if (num == 1) {
        for (int i = 0; i < current_size; i++) {
            file_write << "Наименование вуза: " << applicants_guide[i].university << endl;
            file_write << "Адрес: " << applicants_guide[i].location << endl;
            file_write << "Перечень специальностей: " << applicants_guide[i].specialties << endl;
            file_write << "Конкурс прошлого года по каждой специальности: " << applicants_guide[i].contest << endl;
            file_write << "Размер оплаты при договорном обучении: " << applicants_guide[i].cost << endl;
            file_write << endl; 
            cout << "Строки записаны." << endl;
        }
    }

    if (num == 2) {
        int g;
        cout << "Какую строку хотите записать? " << endl;
        cin >> g;

        if (g >= 1 && g <= current_size) {
            file_write << "Наименование вуза: " << applicants_guide[g - 1].university << endl;
            file_write << "Адрес: " << applicants_guide[g - 1].location << endl;
            file_write << "Перечень специальностей: " << applicants_guide[g - 1].specialties << endl;
            file_write << "Конкурс прошлого года по каждой специальности: " << applicants_guide[g - 1].contest << endl;
            file_write << "Размер оплаты при договорном обучении: " << applicants_guide[g - 1].cost << endl;
            file_write << endl; 
            cout << "Строки записаны." << endl;
        }
        else {
            cout << "Некорректный номер строки" << endl;
        }
    }
    file_write.close();

    cout << "Что дальше?" << endl;
    cin >> choice;

}
void read_file() {
    ifstream file_read("applicant.txt");
    int num;
    string buffer;

    cout << "1 - Прочесть весь файл " << endl;
    cout << "2 - Прочесть один справочник абитурьента " << endl;
    cin >> num; cout << endl;

    if (num != 1 && num != 2) {
        cout << "Некорректный ввод" << endl;
        return; // Выходим из функции, так как введен некорректный номер
    }

    if (num == 1) {
        int count = 1;
        while (getline(file_read, buffer)) {
            cout << buffer << endl; // Выводим содержимое каждой строки файла
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
        cout << "Номер какого справочника вы бы хотели прочесть?" << endl;
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
                cout << buffer << endl; // Выводим содержимое каждой строки файла
                helper--;
            } 
        }
    }

    cout << "Что дальше?" << endl;
    cin >> choice;

}

void choice_specialties() {
    string spec;
    cout << "Введите специальность" << endl;
    cin.ignore(); // очистка буфера ввода
    getline(cin, spec);
    for (int i = 0; i < current_size; i++) {
        if (applicants_guide[i].specialties == spec) { //Проверка по специальности
            cout << "Наименование вуза: " << applicants_guide[i].university << endl;
            cout << "Адрес: " << applicants_guide[i].location << endl;
            cout << "Перечень специальностей: " << applicants_guide[i].specialties << endl;
            cout << "Конкурс прошлого года по каждой специальности: " << applicants_guide[i].contest << endl;
            cout << "Размер оплаты при договорном обучении: " << applicants_guide[i].cost << endl;
            cout << endl;
        }
    }

    cout << "Что дальше?" << endl;
    cin >> choice;
}
