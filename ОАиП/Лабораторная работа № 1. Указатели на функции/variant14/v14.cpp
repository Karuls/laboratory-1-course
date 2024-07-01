#include <iostream>
#include <stdio.h> // Для get_s();
#include <stdarg.h>// Для макросов
using namespace std;

void compr(int count, ...); //Глобально инициализируем ф-цию с пересенным кол-вом значений

int main() {
    setlocale(LC_ALL, "rus");
    char str1[90], str2[90], str3[90];
    int count = 3;

    cout << "Введите первую строку" << endl;
    gets_s(str1, 90);
    cout << "Введите вторую строку" << endl; //Вводим строки
    gets_s(str2, 90);
    cout << "Введите третью строку" << endl;
    gets_s(str3, 90);

    cout << "1-е обращение" << endl;
    compr(count-1, str1, str3); // Вызываем функию сжатияй
    cout << endl;
    cout << "2-е обращение" << endl;
    compr(count, str3, str2, str1);
    cout << endl;
    cout << "3-е обращение" << endl;
    compr(count, str2, str1, str3);

    return 0;
}

void compr(int count, ...) { 
    va_list arg; // Объявляем указатель 
    va_start(arg, count); // Инициализируем указатель на первый аргумент
    for (int i = 0; i < count; ++i) { 
        char* m = va_arg(arg, char*); // Получаем очередной аргумент
        for (int j = 0; m[j] != '\0'; j++) { 
            if (m[j] != ' ') { 
                cout << m[j]; 
            }
        }
    }
    va_end(arg); // Завершаем работу с аргументами
}
