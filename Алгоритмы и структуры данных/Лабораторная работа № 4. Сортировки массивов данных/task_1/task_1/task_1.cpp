#include<iostream>
#include<ctime>
using namespace std;
int main() {
	setlocale(0, "");
	int N;
	cout << "������� ���������� ������� � ����: ";
	cin >> N;

	int* mass = new int[N]; srand(time(NULL));

	for (int i = 0; i < N; i++)
	{
		mass[i] = rand() % 50;
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
	}cout << endl;

	int* buf = new int[N];
	int count = N-1;
	int helper = 0, j = 0, sum = 0;
	for (int i = 0; i < N; i++) {
		
		if (i == 0){
			buf[i] = mass[j]; j++;
		}
		if (i % 2 != 0){
			buf[i] = mass[count]; count = count - 1;
		}
		if (i % 2 == 0 && helper!= 0) {
			buf[i] = mass[j]; j++;
	    }	
		helper = 1;
		cout << buf[i]<<' ';
		}

	for (int i = 0; i < N; i++)
	{
		if (i == 0 || i % 2 == 0) {
			sum += buf[i];
	}

	}
	cout << "������������ ����� ����: " << sum<<endl;
	


	delete[] mass;
	delete[] buf;
}
/*� ���� ��������� "���-�����" ���������� ��������� �����. ������ ������ ����� � ���������. �����������, �������� ���� �������� ��������� ������ � ����� �������, ����� ������� ������� ��� ����� ������ �����.
�� ������ ������� ���������� ������������ ����� � ����. 
����: ����������� ����� ������� (N < 10000) � ����� N ����������� ����� � ���� �������. ���� ������ ������������� (��������, �� 1 �� 100).
�����:  ������� ���������� �� ����� � ����� � ������������ ����� ����.
*/