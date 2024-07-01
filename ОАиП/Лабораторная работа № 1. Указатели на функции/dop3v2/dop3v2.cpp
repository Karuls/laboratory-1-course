#include<iostream>
#include <cstdarg>
using namespace std;
void fmin(int count, ...);

int main() {
    setlocale(LC_ALL, "rus");

    cout << "1-� ���������" << endl;
    fmin(6, 9, 4, 5, 7, 4, 12);
    cout << endl;
    cout << "2-� ���������" << endl;
    fmin(4, 1, 4, 6, 0);
    cout << endl;
    cout << "3-� ���������" << endl;
    fmin(3, 10, 3, 1);
    cout << endl;

}

void fmin(int count, ...) {

    va_list arg; // ��������� ��������� 
    va_start(arg, count);// �������������� ��������� �� ������ ��������
    int sum = 0;
    for (int i = 1; i < (count+1); i++) {
       sum += va_arg(arg, int)*i; // ���������� sum � ��������� ����������, ���������� �� i
     

    }
    va_end(arg); // ��������� ������ � �����������
    cout << sum << endl;
}