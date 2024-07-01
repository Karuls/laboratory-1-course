//Определить структуру для представления информации о наличии
//  санаторных путевок, содержащую следующие поля :
//  Название санатория, Место расположения, Лечебный профиль, Количество путевок.
// Представить введенные данные в виде таблицы, сгруппировав 
// их по лечебным профилям санаториев.В пределах каждой группы 
// данные отсортировать по названиям санаториев.Организовать поиск информации и вывод результатов.

#include<iostream>
#include<Windows.h>
#include<stdio.h>
#include <string>
#include<fstream> 

using namespace std;
#define size 8
struct healing {
	string name;
	string place;
	char healing[50];
	int travel_packages;
};
healing health_center[size];
int choice;
int now_size = 0;

void enter();
void all_out();
void found();

int main() {
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);


	cout << "Введите: " << endl;
	cout << "1 - Ввод данных" << endl;
	cout << "2 - Вывод всей информации" << endl;
	cout << "3 - Поиск информации" << endl;

	cout << "5 - Выход" << endl;

	cin >> choice;

	do {
		switch (choice) {
		case 1: enter(); break; // Функция ввода
		case 2: all_out(); break;// Функция вывода с сортировкой
		case 3: found(); break; // Функция поиска
		}
	} while (choice != 5);

}

void enter() {
	int answer;
	do {
		if (now_size >= size) { // проверка на место
			cout << "Ошибка: массив поездов заполнен." << endl;
			return;
		}

		cout << "Название санатория : ";
		cin.ignore(); // Чистка буфера
		getline(cin, health_center[now_size].name);

		cout << "Местонахождение : ";
		getline(cin, health_center[now_size].place);

		cout << "Лечебный профиль: ";
		cin.getline(health_center[now_size].healing,50);

		cout << "Количество путевок: ";
		cin >> health_center[now_size].travel_packages;

		now_size++;


		cout << "Продолжить ввод? (1 - да, 0 - нет): ";
		cin >> answer;

	} while (answer == 1);
	cout << "Что дальше?" << endl;
	cin >> choice;

}

void all_out() {
	
	//Сортировка по алфавиту...
	for (int i = 0; i < now_size - 1; i++) {
		for (int j = 0; j < now_size - i - 1; j++) {
			if (strcmp(health_center[j].healing, health_center[j + 1].healing) > 0) {
				swap(health_center[j], health_center[j + 1]);
			}
		}
	}


	for (int i = 0; i < now_size; i++) { // Вывод

		cout << "Название санатория : ";
		cout << health_center[i].name << endl;
		
		cout << "Местонахождение : ";
		cout << health_center[i].place << endl;

		cout << "Лечебный профиль: ";
		cout << health_center[i].healing << endl;

		cout << "Количество путевок: ";
		cout << health_center[i].travel_packages << endl;
		cout << endl;
	}

	cout << "Что дальше?" << endl;
	cin >> choice;
}

void found() {
	int ans, answer_found;
	string buffer; bool flag = false;

	do{
	cout << "Поиск по:" << endl;
	cout << "1 - Название санатория : ";
	cout << "2 - Местонахождение : ";
	cout << "3 - Лечебный профиль: ";
	cout << "4 - Количество путевок: ";
	cin >> ans;
	
	switch (ans) {
	case 1: 
		cout << "Введите название санатория : ";
		cin >> buffer;
		for (int i = 0; i < now_size; i++) {
			if (buffer == health_center[i].name) {
				cout << "Название санатория : "<< health_center[i].name << endl;
				cout << "Местонахождение : "<<  health_center[i].place << endl;
				cout << "Лечебный профиль: "<< health_center[i].healing << endl;
				cout << "Количество путевок: " << health_center[i].travel_packages << endl;
				cout << endl;
			}
		}; break;

		case 2:
			cout << "Введите Местонахождение: ";
			cin >> buffer;
			for (int i = 0; i < now_size; i++) {
				if (buffer == health_center[i].place) {
					cout << "Название санатория : " << health_center[i].name << endl;
					cout << "Местонахождение : " << health_center[i].place << endl;
					cout << "Лечебный профиль: " << health_center[i].healing << endl;
					cout << "Количество путевок: " << health_center[i].travel_packages << endl;
					cout << endl;
				}
			}; break;
		case 3: 
			char buf[50];
			cout << "Введите лечебный профиль : ";
			cin.ignore(); // Чистка буфера
			cin.getline(buf,50);

			for (int i = 0; i < now_size; i++) {
				if (strcmp (buf, health_center[i].healing) ==0) {
					cout << "Название санатория : " << health_center[i].name << endl;
					cout << "Местонахождение : " << health_center[i].place << endl;
					cout << "Лечебный профиль: " << health_center[i].healing << endl;
					cout << "Количество путевок: " << health_center[i].travel_packages << endl;
					cout << endl;
				}
			}; break;

		case 4: 
			int reg;
			cout << "Введите Количество путевок: ";
			cin >> reg;
			for (int i = 0; i < now_size; i++) {
				if (reg == health_center[i].travel_packages ) {
					cout << "Название санатория : " << health_center[i].name << endl;
					cout << "Местонахождение : " << health_center[i].place << endl;
					cout << "Лечебный профиль: " << health_center[i].healing << endl;
					cout << "Количество путевок: " << health_center[i].travel_packages << endl;
					cout << endl;
				}
			}; break;
	}

	cout << "Хотите продолжить поиск?(1 - да, 2 - нет)" << endl;
	cin >> answer_found;
	} while (answer_found == 1);
	cout << "Что дальше?" << endl;
	cin >> choice;

}
