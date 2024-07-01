#include <iostream>
#include <fstream>
#include "myStack.h"
using namespace std;

void push(int x, Stack*& myStk)   //Добавление элемента х в стек	
{
	Stack* e = new Stack;    //выделение памяти для нового элемента
	e->data = x;             //запись элемента x в поле data 
	e->next = myStk;         //перенос вершины на следующий элемент 
	myStk = e;               //сдвиг вершины на позицию вперед
}

void push_2(int y, Stack_2*& myStk_2)   //Добавление элемента y в стек	
{
	Stack_2* r = new Stack_2;    
	r->data_2 = y;             
	r->next = myStk_2;         
	myStk_2 = r;               
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
		char x = myStk->data;    //запись элемента из поля data в перем. x 
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

void clear(Stack*& myStk, Stack_2*& myStk_2, Stack_3*& myStk_3) { // Сравнивание следующих элементов
	Stack* e = myStk;int i = 0, j = 0;
	Stack_2* d = myStk_2;
	Stack_3* c = myStk_3;
	while (e != NULL) { // подсчет элементов 1 стека
			i++;
			e = e->next;
	}
	e = myStk;

	while (d != NULL) {// подсчет элементов 2 стека
		j++;
		d = d->next;
	}
	d = myStk_2;
	for (int a = 0; a < i; a++) { // проверка на равность

		for (int w = 0; w < j; w++) {

			if (e->data == d->data_2) { // Запись в 3 стек
				Stack_3* c = new Stack_3;
				c->data_3 = e->data;
				c->next = myStk_3;
				myStk_3 = c;
			}
			d = d->next;
		}
		d = myStk_2;
		e = e->next;
	}
	e = myStk;
	d = myStk_2;
	c = myStk_3;
	while (c != NULL) { // Вывод
		cout << c->data_3;
		cout << "-->";
		c = c->next;
	}
	cout << "--NULL";
	c = myStk_3;


}

