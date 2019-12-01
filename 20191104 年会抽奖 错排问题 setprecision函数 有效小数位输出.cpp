// write your code here cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
	long long d[22] = { 0, 0, 1 };  // 错排数量，预留第一项为0，配合下文中国输入的n
	long long f[22] = { 0, 1, 2 };  // 阶乘
	for (int i = 3; i < 22; ++i) {
		d[i] = (i - 1) * (d[i - 1] + d[i - 2]);  // 错排的递推公式
		f[i] = i * f[i - 1];  // 阶乘的递推公式
	}

	int n;
	while (cin >> n) {
		cout.setf(ios::fixed);
		cout << setprecision(2) << 100.0 * d[n] / f[n] << "%" << endl;
		// printf("%.2f%%\n", 100.0 * d[n] / f[n]); //用100.0来把结果处理成double，保留两位小数

	}
	return 0;
}
