#include <iostream>
#include <ctime>
using namespace std;
int main() {
	/*const int n = 10;
	int mas[n];
	srand(time(nullptr));
	//�������� �� -20 �� 20
	for (int i = 0; i < n; i++) {
		mas[i] = rand() % 41 - 20;
		cout << mas[i] << ' ';
	}
	cout << endl;*/
	/*Array1.���� ����� ����� N(> 0).������������ � ������� �������������
		������ ������� N, ���������� N ������ ������������� �������� ����� :
	1, 3, 5, . . . .*/	/*const int n = 10;
	int mas[n];	mas[0] = 1;	cout << mas[0]<<' ';	for (int i = 1; i < n; i++) {		mas[i] = mas[i - 1] + 2;		cout << mas[i] << ' ';	}*/	/*Array2.���� ����� ����� N(> 0).������������ � ������� �������������
		������ ������� N, ���������� ������� ������ �� ������ �� N - �: 2, 4,
		8, 16, . . . .*/
	/*const int n = 10;
	int mas[n];	mas[0] = 2;	cout << mas[0] << ' ';	for (int i = 1; i < n; i++) {		mas[i] = mas[i - 1] * 2;		cout << mas[i] << ' ';	}*/
	/*Array3.���� ����� ����� N(> 1), � ����� ������ ���� A � �������� D �������������� ����������.������������ � ������� ������ ������� N, ���������� N ������ ������ ������ ���������� : A, A + D, A + 2�D, A + 3�D, . . . .*/
	const int n = 10;
	int mas[n];
	int a, d;
	cin >> a >> d;
	mas[0] = a;
	cout << mas[0] << ' ';	for (int i = 1; i < n; i++) {		mas[i] = mas[i - 1] + d;		cout << mas[i] << ' ';	}
}