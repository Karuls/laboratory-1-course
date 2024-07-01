#include<iostream>
#include<time.h>
using namespace std;
void choice_sorting(int* D, int N); // Протип функции

int main() {
    int N, minutes = 0; // Переменная для хранения минут

    setlocale(0, "");
    srand(time(0)); // Инициализация генератора случайных чисел

    cout << "Введите длину заполняемого массива: ";
    cin >> N;
    int* D = new int[N]; // Выделение памяти для массива
    for (int i = 0; i < N; i++) { // Заполнение массива случайными числами от 0 до 99
        D[i] = rand() % 100;
    }
    cout << "Сгенерированный массив: ";
    for (int i = 0; i < N; i++) {
        cout << D[i] << ' ';
    }
    cout << endl;

    clock_t start = clock(); // Засекаем время начала сортировки
    choice_sorting(D, N);
    clock_t end = clock(); // Засекаем время выхода из сортировки

    cout << "Отсортированный массив: ";
    for (int i = 0; i < N; i++) {
        cout << D[i] << ' ';
    }
    cout << endl;

    double seconds = (double)(end - start) / CLOCKS_PER_SEC; // Вычисление времени выполнения сортировки
    if (seconds > 60) { // Для вывода в формате минуты.секунды
        minutes = seconds / 60;
        seconds = seconds - (minutes * 60);
    }
    else
        minutes = 0;

    cout << "Расчетное время сортировкой Выбора: " << minutes << " минут/а " << seconds << " секунд. " << endl;
    delete[] D; // Освобождение памяти
}

void choice_sorting(int* D, int N) {
    for (int k = 0; k < N - 1; k++) {
        int min = k; // Предполагаем, что минимальный элемент находится в текущей позиции
        for (int i = k + 1; i < N; i++) { // Поиск минимального элемента в оставшейся части массива
            if (D[i] < D[min]) {
                min = i; // Обновляем индекс мин элемента
            }
        }
        // Обмен текущего элемента с минимальным элементом
        int buf = D[k];
        D[k] = D[min];
        D[min] = buf;
    }
}
