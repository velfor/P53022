#include <iostream>
using namespace std;
//Написать класс Apple. У класса должно быть 2 поля - сорт и вес.
//Написать оба конструктора, методы get и set для полей, метод
//print, который выводит информацию о яблоках на экран.
//Создать 1-е яблоко с помощью конструктора без параметров.
//Записать в него информацию с помощью методов set.
//Создать 2-е яблоко конструктором с параметрами.
//Вывести оба яблока на экран.
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