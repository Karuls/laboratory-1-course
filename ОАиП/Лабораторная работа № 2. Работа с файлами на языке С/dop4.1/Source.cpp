#include <stdio.h>
#include<iostream>
int main() {
	FILE* f;
	FILE* g;
	int str[50];
	setlocale(LC_ALL, "RUS");
	fopen_s(&f, "fileA.txt", "r");  // �������� �������� �����
	

	fopen_s(&g, "fileB.txt", "w");
	

	int i = 0;
	while (fscanf_s(f, "%d", &str[i]) == 1) { // ������ ����� �� �����
		i++;
	}

	for (int j = 0; j < i; j++) {
		if (str[j] > 0) {
			fprintf(g, "%d ", str[j]); // ���������� ������������� ����� � ����
		}
	}
	
	printf("������������� ����� ��������\n");
	 
	fclose(g);
	fclose(f);

	return 0;
}
