#include <stdio.h>
#include<iostream>
// Задача:
// Компоненты файла fA – вещественные числа (положительные и отрицательные). Определить и вывести на экран порядковый номер того из них,
//которое наиболее близко к введенному пользователем целому числу.

int main() {
	FILE* f;
	int str[50], x;
	int difference, mindifference = 999, count, number;
	setlocale(LC_ALL, "rus");

	printf("Введите число х: ");
	scanf_s("%d", &x);

	fopen_s(&f, "fileA.txt", "r");  // Проверка открытия файла
	
	int i = 0;
	while (fscanf_s(f, "%d", &str[i]) == 1) { // Читаем числа из файла и считаем кол-во
		i++;
	}

	for (int j = 0; j < i; j++) {
		difference = abs(x - str[j]); // считаем разницу
		if (mindifference > difference) { // считаем минимальную разницу
			mindifference = difference;
			number = j+1; // Номер элемента
			count = str[j]; // элемент
		}
		
	}

	printf("Порядковый номер ближайшего числа:\n");
	printf("%d\n", number);
	printf("Само число: \n");
	printf("%d\n", count);

	
	fclose(f);

	return 0;
}
