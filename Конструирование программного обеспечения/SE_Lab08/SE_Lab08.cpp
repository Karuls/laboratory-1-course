#include <iostream>
int defaultparm(int x, int y, int z, int w, int v, int c = 5, int q = 10) {
	return (x + y + z + w + v + c + q) / 7;
}
using namespace std;
int main()
{
	int rez1 = defaultparm(3, 5, 10, 0, 0);
	cout << rez1 << endl;
	int rez2 = defaultparm(2, 4, 6, 8, 12, 44, 12);
	cout << rez2;
	
}
