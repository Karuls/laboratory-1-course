#include<iostream>
#include<time.h>
using namespace std;
void sort_fast(int* E, int left, int right);// Протип функции

int main() {
    int N, minutes = 0; // Переменная для хранения минут

    setlocale(0, "");
    srand(time(0)); // Инициализация генератора случайных чисел

    cout << "Введите длину заполняемого массива: ";
    cin >> N;
    int* E = new int[N]; // Выделение памяти для массива
    for (int i = 0; i < N; i++) { // Заполнение массива случайными числами от 0 до 99
        E[i] = rand() % 100;
    }
    cout << "Сгенерированный массив: ";
    for (int i = 0; i < N; i++) {
        cout << E[i] << ' ';
    }
    cout << endl;

    clock_t start = clock(); // Засекаем время начала сортировки
    sort_fast(E, 0, N - 1);
    clock_t end = clock(); // Засекаем время выхода из сортировки

    cout << "Отсортированный массив: ";
    for (int i = 0; i < N; i++) {
        cout << E[i] << ' ';
    }
    cout << endl;

    double seconds = (double)(end - start) / CLOCKS_PER_SEC; // Вычисление времени выполнения сортировки
    if (seconds > 60) { // Для вывода в формате минуты.секунды
        minutes = seconds / 60;
        seconds = seconds - (minutes * 60);
    }
    else
        minutes = 0;

    cout << "Расчетное время быстрой сортировкой : " << minutes << " минут/а " << seconds << " секунд. " << endl;
    delete[] E; // Освобождение памяти
}
    void sort_fast(int* E, int left, int right) {
        // Если левая граница больше или равна правой, значит, массив отсортирован
        if (left > right) return;
        int middle = E[(left + right) / 2]; // Выбираем элемент, который будет опорным
        int i = left;
        int j = right;
        // Разделяем массив на две части
        while (i <= j) {
            while (E[i] < middle) i++; // Поиск элемента, который больше опорного слева
            while (E[j] > middle) j--; // Поиск элемента, который меньше опорного справа
            if (i <= j) { // Если нашли элементы, которые нужно поменять
                int buffer = E[i]; // Обмен местами
                E[i] = E[j];
                E[j] = buffer;
                i++; // Переход к следующему элементу справа
                j--; // Переход к следующему элементу слева
            }
        }
        // Рекурсия функции для каждой из половинок
        sort_fast(E, left, j);
        sort_fast(E, i, right);
}
