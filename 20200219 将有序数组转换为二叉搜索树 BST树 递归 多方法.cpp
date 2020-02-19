// 执行用时 :16 ms, 在所有 C++ 提交中击败了87.61%的用户
// 内存消耗 :21.3 MB, 在所有 C++ 提交中击败了21.68%的用户

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		return helper(nums, 0, (int)nums.size() - 1);
	}
	TreeNode* helper(vector<int>& nums, int left, int right) {
		if (left > right)
			return NULL;
		int mid = left + (right - left) / 2;
		TreeNode *cur = new TreeNode(nums[mid]);
		cur->left = helper(nums, left, mid - 1);
		cur->right = helper(nums, mid + 1, right);
		return cur;
	}
};


// 执行用时 :24 ms, 在所有 C++ 提交中击败了50.99%的用户
// 内存消耗 :24.8 MB, 在所有 C++ 提交中击败了7.71%的用户

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		if (nums.empty())
			return NULL;
		int mid = nums.size() / 2;
		TreeNode *cur = new TreeNode(nums[mid]);
		vector<int> left(nums.begin(), nums.begin() + mid), right(nums.begin() + mid + 1, nums.end());
		cur->left = sortedArrayToBST(left);
		cur->right = sortedArrayToBST(right);
		return cur;
	}
};
