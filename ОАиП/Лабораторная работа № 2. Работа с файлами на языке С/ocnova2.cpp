#include <iostream>
#include <stdio.h>  

int main() {
    setlocale(LC_ALL, "");
    const int SIZE = 10;
    FILE* f;
    FILE* g;
    int str[SIZE] = { 1, 2, 1, 2, 5, 6, 7, 8 ,9, 4 };
    int encountered[SIZE] = { 0 }; // Массив для отслеживания встреченных чисел
    int number;

   
    fopen_s(&f, "task1.txt", "w");  // Открытие файла для записи

    for (int i = 0; i < SIZE; i++) {
        fprintf(f, "%d ", str[i]);
    }

    printf("\nМассив загружен в task1.txt\n");
    fclose(f);

    
    fopen_s(&f, "task1.txt", "r");// Открытие файла для чтения

    printf("Содержимое файла task1.txt:\n");

   
    fopen_s(&g, "task1212.txt", "w"); // Открытие файла для записи

                                                 
    while (fscanf_s(f, "%d", &number) == 1) {     // Пока есть числа для считывания из файла f
        // Проверяем, встречалось ли это число ранее
        if (!encountered[number]) { 
            
            fprintf(g, "%d ", number);  // Если число еще не встречалось записываем его в файл g
            // Помечаем число как встреченное
            encountered[number] = 1;
        }
    }

    fclose(f);
    fclose(g);

    return 0;
}
