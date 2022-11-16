//Цикл for
#include <iostream>
using namespace std;
int main() {
	//For1.Даны целые числа K и N(N > 0). Вывести N раз число K.
	/*int n, k;
	cout << "n:";
	cin >> n;
	cout << "K:";
	cin >> k;
	for (int i = 0; i < n; ++i) {
		cout << k << endl;
	}*/
	
	/*//For2.Даны два целых числа A и B(A < B).Вывести в порядке 
	//возрастания все целые числа, расположенные между A и B(включая сами
	//числа A и B), а также количество N этих чисел.*/	/*int a, b;	int n = 0;	cout << "a: ";	cin >> a;
	cout << "b: ";	cin >> b;
	for (int i = a; i <= b; i = i + 1) {
		cout << i << " ";
		n++;
	}
	cout << "qty = " << n << endl;*/

	/*
	For3. Даны два целых числа A и B (A < B). Вывести в порядке убывания
	все целые числа, расположенные между A и B (не включая числа A и B), 
	а также количество N этих чисел
	*/
	/*int a, b;	int n = 0;	cout << "a: ";	cin >> a;
	cout << "b: ";	cin >> b;
	for (int i = b-1; i > a; i = i - 1) {
		cout << i << " ";
		n++;
	}
	cout << "qty = " << n << endl;*/

	/*
	For4. Дано вещественное число — цена 1 кг конфет. Вывести стоимость
	1, 2, . . . , 10 кг конфет.	*/
	double price;
	cout << "input price: ";
	cin >> price;
	for (int weight = 1; weight <= 10; weight++) {
		cout << weight << " kg costs " << weight * price << " $"<< endl;
	}
	
}