// 执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
// 内存消耗 :8.3 MB, 在所有 C++ 提交中击败了47.18%的用户

class Solution {
public:
	int numTrees(int n) {
		vector<int> dp(n + 1);
		dp[0] = dp[1] = 1;
		for (int i = 2; i <= n; ++i) {
			for (int j = 0; j < i; ++j) {
				dp[i] += dp[j] * dp[i - j - 1];
			}
		}
		return dp[n];
	}
};



// 执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
// 内存消耗 :8.1 MB, 在所有 C++ 提交中击败了92.12%的用户

class Solution {
public:
	int numTrees(int n) {
		long res = 1;
		for (int i = n + 1; i <= 2 * n; ++i) {
			res = res * i / (i - n);
		}
		return res / (n + 1);
	}
};

