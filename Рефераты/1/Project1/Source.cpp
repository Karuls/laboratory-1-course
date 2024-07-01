#include<iostream>
#include<time.h>
using namespace std;
void sort_fast(int* E, int left, int right); // Прототипы функий
void bubble_sorting(int* B, int N);
void Shell_sorting(int* C, int N);
void choice_sorting(int* D, int N);
int main() {
	int N;
	int munites = 0;
	setlocale(0, "");
	srand(time(0));
	cout << "Ввелите длинну массива: ";
	cin >> N;
	int* A = new int[N]; // инициализация массиввов 
	int* B = new int[N];
	int* C = new int[N];
	int* D = new int[N];
	int* E = new int[N]; 
	for (int i = 0; i < N; i++) {
		A[i] = rand() % 100;
	}
	cout << "Сгенерированный массив: ";
	for (int i = 0; i < N; i++) { // заполнение массивов
		B[i] = A[i];
		C[i] = A[i];
		D[i] = A[i];
		E[i] = A[i];
	}

	clock_t start = clock();
	sort_fast(E, 0, N - 1);
	clock_t end = clock();
	double seconds = (double)(end - start) / CLOCKS_PER_SEC;
	if (seconds > 60) {
		munites = seconds / 60;
		seconds = seconds - (munites * 60);
	}
	else munites = 00;
	cout << "Расчетное время быстрой сортировкой " << munites << " минут/a " << seconds << " секунд. " << endl;


	start = clock();
	bubble_sorting(B, N);
	end = clock();
	seconds = (double)(end - start) / CLOCKS_PER_SEC;
	if (seconds > 60) {
		munites = seconds / 60;
		seconds = seconds - (munites * 60);
	}
	else munites = 00;
	cout << "Расчетное время пузырьковской сортировкой " << munites << " минут/a " << seconds << " секунд. " << endl;

	start = clock();
	Shell_sorting(C, N); // Вызываем сортировку Шелла
	end = clock();
	
	seconds = (double)(end - start) / CLOCKS_PER_SEC;
	if (seconds > 60) {
		munites = seconds / 60;
		seconds = seconds - (munites * 60);
	}
	else munites = 00;
	cout << "Расчетное время сортировкой Шелла " << munites << " минут/a " << seconds << " секунд. " << endl;


	start = clock();
	choice_sorting(D, N); 
	end = clock();
	
	seconds = (double)(end - start) / CLOCKS_PER_SEC;
	if (seconds > 60) {
		munites = seconds / 60;
		seconds = seconds - (munites * 60);
	}
	else munites = 00;
	cout << "Расчетное время сортировкой выбора: " << munites << " минут/a " << seconds << " секунд. " << endl;



	delete[] A; // освобождение памяти
	delete[] B;
	delete[] C;
	delete[] D;
	delete[] E;

}

void sort_fast(int* E, int left, int right) { // Быстрая сортировка
	if (left > right) return;
	int middle = E[(left + right) / 2];
	int i = left;
	int j = right;
	while (i <= j) {
		while (E[i] < middle)i++;
		while (E[j] > middle)j--;
		if (i <= j) {
			int buffer = E[i];
			E[i] = E[j];
			E[j] = buffer;
			i++;
			j--;
		}
	}
	sort_fast(E, left, j);
	sort_fast(E, i, right);
}

void bubble_sorting(int* B, int N) { // сортировка пузырьковая
	int buffer;
	for (int i = 0; i < N - 1; i++) {
		for (int i = 0; i < N - 1; i++) {
			if (B[i] > B[i + 1]) {
				buffer = B[i];
				B[i] = B[i + 1];
				B[i + 1] = buffer;
			}
		}
	}
}

void Shell_sorting(int* C, int N) { // Сортировка Шелла
	for (int gap = N / 2; gap > 0; gap /= 2) {
		for (int i = gap; i < N; i++) {
			int temp = C[i];
			int j;
			for (j = i; j >= gap && C[j - gap] > temp; j -= gap) {
				C[j] = C[j - gap];
			}
			C[j] = temp;
		}
	}
}

void choice_sorting(int* D, int N) { // Сортировка выбора
	for (int k = 0; k < N - 1; k++) {
		int min = k;
		for (int i = k + 1; i < N; i++) {
			if (D[i] < D[min]) {
				min = i;
			}
		}
		int buf = D[k];
		D[k] = D[min];
		D[min] = buf;
	}
}