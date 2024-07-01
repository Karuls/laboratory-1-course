#include "Hash_Chain.h"
#include <iostream>
using namespace std;
struct AAA
{
	int key;
	char* university_name;
	char* Rector_info;
	AAA(int k, char* z)
	{
		key = k;
		university_name = z;
	}
	AAA()
	{
		key = 0;
		university_name = nullptr;
		Rector_info = NULL;
	}
};
int hf(void* d)
{
	AAA* f = (AAA*)d;
	return f->key;
}
//-------------------------------
void AAA_print(listx::Element* e)
{
	std::cout << ((AAA*)e->data)->key << '-' << ((AAA*)e->data)->university_name << ((AAA*)e->data)->Rector_info<< " / ";
}
//-------------------------------
int main()
{
	setlocale(LC_ALL, "rus");
	int current_size = 7;
	cout << "������� ������ ���-�������" << endl;
	cin >> current_size;
	hashTC::Object H = hashTC::create(current_size, hf);
	int choice;
	int k;
	for (;;)
	{
		cout << "1 - ����� ���-�������" << endl;
		cout << "2 - ���������� ��������" << endl;
		cout << "3 - �������� ��������" << endl;
		cout << "4 - ����� ��������" << endl;
		cout << "0 - �����" << endl;
		cout << "�������� �����" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0: exit(0);
		case 2: {	AAA* a = new AAA;
			char* str = new char[20];
			char* str2 = new char[20];
			cout << "������� ����(��� ��������)" << endl;
			cin >> k;
			a->key = k;
			cout << "������� ��� �������" << endl;
			cin >> str;
			a->university_name = str;
			
			cout << "������� ��� �������" << endl;
			cin >> str2;
			a->Rector_info = str2;
			
			H.insert(a);
		}
			  break;
		case 1: H.Scan();
			break;
		case 3: {	AAA* b = new AAA;
			cout << "������� ����" << endl;
			cin >> k;
			b->key = k;
			H.deleteByData(b);
		}
			  break;
		case 4: AAA * c = new AAA;
			cout << "������� ����" << endl;
			cin >> k;
			c->key = k;
			if (H.search(c) == NULL)
				cout << "������� �� ������" << endl;
			else
			{
				cout << "������ ������� � ������ ������" << endl;
				AAA_print(H.search(c));
				cout << endl;
			}
			break;
		}
	}
	return 0;
}
