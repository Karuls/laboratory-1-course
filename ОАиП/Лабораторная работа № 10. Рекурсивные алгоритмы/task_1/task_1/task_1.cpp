#include <iostream>
using namespace std;

double Fackt(double x, double n) {
	if (n == 0)
		return 1;
	if (n == 1)
		return x;
	return x*x /n /(n - 1)* Fackt(x, n-2);
}

int main() {
	setlocale(0, "");
	cout << Fackt(2, 3);
	
}