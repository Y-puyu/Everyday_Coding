#include <bits/stdc++.h>

using namespace std;

// 素数判断

bool isPrime(int num) {
	int tmp = sqrt(num);        // 数学基础
	for (int i = 2; i <= tmp; ++i) {
		if (num % i == 0)
			return false;
	}
	return true;
}

int main() {
	int num, half, i;
	while (cin >> num) {
		half = num / 2;
		// 从中间行两边找
		for (i = half; i > 0; --i) {
			if (isPrime(i) && isPrime(num - i))
				break;
		}

		cout << i << endl << num - i << endl;
	}
	return 0;
}
