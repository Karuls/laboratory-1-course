// ������ c ���������� ������ ��������, ��������� �� ����,
// ����������� ���������, � �������� �� � ����. 
// // ��������� �� ����� ������ � ������� ��� �����, ������� �������� ����� ��.
#include<iostream>
#include<fstream>
#include<Windows.h>
using namespace std;
int main() {
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);

	ofstream file1_write("FILE1.txt");
	ifstream file1_read("FILE1.txt");
	char buffer[250], reserve[250], word[50];

	cout << "������� ������: " << endl;

	cin.getline(buffer, 250);
	file1_write << buffer;
	file1_write.close();

	
	bool flag = false;
	int j = 0;
	while (file1_read.getline(reserve, 250)) {
		memset(word, 0, sizeof word); // ������� ������
		for (int i = 0; i < strlen(buffer); i++) {

			word[j] = buffer[i]; // ������ �����
			j++;

			if (buffer[i] == 'r') { // �������� �� r
				flag = true;
			}

			if (buffer[i] == ' ') {
				j = 0; // ��������� ��������

				if (flag == true) {
					cout <<"����� � ������ r: " << word << endl;
					flag = false; // �������� ����
				}
				memset(word, 0, sizeof(word));

			}


		}
	}

}