#include<iostream>
#include<string>

using namespace std;

int main() {
    setlocale(LC_ALL, "rus");

    int N;
    cout << "Введите максимальное число N: ";
    cin >> N;
    if (N == 0) {
        cout << "Не удовл." << endl;
        return 0;
    }

    int left = 1, right = N;
    int steps = 0;
    int answer = 0;

    while (answer != 3) {

        int mid = (left + right) / 2;
        cout << mid << endl;

        cout << "1 - мало. 2 - много. 3 - угадал" << endl;
        cin >> answer;

        if (answer == 1) {
            left = mid + 1;
        }
        else if (answer == 2) {
            right = mid - 1;
        }
        else if (answer == 3) {
            cout << "Максимальное количество шагов = " << steps << endl;
        }
        else {
            cout << "Пожалуйста, введите корректный ответ." << endl;
        }

        steps++;
    }

    return 0;
}
