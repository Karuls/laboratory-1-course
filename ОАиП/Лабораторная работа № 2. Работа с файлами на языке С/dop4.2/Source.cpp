#include <stdio.h>
#include <iostream>
int main() {
	FILE* f;
	FILE* g;
	int str[50], x;
	setlocale(LC_ALL, "rus");

	printf("������� ����� �: ");
	scanf_s("%d", &x);

	fopen_s(&f, "f.txt", "r");  // ������� ��� ������
	fopen_s(&g, "g.txt", "w");  // ������� ��� �����


	int i = 0;
	while (fscanf_s(f, "%d", &str[i]) == 1) { // ������ ����� �� �����
		i++;
	}

	for (int j = 0; j < i; j++) {
		if (str[j] > x) {
			fprintf(g, "%d ", str[j]); // ���������� ������������� ����� � ����
		}
	}

	printf("��������� ���������");

	fclose(g);
	fclose(f);

	return 0;
}
