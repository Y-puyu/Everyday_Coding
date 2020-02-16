// 执行用时 :52 ms, 在所有 C++ 提交中击败了92.41%的用户
// 内存消耗 :24.4 MB, 在所有 C++ 提交中击败了33.73%的用户

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
	BSTIterator(TreeNode *root) {
		while (root) {
			s.push(root);
			root = root->left;
		}
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		return !s.empty();
	}

	/** @return the next smallest number */
	int next() {
		TreeNode *n = s.top();
		s.pop();
		int res = n->val;
		if (n->right) {
			n = n->right;
			while (n) {
				s.push(n);
				n = n->left;
			}
		}
		return res;
	}
private:
	stack<TreeNode*> s;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
