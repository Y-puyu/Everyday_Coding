class Solution {
	public int removeElement(int[] nums, int val) {
		int i = 0, j = 0;
		while (j < nums.length) {
			if (nums[j] != val) {
				nums[i++] = nums[j++]; // nums[j] != val，这个元素需要保留
			}
			else {
				j++;  // nums[j] == val，不用保留，直接忽略，往后遍历
			}
		}
		return i;
	}
}




class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int i = 0;
		int n = nums.size();
		while (i < n) {
			if (nums[i] == val) {
				nums[i] = nums[n - 1];
				// reduce array size by one
				n--;
			}
			else {
				i++;
			}
		}
		return n;
	}
};
