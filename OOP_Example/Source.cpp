#include <iostream>
using namespace std;
//�������� ����� Apple. � ������ ������ ���� 2 ���� - ���� � ���.
//�������� ��� ������������, ������ get � set ��� �����, �����
//print, ������� ������� ���������� � ������� �� �����.
//������� 1-� ������ � ������� ������������ ��� ����������.
//�������� � ���� ���������� � ������� ������� set.
//������� 2-� ������ ������������� � �����������.
//������� ��� ������ �� �����.
class Apple {
private:
	string variety;
	double weight;
public:
	Apple() {
		variety = "";
		weight = 0.0;
	}
	Apple(string fvariety, double fweight) {
		variety = fvariety;
		weight = fweight;
	}
	string getVariety() { return variety; }
	void setVariety(string fvariety) { variety = fvariety; }
	double getWeight() { return weight; }
	void setWeight(double fweight) { weight = fweight; }
	void print() { 
		cout << variety << " " << weight << " kg" << endl; 
	}
	
};

int main() {
	Apple a1;
	a1.setVariety("kalvin");
	a1.setWeight(100.54);
	Apple a2("renetka", 214.5);
	a1.print();
	a2.print();
}