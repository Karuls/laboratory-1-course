#include<iostream>
using namespace std;
double add_first_example1x(double);
double add_first_example2x(double);
double add_first_example1a(double);
double add_first_example2a(double);
double dyxotomia(double, double, double, double, double, double, double(*)(double)); // ������������� �������
double dyxotomia2(double, double, double, double, double, double, double(*)(double));
int main() {

	setlocale(LC_ALL, "rus");
	double a, b, x = 0;
	double fx1=0, fa1=0;
	double e = 0.001;

	cout << "������� ����� a b" << endl;
	cin >> a >> b;
	


	fx1 = add_first_example1x(x);  // ����� ������� f1(x)
	x = dyxotomia(x, a, b, e, fx1, fa1, add_first_example1a); // ����� ������� ���������; x ��������� �������� ������
	cout << "������ ��������� (1) = " << x << endl;

	fx1 = add_first_example2x(x); // ����� ������� f2(x)
	fa1 = add_first_example2a(a); // ����� ������� f2(a)
	x = dyxotomia2(x, a, b, e, fx1, fa1, add_first_example1a);
	cout << "������ ��������� (2) = "<< x << endl;

}
double add_first_example1x(double x) { // ������� f(x) ��� 1-��� ���������
     return exp(x) + x - 4;
}

double add_first_example2x(double x) { // ������� f(x) ��� 2-��� ���������
	return pow(x, 2) - 4;
}

double add_first_example1a(double a) { // ������� f(�) ��� 1-��� ���������
	return exp(a) + a - 4;
}

double add_first_example2a(double a) { // ������� f(�) ��� 2-��� ���������
	return pow(a, 2) - 4;
}


// ������� ������ ���������
double dyxotomia(double x, double a, double b, double e, double fx1, double fa1, double (*add_first_example1a)(double a)) {

	fa1 = add_first_example1a(a); // ������������� ������ f1(x)

	while (abs(a-b) > 2*e) { //������� ��������� �����

		x = (a + b) / 2;
		fx1 = add_first_example1a(x); // ��������� �������� ������� � �������� ���������
		
		if ((fx1* fa1) <= 0) {
			b = x;
		}
		else {
			a = x;
		}
		
	}
	return x;

}	
double dyxotomia2(double x, double a, double b, double e, double fx2, double fa2, double (*add_first_example2a)(double a)) {

	fa2 = add_first_example2a(a); // ������������� ������ f1(x)

	while (abs(a - b) > 2 * e) { //������� ��������� �����

		x = (a + b) / 2;
		fx2 = add_first_example2x(x); // ��������� �������� ������� � �������� ���������

		if ((fx2 * fa2) <= 0) {
			b = x;
		}
		else {
			a = x;
		}

	}
	return x;

}