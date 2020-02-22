// 执行用时 :24 ms, 在所有 C++ 提交中击败了46.72%的用户
// 内存消耗 :11 MB, 在所有 C++ 提交中击败了37.59%的用户

class Solution {
public:
	bool judgePoint24(vector<int>& nums) {
		bool res = false;
		double eps = 0.001;
		vector<double> arr(nums.begin(), nums.end());
		helper(arr, eps, res);
		return res;
	}

	void helper(vector<double>& nums, double eps, bool& res) {
		if (res)
			return;
		if (nums.size() == 1) {
			if (abs(nums[0] - 24) < eps)
				res = true;
			return;
		}
		for (int i = 0; i < nums.size(); ++i) {
			for (int j = 0; j < i; ++j) {
				double p = nums[i], q = nums[j];
				vector<double> t{ p + q, p - q, q - p, p * q };
				if (p > eps)
					t.push_back(q / p);
				if (q > eps)
					t.push_back(p / q);
				nums.erase(nums.begin() + i);
				nums.erase(nums.begin() + j);
				for (double e : t) {
					nums.push_back(e);
					helper(nums, eps, res);
					nums.pop_back();
				}
				nums.insert(nums.begin() + j, q);
				nums.insert(nums.begin() + i, p);
			}
		}
	}
};


// 执行用时 :28 ms, 在所有 C++ 提交中击败了41.39%的用户
// 内存消耗 :10 MB, 在所有 C++ 提交中击败了51.88%的用户

class Solution {
public:
	bool judgePoint24(vector<int>& nums) {
		double eps = 0.001;
		vector<char> ops{ '+', '-', '*', '/' };
		vector<double> arr(nums.begin(), nums.end());
		return helper(arr, ops, eps);
	}
	bool helper(vector<double>& nums, vector<char>& ops, double eps) {
		if (nums.size() == 1)
			return abs(nums[0] - 24) < eps;
		for (int i = 0; i < nums.size(); ++i) {
			for (int j = 0; j < nums.size(); ++j) {
				if (i == j)
					continue;
				vector<double> t;
				for (int k = 0; k < nums.size(); ++k) {
					if (k != i && k != j) t.push_back(nums[k]);
				}
				for (char op : ops) {
					if ((op == '+' || op == '*') && i > j)
						continue;
					if (op == '/' && nums[j] < eps)
						continue;
					switch (op) {
					case '+': t.push_back(nums[i] + nums[j]); break;
					case '-': t.push_back(nums[i] - nums[j]); break;
					case '*': t.push_back(nums[i] * nums[j]); break;
					case '/': t.push_back(nums[i] / nums[j]); break;
					}
					if (helper(t, ops, eps))
						return true;
					t.pop_back();
				}
			}
		}
		return false;
	}
};
