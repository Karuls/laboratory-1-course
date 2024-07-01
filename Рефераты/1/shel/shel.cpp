#include<iostream>
#include<time.h>
using namespace std;
void Shell_sorting(int* C, int N); // Протип функции

int main() {
    int N, minutes = 0; // Переменная для хранения минут
    
    setlocale(0, "");
    srand(time(0)); // Инициализация генератора случайных чисел

    cout << "Введите длину заполняемого массива: ";
     cin >> N;
     int* C = new int[N]; // Выделение памяти для массива
    for (int i = 0; i < N; i++) { // Заполнение массива случайными числами от 0 до 99
        C[i] = rand() % 100;
    }
    cout << "Сгенерированный массив: ";
    for (int i = 0; i < N; i++) {
        cout << C[i] << ' ';
    }
    cout << endl;

    clock_t start = clock(); // Засекаем время начала сортировки
    Shell_sorting(C, N); // Вызываем сортировку Шелла
    clock_t end = clock(); // Засекаем время выхода из сортировки

    cout << "Отсортированный массив: ";
    for (int i = 0; i < N; i++) {
        cout << C[i] << ' ';
    }
    cout << endl;

    double seconds = (double)(end - start) / CLOCKS_PER_SEC; // Вычисление времени выполнения сортировки
    if (seconds > 60) { // Для вывода в формате минуты.секунды
        minutes = seconds / 60;
        seconds = seconds - (minutes * 60);
    }
    else
        minutes = 0;

    cout << "Расчетное время сортировкой Шелла: " << minutes << " минут/а " << seconds << " секунд. " << endl;
    delete[] C; // Освобождение памяти
}

void Shell_sorting(int* C, int N) {
    
    for (int gap = N / 2; gap > 0; gap /= 2) { // Начинаем с большого шага, затем уменьшаем его
        for (int i = gap; i < N; i++) {  // Применяем сортировку вставками с указанным шагом
            int temp = C[i]; // Запоминаем текущий элемент
            int j; // Переменная для индекса
            for (j = i; j >= gap && C[j - gap] > temp; j -= gap) { // Перемещаем элементы на расстояние gap вперёд, если нужно
                C[j] = C[j - gap]; // Сдвигаем элементы на шаг gap вперед
            }
            C[j] = temp; // Вставляем сохраненный элемент в нужную позицию
        }
    }
}
