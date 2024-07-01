#include<iostream>
#include<time.h>
using namespace std;
void choice_sorting(int* D, int N); // ������ �������

int main() {
    int N, minutes = 0; // ���������� ��� �������� �����

    setlocale(0, "");
    srand(time(0)); // ������������� ���������� ��������� �����

    cout << "������� ����� ������������ �������: ";
    cin >> N;
    int* D = new int[N]; // ��������� ������ ��� �������
    for (int i = 0; i < N; i++) { // ���������� ������� ���������� ������� �� 0 �� 99
        D[i] = rand() % 100;
    }
    cout << "��������������� ������: ";
    for (int i = 0; i < N; i++) {
        cout << D[i] << ' ';
    }
    cout << endl;

    clock_t start = clock(); // �������� ����� ������ ����������
    choice_sorting(D, N);
    clock_t end = clock(); // �������� ����� ������ �� ����������

    cout << "��������������� ������: ";
    for (int i = 0; i < N; i++) {
        cout << D[i] << ' ';
    }
    cout << endl;

    double seconds = (double)(end - start) / CLOCKS_PER_SEC; // ���������� ������� ���������� ����������
    if (seconds > 60) { // ��� ������ � ������� ������.�������
        minutes = seconds / 60;
        seconds = seconds - (minutes * 60);
    }
    else
        minutes = 0;

    cout << "��������� ����� ����������� ������: " << minutes << " �����/� " << seconds << " ������. " << endl;
    delete[] D; // ������������ ������
}

void choice_sorting(int* D, int N) {
    for (int k = 0; k < N - 1; k++) {
        int min = k; // ������������, ��� ����������� ������� ��������� � ������� �������
        for (int i = k + 1; i < N; i++) { // ����� ������������ �������� � ���������� ����� �������
            if (D[i] < D[min]) {
                min = i; // ��������� ������ ��� ��������
            }
        }
        // ����� �������� �������� � ����������� ���������
        int buf = D[k];
        D[k] = D[min];
        D[min] = buf;
    }
}
