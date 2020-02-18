// 执行用时 :20 ms, 在所有 C++ 提交中击败了44.91%的用户
// 内存消耗 :17.7 MB, 在所有 C++ 提交中击败了9.19%的用户

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
	bool isBalanced(TreeNode* root) {
		if (root == nullptr)
			return true;
		if (abs(getDepth(root->left) - getDepth(root->right)) > 1)
			return false;
		return isBalanced(root->left) && isBalanced(root->right);
	}

	int getDepth(TreeNode* & root) {
		if (root == nullptr)
			return 0;
		return 1 + max(getDepth(root->left), getDepth(root->right));
	}
};


// 执行用时 :20 ms, 在所有 C++ 提交中击败了44.91%的用户
// 内存消耗 :17.6 MB, 在所有 C++ 提交中击败了9.28%的用户

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
	bool isBalanced(TreeNode *root) {
		if (checkDepth(root) == -1)
			return false;
		else
			return true;
	}
	int checkDepth(TreeNode *root) {
		if (!root)
			return 0;
		int left = checkDepth(root->left);
		if (left == -1)
			return -1;
		int right = checkDepth(root->right);
		if (right == -1)
			return -1;
		int diff = abs(left - right);
		if (diff > 1)
			return -1;
		else
			return 1 + max(left, right);
	}
};

