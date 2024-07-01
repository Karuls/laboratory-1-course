// Скопировать из файла FILE1 в файл FILE2 все строки, в которых есть слова,
//  совпадающие с первым словом. Определить количество букв в файле FILE2
#include <iostream>
#include <fstream>
#include <Windows.h>

int main() {
using namespace std;
	setlocale(LC_CTYPE, "rus");
	SetConsoleCP(1251);

	ifstream file1_read("FILE1.txt"); // чтение из файла FILE1.txt 
	ofstream filew2("FILE2.txt"); // Запись в FILE2.txt

	char buf[250], reg[20];
	string word_buffer, dif_word;

	int count = 0, max_vowels = 0;
	int helper; // Для сравнивания следующего слова, без ошибки программы
	int j = 0; // счетчик элементов слова
	bool flag = false; // Флаг для записи только первого слова
	bool flag_word = false; // Флаг для записи строки, если есть одинаковые слова
	int chet = 0;

	while (file1_read.getline(buf, 250)) { // читаем каждую строку

		flag = false; // Обнуление
		flag_word = false;
		helper = 0;
		memset(reg, 0, sizeof reg); // Очищаем массив reg
		for (int i = 0; i < strlen(buf); i++) {

			reg[j] = buf[i]; // Записываем сивмолы в массив reg
			j++; 

			if (isalpha(buf[i])) {
				chet++;
			}

			if (buf[i] == ' ' || buf == NULL) { // если симол равен пробелу или концу стркоки

				if (flag == false) {// запись слова в буфер
					word_buffer = reg;
					flag = true;
				}

				dif_word = reg; // запись слова

				if (helper != 0) {
					if (word_buffer == dif_word) { // сравнение первого слова с последующими
						flag_word = true;
					}
				}
				helper += 1;

				memset(reg, 0, sizeof reg); // Очищаем массив reg
				j = 0;
			}

		}

		if (flag_word == true) { // если есть одинаковые слова
			cout << "В програамме есть повторяющиеся слова" << endl;
			filew2 << buf<< endl;
		}
		else {
			cout << "Строки не былт записаны, тк строка не имеет одинаковых слов" << endl;
		}


	}


	cout << "Количество слов в FILE2.txt: " << chet << endl;
	cout << "Программа завершена" << endl;



}