#include <iostream>

int main() {
    setlocale(LC_ALL, "RUS");
    FILE* f;
    char str1[50];
    float x;
    float num1, num2, hsum, difference, mindifference = 999; 
    float count1, count2;

    printf("Введите цифру x: ");
    scanf_s("%f", &x);

    if (x > 8) { // проверка
        printf("Введите цифру: \n");
        return 1;
     }

    fopen_s(&f, "fileA.txt", "r");  // Проверка открытия файла
    if (f == nullptr) {
        perror("Ошибка открытия файла");
        return 1;
    }

   
    while (fgets(str1, sizeof(str1), f)) { // Читаем строку из файла
        for (int i = 0; i < sizeof(str1); i++) {
           // Здесь переменные получают кодировку числа, немного оригинальности
                if (i % 2 == 0) { 
                num1 = (str1[i] - '0'); // Отниманимаю '0' тк принимаем кодироку, а не число
                num2 = (str1[i + 1] - '0');
                hsum = (num1 + num2) / 2; // Среднее арифметическое
                difference = abs(hsum - x); // Разница

                if (mindifference > difference) { // нахождение мин разницы
                    mindifference = difference;   // и чисел ее нахождения
                    count1 = num1;
                    count2 = num2;
                }
            }
        }
    
    }

    printf("Два члена этой последовательности, среднее арифметическое которых ближе всего к числу х:\n");
    printf("%f, %f\n", count1, count2);
    printf("Разница: \n");
    printf("%f\n", mindifference);

    fclose(f);
    return 0;
}
