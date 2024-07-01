#include <iostream>
#include <fstream>
#include "myStack.h"
using namespace std;

void push(int x, Stack*& myStk)   //���������� �������� � � ����	
{
	Stack* e = new Stack;    //��������� ������ ��� ������ ��������
	e->data = x;             //������ �������� x � ���� data 
	e->next = myStk;         //������� ������� �� ��������� ������� 
	myStk = e;               //����� ������� �� ������� ������
}

void push_2(int y, Stack_2*& myStk_2)   //���������� �������� y � ����	
{
	Stack_2* r = new Stack_2;    
	r->data_2 = y;             
	r->next = myStk_2;         
	myStk_2 = r;               
}

char pop(Stack*& myStk)   //���������� (��������) �������� �� �����
{
	if (myStk == NULL)
	{
		cout << "���� ����!" << endl;
		return -1;               //���� ���� ���� - ������� (-1) 
	}
	else
	{
		Stack* e = myStk;        //�-���������� ��� �������� ������ ��������
		char x = myStk->data;    //������ �������� �� ���� data � �����. x 
		if (myStk)
			myStk = myStk->next;   //������� �������
		delete e;
		return x;
	}
}

void toFile(Stack*& myStk) //������ � ����
{
	Stack* e = myStk;
	Stack buf;
	ofstream frm("mStack.dat");
	if (frm.fail())
	{
		cout << "\n ������ �������� �����";
		exit(1);
	}
	while (e)
	{
		buf = *e;
		frm.write((char*)&buf, sizeof(Stack));
		e = e->next;
	}
	frm.close();
	cout << "���� ������� � ���� mStack.dat\n";
}

void fromFile(Stack*& myStk)          //���������� �� �����
{
	Stack buf, * p = nullptr, * e = nullptr;
	ifstream frm("mStack.dat");
	if (frm.fail())
	{
		cout << "\n ������ �������� �����";
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
	cout << "\n���� ������ �� ����� mStack.dat\n\n";
}

void show(Stack*& myStk)  //����� ����� � ��������
{
	Stack* e = myStk;
	if (e == NULL)
		cout << "���� ����!" << endl;
	while (e != NULL)
		cout << pop(e) << " ";
	cout << endl;
}

void clear(Stack*& myStk, Stack_2*& myStk_2, Stack_3*& myStk_3) { // ����������� ��������� ���������
	Stack* e = myStk;int i = 0, j = 0;
	Stack_2* d = myStk_2;
	Stack_3* c = myStk_3;
	while (e != NULL) { // ������� ��������� 1 �����
			i++;
			e = e->next;
	}
	e = myStk;

	while (d != NULL) {// ������� ��������� 2 �����
		j++;
		d = d->next;
	}
	d = myStk_2;
	for (int a = 0; a < i; a++) { // �������� �� ��������

		for (int w = 0; w < j; w++) {

			if (e->data == d->data_2) { // ������ � 3 ����
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
	while (c != NULL) { // �����
		cout << c->data_3;
		cout << "-->";
		c = c->next;
	}
	cout << "--NULL";
	c = myStk_3;


}

