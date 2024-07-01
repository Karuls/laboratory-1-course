#include<iostream>
#include <cstdarg>
using namespace std;
void fmin(int count, ...);

int main() {
    setlocale(LC_ALL, "rus");

    cout << "1-е обращение" << endl;
    fmin(6, 9, 4, 5, 7, 4, 12);
    cout << endl;
    cout << "2-е обращение" << endl;
    fmin(4, 1, 4, 6, 0);
    cout << endl;
    cout << "3-е обращение" << endl;
    fmin(2, 10, 1, 5, 4);
    cout << endl;

}

void fmin(int count, ...) {

    va_list arg; // ќбъ€вл€ем указатель 
    va_start(arg, count);// »нициализируем указатель на первый аргумент
    int max = va_arg(arg, int);// »нициализируем указатель на первый аргумент
    for (int i = 1; i < count; i++) {
        int cifra = va_arg(arg, int);
        if (max < cifra) {
            max = cifra;

        }

    }
    va_end(arg);
    cout << max << endl;
}