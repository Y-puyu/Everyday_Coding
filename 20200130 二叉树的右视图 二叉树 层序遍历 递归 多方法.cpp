// 执行用时 :4 ms, 在所有 C++ 提交中击败了87.98%的用户
// 内存消耗 :10.2 MB, 在所有 C++ 提交中击败了5.01%的用户
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	vector<int> rightSideView(TreeNode *root) {
		vector<int> res;
		if (!root) return res;
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty()) {
			res.push_back(q.back()->val);
			int size = q.size();
			for (int i = 0; i < size; ++i) {
				TreeNode *node = q.front();
				q.pop();
				if (node->left) q.push(node->left);
				if (node->right) q.push(node->right);
			}
		}
		return res;
	}
};


// 执行用时 :8 ms, 在所有 C++ 提交中击败了44.48%的用户
// 内存消耗 :10 MB, 在所有 C++ 提交中击败了5.71%的用户
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
	vector<int> rightSideView(TreeNode* root) {
		vector<int> res;
		helper(root, 0, res);
		return res;
	}
	void helper(TreeNode* root, int level, vector<int>& res) {
		if (!root) return;
		if (res.size() == level) res.push_back(root->val);
		helper(root->right, level + 1, res);
		helper(root->left, level + 1, res);
	}
};
