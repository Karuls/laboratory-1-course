//1. ����������� �� ����� FILE1 � ���� FILE2 ��� ������, � ������� ��� ����, 
// ����������� � ������ ������. ���������� ���������� ��������� ���� � ������ ������ ����� FILE2.
#include <iostream>
#include <fstream>
#include <Windows.h>
using namespace std;
int main() {
   
	setlocale(LC_CTYPE, "rus");
	SetConsoleCP(1251);

	ifstream file1_read("FILE1.txt"); // ������ �� ����� FILE1.txt 
	ofstream filew2("FILE2.txt"); // ������ � FILE2.txt

	char buf[250], reg[20];
	string word_buffer, dif_word;

	int count = 0, max_vowels = 0;
	int helper; // ��� ����������� ���������� �����, ��� ������ ���������
	int j = 0; // ������� ��������� �����
	bool flag = false; // ���� ��� ������ ������ ������� �����
	bool flag_word = false; // ���� ��� ������ ������, ���� ���� ���������� �����
	bool vowels = false; // ���� ��� �������� ������ ������ ������

	while (file1_read.getline(buf, 250)) { // ������ ������ ������

		flag = false; // ���������
		flag_word = false;
		helper = 0;
        memset(reg, 0, sizeof reg); // ������� ������ reg
		for (int i = 0; i < strlen(buf); i++) {
			
				reg[j] = buf[i]; // ���������� ������� � ������ reg
				j++;

			if (vowels == false) {
			if (buf[i] == 'a'|| buf[i] == 'e' || buf[i] == 'i' || buf[i] == 'o' || buf[i] == 'u' || buf[i] == 'y') { // ������� ��������
				count++;
			}
			}

			if (buf[i] == ' ' || buf == NULL) { // ���� ����� ����� ������� ��� ����� �������
				
				if (flag == false) {// ������ ����� � �����
					word_buffer = reg;
					flag = true;
				}

                dif_word = reg; // ������ �����

				if (helper != 0) {
					if (word_buffer == dif_word) { // ��������� ������� ����� � ������������
						flag_word = true;
					}
				}
				helper += 1;
			
				memset(reg, 0, sizeof reg); // ������� ������ reg
				j = 0;
			}
			
		}
		
		if (flag_word == true) { // ���� ���� ���������� �����
			cout << "� ���������� ���� ������������� �����" << endl;
			filew2 << buf << endl;
		}
		else {
			cout << "������ �� ���� ��������, �� ������ �� ����� ���������� ����" << endl;
		}

		if (vowels == false) {
			cout << "���������� �������� � ������ ������: " << count <<endl;
		}
		vowels = true;
	}

	filew2.close();
	file1_read.close();

	cout << "��������� ���������" << endl;
	


}