#include<iostream>
using namespace std;

class Spisok
{
private:
	struct node
	{
		int elem;
		node* sled;
	} *phead; // Указатель на начало списка
public:
	Spisok() {
		phead = new(node);
		(*phead).sled = NULL;
	}// Конструктор
	~Spisok() { delete& phead; }// Деструктор
	void POSTROENIE();

	void VYVOD();
	void OCHISTKA();
};

void Spisok::POSTROENIE() {
	node* t;
	int el;
	phead = new (node);
	t = phead; (*t).sled = NULL;
	cout << "Вводите элементы звеньев списка: ";
	cin >> el;
	while (el != 0) {
		(*t).sled = new(node); t = (*t).sled;
		(*t).elem = el; (*t).sled = NULL;
		cin >> el;
	}
}

void Spisok::VYVOD()
// Вывод содержимого однонаправленнго линейного списка
// С заглавным звеном
// phead - указатель на заглавное звено списка
{
	node* t;
	t = (*phead).sled;
	cout << " Список :";
	while (t != NULL) {
		cout << (*t).elem << " ";
		t = (*t).sled;
	}
	cout << endl;
}

void Spisok::OCHISTKA() {
	// Удаление однонаправлено списка из памяти
	// *phead - указатель на заглавное звено списка
	struct node* q, * q1; // Рабочие указатели
	q = phead;
	q1 = (*q).sled; // Указатель q1 "опережает" указатель q.
	while (q1 != NULL) {
		q = q1;
		q1 = (*q1).sled;
		delete q;
	}
	delete phead; // Удаление заглавного звена
}
int main() {
	setlocale(0, "");
	Spisok nazva;
	nazva.POSTROENIE();
	nazva.VYVOD();
	nazva.OCHISTKA();
	return 0;
}