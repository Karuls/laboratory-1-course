#include <iostream>
#include <fstream>
using namespace std;

int main() {
	
	setlocale(LC_CTYPE, "rus");

	ifstream file1_read("FILE1.txt"); // ������ �� ����� FILE1.txt 
	ofstream filew("FILE1.txt"); // ������ � FILE1.txt
	ofstream filew2("FILE2.txt"); // ������ � FILE2.txt

	char str[250], buffer[250], reg[20];
	string word_buffer;
 
	int count_of_a = 0, max_a = 0, number_word = 0, count_word = 0;
	int j = 0;
	bool flag = false;
	while (file1_read.getline(buffer, 250)) { // ������ ������ ������
		flag = false;
	for (int i = 0; i < strlen(buffer); i++) {

		reg[j] = buffer[i]; // ���������� ������� � ������ reg
			j++;
		if (buffer[i] == 'a') { // ������� �������� �
	      count_of_a++;
		}
	     j++;

		if (buffer[i] == ' ' || buffer == NULL) { // ���� ����� ����� ������� ��� ����� �������
			count_word++; 

			if (count_of_a > max_a) { // ������� ��� ���������� ����� � ���� ���-��� 'a'
              max_a = count_of_a;
			  number_word = count_word;
			}
			
			if (word_buffer == reg) {
				flag = true;
			}
			word_buffer = reg; // ������ ����� � �����

			memset(reg, 0, sizeof reg); // ������� ������ reg
			j = 0; count_of_a = 0; // ��������� ��������
		}

	}
	if (flag == true) { // ���� ���� ���������� �����
		cout << "� ���������� ���� ������������� �����" << endl;
		filew2 << buffer;
	}
	else {
		cout << "������ �� ���� ��������, �� ������ �� ����� ���������� ����" << endl;
	}

	}
	filew2.close();
	file1_read.close();

	cout << "��������� ���������" << endl;
	cout << "����� �����, � ������� ������ ����� ���� ��: " << number_word << "( � ������: " << max_a << " )" << endl;


}