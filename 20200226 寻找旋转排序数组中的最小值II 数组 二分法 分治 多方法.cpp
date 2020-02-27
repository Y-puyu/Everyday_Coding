// 执行用时 :4 ms, 在所有 C++ 提交中击败了97.71%的用户
// 内存消耗 :14.5 MB, 在所有 C++ 提交中击败了5.51%的用户

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[right]) 
                left = mid + 1;
            else if (nums[mid] < nums[right]) 
                right = mid;
            else 
                --right;
        }
        return nums[right];
    }
};


// 执行用时 :12 ms, 在所有 C++ 提交中击败了17.42%的用户
// 内存消耗 :14.7 MB, 在所有 C++ 提交中击败了5.15%的用户

class Solution {
public:
    int findMin(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }
    int helper(vector<int>& nums, int start, int end) {
        if (start == end) 
            return nums[start];
        if (nums[start] < nums[end]) 
            return nums[start];
        int mid = (start + end) / 2;
        return min(helper(nums, start, mid), helper(nums, mid + 1, end));
    }
};
