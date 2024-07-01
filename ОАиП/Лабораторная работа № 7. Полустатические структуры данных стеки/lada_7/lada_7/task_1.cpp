#include <iostream>
#include "myStack.h"
using namespace std;
//����������� �������, ������� ��������� ���� Stack, ������� � ���� ������������� �������� ������ Stack1 � Stack2.
int main()
{
	setlocale(LC_ALL, "Rus");
	int choice; int x,y;
	Stack* myStk = new Stack; myStk = NULL;       
	Stack_2* myStk_2 = new Stack_2; myStk_2 = NULL;
	Stack_3* myStk_3 = new Stack_3; myStk_3 = NULL;
	for (;;)
	{
		cout << "�������� �������:" << endl;
		cout << "1 - ���������� �������� � ����" << endl;
		cout << "2 - ���������� �������� � ���� 2" << endl;
		cout << "3 - ���������� �������� �� �����" << endl;
		cout << "4 - ������ � ����" << endl;
		cout << "5 - ������ �� �����" << endl;
		cout << "6 - ����� �����" << endl;
		cout << "7 - ���� �� � ����� �������, ������ ���������� �� ��� ��������?" << endl;
		cout << "0 - �����" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "������� �������: " << endl;
			cin >> x;
			push(x, myStk);
			break;

		case 2:
			cout << "������� �������: " << endl;
			cin >> y;
			push_2(y, myStk_2);
			break;

		case 3:
			x = pop(myStk);
			if (x != -1)
				cout << "����������� �������: " << x << endl;
			break;

		case 4:
			toFile(myStk);
			break;
		
		case 5:
			fromFile(myStk);
			break;
		
		case 6:
			cout << "���� ����: " << endl;
			show(myStk);
			break;

		case 7:
			clear(myStk, myStk_2, myStk_3);
			break;
	
		case 0: 
			return 0;
			break;
		}
	}
	return 0;
}
