class Solution {
public:
	int compress(vector<char>& chars) {
		int n = chars.size(), cur = 0;
		for (int i = 0, j = 0; i < n; i = j) {
			while (j < n && chars[j] == chars[i]) ++j;
			chars[cur++] = chars[i];
			if (j - i == 1) continue;
			for (char c : to_string(j - i)) chars[cur++] = c;
		}
		return cur;
	}
};


class Solution {
public:
	int compress(vector<char>& chars) {
		int n = chars.size();
		int cur = 0;
		for (int i = 0, j = 0; i < n; j = i) {
			while (i < n && chars[i] == chars[j]) {
				i++;
			}
			chars[cur++] = chars[j];
			if (i - j == 1) {
				continue;
			}
			string s = to_string(i - j);
			for (int t = 0; t < s.size(); t++) {
				chars[cur++] = s[t];
			}
		}
		return cur;
	}
};


class Solution {
public:
	void insetNum(vector<char>& chars, int num, int& index) {
		int begin = index;
		while (num != 0) {
			chars[index++] = num % 10 + ' 0';
			num /= 10;
		}
		int end = index - 1;
		while (begin < end) {
			int temp = chars[begin];
			chars[begin] = chars[end];
			chars[end] = temp;
			begin++;
			end--;
		}
	}
	int compress(vector<char>& chars) {
		char target = chars[0];
		int count = 1;
		int index = 0;
		for (int i = 1; i < chars.size(); ++i) {
			if (chars[i] != target) {
				chars[index++] = target;
				target = chars[i];
				if (count != 1) insetNum(chars, count, index);
				count = 1;
			}
			else count++;
		}
		chars[index++] = target;
		if (count != 1) insetNum(chars, count, index);
		return index;
	}
};


class Solution {
public:
	int compress(vector<char>& chars) {
		vector<char> vt;
		vector<char> vt1;
		int cnt = 0;
		chars.push_back(' ');
		for (int i = 0; i < chars.size() - 1; ) {
			char ch = ' ';
			int num = 0;
			ch = chars[i];
			vt.push_back(ch);
			while (ch == chars[i]) {
				++num;
				++i;
			}
			if (num == 1) continue;

			if (num > 1 && num < 10) {
				vt.push_back('0' + num);
				continue;
			}
			while (num > 9) {
				vt1.push_back('0' + (num % 10));
				num /= 10;
			}
			vt1.push_back('0' + num);
			for (int i = vt1.size() - 1; i >= cnt; --i) {
				vt.push_back(vt1[i]);
			}
			cnt = vt1.size();
		}
		for (int i = 0; i < vt.size(); ++i) {
			chars[i] = vt[i];
		}
		return vt.size();
	}
};
