#include<iostream>
#include<stdio.h>
int main() {
	FILE* g;
	FILE* f;
	setlocale(LC_ALL, "rus");
	char str1[50], str2[50], str3[50], str4[50], str5[50], str6[50];

	fopen_s(&f, "F1.txt", "w");
	 
	printf("������� ������ � 1");
	gets_s(str1);
	fputs(str1, f);
	fputs("\n", f);

	printf("������� ������ � 2");
	gets_s(str2);
	fputs(str2, f);
	fputs("\n", f);

	printf("������� ������ � 3");
	gets_s(str3);
	fputs(str3, f);
	fputs("\n", f);

	printf("������� ������ � 4");
	gets_s(str4);
	fputs(str4, f);
	fputs("\n", f);

	printf("������� ������ � 5");
	gets_s(str5);
	fputs(str5, f);
	fputs("\n", f);

	printf("������� ������ � 6");
	gets_s(str6);
	fputs(str6, f);
	fputs("\n", f);

	fclose(f);

	fopen_s(&f, "F1.txt", "r");// ������� ��� ������
	fopen_s(&g, "F2.txt", "w");// ������� ��� ������

	int i = 0;
	while (fgets(str1, sizeof(str1), f) != nullptr)
	{
		if (str1 == NULL);  // ������� ���-�� �����; ���� ������ ����������� i++
		i++; 
		if (i%2 == 0) { // ���� ������ ������, ���������� �� � F2
			fputs(str1, g);
		} 
	}

	

	fclose(f);
	fclose(g);
}