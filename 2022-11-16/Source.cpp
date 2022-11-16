#include <iostream>
#include <ctime>
using namespace std;
double powerA3(double a) {
	//double res = a * a * a;
	//return res;
	return a * a * a;
}
double powerA2(double a) {
	return a * a;
}
double powerA4(double a) {
	return powerA2(a) * powerA2(a); // a*a*a*a
}
double aMean(double x, double y) {
	return (x + y) / 2;
}
double gMean(double x, double y) {
	return sqrt(x * y);
}
double triangleP(double a) {
	return 3 * a;
}
double triangleS(double a) {
	return a * a * sqrt(3) / 4;
}
int main() {
	/*Proc1. Описать функцию powerA3(A), вычисляющую третью степень числа A и возвращающую ее (параметр вещественный). С помощью этой функции найти третьи степени пяти случайных чисел.*/
	/*srand(time(nullptr));
	for (int i = 1; i <= 5; i++) {
		double x = rand() % 11;
		double x3 = powerA3(x);
		cout << "x = " << x << " x^3 = " << x3 << endl;
	}*/
	/*
	Proc2. Описать 2 функции powerA2(А), powerA4(A), вычисляющию вторую и четвертую степень числа A и возвращающию эти степени (параметры являются вещественными). С помощью этих функций найти вторую и четвертую степень пяти случайных чисел
	*/
	/*srand(time(nullptr));
	for (int i = 1; i <= 5; i++) {
		double x = rand() % 11;
		double x2 = powerA2(x);
		double x4 = powerA4(x);
		cout << "x = " << x << " x^2 = " << x2 << " x^4 = " <<
			x4 << endl;
	}*/
	/*
	Proc3. Описать 2 функции aMean(X, Y), gMean(X,Y), вычисляющие среднее арифметическое aMean = (X+Y)/2 и среднее геометрическое gMean = √ X·Y двух положительных чисел X и Y (X и Y — входные параметры вещественного типа). С помощью этих функций найти среднее арифметическое и среднее геометрическое для 10 пар случайных чисел.
	*/
	/*for (int i = 1; i <= 10; i++) {
		double x1 = rand() % 101 * 0.1;
		double y1 = rand() % 101 * 0.1;
		cout << "x = " << x1 << " y = " << y1 << " sr_arifm = " <<
			aMean(x1, y1) << " sr_geom = " << gMean(x1, y1) <<
			endl;
	}*/
	/*
	Proc4. Описать 2 функции triangleP(a) и triangleS(a), вычисляющие по стороне a равностороннего треугольника его периметр P = 3·a и площадь S = a^2 · √ 3/4 (параметры являются вещественными). С помощью этих функций найти периметры и площади трех равносторонних треугольников с данными сторонами (стороны ввести с клавиатуры).
	*/
	//srand(time(nullptr));
	setlocale(LC_ALL, "russian");
	double a;
	for (int i = 1; i <= 5; i++) {
		cout << "Введите сторону треугольника ";
		cin >> a;
		cout << "P = " << triangleP(a) << " S = " << triangleS(a)
			<< endl;
	}
}