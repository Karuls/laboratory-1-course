#include <iostream>
#include <stdio.h>
#include <cctype>

int main() {
    setlocale(LC_ALL, "RUS");
    using namespace std;
    FILE* f;
    FILE* g;
    char str1[50], str2[50], str3[50], str4[50], str5[50];
    bool flag = true;

    fopen_s(&f, "ffff.txt", "w");  // �������� ����� ��� ������
    if (f == nullptr) { //�������� �� ��������
        cout << "������ �������� ����� ffff.txt\n";
        return 1;
    }

    printf("������� ������ �1: "); // ������ ������ � ����
    gets_s(str1);
    fwrite(str1, strlen(str1), 1, f);
    fputs("\n", f);

    printf("������� ������ �2: ");
    gets_s(str2);
    fwrite(str2, strlen(str2), 1, f);
    fputs("\n", f);

    printf("������� ������ �3: ");
    gets_s(str3);
    fwrite(str3, strlen(str3), 1, f);
    fputs("\n", f);

    printf("������� ������ �4: ");
    gets_s(str4);
    fwrite(str4, strlen(str4), 1, f);
    fputs("\n", f);

    printf("������� ������ �5: ");
    gets_s(str5);
    fwrite(str5, strlen(str5), 1, f);
    fputs("\n", f);

    printf("\n������ ���������\n");
    fclose(f);

    fopen_s(&f, "ffff.txt", "r");  // �������� ����� ��� �������
    if (f == nullptr) {// ��������
        cout << "������ �������� ����� ffff.txt ��� ������\n";
        return 1;
    }

    fopen_s(&g, "gggg.txt", "w"); // �������� ����� ��� ������
    if (g == nullptr) { // �������
        cout << "������ �������� ����� gggg.txt\n";
        return 1;
    }

    
    while (fgets(str1, sizeof(str1), f) != nullptr) { // �������� ������ �� ����� �����
        flag = true; // ���������� ���� ����� ������ ����� �������
        for (int i = 0; str1[i] != '\0'; i++) {
            if (isdigit(str1[i])) { // �������� �� �����
                flag = false;
                break; // ���������� ���� for
            }
        }
        if (flag == true) { // ���� � ������ ��� ����, ���������� �� � ���� gggg.txt
            fputs(str1, g); // ������������ ������ 
        }
    }

    fclose(f);
    fclose(g);
    return 0;
}
