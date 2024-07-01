#include<iostream>
#include<ctime>
using namespace std;
int main() {
	setlocale(0, "");
	int N;
	cout << "������� ���������� ��������: ";
	cin >> N;

	int* mass = new int[N]; srand(time(NULL));

	for (int i = 0; i < N; i++)
	{
		mass[i] = rand() % 10;
	}

	for (int i = 0; i < N; i++)
	{
		cout << i << ". " << mass[i] << endl;
	} cout << endl;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N - 1; j++) {
			if (mass[j] < mass[j + 1]) {
				swap(mass[j], mass[j + 1]);
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		cout << i << ". " << mass[i] << endl;
	} cout << endl;


	int first = mass[0], second = 0, third = 0;
	bool help = false; bool help2 = false;
	for (int i = 0; i < N; i++)
	{
		if (mass[i] < first && help == false) {
			 second = mass[i]; help = true;
		}
		if (mass[i] < second && help2 == false) {
			third = mass[i]; help2 = true;
		}
		}

	

	int count = 0;
	for (int i = 0; i < N; i++)
	{
		if (mass[i] == first || mass[i] == second || mass[i] == third) {
			count++;
		}
	}cout << endl;
	cout << "1 �����: " << first << " ������" << endl;
	cout << "2 �����: " << second << " ������ " << endl;
	cout << "3 �����: " << third << " ������" << endl;
	cout << "����� ��������: " << count << endl;


	delete[] mass;
	
} /*������ 2
�� ����������� ��������� ��������� ������������ ���������. ��������� ���������� ����� �������� ������� ���������� �������. �������� ��������� ��������� ��������, ���������� ������ �� ���� III �������.
�� ����������� ��������� ���������� ���������� ��������. 
����: ����������� ����� �������� (N < 10000) � ����� N ����������� ����� � ���������� ���������� (������������� �� 1 �� 100)
�����: ���� ����� � ����� ��������.
*/