#include<iostream>
#include<time.h>
using namespace std;
void Shell_sorting(int* C, int N); // ������ �������

int main() {
    int N, minutes = 0; // ���������� ��� �������� �����
    
    setlocale(0, "");
    srand(time(0)); // ������������� ���������� ��������� �����

    cout << "������� ����� ������������ �������: ";
     cin >> N;
     int* C = new int[N]; // ��������� ������ ��� �������
    for (int i = 0; i < N; i++) { // ���������� ������� ���������� ������� �� 0 �� 99
        C[i] = rand() % 100;
    }
    cout << "��������������� ������: ";
    for (int i = 0; i < N; i++) {
        cout << C[i] << ' ';
    }
    cout << endl;

    clock_t start = clock(); // �������� ����� ������ ����������
    Shell_sorting(C, N); // �������� ���������� �����
    clock_t end = clock(); // �������� ����� ������ �� ����������

    cout << "��������������� ������: ";
    for (int i = 0; i < N; i++) {
        cout << C[i] << ' ';
    }
    cout << endl;

    double seconds = (double)(end - start) / CLOCKS_PER_SEC; // ���������� ������� ���������� ����������
    if (seconds > 60) { // ��� ������ � ������� ������.�������
        minutes = seconds / 60;
        seconds = seconds - (minutes * 60);
    }
    else
        minutes = 0;

    cout << "��������� ����� ����������� �����: " << minutes << " �����/� " << seconds << " ������. " << endl;
    delete[] C; // ������������ ������
}

void Shell_sorting(int* C, int N) {
    
    for (int gap = N / 2; gap > 0; gap /= 2) { // �������� � �������� ����, ����� ��������� ���
        for (int i = gap; i < N; i++) {  // ��������� ���������� ��������� � ��������� �����
            int temp = C[i]; // ���������� ������� �������
            int j; // ���������� ��� �������
            for (j = i; j >= gap && C[j - gap] > temp; j -= gap) { // ���������� �������� �� ���������� gap �����, ���� �����
                C[j] = C[j - gap]; // �������� �������� �� ��� gap ������
            }
            C[j] = temp; // ��������� ����������� ������� � ������ �������
        }
    }
}
