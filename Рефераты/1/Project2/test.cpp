#include<iostream>
#include<time.h>
using namespace std;
void bubble_sorting(int* B, int N); // Протип функции

int main() {
    int N, minutes = 0; // Переменная для хранения минут
    
    setlocale(0, "");
    srand(time(0)); // Инициализация генератора случайных чисел

    cout << "Введите длину заполняемого массива: ";
    cin >> N;
    int* B = new int[N]; // Выделение памяти для массива
    for (int i = 0; i < N; i++) { // Заполнение массива случайными числами от 0 до 99
        B[i] = rand() % 100;
    }
    cout << "Сгенерированный массив: ";
    for (int i = 0; i < N; i++) {
        cout << B[i] << ' ';
    }
    cout << endl;

    clock_t start = clock(); // Засекаем время начала сортировки
    bubble_sorting(B, N); // Вызов функцию пузырьковой сортирвки
    clock_t end = clock(); // Засекаем время выхода из сортировки

    cout << "Отсортированный массив: ";
    for (int i = 0; i < N; i++) {
        cout << B[i] << ' ';
    }
    cout << endl;

    double seconds = (double)(end - start) / CLOCKS_PER_SEC; // Вычисление времени выполнения сортировки
    if (seconds > 60) { // Для вывода в формате минуты.секунды
        minutes = seconds / 60;
        seconds = seconds - (minutes * 60);
    }
    else
        minutes = 0;

    cout << "Расчетное время пузырьковой сортировкой " << minutes << " минут/а " << seconds << " секунд. " << endl;
    delete[] B; // Освобождение памяти
}


void bubble_sorting(int* B, int N) {
    int buffer;

    for (int i = 0; i < N - 1; i++) {    // Внешний цикл проходит по массиву N-1 раз
        for (int i = 0; i < N - 1; i++) {  // Внутренний цикл для каждой итерации внешнего цикла
            if (B[i] > B[i + 1]) {        // Если текущий элемент больше следующего, меняем их местами
                B[i] = B[i] + B[i + 1];
                B[i + 1] = B[i] - B[i + 1];
                B[i] = B[i] - B[i + 1];
            }
        }
    }
}
/*Важно, что обмен значениями переменных реалзван без
дополнительных переменных или функций, а по примеру:
int A = 5, B = 3;
A = A(5) + B(3);
B = A(8) - B(3);
A = A(8) - B(5);
*/
