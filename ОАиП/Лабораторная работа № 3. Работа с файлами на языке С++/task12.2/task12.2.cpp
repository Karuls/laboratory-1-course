#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    setlocale(LC_ALL, "rus");

    ofstream file1_write("FILE1.txt");
    ifstream file1_read("FILE1.txt");

    string buffer, reserve;
    int number;

    cout << "Введите строку: " << endl;
    getline(cin, buffer); //Запись
    file1_write << buffer;
    file1_write.close();

    while (getline(file1_read, reserve)) { // Чтение

        istringstream iss(reserve);
        while (iss >> number) { // Пытаемся извлечь числа из строки

            if (number % 2 != 0) { // Проверяем на нечетность
                cout << number << endl;
            }

        }

    }
    file1_read.close();
    return 0;
}
