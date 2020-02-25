// 执行用时 :12 ms, 在所有 C++ 提交中击败了42.40%的用户
// 内存消耗 :12.5 MB, 在所有 C++ 提交中击败了5.37%的用户

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[right]) 
                left = mid + 1;
            else 
                right = mid;
        }
        return nums[right];
    }
};


// 执行用时 :8 ms, 在所有 C++ 提交中击败了42.40%的用户
// 内存消耗 :12.7 MB, 在所有 C++ 提交中击败了5.37%的用户

class Solution {
public:
    int findMin(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }
    int helper(vector<int>& nums, int start, int end) {
        if (nums[start] <= nums[end]) 
            return nums[start];
        int mid = (start + end) / 2;
        return min(helper(nums, start, mid), helper(nums, mid + 1, end));
    }
};
