#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	setlocale(0, "");
	vector<int> v{ 1,2,3,4,5,6,7,8,9,10 };
	int target1 = 3;
	int num_items1 = count(v.begin(), v.end(), target1);
	cout << "Число: " << target1 << " Количество: " << num_items1 << endl;

	int num_items3 = count_if(v.begin(), v.end(), [](int i) {return i % 3 == 0; });

	cout << "кол-во элементов, кратных 3: " << num_items3 << endl;
	cout << " Лямбда, захват переменных " << endl;

	for (auto i : v) [i]() {if (i % 3 == 0) cout << i << " "; }(); cout << endl;
	cout << "  Лямбда с параметрами" << endl;

	for (auto i : v) [](auto i) {if (i % 3 == 0) cout << i << " "; }(i); cout << endl;
	cout << "  Лямбда без параметров" << endl;

	for (auto i : v) [i]{if (i % 3 == 0) cout << i << " "; }();


	// ДОП
	cout << endl << "ДОП: ";
	int x = -1;
	auto VICH_TEST = [x]()
		{
			if (x < 0) return false;
			else return true;
		};
	cout << VICH_TEST();
}