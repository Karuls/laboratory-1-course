#include <iostream>
#include <Windows.h>
#include <vector>
#include <string>
#include <chrono>
using namespace std;
struct person {
    string lastname;
    string firstname;
    string patronimic;
    int tel;
};

int currentsize = 0;

class Hashtable {
private:
    vector<vector<person>> table;
public:
    Hashtable() {
        table.resize(currentsize);
    }

    int hashfunc(int copynum) {
        int sum = 0;
        while (copynum) {
            sum += (copynum % 10);
            copynum /= 10;
        }
        return sum % currentsize;
    }

    void add(person pers) {
        int index = hashfunc(pers.tel);
        table[index].push_back(pers);
    }

    void del(int te) {
        int index = hashfunc(te);
        if (table[index].empty()) {
            cout << "Такого человека нет в списке\n";
        }
        else {
            bool t = false;
            for (int i = 0; i < table[index].size(); i++) {
                if (te == table[index][i].tel) {
                    table[index].erase(table[index].begin() + i);
                    t = true;
                    break;
                }
            }
            if (!t) {
                cout << "Такого человека нет в списке\n";
            }
        }
    }

    void search(int te) {
        int index = hashfunc(te);
        if (table[index].empty()) {
            cout << "Такого человека нет в списке\n";
        }
        else {
            bool t = false;
            for (int i = 0; i < table[index].size(); i++) {
                if (te == table[index][i].tel) {
                    cout << "Информация найдена\n" << "Она находится в ячейке с индексом " << index << " в " << i + 1 << " месте этой ячейки\n";
                    t = true;
                    break;
                }
            }
            if (!t) {
                cout << "Такого человека нет в списке\n";
            }
        }
    }

    void output() { // функция для вывода элементов хэш-таблицы
        for (int i = 0; i < table.size(); i++) {
            cout << "Ячейка с индексом " << i << '\n';
            if (table[i].empty()) {
                cout << "Пусто\n";
                cout << '\n';
            }
            else {
                for (int j = 0; j < table[i].size(); j++) {
                    cout << "Фамилия: " << table[i][j].lastname << '\n';
                    cout << "Имя: " << table[i][j].firstname << '\n';
                    cout << "Отчество: " << table[i][j].patronimic << '\n';
                    cout << "Телефон: " << table[i][j].tel << '\n';
                    cout << '\n';
                }
            }
        }
    }

};

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    int choice;
    string b;
    cout << "Введите размер таблицы\n";
    getline(cin, b);
    currentsize = stoi(b);
    Hashtable table;
    for (;;)
    {
        cout << "1 - вывод хеш-таблицы на экран\n";
        cout << "2 - добавить элемент\n";
        cout << "3 - удалить элемент\n";
        cout << "4 - найти элемент по ключу\n";
        cout << "0 - выход\n";
        cout << "сделайте выбор\n";
        getline(cin, b);
        while (b.length() != 1) {
            cout << "Некорректный ввод\n";
            getline(cin, b);
        }
        choice = b[0];
        switch (choice)
        {
        case '0':  exit(0);
        case '1': {
            table.output();
            break;
        }
        case '2': {
            person buf;
            cout << "введите Фамилию\n";
            getline(cin, b);
            buf.lastname = b;
            cout << "введите имя\n";
            getline(cin, b);
            buf.firstname = b;
            cout << "введите отчество\n";
            getline(cin, b);
            buf.patronimic = b;
            cout << "введите номер телефона\n";
            getline(cin, b);
            buf.tel = stoi(b);
            table.add(buf);
            break;
        }
        case '3': {
            cout << "введите номер телефона\n";
            getline(cin, b);
            table.del(stoi(b));
            break;
        }
        case '4': {
            cout << "введите номер телефона\n";
            getline(cin, b);
            auto start = chrono::high_resolution_clock::now();
            table.search(stoi(b));
            auto end = chrono::high_resolution_clock::now();
            auto time = chrono::duration_cast<std::chrono::microseconds>(end - start);
            cout << "Время поиска " << time.count() << "мкс\n";
            break;
        }
        default:  cout << "\nВведена неверная команда!\n";
        }
    }
    return 0;
}