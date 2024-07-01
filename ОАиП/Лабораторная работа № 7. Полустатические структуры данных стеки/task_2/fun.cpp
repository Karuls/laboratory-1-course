#include <iostream>
#include <fstream>
#include "fun.h"
using namespace std;

void push(int x, Stack*& myStk)   //���������� �������� � � ����	
{
	Stack* e = new Stack;    //��������� ������ ��� ������ ��������
	e->data = x;             //������ �������� x � ���� data 
	e->next = myStk;         //������� ������� �� ��������� ������� 
	myStk = e;               //����� ������� �� ������� ������
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
		int x = myStk->data;    //������ �������� �� ���� data � �����. x 
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

void clear(Stack*& myStk) {
	bool flag = false;
	Stack* e = myStk;
	Stack* previous, * current, * temp;

	if (e == NULL) {
		cout << "������ ����" << endl;
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
			current = current->next; // ������� � ���������� 
		}
		if (current != NULL) {
			temp = current;
			previous->next = current->next;
			delete temp;
		}
	}

	cout << "������ ������������� ������� ������" << endl;

	// ������ �������� ����� ��������
	e = myStk;
	while (e != NULL) {
		cout << "-->" << "(" << e->data << ")";
		e = e->next;
	}
	cout << "-->NULL" << endl;
}

