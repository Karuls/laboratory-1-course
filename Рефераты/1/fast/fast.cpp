#include<iostream>
#include<time.h>
using namespace std;
void sort_fast(int* E, int left, int right);// ������ �������

int main() {
    int N, minutes = 0; // ���������� ��� �������� �����

    setlocale(0, "");
    srand(time(0)); // ������������� ���������� ��������� �����

    cout << "������� ����� ������������ �������: ";
    cin >> N;
    int* E = new int[N]; // ��������� ������ ��� �������
    for (int i = 0; i < N; i++) { // ���������� ������� ���������� ������� �� 0 �� 99
        E[i] = rand() % 100;
    }
    cout << "��������������� ������: ";
    for (int i = 0; i < N; i++) {
        cout << E[i] << ' ';
    }
    cout << endl;

    clock_t start = clock(); // �������� ����� ������ ����������
    sort_fast(E, 0, N - 1);
    clock_t end = clock(); // �������� ����� ������ �� ����������

    cout << "��������������� ������: ";
    for (int i = 0; i < N; i++) {
        cout << E[i] << ' ';
    }
    cout << endl;

    double seconds = (double)(end - start) / CLOCKS_PER_SEC; // ���������� ������� ���������� ����������
    if (seconds > 60) { // ��� ������ � ������� ������.�������
        minutes = seconds / 60;
        seconds = seconds - (minutes * 60);
    }
    else
        minutes = 0;

    cout << "��������� ����� ������� ����������� : " << minutes << " �����/� " << seconds << " ������. " << endl;
    delete[] E; // ������������ ������
}
    void sort_fast(int* E, int left, int right) {
        // ���� ����� ������� ������ ��� ����� ������, ������, ������ ������������
        if (left > right) return;
        int middle = E[(left + right) / 2]; // �������� �������, ������� ����� �������
        int i = left;
        int j = right;
        // ��������� ������ �� ��� �����
        while (i <= j) {
            while (E[i] < middle) i++; // ����� ��������, ������� ������ �������� �����
            while (E[j] > middle) j--; // ����� ��������, ������� ������ �������� ������
            if (i <= j) { // ���� ����� ��������, ������� ����� ��������
                int buffer = E[i]; // ����� �������
                E[i] = E[j];
                E[j] = buffer;
                i++; // ������� � ���������� �������� ������
                j--; // ������� � ���������� �������� �����
            }
        }
        // �������� ������� ��� ������ �� ���������
        sort_fast(E, left, j);
        sort_fast(E, i, right);
}
