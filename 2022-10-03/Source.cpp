#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "rus");
	/*int day;	cin >> day;	switch (day) {		case 1: cout << "monday" << endl; break;		case 2: cout << "tuesday" << endl; break;		case 3: cout << "wednesday" << endl; break;		case 4: cout << "thursday" << endl; break;		case 5: cout << "friday" << endl; break;		case 6: cout << "saturday" << endl; break;		case 7: cout << "sunday" << endl; break;		default: cout << "wrong day number" << endl;	}*/	/*Case2.Дано целое число K.Вывести строку - описание оценки, соответствующей числу K(1 — «плохо», 2 — «неудовлетворительно», 3 — «удовлетворительно», 4 — «хорошо», 5 — «отлично»).Если K не лежит в диапазоне 1–5,
		то вывести строку «ошибка».*/
	/*int mark;
	cin >> mark;
	switch (mark) {
	case 1: cout << "плохо" << endl; break;
	case 2: cout << "неудовлетворительно" << endl; break;
	case 3: cout << "удовлетворительно" << endl; break;
	case 4: cout << "хорошо" << endl; break;
	case 5: cout << "отлично" << endl; break;
	default: cout << "нет такой оценки" << endl;
	}*/
	/*Case3.Дан номер месяца — целое число в диапазоне 1–12(1 — январь, 2 — февраль и т.д.).Вывести название соответствующего времени года(«зима»,
		«весна», «лето», «осень»).*/	int month;	cin >> month;	switch (month) {	case 1:	case 2:	case 12: cout << "winter" << endl; break;	case 3:	case 4:	case 5: cout << "spring" << endl; break;	case 6:	case 7:	case 8: cout << "summer" << endl; break;	case 9:	case 10:	case 11: cout << "autumn" << endl; break;	}
	
}