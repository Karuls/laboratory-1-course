#include <iostream>
#include <stdio.h>  

int main() {
    setlocale(LC_ALL, "");
    const int SIZE = 10;
    FILE* f;
    FILE* g;
    int str[SIZE] = { 1, 2, 1, 2, 5, 6, 7, 8 ,9, 4 };
    int encountered[SIZE] = { 0 }; // ������ ��� ������������ ����������� �����
    int number;

   
    fopen_s(&f, "task1.txt", "w");  // �������� ����� ��� ������

    for (int i = 0; i < SIZE; i++) {
        fprintf(f, "%d ", str[i]);
    }

    printf("\n������ �������� � task1.txt\n");
    fclose(f);

    
    fopen_s(&f, "task1.txt", "r");// �������� ����� ��� ������

    printf("���������� ����� task1.txt:\n");

   
    fopen_s(&g, "task1212.txt", "w"); // �������� ����� ��� ������

                                                 
    while (fscanf_s(f, "%d", &number) == 1) {     // ���� ���� ����� ��� ���������� �� ����� f
        // ���������, ����������� �� ��� ����� �����
        if (!encountered[number]) { 
            
            fprintf(g, "%d ", number);  // ���� ����� ��� �� ����������� ���������� ��� � ���� g
            // �������� ����� ��� �����������
            encountered[number] = 1;
        }
    }

    fclose(f);
    fclose(g);

    return 0;
}
