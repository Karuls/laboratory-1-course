#include<iostream>
using namespace std;

class Spisok
{
private:
	struct node
	{
		int elem;
		node* sled;
	} *phead; // ��������� �� ������ ������
public:
	Spisok() {
		phead = new(node);
		(*phead).sled = NULL;
	}// �����������
	~Spisok() { delete& phead; }// ����������
	void POSTROENIE();

	void VYVOD();
	void OCHISTKA();
};

void Spisok::POSTROENIE() {
	node* t;
	int el;
	phead = new (node);
	t = phead; (*t).sled = NULL;
	cout << "������� �������� ������� ������: ";
	cin >> el;
	while (el != 0) {
		(*t).sled = new(node); t = (*t).sled;
		(*t).elem = el; (*t).sled = NULL;
		cin >> el;
	}
}

void Spisok::VYVOD()
// ����� ����������� ���������������� ��������� ������
// � ��������� ������
// phead - ��������� �� ��������� ����� ������
{
	node* t;
	t = (*phead).sled;
	cout << " ������ :";
	while (t != NULL) {
		cout << (*t).elem << " ";
		t = (*t).sled;
	}
	cout << endl;
}

void Spisok::OCHISTKA() {
	// �������� �������������� ������ �� ������
	// *phead - ��������� �� ��������� ����� ������
	struct node* q, * q1; // ������� ���������
	q = phead;
	q1 = (*q).sled; // ��������� q1 "���������" ��������� q.
	while (q1 != NULL) {
		q = q1;
		q1 = (*q1).sled;
		delete q;
	}
	delete phead; // �������� ���������� �����
}
int main() {
	setlocale(0, "");
	Spisok nazva;
	nazva.POSTROENIE();
	nazva.VYVOD();
	nazva.OCHISTKA();
	return 0;
}