#include<iostream>
#include<ctime>
using namespace std;
int main() {
	setlocale(0, "");
	int N;
	cout << "Введите количество товаров в чеке: ";
	cin >> N;

	int* mass = new int[N]; srand(time(NULL));

	for (int i = 0; i < N; i++)
	{
		mass[i] = rand() % 50;
	}

	for (int i = 0; i < N; i++)
	{
		cout << i << ". " << mass[i] << endl;
	} cout << endl;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N - 1; j++) {
			if (mass[j] < mass[j + 1]) {
				swap(mass[j], mass[j + 1]);
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		cout << i << ". " << mass[i] << endl;
	}cout << endl;

	int* buf = new int[N];
	int count = N-1;
	int helper = 0, j = 0, sum = 0;
	for (int i = 0; i < N; i++) {
		
		if (i == 0){
			buf[i] = mass[j]; j++;
		}
		if (i % 2 != 0){
			buf[i] = mass[count]; count = count - 1;
		}
		if (i % 2 == 0 && helper!= 0) {
			buf[i] = mass[j]; j++;
	    }	
		helper = 1;
		cout << buf[i]<<' ';
		}

	for (int i = 0; i < N; i++)
	{
		if (i == 0 || i % 2 == 0) {
			sum += buf[i];
	}

	}
	cout << "Максимальная сумма чека: " << sum<<endl;
	


	delete[] mass;
	delete[] buf;
}
/*В сети магазинов "ФИТ-Аудио" проводится рекламная акция. Каждый второй товар – бесплатно. Естественно, кассирам дано указание пробивать товары в таком порядке, чтобы магазин потерял как можно меньше денег.
По списку товаров определите максимальную сумму в чеке. 
Вход: натуральное число товаров (N < 10000) и далее N натуральных чисел – цены товаров. Цену товара сгенерировать (Например, от 1 до 100).
Выход:  Порядок пробивания на кассе и число – максимальная сумма чека.
*/