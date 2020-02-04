// 执行用时 :48 ms, 在所有 C++ 提交中击败了68.87%的用户
// 内存消耗 :104.1 MB, 在所有 C++ 提交中击败了26.91%的用户

class Solution {
public:
	string longestPalindrome(string s) {
		if (s.size() < 2) return s;
		int n = s.size(), maxLen = 0, start = 0;
		for (int i = 0; i < n - 1; ++i) {
			searchPalindrome(s, i, i, start, maxLen);
			searchPalindrome(s, i, i + 1, start, maxLen);
		}
		return s.substr(start, maxLen);
	}
	void searchPalindrome(string s, int left, int right, int& start, int& maxLen) {
		while (left >= 0 && right < s.size() && s[left] == s[right]) {
			--left; ++right;
		}
		if (maxLen < right - left - 1) {
			start = left + 1;
			maxLen = right - left - 1;
		}
	}
};


// 执行用时 :8 ms, 在所有 C++ 提交中击败了96.95%的用户
// 内存消耗 :8.9 MB, 在所有 C++ 提交中击败了79.79%的用户

class Solution {
public:
	string longestPalindrome(string s) {
		if (s.size() < 2) return s;
		int n = s.size(), maxLen = 0, start = 0;
		for (int i = 0; i < n; ) {
			if (n - i <= maxLen / 2) break;
			int left = i, right = i;
			while (right < n - 1 && s[right + 1] == s[right]) {
				++right;
			}
			i = right + 1;
			while (right < n - 1 && left > 0 && s[right + 1] == s[left - 1]) {
				++right;
				--left;
			}
			if (maxLen < right - left + 1) {
				maxLen = right - left + 1;
				start = left;
			}
		}
		return s.substr(start, maxLen);
	}
};


// 执行用时 :292 ms, 在所有 C++ 提交中击败了18.00%的用户
// 内存消耗 :13.1 MB, 在所有 C++ 提交中击败了58.43%的用户

class Solution {
public:
	string longestPalindrome(string s) {
		if (s.empty()) return "";
		int n = s.size(), dp[n][n] = { 0 }, left = 0, len = 1;
		for (int i = 0; i < n; ++i) {
			dp[i][i] = 1;
			for (int j = 0; j < i; ++j) {
				dp[j][i] = (s[i] == s[j] && (i - j < 2 || dp[j + 1][i - 1]));
				if (dp[j][i] && len < i - j + 1) {
					len = i - j + 1;
					left = j;
				}
			}
		}
		return s.substr(left, len);
	}
};


// 执行用时 :8 ms, 在所有 C++ 提交中击败了96.95%的用户
// 内存消耗 :9.2 MB, 在所有 C++ 提交中击败了76.59%的用户

class Solution {
public:
	string longestPalindrome(string s) {
		string t = "$#";
		for (int i = 0; i < s.size(); ++i) {
			t += s[i];
			t += '#';
		}
		int p[t.size()] = { 0 }, id = 0, mx = 0, resId = 0, resMx = 0;
		for (int i = 1; i < t.size(); ++i) {
			p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;
			while (t[i + p[i]] == t[i - p[i]]) ++p[i];
			if (mx < i + p[i]) {
				mx = i + p[i];
				id = i;
			}
			if (resMx < p[i]) {
				resMx = p[i];
				resId = i;
			}
		}
		return s.substr((resId - resMx) / 2, resMx - 1);
	}
};
