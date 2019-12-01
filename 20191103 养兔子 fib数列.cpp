// write your code here cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
	long long num[91] = { 1, 2 };
	for (int i = 2; i <= 90; ++i) {
		num[i] = num[i - 1] + num[i - 2];
	}
	int d;
	while (cin >> d)
		cout << num[d - 1] << endl;
	return 0;
}
