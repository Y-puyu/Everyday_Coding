// 执行用时 :20 ms, 在所有 C++ 提交中击败了86.59%的用户
// 内存消耗 :11.6 MB, 在所有 C++ 提交中击败了12.01%的用户

class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		unordered_map<int, int> m;
		priority_queue<pair<int, int>> q;
		vector<int> res;
		for (auto a : nums) ++m[a];
		for (auto it : m) q.push({ it.second, it.first });
		for (int i = 0; i < k; ++i) {
			res.push_back(q.top().second); q.pop();
		}
		return res;
	}
};


// 执行用时 :20 ms, 在所有 C++ 提交中击败了86.59%的用户
// 内存消耗 :13.3 MB, 在所有 C++ 提交中击败了5.06%的用户

class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		unordered_map<int, int> m;
		vector<vector<int>> bucket(nums.size() + 1);
		vector<int> res;
		for (auto a : nums) ++m[a];
		for (auto it : m) {
			bucket[it.second].push_back(it.first);
		}
		for (int i = nums.size(); i >= 0; --i) {
			for (int j = 0; j < bucket[i].size(); ++j) {
				res.push_back(bucket[i][j]);
				if (res.size() == k) return res;
			}
		}
		return res;
	}
};
