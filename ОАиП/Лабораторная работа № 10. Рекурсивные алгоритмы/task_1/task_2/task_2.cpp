#include <iostream>
using namespace std;
int FN(int n, int m) {
	if (n == 0)
		return 1;
	if (n < m)
		return -1;
	return 2*FN(n-1,m);
}

int main() {
	setlocale(0, "");
	cout << FN(3, 2);

}