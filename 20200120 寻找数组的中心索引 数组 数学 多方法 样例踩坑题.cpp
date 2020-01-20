class Solution {
public:
	int pivotIndex(vector<int>& nums) {
		if (nums.size() == 0) return -1;
		int sumtotal = 0;
		for (int i = 0; i < nums.size(); i++) {
			sumtotal += nums[i];
		}
		int sumleft = 0;
		for (int i = 0; i < nums.size(); i++) {
			if (sumleft * 2 == sumtotal - nums[i]) return i;
			sumleft += nums[i];
		}
		return -1;
	}
};


class Solution {
public:
	int pivotIndex(vector<int>& nums) {
		if (nums.size() == 0) return -1;
		vector<int> nums1(nums.size() + 2, 0);
		vector<int> nums2(nums.size() + 2, 0);
		int cnt = 0;
		for (int i = 0; i < nums.size(); ++i) {
			cnt += nums[i];
			nums1[i + 1] = cnt;
		}
		cnt = 0;
		for (int j = nums.size() - 1; j >= 0; --j) {
			cnt += nums[j];
			nums2[j + 1] = cnt;
		}
		for (int i = 1; i < nums1.size() - 1; ++i) {
			if (nums1[i - 1] == nums2[i + 1]) return i - 1;
		}
		return -1;
	}
};