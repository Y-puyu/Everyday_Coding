// write your code here cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
	int fib[100001];
	fib[0] = 1;
	fib[1] = 1;
	// 提前计算斐波那契数列，只保留后6位
	for (int i = 2; i <= 100000; ++i) {
		fib[i] = fib[i - 1] + fib[i - 2];
		fib[i] = fib[i] % 1000000;  // 由于只是相加，所以只要后六位不影响下一个数的结果
	}

	int n;
	while (cin >> n) {
		if (n < 29)
			cout << fib[n] << endl;
		else
			// printf("%06d\n", fib[n]);
			cout << setw(6) << setfill('0') << fib[n] << endl;
	}
	return 0;
}
