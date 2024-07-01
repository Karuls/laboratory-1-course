#include <iostream>
#include "myStack.h"
using namespace std;
//Разработать функцию, которая формирует стек Stack, включив в него повторяющиеся элементы стеков Stack1 и Stack2.
int main()
{
	setlocale(LC_ALL, "Rus");
	int choice; int x,y;
	Stack* myStk = new Stack; myStk = NULL;       
	Stack_2* myStk_2 = new Stack_2; myStk_2 = NULL;
	Stack_3* myStk_3 = new Stack_3; myStk_3 = NULL;
	for (;;)
	{
		cout << "Выберите команду:" << endl;
		cout << "1 - Добавление элемента в стек" << endl;
		cout << "2 - Добавление элемента в стек 2" << endl;
		cout << "3 - Извлечение элемента из стека" << endl;
		cout << "4 - Запись в файл" << endl;
		cout << "5 - Чтение из файла" << endl;
		cout << "6 - Вывод стека" << endl;
		cout << "7 - Есть ли в стеке элемент, равный следующему за ним элементу?" << endl;
		cout << "0 - Выход" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Введите элемент: " << endl;
			cin >> x;
			push(x, myStk);
			break;

		case 2:
			cout << "Введите элемент: " << endl;
			cin >> y;
			push_2(y, myStk_2);
			break;

		case 3:
			x = pop(myStk);
			if (x != -1)
				cout << "Извлеченный элемент: " << x << endl;
			break;

		case 4:
			toFile(myStk);
			break;
		
		case 5:
			fromFile(myStk);
			break;
		
		case 6:
			cout << "Весь стек: " << endl;
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
