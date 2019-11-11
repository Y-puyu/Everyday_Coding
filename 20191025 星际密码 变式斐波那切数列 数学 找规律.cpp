// write your code here cpp
#include <bits/stdc++.h>

using namespace std;

vector<int> a = { 1, 1 };

void datainit() {
	for (int i = 2; i < 10005; ++i)
		a.push_back((a[i - 1] + a[i - 2]) % 10000);	// 变式斐波拉切数列
}

int main() {
	int n, t;
	datainit();
	while (cin >> n) {
		while (n--) {
			cin >> t;
			printf("%04d", a[t]);
		}
		cout << endl;
	}
	return 0;
}
