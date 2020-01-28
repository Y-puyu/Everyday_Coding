class Solution {
public:
	int findUnsortedSubarray(vector<int>& nums) {
		int res = 0, start = -1, n = nums.size();
		for (int i = 1; i < n; ++i) {
			if (nums[i] < nums[i - 1]) {
				int j = i;
				while (j > 0 && nums[j] < nums[j - 1]) {
					swap(nums[j], nums[j - 1]);
					--j;
				}
				if (start == -1 || start > j) start = j;
				res = i - start + 1;
			}
		}
		return res;
	}
};

class Solution {
public:
	int findUnsortedSubarray(vector<int>& nums) {
		int n = nums.size(), i = 0, j = n - 1;
		vector<int> t = nums;
		sort(t.begin(), t.end());
		while (i < n && nums[i] == t[i]) ++i;
		while (j > i && nums[j] == t[j]) --j;
		return j - i + 1;
	}
};

class Solution {
public:
	int findUnsortedSubarray(vector<int>& nums) {
		int n = nums.size(), start = -1, end = -2;
		int mn = nums[n - 1], mx = nums[0];
		for (int i = 1; i < n; ++i) {
			mx = max(mx, nums[i]);
			mn = min(mn, nums[n - 1 - i]);
			if (mx > nums[i]) end = i;
			if (mn < nums[n - 1 - i]) start = n - 1 - i;
		}
		return end - start + 1;
	}
};


