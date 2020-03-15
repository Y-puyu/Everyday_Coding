// 执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
// 内存消耗 :9.5 MB, 在所有 C++ 提交中击败了5.34%的用户

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        vector<int> dp(nums.size(), 0);
        dp[0]=nums[0];
        dp[1]=max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); ++i) {
            dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);
        }
        return dp.back();
    }
};
