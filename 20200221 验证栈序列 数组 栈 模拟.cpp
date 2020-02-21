// 执行用时 :8 ms, 在所有 C++ 提交中击败了93.62%的用户
// 内存消耗 :9.6 MB, 在所有 C++ 提交中击败了5.30%的用户

class Solution {
public:
	bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
		stack<int> s1, s2;
		for (int i = popped.size() - 1; i >= 0; --i)
			s2.push(popped[i]);
		for (int i = 0; i < pushed.size(); ++i) {
			s1.push(pushed[i]);
			while (s2.top() == s1.top()) {
				s1.pop();
				s2.pop();
				if (s1.empty())
					break;
			}
		}
		return s1.empty();
	}
};
