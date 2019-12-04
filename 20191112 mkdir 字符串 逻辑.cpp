// write your code here cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	while (cin >> n) {
		vector<string> list(n);
		vector<bool> flag(n, true);
		for (int i = 0; i < n; ++i)
			cin >> list[i];
		sort(list.begin(), list.end());  // 将字符串排序放到一起

		for (int i = 0; i < list.size() - 1; ++i) {
			// 1. 两串相同
			// 2. 前串是后串的子串，而且后串是一位'/'
			if (list[i] == list[i + 1])
				flag[i] = false;
			else if (list[i].size() < list[i + 1].size() &&
				list[i] == list[i + 1].substr(0, list[i].size()) && list[i + 1][list[i].size()] == '/')
				flag[i] = false;
		}

		for (int i = 0; i < list.size(); ++i)
			if (flag[i])
				cout << "mkdir -p " << list[i] << endl;
		cout << endl;
	}
	return 0;
}
