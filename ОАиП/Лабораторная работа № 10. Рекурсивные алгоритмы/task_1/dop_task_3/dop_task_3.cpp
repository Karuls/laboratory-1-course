#include <iostream>
using namespace std;

// Функция для обмена значений двух переменных
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Рекурсивная функция для генерации всех перестановок
void generatePermutations(int numbers[], int start, int end) {
    if (start == end) {
        // Базовый случай: если start и end совпадают, значит массив отсортирован,
        // и мы можем его распечатать как перестановку
        for (int i = 0; i <= end; ++i) {
            cout << numbers[i] << " ";
        }
        cout << endl;
    }
    else {
        // Рекурсивный случай: для каждой позиции от start до end
        // генерируем все возможные перестановки
        for (int i = start; i <= end; ++i) {
            // Меняем местами текущий элемент с элементом на позиции start
            swap(numbers[start], numbers[i]);
            // Рекурсивно вызываем функцию для оставшейся части массива
            generatePermutations(numbers, start + 1, end);
            // Возвращаем обратно элементы массива, чтобы перейти к следующей перестановке
            swap(numbers[start], numbers[i]);
        }
    }
}

int main() {
    setlocale(0, "");
    int n = 5;
    int numbers[] = { 1, 2, 3, 4, 5 };
    cout << "Все перестановки чисел:" << endl;
    generatePermutations(numbers, 0, n - 1);
    return 0;
}
