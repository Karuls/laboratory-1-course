#include<iostream>
#include <time.h> 
int recurs(int);
using namespace std;

int main() {

	setlocale(LC_ALL, "rus");
	int f0 = 0, f1 = 1;
	int N, next = 0;
	int munites = 0;

	cout << "������� N-����� ������������������ ���������" << endl;
	cin >> N; 
	
	if (N <= 0) {
		cout << "������� ������������� ������������� ��������. " << endl;
	}
	else {

	

	clock_t start = clock();
	cout << "����� " << N << " ��������� ����� �������� = " << abs(recurs(N-1)) << endl; 
	clock_t end = clock();

	int seconds = (double)(end - start) / CLOCKS_PER_SEC;

	if (seconds > 60) {
		munites = seconds / 60;
		seconds = seconds - (munites * 60);
	}
	else {
		munites = 00;
	}

	cout << "��������� ����� ��������� "<< munites <<" �����/a " << seconds << " ������. " << endl;

	
	start = clock();
	for (int i = 0; i < N-2; i++) {
		next = f1 + f0;
		f0 = f1;
		f1 = next;
		
	}
	cout << "����� ��������� ����� ����: " << abs(next) << endl;

	end = clock();
	seconds = (double)(end - start) / CLOCKS_PER_SEC;

	if (seconds > 60) {
		munites = seconds / 60;
		seconds = seconds - (munites * 60);

	}
	else {
		munites = 00;
	}

	cout << "��������� ����� ������ " << munites << " �����/a " << seconds << " ������." << endl;
	}
}
	int recurs(int N) {
		if (N == 0) {
			return 0;
		}
		else if (N == 1) {
			return 1;
		}
		else {
			
			return recurs(N - 1) + recurs(N - 2);
		}
		
	
}