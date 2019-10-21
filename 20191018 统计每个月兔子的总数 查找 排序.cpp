#include <bits/stdc++.h>

using namespace std;

int main() {
	int month;
	while (cin >> month) {
		int first = 1;
		int second = 1;
		int result;
		if (month == 1 || month == 2)
			cout << 1;
		else {
			for (int i = 3; i <= month; ++i) {
				result = first + second;
				first = second;
				second = result;
			}
			cout << result << endl;
		}
	}
	return 0;
}
