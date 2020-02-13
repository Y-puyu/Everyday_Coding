// 执行用时 :16 ms, 在所有 C++ 提交中击败了76.80%的用户
// 内存消耗 :20.9 MB, 在所有 C++ 提交中击败了13.68%的用户

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
	bool isValidBST(TreeNode* root) {
		return isValidBST(root, LONG_MIN, LONG_MAX);
	}
	bool isValidBST(TreeNode* root, long mn, long mx) {
		if (!root)
			return true;
		if (root->val <= mn || root->val >= mx)
			return false;
		return isValidBST(root->left, mn, root->val) && isValidBST(root->right, root->val, mx);
	}
};

// 执行用时 :16 ms, 在所有 C++ 提交中击败了76.80%的用户
// 内存消耗 :21.2 MB, 在所有 C++ 提交中击败了5.12%的用户
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
	bool isValidBST(TreeNode* root) {
		if (!root)
			return true;
		vector<int> vt;
		inorder(root, vt);
		for (int i = 0; i < vt.size() - 1; ++i) {
			if (vt[i] >= vt[i + 1])
				return false;
		}
		return true;
	}
	void inorder(TreeNode* root, vector<int>& vt) {
		if (!root) return;
		inorder(root->left, vt);
		vt.push_back(root->val);
		inorder(root->right, vt);
	}
};


// 执行用时 :28 ms, 在所有 C++ 提交中击败了10.98%的用户
// 内存消耗 :21.4 MB, 在所有 C++ 提交中击败了5.03%的用户

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
	vector<int> vt;
	void Inorder(TreeNode* root) {
		if (root) {
			Inorder(root->left);
			vt.push_back(root->val);
			Inorder(root->right);
		}
	}

	bool isValidBST(TreeNode* root) {
		Inorder(root);
		vector<int> tmp(vt.begin(), vt.end());
		sort(vt.begin(), vt.end());
		unique(vt.begin(), vt.end());
		vector<int>::iterator new_end = unique(vt.begin(), vt.end());
		vt.erase(new_end, vt.end());
		if (vt == tmp)
			return true;
		else
			return false;
	}
};


// 执行用时 :8 ms, 在所有 C++ 提交中击败了98.82%的用户
// 内存消耗 :20.7 MB, 在所有 C++ 提交中击败了25.55%的用户

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
	bool isValidBST(TreeNode* root) {
		TreeNode *pre = NULL;
		return inorder(root, pre);
	}
	bool inorder(TreeNode* node, TreeNode*& pre) {
		if (!node)
			return true;
		bool res = inorder(node->left, pre);
		if (!res)
			return false;
		if (pre) {
			if (node->val <= pre->val)
				return false;
		}
		pre = node;
		return inorder(node->right, pre);
	}
};

// 执行用时 :16 ms, 在所有 C++ 提交中击败了76.80%的用户
// 内存消耗 :20.7 MB, 在所有 C++ 提交中击败了22.94%的用户
class Solution {
public:
	bool isValidBST(TreeNode* root) {
		stack<TreeNode*> s;
		TreeNode *p = root, *pre = NULL;
		while (p || !s.empty()) {
			while (p) {
				s.push(p);
				p = p->left;
			}
			p = s.top(); s.pop();
			if (pre && p->val <= pre->val)
				return false;
			pre = p;
			p = p->right;
		}
		return true;
	}
};

// 执行用时 :12 ms, 在所有 C++ 提交中击败了92.89%的用户
// 内存消耗 :20.5 MB, 在所有 C++ 提交中击败了59.08%的用户.

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
	bool isValidBST(TreeNode *root) {
		if (!root) return true;
		TreeNode *cur = root, *pre, *parent = NULL;
		bool res = true;
		while (cur) {
			if (!cur->left) {
				if (parent && parent->val >= cur->val) res = false;
				parent = cur;
				cur = cur->right;
			}
			else {
				pre = cur->left;
				while (pre->right && pre->right != cur) pre = pre->right;
				if (!pre->right) {
					pre->right = cur;
					cur = cur->left;
				}
				else {
					pre->right = NULL;
					if (parent->val >= cur->val) res = false;
					parent = cur;
					cur = cur->right;
				}
			}
		}
		return res;
	}
};

