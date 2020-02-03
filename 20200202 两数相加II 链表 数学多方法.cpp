// 执行用时 :32 ms, 在所有 C++ 提交中击败了55.83%的用户
// 内存消耗 :10.7 MB, 在所有 C++ 提交中击败了74.35%的用户

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	ListNode* addTwoNumbers(ListNode *l1, ListNode *l2) {
		ListNode* tmp = new ListNode(-1), *cur = tmp;
		int cnt = 0;
		l1 = reverseList(l1);
		l2 = reverseList(l2);
		while (l1 || l2) {
			int val1 = l1 ? l1->val : 0;
			int val2 = l2 ? l2->val : 0;
			int sum = val1 + val2 + cnt;
			cnt = sum / 10;
			cur->next = new ListNode(sum % 10);
			cur = cur->next;
			if (l1) l1 = l1->next;
			if (l2) l2 = l2->next;
		}
		if (cnt) cur->next = new ListNode(1);
		return reverseList(tmp->next);
	}

	ListNode* reverseList(ListNode *head) {
		if (!head) return head;
		ListNode* dummy = new ListNode(-1);
		dummy->next = head;
		ListNode* cur = head;
		while (cur->next) {
			ListNode *tmp = cur->next;
			cur->next = tmp->next;
			tmp->next = dummy->next;
			dummy->next = tmp;
		}
		return dummy->next;
	}
};

// 执行用时 :28 ms, 在所有 C++ 提交中击败了75.83%的用户
// 内存消耗 :10.8 MB, 在所有 C++ 提交中击败了71.63%的用户

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int n1 = 0, n2 = 0, carry = 0;;
		n1 = getLength(l1);
		n2 = getLength(l2);
		if (n1 > n2) l2 = padList(l2, n1 - n2);
		if (n2 > n1) l1 = padList(l1, n2 - n1);
		ListNode* res = addTwoNumbersDFS(l1, l2, carry);
		if (carry == 1) {
			ListNode* tmp = new ListNode(1);
			tmp->next = res;
			res = tmp;
		}
		return res;
	}
	ListNode* addTwoNumbersDFS(ListNode* l1, ListNode* l2, int &carry) {
		if (!l1 && !l2) return NULL;
		ListNode* list = addTwoNumbersDFS(l1->next, l2->next, carry);
		int sum = l1->val + l2->val + carry;
		ListNode* res = new ListNode(sum % 10);
		res->next = list;
		carry = sum / 10;
		return res;
	}
	ListNode* padList(ListNode* list, int len) {
		ListNode* dummy = new ListNode(-1);
		ListNode* cur = dummy;
		for (int i = 0; i < len; ++i) {
			cur->next = new ListNode(0);
			cur = cur->next;
		}
		cur->next = list;
		return dummy->next;
	}
	int getLength(ListNode* list) {
		ListNode* cur = list;
		int res = 0;
		while (cur) {
			++res;
			cur = cur->next;
		}
		return res;
	}
};


// 执行用时 :24 ms, 在所有 C++ 提交中击败了88.54%的用户
// 内存消耗 :11.4 MB, 在所有 C++ 提交中击败了61.79%的用户

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int n1 = getLength(l1), n2 = getLength(l2);
		ListNode* head = new ListNode(1);
		head->next = (n1 > n2) ? helper(l1, l2, n1 - n2) : helper(l2, l1, n2 - n1);
		if (head->next->val > 9) {
			head->next->val %= 10;
			return head;
		}
		return head->next;
	}
	int getLength(ListNode* head) {
		int cnt = 0;
		while (head) {
			++cnt;
			head = head->next;
		}
		return cnt;
	}
	ListNode* helper(ListNode* l1, ListNode* l2, int diff) {
		if (!l1) return NULL;
		ListNode* res = (diff == 0) ? new ListNode(l1->val + l2->val) : new ListNode(l1->val);
		ListNode* post = (diff == 0) ? helper(l1->next, l2->next, 0) : helper(l1->next, l2, diff - 1);
		if (post && post->val > 9) {
			post->val %= 10;
			++res->val;
		}
		res->next = post;
		return res;
	}
};

// 执行用时 :24 ms, 在所有 C++ 提交中击败了88.54%的用户
// 内存消耗 :11.4 MB, 在所有 C++ 提交中击败了61.79%的用户

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int n1 = getLength(l1), n2 = getLength(l2);
		ListNode* head = new ListNode(1);
		head->next = (n1 > n2) ? helper(l1, l2, n1 - n2) : helper(l2, l1, n2 - n1);
		if (head->next->val > 9) {
			head->next->val %= 10;
			return head;
		}
		return head->next;
	}
	int getLength(ListNode* head) {
		int cnt = 0;
		while (head) {
			++cnt;
			head = head->next;
		}
		return cnt;
	}
	ListNode* helper(ListNode* l1, ListNode* l2, int diff) {
		if (!l1) return NULL;
		ListNode* res = (diff == 0) ? new ListNode(l1->val + l2->val) : new ListNode(l1->val);
		ListNode* post = (diff == 0) ? helper(l1->next, l2->next, 0) : helper(l1->next, l2, diff - 1);
		if (post && post->val > 9) {
			post->val %= 10;
			++res->val;
		}
		res->next = post;
		return res;
	}
};

// 执行用时 :16 ms, 在所有 C++ 提交中击败了99.27%的用户
// 内存消耗 :10.6 MB, 在所有 C++ 提交中击败了78.89%的用户

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int n1 = getLength(l1), n2 = getLength(l2), diff = abs(n1 - n2);
		if (n1 < n2) swap(l1, l2);
		ListNode *dummy = new ListNode(0), *cur = dummy, *right = cur;
		while (diff > 0) {
			cur->next = new ListNode(l1->val);
			if (l1->val != 9) right = cur->next;
			cur = cur->next;
			l1 = l1->next;
			--diff;
		}
		while (l1) {
			int val = l1->val + l2->val;
			if (val > 9) {
				val %= 10;
				++right->val;
				while (right->next) {
					right->next->val = 0;
					right = right->next;
				}
				right = cur;
			}
			cur->next = new ListNode(val);
			if (val != 9) right = cur->next;
			cur = cur->next;
			l1 = l1->next;
			l2 = l2->next;
		}
		return (dummy->val == 1) ? dummy : dummy->next;
	}
	int getLength(ListNode* head) {
		int cnt = 0;
		while (head) {
			++cnt;
			head = head->next;
		}
		return cnt;
	}
};
