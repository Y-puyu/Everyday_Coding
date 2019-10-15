#include <iostream>
using namespace std;
int main() {
	int array[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int year;
	int month;
	int day;
	int sum = 0;
	while (cin >> year >> month >> day) {
		sum = 0;
		for (int i = 0; i < month - 1; i++) {
			sum += array[i];
		}
		sum += day;
		if (month > 2) {
			if ((year % 4 == 0 && year % 100) || (year % 400 == 0)) {
				sum += 1;
			}
		}
		cout << sum << endl;
	}
}
