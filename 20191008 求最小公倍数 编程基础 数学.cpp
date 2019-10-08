// Topic link£ºhttps://www.nowcoder.com/practice/22948c2cad484e0291350abad86136c3?tpId=37&&tqId=21331&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
// Í¬²½CSDN

#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
	int r;
	while (r = a % b) {
		a = b;
		b = r;
	}

	return b;
}

int main() {
	int a, b;
	while (cin >> a >> b) {
		cout << (a * b) / gcd(a, b) << endl;
	}

	return 0;
}