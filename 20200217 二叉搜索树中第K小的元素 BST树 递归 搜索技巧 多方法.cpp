// 执行用时 :24 ms, 在所有 C++ 提交中击败了70.31%的用户
// 内存消耗 :21.6 MB, 在所有 C++ 提交中击败了33.58%的用户

class Solution {
public:
	int kthSmallest(TreeNode* root, int k) {
		int cnt = 0;
		stack<TreeNode*> s;
		TreeNode *p = root;
		while (p || !s.empty()) {
			while (p) {
				s.push(p);
				p = p->left;
			}
			p = s.top();
			s.pop();
			++cnt;
			if (cnt == k)
				return p->val;
			p = p->right;
		}
		return 0;
	}
};


// 执行用时 :28 ms, 在所有 C++ 提交中击败了44.03%的用户
// 内存消耗 :22 MB, 在所有 C++ 提交中击败了6.89%的用户

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
	int InOrder(TreeNode* root, int& k) {
		if (root) {
			int val = InOrder(root->left, k);
			if (k == 0)
				return val;
			if (--k == 0)
				return root->val;
			return InOrder(root->right, k);
		}
		return -1;
	}

	int kthSmallest(TreeNode* root, int k) {
		return InOrder(root, k);
	}
};



// 执行用时 :20 ms, 在所有 C++ 提交中击败了88.64%的用户
// 内存消耗 :22.1 MB, 在所有 C++ 提交中击败了5.23%的用户

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
	int kthSmallest(TreeNode* root, int k) {
		int cnt = count(root->left);
		if (k <= cnt)
			return kthSmallest(root->left, k);
		else if (k > cnt + 1)
			return kthSmallest(root->right, k - cnt - 1);
		return root->val;
	}
	int count(TreeNode* node) {
		if (!node)
			return 0;
		return 1 + count(node->left) + count(node->right);
	}
};



// 执行用时 :32 ms, 在所有 C++ 提交中击败了24.55%的用户
// 内存消耗 :24.9 MB, 在所有 C++ 提交中击败了5.23%的用户

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


 /**
  * Definition for a binary tree node.
  * struct TreeNode {
  *     int val;
  *     TreeNode *left;
  *     TreeNode *right;
  *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  * };
  */


  // Follow up
class Solution {
public:
	struct MyTreeNode {
		int val;
		int count;
		MyTreeNode *left;
		MyTreeNode *right;
		MyTreeNode(int x) : val(x), count(1), left(NULL), right(NULL) {}
	};

	MyTreeNode* build(TreeNode* root) {
		if (!root)
			return NULL;
		MyTreeNode* node = new MyTreeNode(root->val);
		node->left = build(root->left);
		node->right = build(root->right);
		if (node->left)
			node->count += node->left->count;
		if (node->right)
			node->count += node->right->count;
		return node;
	}

	int kthSmallest(TreeNode* root, int k) {
		MyTreeNode *node = build(root);
		return helper(node, k);
	}

	int helper(MyTreeNode*& node, int k) {
		if (node == nullptr)
			return 0;
		if (node->left) {
			int cnt = node->left->count;
			if (k <= cnt)
				return helper(node->left, k);
			else if (k > cnt + 1)
				return helper(node->right, k - 1 - cnt);
			return node->val;
		}
		else {
			if (k == 1)
				return node->val;
			return helper(node->right, k - 1);
		}
	}
};
