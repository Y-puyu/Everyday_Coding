// 执行用时 :8 ms, 在所有 C++ 提交中击败了98.78%的用户
// 内存消耗 :13.3 MB, 在所有 C++ 提交中击败了5.10%的用户

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int val = 0;
        for (int i = 0; i < nums.size(); ++i) val ^= nums[i];
        return val;
    }
};
