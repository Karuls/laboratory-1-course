#include<iostream>
#include<fstream>
using namespace std;

int main() {
    setlocale(LC_ALL, "RUS");

    ifstream file1_read("FILE1.txt"); // ������ �� ����� FILE1.txt 
    ofstream file2_write("FILE2.txt"); // ������ � ���� FILE2.txt


    char buffer[250];
    bool flag;
    int j = 0;

    while (file1_read.getline(buffer, 250)) { // ������ ������ ������
        flag = false;

        for (int i = 0; i < strlen(buffer); i++) {

            if (buffer[0] == 'A') { 
                flag = true;
            }

            if (buffer[i] == ' ') {
                j++;
            }
        }

        if (flag) { // ���������� ������ � ����,���� ���� true
            file2_write << buffer << endl;
        }
    }

    cout << "���� � FILE1.txt: " << j << endl;

    file1_read.close();
    file2_write.close();

    return 0;
}
