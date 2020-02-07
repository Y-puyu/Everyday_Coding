// 执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
// 内存消耗 :9.3 MB, 在所有 C++ 提交中击败了17.23%的用户

class Solution {
public:
	int strStr(string haystack, string needle) {
		return haystack.find(needle);
	}
};


// 执行用时 :4 ms, 在所有 C++ 提交中击败了93.63%的用户
// 内存消耗 :9.3 MB, 在所有 C++ 提交中击败了17.69%的用户

class Solution {
public:
	int strStr(string haystack, string needle) {
		if (needle.empty()) return 0;
		int m = haystack.size(), n = needle.size();
		if (m < n) return -1;
		for (int i = 0; i <= m - n; ++i) {
			int j = 0;
			for (j = 0; j < n; ++j) {
				if (haystack[i + j] != needle[j]) break;
			}
			if (j == n) return i;
		}
		return -1;
	}
};


// 执行用时 :8 ms, 在所有 C++ 提交中击败了58.17%的用户
// 内存消耗 :9.2 MB, 在所有 C++ 提交中击败了29.70%的用户

class Solution {
public:
	int strStr(string haystack, string needle) {
		for (int i = 0; ; ++i) {
			for (int j = 0; ; ++j) {
				if (j == needle.size()) return i;
				if (i + j == haystack.size()) return -1;
				if (needle[j] != haystack[i + j]) break;
			}
		}
		return -1;
	}
};


// 执行用时 :4 ms, 在所有 C++ 提交中击败了93.63%的用户
// 内存消耗 :9.5 MB, 在所有 C++ 提交中击败了9.10%的用户

class Solution {
public:
	int strStr(string haystack, string needle) {
		return kmp(haystack, needle);
	}

	vector<int> getNext(string p) {
		int n = p.size(), k = -1, j = 0;
		vector<int> next(n, -1);
		while (j < n - 1) {
			if (k == -1 || p[j] == p[k]) {
				++k; ++j;
				next[j] = (p[j] != p[k]) ? k : next[k];
			}
			else {
				k = next[k];
			}
		}
		return next;
	}
	int kmp(string s, string p) {
		int m = s.size(), n = p.size(), i = 0, j = 0;
		vector<int> next = getNext(p);
		while (i < m && j < n) {
			if (j == -1 || s[i] == p[j]) {
				++i; ++j;
			}
			else {
				j = next[j];
			}
		}
		return (j == n) ? i - j : -1;
	}
};
