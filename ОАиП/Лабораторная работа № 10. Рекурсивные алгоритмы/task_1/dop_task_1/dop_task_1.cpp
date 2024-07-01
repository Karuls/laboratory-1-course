#include <iostream>
#include <fstream>

using namespace std;

// Функция для записи числа в файл
void writeToFile(char* currentNumber, int length, ofstream& file) {
    for (int i = 0; i < length; ++i) {
        cout << currentNumber[i];
        file << currentNumber[i];
    }
    cout << endl;
    file << endl;
}

// Функция для генерации чисел рекурсивно
void generate(int A, char* currentNumber, int currentLength, ofstream& file) {
    if (currentLength == A) {
        writeToFile(currentNumber, A, file); // Записываем число в файл
        return;
    }
    for (int digit = 1; digit <= A; ++digit) {
        bool validDigit = true;
        if (currentLength > 0) {
            int lastDigit = currentNumber[currentLength - 1] - '0';
            if (lastDigit > digit)
                validDigit = false;
        }
        if (validDigit) {
            currentNumber[currentLength] = '0' + digit;
            generate(A, currentNumber, currentLength + 1, file);
        }
    }
}

// Функция для генерации чисел
void genNum(int A) {
    ofstream outputFile("output.txt");
    if (!outputFile) {
        cerr << "Unable to create output file!" << endl;
        return;
    }
    char currentNumber[10]; // Предполагаем, что максимальная длина числа - 10 цифр
    generate(A, currentNumber, 0, outputFile);
    outputFile.close();
}

int main() {
    setlocale(0, "");
    int A;
    cout << "Введите цифру A: ";
    cin >> A;
    genNum(A);
    cout << "Генерация чисел завершена. Результаты записаны в файл output.txt." << endl;
    return 0;
}
