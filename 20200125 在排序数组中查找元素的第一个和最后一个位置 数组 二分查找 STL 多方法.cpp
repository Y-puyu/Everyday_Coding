class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		int start = -1, end = -1;
		vector<int> res;
		for (int i = 0; i < nums.size(); ++i) {
			if (start == -1 && nums[i] == target) start = i;
			if (nums[i] == target) end = i;
		}
		res.emplace_back(start);
		res.emplace_back(end);
		return res;
	}
};


class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> ans = { -1, -1 };
		if (nums.empty()) return ans; // 数组为空的情况
		int l = 0, r = nums.size() - 1;
		if (nums[l] > target) return ans; // 若target不在数组范围内
		if (nums[r] < target) return ans;

		while (l < r) { // 先查找元素的第一个位置
			int mid = l + (r - l) / 2;
			if (nums[mid] >= target) r = mid;
			else l = mid + 1;
		} // 到出循环时，索引 l 和 r 在同一个位置，即查找元素的第一个位置
		if (nums[l] == target)   ans[0] = l; // 防止查找元素在数组位置内 但 数组内没有目标元素
		r = nums.size(); // 不设成 nums.size() - 1 的原因是，应对数组大小为一的情况，后面操作会超出索引。
		while (l < r) { // 查找元素的最后一个位置
			int mid = l + (r - l) / 2;
			if (nums[mid] > target) r = mid;
			else l = mid + 1;
		}
		// 到处循环时，l和r 在同一个位置，即 查找元素的最后一个位置的下一位
		if (nums[l - 1] == target)   ans[1] = l - 1;
		return ans;
	}
};

class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		//返回第一个大于等于target的迭代器
		auto left = lower_bound(nums.begin(), nums.end(), target);
		//返回第一个大于target的迭代器
		auto right = upper_bound(nums.begin(), nums.end(), target);
		if (left == right) return { -1,-1 };
		return { left - nums.begin(), right - nums.begin() - 1 };
	}
};