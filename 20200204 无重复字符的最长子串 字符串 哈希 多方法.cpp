// 执行用时 :8 ms, 在所有 C++ 提交中击败了93.37%的用户
// 内存消耗 :10.1 MB, 在所有 C++ 提交中击败了55.72%的用户

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		vector<int> m(128, -1);
		int res = 0, left = -1;
		for (int i = 0; i < s.size(); ++i) {
			left = max(left, m[s[i]]);
			m[s[i]] = i;
			res = max(res, i - left);
		}
		return res;
	}
};

// 执行用时 :8 ms, 在所有 C++ 提交中击败了93.37%的用户
// 内存消耗 :10.1 MB, 在所有 C++ 提交中击败了55.85%的用户

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		vector<int> m(128, -1);
		int res = 0, left = -1;
		for (int i = 0; i < s.size(); ++i) {
			left = max(left, m[s[i]]);
			m[s[i]] = i;
			res = max(res, i - left);
		}
		return res;
	}
};


// 执行用时 :44 ms, 在所有 C++ 提交中击败了27.07%的用户
// 内存消耗 :13.6 MB, 在所有 C++ 提交中击败了21.27%的用户

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int res = 0, left = 0, i = 0, n = s.size();
		unordered_set<char> t;
		while (i < n) {
			if (!t.count(s[i])) {
				t.insert(s[i++]);
				res = max(res, (int)t.size());
			}
			else {
				t.erase(s[left++]);
			}
		}
		return res;
	}
};

