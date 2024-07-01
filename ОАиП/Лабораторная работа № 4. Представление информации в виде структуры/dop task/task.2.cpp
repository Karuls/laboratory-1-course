//1. Определить структуру для представления информации о сданных студентом экзаменах,
//  содержащую поля: ФИО студента, число экзаменов, полученные оценки. 
// Определить функции для обработки отдельного объекта (например, для проверки,
//  сданы ли все экзамены на 4 и 5). Написать функцию для обработки массива структур.
//  В результате обработки требуется вычислить характеристику успеваемости студентов,
//  то есть отношение числа студентов, сдавших экзамены на 4 и 5, к общему числу студентов, в процентах.
#include<iostream>
#include<Windows.h>
#include<stdio.h>
#include <string>
#include<fstream> 
using namespace std;

#define size 15 //Длинна массива структуры
#define Max_rating 10

struct students { 
	string FIO;
	int count_of_exams;
    int rating[Max_rating];
};
struct students students_mass[size];
int enter_size = 0;  //Для подсчета количества введенного массива
int choice;

void enter(); //Функция ввода
void test_rating();// Функция проверки оценок
void perfomance_calculation();// Функция характеристики успеваемости студентов

int main() {
	SetConsoleCP(1251);
	setlocale(LC_ALL, "rus");

	cout << "Введите: " << endl;
	cout << "1 - Ввод данных" << endl;
	cout << "2 - Проверка на оценки" << endl;
	cout << "3 - Вычислить характеристику успеваемости студентов" << endl;
	cout << "5 - Выход" << endl;
	cin >> choice;

	do
	{
		switch (choice) {
		case 1: enter(); break;
		case 2: test_rating(); break;
		case 3: perfomance_calculation(); break;
		}
	} 
	while (choice != 5);
}

void enter() {
	int answer;
	cout << "Ввод информации" << endl;
	do {

	
	if (enter_size < size) {
		cout << enter_size+1 <<" Студент " << endl;
		cout << "Введите ФИО студента: " << endl;
		
		cin.ignore();
		getline(cin, students_mass[enter_size].FIO);
		cout << "Введите кол-во экзаменов: ";
		cin >> students_mass[enter_size].count_of_exams;
		cout << "Введите оценки: ";
		for (int i = 0; i < students_mass[enter_size].count_of_exams; ++i) {
			cin >> students_mass[enter_size].rating[i];
		}
		enter_size++;
	}
	else {
		cout << "Максимум места достигнут" << endl;
		break;
	}
	
	cout << "Продолжить ввод? (1 - да, 0 - нет): ";
	cin >> answer;

	} while (answer == 1);

	cout << "Что дальше?" << endl;
	cin >> choice;
}

void test_rating() {
	int number; int answer;
	bool flag_exams;
	do{
		flag_exams = true;
	cout << "Рейтинг какого студента вы бы хотели увидеть?" << endl;
	cin >> number;
     
	for (int i = 0; i < students_mass[number - 1].count_of_exams; i++) {

		if (students_mass[number-1].rating[i] < 4) {
			flag_exams = false;
		}

	}
	if (flag_exams == true) {
		cout << "Этот студент сдал все на отлично" << endl;
	}
	else if (flag_exams == false) {
		cout << "У этого студента есть оценки ниже 4 и 5" << endl;
	}
	cout << "Продолжить ввод? (1 - да, 0 - нет): ";
	cin >> answer;
	
	} while (answer == 1);

	cout << "Что дальше?" << endl;
	cin >> choice;
}

void perfomance_calculation() { //
	bool flag;
	int clever_students = 0;
	int students; double percent;
	students = enter_size; // количество введеных студентов
	for (int i = 0; i < enter_size; i++) {
		
		flag = true;
		for (int g = 0; g < students_mass[i].count_of_exams; g++) { // смена массивов
			if (students_mass[i].rating[g] < 4) { // смена оценок
				flag = false;	
			}
		}

		if (flag == true) { 
			clever_students++;
		}

	}
	 percent = (static_cast<double>(clever_students) / students) * 100;
	cout << "Характеристика успеваемости студентов: " << percent << "%" << endl;

	cout << "Что дальше?" << endl;
	cin >> choice;

}