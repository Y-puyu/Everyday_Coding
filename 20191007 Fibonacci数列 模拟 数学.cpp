// Topic link：https://www.nowcoder.com/practice/18ecd0ecf5ef4fe9ba3f17f8d00d2d66?tpId=85&&tqId=29846&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking
// 同步CSDN

#include <bits/stdc++.h>

using namespace std;

int main() {
	int N, f, l = 0, r = 0, f0 = 0, f1 = 1;
	cin >> N;
	while (1) {
		f = f0 + f1;
		f0 = f1;
		f1 = f;
		// 找到比N小且距离N最近的数，求出距离
		if (f < N)
			l = N - f;
		else {
			// 找到比N大且距离N最近的数，求出距离
			r = f - N;
			break;
		}
	}

	// 取最小距离
	cout << min(l, r) << endl;
	return 0;
}
