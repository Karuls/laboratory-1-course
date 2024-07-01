#include<iostream>
#include<stdio.h>
int main() {
	FILE* g;
	FILE* f;
	setlocale(LC_ALL, "rus");
	char str1[50], str2[50], str3[50], str4[50], str5[50], str6[50];

	fopen_s(&f, "F1.txt", "w");
	 
	printf("¬ведите сторок є 1");
	gets_s(str1);
	fputs(str1, f);
	fputs("\n", f);

	printf("¬ведите сторок є 2");
	gets_s(str2);
	fputs(str2, f);
	fputs("\n", f);

	printf("¬ведите сторок є 3");
	gets_s(str3);
	fputs(str3, f);
	fputs("\n", f);

	printf("¬ведите сторок є 4");
	gets_s(str4);
	fputs(str4, f);
	fputs("\n", f);

	printf("¬ведите сторок є 5");
	gets_s(str5);
	fputs(str5, f);
	fputs("\n", f);

	printf("¬ведите сторок є 6");
	gets_s(str6);
	fputs(str6, f);
	fputs("\n", f);

	fclose(f);

	fopen_s(&f, "F1.txt", "r");// открыли дл€ чтени€
	fopen_s(&g, "F2.txt", "w");// открыли дл€ записи

	int i = 0;
	while (fgets(str1, sizeof(str1), f) != nullptr)
	{
		if (str1 == NULL);  // —читаем кол-во строк; если строка закончилась i++
		i++; 
		if (i%2 == 0) { // ≈сли строка четна€, записываем ее в F2
			fputs(str1, g);
		} 
	}

	

	fclose(f);
	fclose(g);
}