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
    fmin(3, 10, 3, 1);
    cout << endl;

}

void fmin(int count, ...) {

    va_list arg; // Объявляем указатель 
    va_start(arg, count);// Инициализируем указатель на первый аргумент
    int sum = 0;
    for (int i = 1; i < (count+1); i++) {
       sum += va_arg(arg, int)*i; // Складываем sum с очередным аргументом, умноденным на i
     

    }
    va_end(arg); // Завершаем работу с аргументами
    cout << sum << endl;
}