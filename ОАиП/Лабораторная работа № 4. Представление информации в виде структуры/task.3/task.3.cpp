//Описать структуру с именем TRAIN, содержащую поля :
//  названия пункта назначения, номер поезда, время 
// отправления.Написать программу, выполняющую ввод
//  с клавиатуры данных в массив, состоящий из восьми
//  элементов типа TRAIN(записи должны быть размещены
//  в алфавитном порядке по названиям пунктов назначения); 
// вывод на экран информации о поездах, отправляющихся 
// после введенного с клавиатуры времени(если таких поездов нет,	
//  то вывести сообщение об этом).
#include<iostream>
#include<Windows.h>
#include<stdio.h>

using namespace std;
#define size 8
struct TRAIN {
	char name[20];
	int number;
	int time;
};
TRAIN train_mass[size];
int choice;
int now_size = 0;

void enter();
void out();
void sort();
void all_out();

int main() {
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);


	cout << "Введите: " << endl;
	cout << "1 - Ввод данных" << endl;
	cout << "2 - вывод на экран информации о поездах, отправляющихся после введенного с клавиатуры времен" << endl;
	cout << "3 - Сортировка станций по алфавиту" << endl;
	cout << "4 - Вывод всей информации" << endl;
	cout << "5 - Выход" << endl;
	
	cin >> choice;

	do {
		switch (choice) {
		case 1: enter(); break;
		case 2: out(); break;
		case 3: sort(); break;
		case 4: all_out(); break;
		}
	} while (choice != 5);

}

void enter() {
	int answer;
	do{
	if (now_size >= size) { // проверка на место
		cout << "Ошибка: массив поездов заполнен." << endl;
		return;
	}

	cout << "Введите название пункта назначения: ";
	cin.ignore(); // Чистка буфера
	cin.getline(train_mass[now_size].name, 20);

	cout << "Введите номер поезда: ";
	cin >> train_mass[now_size].number;

	cout << "Введите время отправления: ";
	cin >> train_mass[now_size].time;

	now_size++;


	cout << "Продолжить ввод? (1 - да, 0 - нет): ";
	cin >> answer;

	} while (answer == 1);


	cout << "Что дальше?" << endl;
	cin >> choice;

}

void out() { //Функция 
	int enter_time;
	int hours;
	int min;
	bool flag = false;
	cout << "Введите время: " << endl;
	cin >> enter_time;

	hours = enter_time / 100;
	min = enter_time % 100;

	for (int i = 0; i < now_size; i++) {

		if ( (hours*60 +min) <  ((train_mass[i].time/100)*60) + (train_mass[i].time%100)) {
			
			cout << "Имя Станции: ";
			cout << train_mass[i].name << endl;

			cout << "Номер поезда: ";
			cout << train_mass[i].number << endl;

			cout << "Время отправления: ";
			cout << train_mass[i].time << endl;
			cout << endl;
			flag = true;

			
	 }

		if (flag == false) {
			cout << "Таких поездов нету" << endl;
		}

	}
	cout << "Что дальше?" << endl;
	cin >> choice;
}

void sort() {// Сортировка
	cout << "Сортировка по алфавиту..." << endl;
	for (int i = 0; i < now_size - 1; i++) {
		for (int j = 0; j < now_size - i - 1; j++) {
			if (strcmp(train_mass[j].name, train_mass[j + 1].name) > 0) {
				swap(train_mass[j], train_mass[j + 1]);
			}
		}
	}
	cout << "Что дальше?" << endl;
	cin >> choice;
}

void all_out() {// Вывод всего записанного
	for (int i = 0; i < now_size; i++) {
		cout << "Имя Станции: ";
		cout << train_mass[i].name << endl;

		cout << "Номер поезда: ";
		cout << train_mass[i].number << endl;

		cout << "Время отправления: ";
		cout << train_mass[i].time << endl;
		cout << endl;
	}

	cout << "Что дальше?" << endl;
	cin >> choice;
}