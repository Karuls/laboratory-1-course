#include <iostream>
#include <stdio.h>
#include <cctype>

int main() {
    setlocale(LC_ALL, "RUS");
    using namespace std;
    FILE* f;
    FILE* g;
    char str1[50], str2[50], str3[50], str4[50], str5[50];
    bool flag = true;

    fopen_s(&f, "ffff.txt", "w");  // Открытие файла для записи
    if (f == nullptr) { //проверка на открытие
        cout << "Ошибка открытия файла ffff.txt\n";
        return 1;
    }

    printf("Введите строку №1: "); // вносим строки в файл
    gets_s(str1);
    fwrite(str1, strlen(str1), 1, f);
    fputs("\n", f);

    printf("Введите строку №2: ");
    gets_s(str2);
    fwrite(str2, strlen(str2), 1, f);
    fputs("\n", f);

    printf("Введите строку №3: ");
    gets_s(str3);
    fwrite(str3, strlen(str3), 1, f);
    fputs("\n", f);

    printf("Введите строку №4: ");
    gets_s(str4);
    fwrite(str4, strlen(str4), 1, f);
    fputs("\n", f);

    printf("Введите строку №5: ");
    gets_s(str5);
    fwrite(str5, strlen(str5), 1, f);
    fputs("\n", f);

    printf("\nСтроки загружены\n");
    fclose(f);

    fopen_s(&f, "ffff.txt", "r");  // Открытие файла для чтениия
    if (f == nullptr) {// проверка
        cout << "Ошибка открытия файла ffff.txt для чтения\n";
        return 1;
    }

    fopen_s(&g, "gggg.txt", "w"); // Открытие файла для записи
    if (g == nullptr) { // проврка
        cout << "Ошибка создания файла gggg.txt\n";
        return 1;
    }

    
    while (fgets(str1, sizeof(str1), f) != nullptr) { // получаем строки до конца файла
        flag = true; // Сбрасываем флаг перед каждой новой строкой
        for (int i = 0; str1[i] != '\0'; i++) {
            if (isdigit(str1[i])) { // Проверка на цифру
                flag = false;
                break; // прекращаем цикл for
            }
        }
        if (flag == true) { // Если в строке нет цифр, записываем ее в файл gggg.txt
            fputs(str1, g); // записивываем строку 
        }
    }

    fclose(f);
    fclose(g);
    return 0;
}
