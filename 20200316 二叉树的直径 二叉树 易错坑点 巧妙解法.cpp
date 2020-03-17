// 执行用时 :8 ms, 在所有 C++ 提交中击败了95.78%的用户
// 内存消耗 :22.3 MB, 在所有 C++ 提交中击败了15.63%的用户

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
    int cnt = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr) return 0;
        maxDepth(root); 
        return cnt;
    }
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        if ((left + right) > cnt) cnt = left + right;
        return 1 + max(left, right);
    }
};
