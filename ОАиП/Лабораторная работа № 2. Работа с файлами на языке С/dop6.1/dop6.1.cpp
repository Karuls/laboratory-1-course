#include <stdio.h>
#include<iostream>
// ������:
// ���������� ����� fA � ������������ ����� (������������� � �������������). ���������� � ������� �� ����� ���������� ����� ���� �� ���,
//������� �������� ������ � ���������� ������������� ������ �����.

int main() {
	FILE* f;
	int str[50], x;
	int difference, mindifference = 999, count, number;
	setlocale(LC_ALL, "rus");

	printf("������� ����� �: ");
	scanf_s("%d", &x);

	fopen_s(&f, "fileA.txt", "r");  // �������� �������� �����
	
	int i = 0;
	while (fscanf_s(f, "%d", &str[i]) == 1) { // ������ ����� �� ����� � ������� ���-��
		i++;
	}

	for (int j = 0; j < i; j++) {
		difference = abs(x - str[j]); // ������� �������
		if (mindifference > difference) { // ������� ����������� �������
			mindifference = difference;
			number = j+1; // ����� ��������
			count = str[j]; // �������
		}
		
	}

	printf("���������� ����� ���������� �����:\n");
	printf("%d\n", number);
	printf("���� �����: \n");
	printf("%d\n", count);

	
	fclose(f);

	return 0;
}
