class Solution {
public:
	int reverse(int x) {
		int rev = 0;
		while (x != 0) {
			int pop = x % 10;
			x /= 10;
			if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
			if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
			rev = rev * 10 + pop;
		}
		return rev;
	}
};


// 执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
// 内存消耗 :8.3 MB, 在所有 C++ 提交中击败了19.02%的用户

class Solution {
public:
	int reverse(int x) {
		int res = 0;
		while (x != 0) {
			if (abs(res) > INT_MAX / 10) return 0;
			res = res * 10 + x % 10;
			x /= 10;
		}
		return res;
	}
};


// 执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
// 内存消耗 :8.3 MB, 在所有 C++ 提交中击败了10.92%的用户

class Solution {
public:
	int reverse(int x) {
		long res = 0;
		while (x != 0) {
			res = 10 * res + x % 10;
			x /= 10;
		}
		return (res > INT_MAX || res < INT_MIN) ? 0 : res;
	}
};
