#include<iostream>
#include <cmath>
#include<Windows.h>
using namespace std;
int main() {
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int X = 23;
	int Y = 24;
	int Z = 25;
	float S = 15;
	bool flag1 = false;
	bool flag2 = true;
	char name_ENG = 'e';
	wchar_t name_RUS = L'е';
	wchar_t name_eng = L'e';
	wchar_t name_rus = L'е';
	short count1 = X;
	short count2 = -X;
	short count3 = -32768;
	short count4 = 32767;
	unsigned short max_short = 0xFFFF;
	unsigned short min_short = 0x0000;
	int digit1 = Y;
	int digit2 = -Y;
	int max_int = 2147483647;
	int min_int = -2147483648;
	unsigned int max_value = 0xFFFFFFFF;
	unsigned int min_value = 0x00000000;
	long long_num1 = Z;
	long long_num2 = -Z;
	long long_min = pow(-2, 63);
	long long_max = pow(2, 63) - 1;
	unsigned long unsigned_long_max = 0xFFFFFFFFUL;
	unsigned long unsigned_long_min = 0x00000000UL;
	float float_num1 = S;
	float float_num2 = -S;
	float inf = S/0;
	float neg_inf = -S/0;
	float ind = inf/neg_inf;

    char ch = 'a';

	int (*operation)(int, int);
	int add(int a, int b);
	int multiply(int a, int b);

	wchar_t wch = L'b';
	short sh = 10;
	int i = 20;
	float f = 30.5f;
	double d = 40.7;

	char* ptr_ch = &ch;
	wchar_t* ptr_wch = &wch;
	short* ptr_sh = &sh;
	int* ptr_i = &i;
	float* ptr_f = &f;
	double* ptr_d = &d;

	return 0;
}
