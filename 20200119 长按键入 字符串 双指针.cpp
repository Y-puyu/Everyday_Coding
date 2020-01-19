class Solution {
public:
	bool isLongPressedName(string name, string typed) {
		for (int i = 0, j = 0; i < name.length(); ++i) {
			while (name[i] == name[i + 1]) {
				++i;
				++j;
			}
			int flag = j;
			while (typed[j] == name[i]) {
				++j;
			}

			if (flag == j) return false;
		}
		return true;
	}
};