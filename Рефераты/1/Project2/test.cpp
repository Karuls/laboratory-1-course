#include<iostream>
#include<time.h>
using namespace std;
void bubble_sorting(int* B, int N); // ������ �������

int main() {
    int N, minutes = 0; // ���������� ��� �������� �����
    
    setlocale(0, "");
    srand(time(0)); // ������������� ���������� ��������� �����

    cout << "������� ����� ������������ �������: ";
    cin >> N;
    int* B = new int[N]; // ��������� ������ ��� �������
    for (int i = 0; i < N; i++) { // ���������� ������� ���������� ������� �� 0 �� 99
        B[i] = rand() % 100;
    }
    cout << "��������������� ������: ";
    for (int i = 0; i < N; i++) {
        cout << B[i] << ' ';
    }
    cout << endl;

    clock_t start = clock(); // �������� ����� ������ ����������
    bubble_sorting(B, N); // ����� ������� ����������� ���������
    clock_t end = clock(); // �������� ����� ������ �� ����������

    cout << "��������������� ������: ";
    for (int i = 0; i < N; i++) {
        cout << B[i] << ' ';
    }
    cout << endl;

    double seconds = (double)(end - start) / CLOCKS_PER_SEC; // ���������� ������� ���������� ����������
    if (seconds > 60) { // ��� ������ � ������� ������.�������
        minutes = seconds / 60;
        seconds = seconds - (minutes * 60);
    }
    else
        minutes = 0;

    cout << "��������� ����� ����������� ����������� " << minutes << " �����/� " << seconds << " ������. " << endl;
    delete[] B; // ������������ ������
}


void bubble_sorting(int* B, int N) {
    int buffer;

    for (int i = 0; i < N - 1; i++) {    // ������� ���� �������� �� ������� N-1 ���
        for (int i = 0; i < N - 1; i++) {  // ���������� ���� ��� ������ �������� �������� �����
            if (B[i] > B[i + 1]) {        // ���� ������� ������� ������ ����������, ������ �� �������
                B[i] = B[i] + B[i + 1];
                B[i + 1] = B[i] - B[i + 1];
                B[i] = B[i] - B[i + 1];
            }
        }
    }
}
/*�����, ��� ����� ���������� ���������� �������� ���
�������������� ���������� ��� �������, � �� �������:
int A = 5, B = 3;
A = A(5) + B(3);
B = A(8) - B(3);
A = A(8) - B(5);
*/
