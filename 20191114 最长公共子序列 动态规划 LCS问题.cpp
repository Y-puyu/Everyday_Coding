// write your code here cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
	string s1, s2;
	while (cin >> s1 >> s2) {
		int s1Length = s1.length();
		int s2Length = s2.length();
		// 用来保存状态转移方程中间结果的矩阵
		vector<vector<int>> dp(s1Length, vector<int>(s2Length, 0));
		// 初始化dp矩阵边界：边界要么在，要么不在
		dp[0][0] = (s1[0] == s2[0]) ? 1 : 0;
		for (int i = 1; i < s1Length; ++i) {
			dp[i][0] = (s1[i] == s2[0]) ? 1 : 0;
			dp[i][0] = max(dp[i - 1][0], dp[i][0]);
		}
		for (int j = 1; j < s2Length; ++j) {
			dp[0][j] = (s1[0] == s2[j]) ? 1 : 0;
			dp[0][j] = max(dp[0][j - 1], dp[0][j]);
		}

		// 根据状态转移方程进行计算
		for (int i = 1; i < s1Length; ++i) {
			for (int j = 1; j < s2Length; ++j) {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				if (s1[i] == s2[j])
					dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
			}
		}
		cout << dp[s1Length - 1][s2Length - 1] << endl;
	}
	return 0;
}
