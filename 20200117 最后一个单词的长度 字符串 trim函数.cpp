class Solution {
public:
	void trim(string &s)
	{
		if (s.empty())
		{
			return;
		}
		s.erase(0, s.find_first_not_of(" "));
		s.erase(s.find_last_not_of(" ") + 1);
	}
	int lengthOfLastWord(string s) {
		reverse(s.begin(), s.end());
		int cnt = 0;
		int flag = 0;
		trim(s);
		for (int len = 0; len < s.size(); ++len) {
			if (s[len] != ' ') {
				cnt++;
			}
			else {
				break;
			}
		}
		return cnt;
	}
};



class Solution {
public:
	int lengthOfLastWord(string s) {
		int pos0 = s.find_last_not_of(" ");
		int pos1 = s.find_last_of(" ", pos0);
		if ((pos0 - pos1) < 0)
		{
			return 0;
		}
		return pos0 - pos1;
	}
};