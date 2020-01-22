// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> record;
		for (int i = 0; i < nums.size(); i++) {

			int complement = target - nums[i];
			if (record.find(complement) != record.end()) {
				int res[] = { i, record[complement] };
				return vector<int>(res, res + 2);
			}

			record[nums[i]] = i;
		}
	}
};


// 时间复杂度：O(n^2)
// 空间复杂度：O(1)
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> vt(2, 0);
		for (int i = 0; i < nums.size() - 1; ++i) {
			for (int j = i + 1; j < nums.size(); ++j) {
				if (nums[i] + nums[j] == target) {
					vt[0] = i;
					vt[1] = j;
					break;
				}
			}
		}
		return vt;
	}
};

