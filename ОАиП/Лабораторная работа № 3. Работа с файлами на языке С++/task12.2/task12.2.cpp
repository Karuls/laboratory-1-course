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

    cout << "������� ������: " << endl;
    getline(cin, buffer); //������
    file1_write << buffer;
    file1_write.close();

    while (getline(file1_read, reserve)) { // ������

        istringstream iss(reserve);
        while (iss >> number) { // �������� ������� ����� �� ������

            if (number % 2 != 0) { // ��������� �� ����������
                cout << number << endl;
            }

        }

    }
    file1_read.close();
    return 0;
}
