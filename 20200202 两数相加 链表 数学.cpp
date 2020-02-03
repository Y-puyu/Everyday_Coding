class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* tmp = new ListNode(-1), *cur = tmp;
		int cnt = 0;
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
		return tmp->next;
	}
};