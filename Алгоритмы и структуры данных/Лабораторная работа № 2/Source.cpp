#include<iostream>
#include<string>

using namespace std;

int main() {
    setlocale(LC_ALL, "rus");

    int N;
    cout << "������� ������������ ����� N: ";
    cin >> N;
    if (N == 0) {
        cout << "�� �����." << endl;
        return 0;
    }

    int left = 1, right = N;
    int steps = 0;
    int answer = 0;

    while (answer != 3) {

        int mid = (left + right) / 2;
        cout << mid << endl;

        cout << "1 - ����. 2 - �����. 3 - ������" << endl;
        cin >> answer;

        if (answer == 1) {
            left = mid + 1;
        }
        else if (answer == 2) {
            right = mid - 1;
        }
        else if (answer == 3) {
            cout << "������������ ���������� ����� = " << steps << endl;
        }
        else {
            cout << "����������, ������� ���������� �����." << endl;
        }

        steps++;
    }

    return 0;
}
