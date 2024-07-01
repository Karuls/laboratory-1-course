#include <stdio.h>
#include <iostream>
int main() {
	FILE* f;
	FILE* g;
	int str[50], x;
	setlocale(LC_ALL, "rus");

	printf("Введите число х: ");
	scanf_s("%d", &x);

	fopen_s(&f, "f.txt", "r");  // Открыли для чтения
	fopen_s(&g, "g.txt", "w");  // Открыли для ввода


	int i = 0;
	while (fscanf_s(f, "%d", &str[i]) == 1) { // Читаем числа из файла
		i++;
	}

	for (int j = 0; j < i; j++) {
		if (str[j] > x) {
			fprintf(g, "%d ", str[j]); // Записываем положительные числа в файл
		}
	}

	printf("Программа завершена");

	fclose(g);
	fclose(f);

	return 0;
}
