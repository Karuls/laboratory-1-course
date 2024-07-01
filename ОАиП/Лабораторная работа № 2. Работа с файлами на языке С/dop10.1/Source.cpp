#include <iostream>

int main() {
    setlocale(LC_ALL, "RUS");
    FILE* f;
    char str1[50];
    float x;
    float num1, num2, hsum, difference, mindifference = 999; 
    float count1, count2;

    printf("������� ����� x: ");
    scanf_s("%f", &x);

    if (x > 8) { // ��������
        printf("������� �����: \n");
        return 1;
     }

    fopen_s(&f, "fileA.txt", "r");  // �������� �������� �����
    if (f == nullptr) {
        perror("������ �������� �����");
        return 1;
    }

   
    while (fgets(str1, sizeof(str1), f)) { // ������ ������ �� �����
        for (int i = 0; i < sizeof(str1); i++) {
           // ����� ���������� �������� ��������� �����, ������� ��������������
                if (i % 2 == 0) { 
                num1 = (str1[i] - '0'); // ����������� '0' �� ��������� ��������, � �� �����
                num2 = (str1[i + 1] - '0');
                hsum = (num1 + num2) / 2; // ������� ��������������
                difference = abs(hsum - x); // �������

                if (mindifference > difference) { // ���������� ��� �������
                    mindifference = difference;   // � ����� �� ����������
                    count1 = num1;
                    count2 = num2;
                }
            }
        }
    
    }

    printf("��� ����� ���� ������������������, ������� �������������� ������� ����� ����� � ����� �:\n");
    printf("%f, %f\n", count1, count2);
    printf("�������: \n");
    printf("%f\n", mindifference);

    fclose(f);
    return 0;
}
