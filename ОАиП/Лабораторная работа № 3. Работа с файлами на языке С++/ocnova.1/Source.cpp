#include <iostream>
#include <fstream>
using namespace std;

int main() {
	
	setlocale(LC_CTYPE, "rus");

	ifstream file1_read("FILE1.txt"); // чтение из файла FILE1.txt 
	ofstream filew("FILE1.txt"); // запись в FILE1.txt
	ofstream filew2("FILE2.txt"); // Запись в FILE2.txt

	char str[250], buffer[250], reg[20];
	string word_buffer;
 
	int count_of_a = 0, max_a = 0, number_word = 0, count_word = 0;
	int j = 0;
	bool flag = false;
	while (file1_read.getline(buffer, 250)) { // читаем каждую строку
		flag = false;
	for (int i = 0; i < strlen(buffer); i++) {

		reg[j] = buffer[i]; // Записываем сивмолы в массив reg
			j++;
		if (buffer[i] == 'a') { // счетчик символов а
	      count_of_a++;
		}
	     j++;

		if (buffer[i] == ' ' || buffer == NULL) { // если симол равен пробелу или концу стркоки
			count_word++; 

			if (count_of_a > max_a) { // условие для нахожления слова с наиб кол-вом 'a'
              max_a = count_of_a;
			  number_word = count_word;
			}
			
			if (word_buffer == reg) {
				flag = true;
			}
			word_buffer = reg; // запись слова в буфер

			memset(reg, 0, sizeof reg); // Очищаем массив reg
			j = 0; count_of_a = 0; // обнуление счетчика
		}

	}
	if (flag == true) { // если есть одинаковые слова
		cout << "В програамме есть повторяющиеся слова" << endl;
		filew2 << buffer;
	}
	else {
		cout << "Строки не былт записаны, тк строка не имеет одинаковых слов" << endl;
	}

	}
	filew2.close();
	file1_read.close();

	cout << "Программа завершена" << endl;
	cout << "Номер слова, в котором больше всего букв «а»: " << number_word << "( А именно: " << max_a << " )" << endl;


}