#include <iostream>
#include <fstream>
#include "fun.h"
using namespace std;

void push(int x, Stack*& myStk)   //Добавление элемента х в стек	
{
	Stack* e = new Stack;    //выделение памяти для нового элемента
	e->data = x;             //запись элемента x в поле data 
	e->next = myStk;         //перенос вершины на следующий элемент 
	myStk = e;               //сдвиг вершины на позицию вперед
}

char pop(Stack*& myStk)   //Извлечение (удаление) элемента из стека
{
	if (myStk == NULL)
	{
		cout << "Стек пуст!" << endl;
		return -1;               //если стек пуст - возврат (-1) 
	}
	else
	{
		Stack* e = myStk;        //е-переменная для хранения адреса элемента
		int x = myStk->data;    //запись элемента из поля data в перем. x 
		if (myStk)
			myStk = myStk->next;   //перенос вершины
		delete e;
		return x;
	}
}

void toFile(Stack*& myStk) //Запись в файл
{
	Stack* e = myStk;
	Stack buf;
	ofstream frm("mStack.dat");
	if (frm.fail())
	{
		cout << "\n Ошибка открытия файла";
		exit(1);
	}
	while (e)
	{
		buf = *e;
		frm.write((char*)&buf, sizeof(Stack));
		e = e->next;
	}
	frm.close();
	cout << "Стек записан в файл mStack.dat\n";
}

void fromFile(Stack*& myStk)          //Считывание из файла
{
	Stack buf, * p = nullptr, * e = nullptr;
	ifstream frm("mStack.dat");
	if (frm.fail())
	{
		cout << "\n Ошибка открытия файла";
		exit(1);
	}
	frm.seekg(0);
	frm.read((char*)&buf, sizeof(Stack));
	while (!frm.eof())
	{
		push(buf.data, e);
		frm.read((char*)&buf, sizeof(Stack));
	}
	frm.close();
	while (e != NULL)
	{
		buf.data = pop(e);
		push(buf.data, p);
		myStk = p;
	}
	cout << "\nСтек считан из файла mStack.dat\n\n";
}

void show(Stack*& myStk)  //Вывод стека с очисткой
{
	Stack* e = myStk;
	if (e == NULL)
		cout << "Стек пуст!" << endl;
	while (e != NULL)
		cout << pop(e) << " ";
	cout << endl;
}

void clear(Stack*& myStk) {
	bool flag = false;
	Stack* e = myStk;
	Stack* previous, * current, * temp;

	if (e == NULL) {
		cout << "Список пуст" << endl;
		return;
	}

	if (e->data < 0) {
		temp = e;
		myStk = e->next;
		delete temp;
	}
	else {
		previous = e;
		current = e->next;
		while (current != NULL && current->data > 0) {
			previous = current;
			current = current->next; // перейти к следующему 
		}
		if (current != NULL) {
			temp = current;
			previous->next = current->next;
			delete temp;
		}
	}

	cout << "Первый положительный элемент удален" << endl;

	// Печать значений после удаления
	e = myStk;
	while (e != NULL) {
		cout << "-->" << "(" << e->data << ")";
		e = e->next;
	}
	cout << "-->NULL" << endl;
}

