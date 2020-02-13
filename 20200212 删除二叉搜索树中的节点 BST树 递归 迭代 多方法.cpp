// 执行用时 :28 ms, 在所有 C++ 提交中击败了84.50%的用户
// 内存消耗 :12.8 MB, 在所有 C++ 提交中击败了23.01%的用户

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
	TreeNode* deleteNode(TreeNode* root, int key) {
		if (root == nullptr)
			return nullptr;
		TreeNode* cur = root;
		TreeNode* parent = nullptr;
		while (cur) {
			if (cur->val == key)
				break;
			else if (cur->val > key) {
				parent = cur;
				cur = cur->left;
			}
			else {
				parent = cur;
				cur = cur->right;
			}
		}

		if (cur == nullptr)
			return root;
		if (cur->left == nullptr && cur->right == nullptr) {
			if (cur != root) {
				if (parent->left == cur)
					parent->left = nullptr;
				else
					parent->right = nullptr;
			}
			else
				root = nullptr;
			delete cur;
			cur = nullptr;
		}

		else if (cur->left == nullptr) {
			if (cur != root) {
				if (parent->left == cur)
					parent->left = cur->right;
				else
					parent->right = cur->right;
			}
			else
				root = cur->right;
			delete cur;
			cur = nullptr;
		}
		else if (cur->right == nullptr) {
			if (cur != root) {
				if (parent->left == cur)
					parent->left = cur->left;
				else
					parent->right = cur->left;
			}
			else {
				root = cur->left;
			}
			delete cur;
			cur = nullptr;
		}
		else {
			TreeNode* leftMost = cur->left;
			parent = cur;
			while (leftMost->right) {
				parent = leftMost;
				leftMost = leftMost->right;
			}
			cur->val = leftMost->val;
			if (parent->right == leftMost)
				parent->right = leftMost->left;
			else
				parent->left = leftMost->left;
			delete leftMost;
			leftMost = nullptr;
		}
		return root;
	}
};


// 执行用时 :140 ms, 在所有 C++ 提交中击败了66.29%的用户
// 内存消耗 :35.5 MB, 在所有 C++ 提交中击败了36.81%的用户

class Solution {
public:
	bool canCross(vector<int>& stones) {
		unordered_map<int, unordered_set<int>> m;
		vector<int> dp(stones.size(), 0);
		m[0].insert(0);
		int k = 0;
		for (int i = 1; i < stones.size(); ++i) {
			while (dp[k] + 1 < stones[i] - stones[k]) ++k;
			for (int j = k; j < i; ++j) {
				int t = stones[i] - stones[j];
				if (m[j].count(t - 1) || m[j].count(t) || m[j].count(t + 1)) {
					m[i].insert(t);
					dp[i] = max(dp[i], t);
				}
			}
		}
		return dp.back() > 0;
	}
};


// 执行用时 :20 ms, 在所有 C++ 提交中击败了98.71%的用户
// 内存消耗 :12.7 MB, 在所有 C++ 提交中击败了43.44%的用户

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
	TreeNode* deleteNode(TreeNode* root, int key) {
		if (!root)
			return nullptr;
		TreeNode *cur = root, *pre = nullptr;
		while (cur) {
			if (cur->val == key)
				break;
			pre = cur;
			if (cur->val > key)
				cur = cur->left;
			else
				cur = cur->right;
		}
		if (!pre)
			return del(cur);
		if (pre->left && pre->left->val == key)
			pre->left = del(cur);
		else
			pre->right = del(cur);
		return root;
	}
	TreeNode* del(TreeNode* node) {
		if (!node)
			return nullptr;
		if (!node->right)
			return node->left;
		TreeNode *t = node->right;
		while (t->left)
			t = t->left;
		t->left = node->left;
		return node->right;
	}
};


// 执行用时 :20 ms, 在所有 C++ 提交中击败了98.71%的用户
// 内存消耗 :12.9 MB, 在所有 C++ 提交中击败了43.44%的用户

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
	TreeNode* deleteNode(TreeNode* root, int key) {
		if (!root)
			return NULL;
		if (root->val == key) {
			if (!root->right)
				return root->left;
			else {
				TreeNode *cur = root->right;
				while (cur->left)
					cur = cur->left;
				swap(root->val, cur->val);
			}
		}
		root->left = deleteNode(root->left, key);
		root->right = deleteNode(root->right, key);
		return root;
	}
};

