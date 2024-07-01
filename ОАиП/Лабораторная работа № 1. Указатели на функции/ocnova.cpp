#include<iostream>
using namespace std;
double add_first_example1x(double);
double add_first_example2x(double);
double add_first_example1a(double);
double add_first_example2a(double);
double dyxotomia(double, double, double, double, double, double, double(*)(double)); // Инициализация функций
double dyxotomia2(double, double, double, double, double, double, double(*)(double));
int main() {

	setlocale(LC_ALL, "rus");
	double a, b, x = 0;
	double fx1=0, fa1=0;
	double e = 0.001;

	cout << "Введите числа a b" << endl;
	cin >> a >> b;
	


	fx1 = add_first_example1x(x);  // Вызов функции f1(x)
	x = dyxotomia(x, a, b, e, fx1, fa1, add_first_example1a); // Вызов функции Духотомии; x принимает значение корней
	cout << "Корень уравнения (1) = " << x << endl;

	fx1 = add_first_example2x(x); // Вызов функции f2(x)
	fa1 = add_first_example2a(a); // Вызов функции f2(a)
	x = dyxotomia2(x, a, b, e, fx1, fa1, add_first_example1a);
	cout << "Корень уравнения (2) = "<< x << endl;

}
double add_first_example1x(double x) { // Функция f(x) для 1-ого уравнения
     return exp(x) + x - 4;
}

double add_first_example2x(double x) { // Функция f(x) для 2-ого уравнения
	return pow(x, 2) - 4;
}

double add_first_example1a(double a) { // Функция f(а) для 1-ого уравнения
	return exp(a) + a - 4;
}

double add_first_example2a(double a) { // Функция f(а) для 2-ого уравнения
	return pow(a, 2) - 4;
}


// Функция метода Духотомии
double dyxotomia(double x, double a, double b, double e, double fx1, double fa1, double (*add_first_example1a)(double a)) {

	fa1 = add_first_example1a(a); // использование функии f1(x)

	while (abs(a-b) > 2*e) { //Условие завершния цикла

		x = (a + b) / 2;
		fx1 = add_first_example1a(x); // Вычисляем значение функции в середине интервала
		
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

	fa2 = add_first_example2a(a); // использование функии f1(x)

	while (abs(a - b) > 2 * e) { //Условие завершния цикла

		x = (a + b) / 2;
		fx2 = add_first_example2x(x); // Вычисляем значение функции в середине интервала

		if ((fx2 * fa2) <= 0) {
			b = x;
		}
		else {
			a = x;
		}

	}
	return x;

}