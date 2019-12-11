// write your code here cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	while (cin >> n) {
		// 接受用户输入的数据
		vector<int> height(n, 0);
		for (int i = 0; i < n; i++) {
			cin >> height[i];
		}
		// f用来保存状态转移方程的结果，f[i]表示以height[i]结尾的最长上升子序列所包含元素的个数
		vector<int> f(n, 1);
		int result = 1;
		// 子序列中的数据一个一个增加
		for (int i = 1; i < n; ++i) {
			// 从0开始统计到i位置，最长上升子序列长度
			for (int j = 0; j < i; ++j) {
				if (height[i] > height[j])
					f[i] = max(f[i], f[j] + 1);
			}
			// 获取从0到i位置的最长子序列长度
			result = max(result, f[i]);
		}
		cout << result << endl;
	}
}
