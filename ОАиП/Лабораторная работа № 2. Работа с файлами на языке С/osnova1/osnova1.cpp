#include <iostream>
#include <stdio.h>


int main() {
    setlocale(LC_ALL, "RUS");
    using namespace std;
    FILE* f;
    FILE* g;
    char str1[50];
    int str2[5];
    int number = 0; int num;
 

    printf("������� ����� �������, ������� ������ �������� � ����: ");
    scanf_s("%d", &number); 


    fopen_s(&f, "ffff.txt", "r");  // �������� ����� ��� ������ 
    if (f == nullptr) { // ��������
        cout << "������ �������� ����� ffff.txt\n";
        return 1;
    }

    fscanf_s(f, "%d", &num); // num = 1 ������ ��� ��������� ���-�� ��������

    if ((int)num < number || number < 1) {
        printf("� ����� ��� ������� �������� ");
        return 0;
     }
    else {

    fopen_s(&g, "gggg.txt", "w"); // �������� ����� ��� ������
    if (g == nullptr) { // ��������
        cout << "������ �������� ����� gggg.txt\n";
        return 1;
    }

    
    int stolbec;
    while (fgets(str1, sizeof(str1), f) != nullptr) { // ������ ������, ���� ���� �� ��������
        for (int i = 0; i < number; i++) { // ������ ������

            if (i == (number - 1)) { // ��������� ����� �������� ������
                stolbec = str1[i] - '0';  // ����������� '0' �� ��������� ��������, � �� �����
                fprintf(g, "%d", stolbec);
                fputs("\n", g);
                break; // ���������� ����
                
            }
        }
    }
    printf("��������� ������� ������� � gggg.txt \n");

 

    fclose(f);
    fclose(g);
    return 0;
}
 }