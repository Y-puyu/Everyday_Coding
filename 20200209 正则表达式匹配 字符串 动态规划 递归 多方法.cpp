// 执行用时 :252 ms, 在所有 C++ 提交中击败了27.61%的用户
// 内存消耗 :12.3 MB, 在所有 C++ 提交中击败了29.00%的用户

class Solution {
public:
	bool isMatch(string s, string p) {
		if (p.empty()) return s.empty();
		if (p.size() == 1) {
			return (s.size() == 1 && (s[0] == p[0] || p[0] == '.'));
		}
		if (p[1] != '*') {
			if (s.empty()) return false;
			return (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1));
		}
		while (!s.empty() && (s[0] == p[0] || p[0] == '.')) {
			if (isMatch(s, p.substr(2))) return true;
			s = s.substr(1);
		}
		return isMatch(s, p.substr(2));
	}
};


// 执行用时 :308 ms, 在所有 C++ 提交中击败了15.39%的用户
// 内存消耗 :15.7 MB, 在所有 C++ 提交中击败了8.27%的用户

class Solution {
public:
	bool isMatch(string s, string p) {
		if (p.empty()) return s.empty();
		if (p.size() > 1 && p[1] == '*') {
			return isMatch(s, p.substr(2)) || (!s.empty() && (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p));
		}
		else {
			return !s.empty() && (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1));
		}
	}
};


// 执行用时 :12 ms, 在所有 C++ 提交中击败了62.31%的用户
// 内存消耗 :9.3 MB, 在所有 C++ 提交中击败了43.97%的用户

class Solution {
public:
	bool isMatch(string s, string p) {
		int m = s.size(), n = p.size();
		vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
		dp[0][0] = true;
		for (int i = 0; i <= m; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (j > 1 && p[j - 1] == '*') {
					dp[i][j] = dp[i][j - 2] || (i > 0 && (s[i - 1] == p[j - 2] || p[j - 2] == '.') && dp[i - 1][j]);
				}
				else {
					dp[i][j] = i > 0 && dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
				}
			}
		}
		return dp[m][n];
	}
};

