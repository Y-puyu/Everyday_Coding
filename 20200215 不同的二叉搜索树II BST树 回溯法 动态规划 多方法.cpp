// 执行用时 :16 ms, 在所有 C++ 提交中击败了89.20%的用户
// 内存消耗 :17.6 MB, 在所有 C++ 提交中击败了8.51%的用户

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
	vector<TreeNode*> generateTrees(int n) {
		if (n == 0)
			return {};
		return help(1, n);
	}

	// 构建（start，end）的二叉树（得到的是所有可能存在的形式的集合）
	vector<TreeNode*> help(int start, int end) {
		if (start > end)
			return { nullptr };
		vector<TreeNode*> res;
		// 根节点为 i时，生成二叉搜索树
		for (int i = start; i <= end; ++i) {
			auto left = help(start, i - 1);     // 构建左子树（得到的是左子树所有可能存在的形式的集合）递归
			auto right = help(i + 1, end);      // 构建右子树（得到的是右子树所有可能存在的形式的集合）递归
			// 对所有左子树、右子树进行组合
			for (auto& a : left) {
				for (auto& b : right) {
					TreeNode* node = new TreeNode(i);
					// 将左、右子树合并到根节点下
					node->left = a;
					node->right = b;
					res.push_back(node);
				}
			}
		}
		/ 这里返回的是根节点的指针的vector
			// 这个返回值代表的意思是，这个ans里面存了所有当前树的根节点指针，
			// 就是，如果l=2,r=4,里面就保存了根节点为:2,3,4时候，所有子树的情况，
			// 而且，当根节点为3的时候，左右子树的根可以分别为[1,2]和[4]，那么，需要组合所有情况，
			// 就是，当根节点为3时，左右子树的根节点分别为[1,4]或者[2,4]
			// 通过这个根节点指针，可以找到相应的左子树和右子树，
			return res;
	}
};


// 执行用时 :20 ms, 在所有 C++ 提交中击败了75.17%的用户
// 内存消耗 :12.8 MB, 在所有 C++ 提交中击败了94.01%的用户

class Solution {
public:
	vector<TreeNode*> generateTrees(int n) {
		if (n == 0)
			return {};
		vector<vector<vector<TreeNode*>>> memo(n, vector<vector<TreeNode*>>(n));
		return helper(1, n, memo);
	}
	vector<TreeNode*> helper(int start, int end, vector<vector<vector<TreeNode*>>>& memo) {
		if (start > end)
			return { nullptr };
		if (!memo[start - 1][end - 1].empty())
			return memo[start - 1][end - 1];
		vector<TreeNode*> res;
		for (int i = start; i <= end; ++i) {
			auto left = helper(start, i - 1, memo), right = helper(i + 1, end, memo);
			for (auto a : left) {
				for (auto b : right) {
					TreeNode *node = new TreeNode(i);
					node->left = a;
					node->right = b;
					res.push_back(node);
				}
			}
		}
		return memo[start - 1][end - 1] = res;
	}
};
