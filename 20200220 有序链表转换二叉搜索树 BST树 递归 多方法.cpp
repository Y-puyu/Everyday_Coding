// 执行用时 :20 ms, 在所有 C++ 提交中击败了97.62%的用户
// 内存消耗 :24.6 MB, 在所有 C++ 提交中击败了37.78%的用户

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
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
class Solution {
public:
	TreeNode *sortedListToBST(ListNode* head) {
		if (!head)
			return NULL;
		if (!head->next)
			return new TreeNode(head->val);
		ListNode *slow = head, *fast = head, *last = slow;
		while (fast->next && fast->next->next) {
			last = slow;
			slow = slow->next;
			fast = fast->next->next;
		}
		fast = slow->next;
		last->next = NULL;
		TreeNode *cur = new TreeNode(slow->val);
		if (head != slow)
			cur->left = sortedListToBST(head);
		cur->right = sortedListToBST(fast);
		return cur;
	}
};


// 执行用时 :32 ms, 在所有 C++ 提交中击败了69.24%的用户
// 内存消耗 :24.9 MB, 在所有 C++ 提交中击败了22.57%的用户

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
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
class Solution {
public:
	TreeNode* sortedListToBST(ListNode* head) {
		if (!head)
			return NULL;
		return helper(head, NULL);
	}
	TreeNode* helper(ListNode* head, ListNode* tail) {
		if (head == tail)
			return NULL;
		ListNode *slow = head, *fast = head;
		while (fast != tail && fast->next != tail) {
			slow = slow->next;
			fast = fast->next->next;
		}
		TreeNode *cur = new TreeNode(slow->val);
		cur->left = helper(head, slow);
		cur->right = helper(slow->next, tail);
		return cur;
	}
};
