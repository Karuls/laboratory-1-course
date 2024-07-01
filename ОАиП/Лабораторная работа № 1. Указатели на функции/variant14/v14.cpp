#include <iostream>
#include <stdio.h> // ��� get_s();
#include <stdarg.h>// ��� ��������
using namespace std;

void compr(int count, ...); //��������� �������������� �-��� � ���������� ���-��� ��������

int main() {
    setlocale(LC_ALL, "rus");
    char str1[90], str2[90], str3[90];
    int count = 3;

    cout << "������� ������ ������" << endl;
    gets_s(str1, 90);
    cout << "������� ������ ������" << endl; //������ ������
    gets_s(str2, 90);
    cout << "������� ������ ������" << endl;
    gets_s(str3, 90);

    cout << "1-� ���������" << endl;
    compr(count-1, str1, str3); // �������� ������ �������
    cout << endl;
    cout << "2-� ���������" << endl;
    compr(count, str3, str2, str1);
    cout << endl;
    cout << "3-� ���������" << endl;
    compr(count, str2, str1, str3);

    return 0;
}

void compr(int count, ...) { 
    va_list arg; // ��������� ��������� 
    va_start(arg, count); // �������������� ��������� �� ������ ��������
    for (int i = 0; i < count; ++i) { 
        char* m = va_arg(arg, char*); // �������� ��������� ��������
        for (int j = 0; m[j] != '\0'; j++) { 
            if (m[j] != ' ') { 
                cout << m[j]; 
            }
        }
    }
    va_end(arg); // ��������� ������ � �����������
}
