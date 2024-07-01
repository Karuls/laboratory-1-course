#include <iostream>
#include <fstream>
using namespace std;

int write(ofstream& fout, int size);
void read(char buffer[250]);

int main() {
    setlocale(LC_CTYPE, "rus");
    int size, weihth;
    char buffer[250], str[250], readBuffer[250]; // Изменили имя массива на readBuffer
    ifstream ifile("t.txt"); // создание объекта ifile класса ifstream для чтения 
    ofstream fout("t.txt"); // создание объекта fout класса ofstream для записи 
    ofstream file("a.txt"); // создание объекта file класса ofstream для записи 

    cout << "Введите кол-во символов первой строки" << endl;
    cin >> size;

    weihth = write(fout, size); // Вызов функции записи
    if (size > weihth) {
        cout << "\n Ваша строка меньше, чем кол-во символов\n";
        return 0;
    }

    ifile.getline(buffer, 250); // Чтение и запись в buffer

    for (int i = 0; i < strlen(buffer); i++) { // Пока размер buffer больше i
        file << buffer[i]; //Записываем символ
        if (i == size) { // если i = введенному размеру строки
            file << endl; //Передаём конец строки
        }
    }
    file.close(); // Закрываем файл


    read(readBuffer); // Читаем содержимое файла a.txt после его записи

    ifile.close(); // Закрываем файл t.txt

    return 0;
}

int write(ofstream& fout, int size) {
    char str[250];
    cout << "Введите строку" << endl;
    cin.ignore(); // Игнорируем символ новой строки во входном буфере
    cin.getline(str, 250);
    fout << str; // Передаем в файл
    fout.close(); // закрываем

    return strlen(str); // передаём длинну строки
}

void read(char buffer[250]) { // Чтение Файла
    ifstream file_a("a.txt"); // Открываем файл заново для чтения
    cout << "Получили: " << endl;
    while (file_a.getline(buffer, 250)) {
        cout << buffer << endl;
    }
    file_a.close(); // Закрываем файл
}
