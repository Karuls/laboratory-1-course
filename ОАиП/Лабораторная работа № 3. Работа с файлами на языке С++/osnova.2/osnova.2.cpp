#include <iostream>
#include <fstream>
using namespace std;

int write(ofstream& fout, int size);
void read(char buffer[250]);

int main() {
    setlocale(LC_CTYPE, "rus");
    int size, weihth;
    char buffer[250], str[250], readBuffer[250]; // �������� ��� ������� �� readBuffer
    ifstream ifile("t.txt"); // �������� ������� ifile ������ ifstream ��� ������ 
    ofstream fout("t.txt"); // �������� ������� fout ������ ofstream ��� ������ 
    ofstream file("a.txt"); // �������� ������� file ������ ofstream ��� ������ 

    cout << "������� ���-�� �������� ������ ������" << endl;
    cin >> size;

    weihth = write(fout, size); // ����� ������� ������
    if (size > weihth) {
        cout << "\n ���� ������ ������, ��� ���-�� ��������\n";
        return 0;
    }

    ifile.getline(buffer, 250); // ������ � ������ � buffer

    for (int i = 0; i < strlen(buffer); i++) { // ���� ������ buffer ������ i
        file << buffer[i]; //���������� ������
        if (i == size) { // ���� i = ���������� ������� ������
            file << endl; //������� ����� ������
        }
    }
    file.close(); // ��������� ����


    read(readBuffer); // ������ ���������� ����� a.txt ����� ��� ������

    ifile.close(); // ��������� ���� t.txt

    return 0;
}

int write(ofstream& fout, int size) {
    char str[250];
    cout << "������� ������" << endl;
    cin.ignore(); // ���������� ������ ����� ������ �� ������� ������
    cin.getline(str, 250);
    fout << str; // �������� � ����
    fout.close(); // ���������

    return strlen(str); // ������� ������ ������
}

void read(char buffer[250]) { // ������ �����
    ifstream file_a("a.txt"); // ��������� ���� ������ ��� ������
    cout << "��������: " << endl;
    while (file_a.getline(buffer, 250)) {
        cout << buffer << endl;
    }
    file_a.close(); // ��������� ����
}
