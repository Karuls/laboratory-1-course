#include<iostream>
#include<fstream>
#include<cstring> // ��� ������������� ������� strlen
using namespace std;

int main() {
    setlocale(LC_ALL, "RUS");
    ofstream file1_write("FILE1.txt");
    ifstream file1_read("FILE1.txt"); // ������ �� ����� FILE1.txt 
    char buffer[250], word[250];
    string buf;

    cout << "������� ������, ��������� �� ���� � ����, ����������� ���������" << endl;
    cin.getline(buffer, 250); // ���������� cin ��� ������ ������
    file1_write << buffer;
    file1_write.close();

    file1_read.getline(buffer, 250);
    file1_read.close();
    int count = 0, g = 0, max_count = 0, word_count = 0, number_word;
    for (int i = 0; i < strlen(buffer); i++) {

        word[g] = buffer[i];
        count++;
        g++;

        if (buffer[i] == ' ') {
            count--; //������� �� �������� ������
            word_count++;
            if (count > max_count) { // ���������� ���-�� �������� ����������� ����� � ��� ������
                max_count = count;
                buf = word;
                number_word = word_count;
            }

            count = 0;
            memset(word, 0, sizeof word); // ������� ������ word
            g = 0; // ���������� ������ ��� ������ �����
        }

    }

    cout << "���-�� �������� � ����� ������� �����: " << max_count << endl;
    cout << "���� ��� �����: " << buf << endl;
    return 0; 
}
