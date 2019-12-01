// write your code here cpp
#include <bits/stdc++.h>

using namespace std;

// 闰年判断
int LeapYear(int year) {
	return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
}

// 足年天数
int FullYear(int year) {
	return 2 * 31 + 1 * 28 + 1 * 31 + 2 * 30 + 1 * 31 + 2 * 30 + 1 * 31
		+ 2 * 31 + 2 * 30 + 2 * 31 + 1 * 30 + 2 * 31 + LeapYear(year);
}

// 判断该月是否为素数月
bool PrimeMonth(int n) {
	return n == 2 || n == 3 || n == 5 || n == 7 || n == 11;
}

// 求解当日为一年第几天
int DaysYear(int year, int month, int day) {
	if (!PrimeMonth(month))
		day *= 2;
	while (--month) {
		switch (month) {
		case 1:
		case 8:
		case 10:
		case 12:
			day += 62;
			break;
		case 3:
		case 5:
		case 7:
			day += 31;
			break;
		case 4:
		case 6:
		case 9:
			day += 60;
			break;
		case 11:
			day += 30;
			break;
		case 2:
			day += 28 + LeapYear(year);
			break;
		default:;
		}
	}
	return day;
}

int main() {
	int year1, month1, day1, year2, month2, day2;
	int count = 0;
	while (cin >> year1 >> month1 >> day1 >> year2 >> month2 >> day2) {
		count = 0;
		// 这里day1 - 1可能出现0日，但如2月0日即为1月31日，不影响结果
		count += FullYear(year1) - DaysYear(year1, month1, day1 - 1);
		count += DaysYear(year2, month2, day2);
		if (year1 == year2)
			count -= FullYear(year1);
		for (int i = year1 + 1; i < year2; ++i)
			count += FullYear(i);
		cout << count << endl;
	}
	return 0;
}
