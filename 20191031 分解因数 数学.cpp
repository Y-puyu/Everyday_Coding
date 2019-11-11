// write your code here cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, i;
	while (cin >> n) {
		cout << n << " = ";
		for (i = 2; i <= sqrt(n); ++i)
			if (n % i == 0) {
				while (n % i == 0) {
					n /= i;
					cout << i;
					if (n != 1)	// 素数情况
						cout << " * ";
				}
			}
		if (n != 1)	// 素数情况
			cout << n;
		cout << endl;
	}
	return 0;
}
