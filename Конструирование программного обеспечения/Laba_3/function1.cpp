#include "stdafx.h"
#include "function1.h"


void calculate_day_number(int year) {
	using namespace std;
	int programmers_day = 255; // ���������� ������ � ����
	int first_summer_day = 152;
	int mums_day = 67;
	if (year % 4 == 0){
		programmers_day += 1;
		first_summer_day += 1;
		mums_day +=1;
		cout << "��������� ��� ���� �������� ����������" << endl;
	}
	else {
		cout << "��������� ��� ���� �� �������� ����������" << endl;
	}
	
}