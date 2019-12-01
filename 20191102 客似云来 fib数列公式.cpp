// write your code here cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
	long long fib[100001] = { 0 };
	fib[0] = 1;
	fib[1] = 1;
	for (int i = 2; i <= 100000; ++i) {
		fib[i] = fib[i - 1] + fib[i - 2];
	}
	int n, m;
	while (cin >> n >> m) {
		n -= 1;
		m -= 1;
		long long count = 0;
		for (int i = n; i <= m; ++i)
			count += fib[i];
		cout << count << endl;
	}
	return 0;
}
