// write your code here cpp、
#include <bits/stdc++.h>

using namespace std;

int main() {
	long long n;
	int cnt;
	while (cin >> n) {
		if (n == 0)
			break;
		cnt = 0;
		while (n >= 2) {
			if (n % 3)
				// 不可以整除则取最差情况；最重的一份为n/3 + 1个金币
				n = n / 3 + 1;
			else
				n /= 3;
			cnt++;
		}
		cout << cnt << endl;
	}
	return 0;
}