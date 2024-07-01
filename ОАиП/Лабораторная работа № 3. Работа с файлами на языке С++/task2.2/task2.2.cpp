#include<iostream>
#include<fstream>
#include<cstring> // Для использования функции strlen
using namespace std;

int main() {
    setlocale(LC_ALL, "RUS");
    ofstream file1_write("FILE1.txt");
    ifstream file1_read("FILE1.txt"); // чтение из файла FILE1.txt 
    char buffer[250], word[250];
    string buf;

    cout << "Введите строку, состоящую из цифр и слов, разделенных пробелами" << endl;
    cin.getline(buffer, 250); // Используем cin для чтения строки
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
            count--; //Убираем из счетчика пробел
            word_count++;
            if (count > max_count) { // Нахождение кол-ва символов длиннейшего слова и его самого
                max_count = count;
                buf = word;
                number_word = word_count;
            }

            count = 0;
            memset(word, 0, sizeof word); // Очищаем массив word
            g = 0; // Сбрасываем индекс для нового слова
        }

    }

    cout << "Кол-во символов в самом длинном слове: " << max_count << endl;
    cout << "Само это слово: " << buf << endl;
    return 0; 
}
