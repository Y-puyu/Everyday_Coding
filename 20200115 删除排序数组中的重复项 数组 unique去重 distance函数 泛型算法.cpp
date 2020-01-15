class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		auto iter = unique(nums.begin(), nums.end());      //ÖØÅÅÈİÆ÷
		return iter - nums.begin();
	}
};


class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		return distance(nums.begin(), unique(nums.begin(), nums.end()));
	}
};

