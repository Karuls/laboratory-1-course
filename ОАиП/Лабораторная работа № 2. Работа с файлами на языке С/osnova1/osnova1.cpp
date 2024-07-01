#include <iostream>
#include <stdio.h>


int main() {
    setlocale(LC_ALL, "RUS");
    using namespace std;
    FILE* f;
    FILE* g;
    char str1[50];
    int str2[5];
    int number = 0; int num;
 

    printf("Введите номер столбца, который хотите записать в файл: ");
    scanf_s("%d", &number); 


    fopen_s(&f, "ffff.txt", "r");  // Открытие файла для чтения 
    if (f == nullptr) { // проверка
        cout << "Ошибка открытия файла ffff.txt\n";
        return 1;
    }

    fscanf_s(f, "%d", &num); // num = 1 строка для получения кол-ва столбцов

    if ((int)num < number || number < 1) {
        printf("В файле нет столько столбцов ");
        return 0;
     }
    else {

    fopen_s(&g, "gggg.txt", "w"); // Открытие файла для записи
    if (g == nullptr) { // проверка
        cout << "Ошибка создания файла gggg.txt\n";
        return 1;
    }

    
    int stolbec;
    while (fgets(str1, sizeof(str1), f) != nullptr) { // читаем строки, пока файл не кончится
        for (int i = 0; i < number; i++) { // читает строки

            if (i == (number - 1)) { // остановка перед заданным числом
                stolbec = str1[i] - '0';  // Отниманимаю '0' тк принимаем кодироку, а не число
                fprintf(g, "%d", stolbec);
                fputs("\n", g);
                break; // пропускаем цикл
                
            }
        }
    }
    printf("Указанный столбец записан в gggg.txt \n");

 

    fclose(f);
    fclose(g);
    return 0;
}
 }