class Solution {
public:
	string addBinary(string a, string b) {
		int al = a.size();
		int bl = b.size();
		while (al < bl) {    //让两个字符串等长，若不等长，在短的字符串前补零，否则之后的操作会超出索引
			a = '0' + a;
			++al;
		}
		while (al > bl) {
			b = '0' + b;
			++bl;
		}
		for (int j = a.size() - 1; j > 0; --j) {   //从后到前遍历所有的位数，同位相加
			a[j] = a[j] - '0' + b[j];
			if (a[j] >= '2') {    //若大于等于字符‘2’，需要进一
				a[j] = (a[j] - '0') % 2 + '0';
				a[j - 1] = a[j - 1] + 1;
			}
		}
		a[0] = a[0] - '0' + b[0]; //将ab的第0位相加
		if (a[0] >= '2') {   //若大于等于2，需要进一
			a[0] = (a[0] - '0') % 2 + '0';
			a = '1' + a;
		}
		return a;
	}
};


class Solution {
public:
	string addBinary(string a, string b) {
		int alen = a.length();
		int blen = b.length();
		int length = 0;
		int cnt = 0;
		int cnt1 = 0;
		int flag = 0;
		if (alen > blen) {
			cnt = alen - blen;
			cnt1 = cnt;
			flag = 1;
			while (cnt) {
				b.push_back('0');
				--cnt;
			}
		}
		if (alen < blen) {
			cnt = blen - alen;
			cnt1 = cnt;
			flag = 2;
			while (cnt) {
				a.push_back('0');
				--cnt;
			}
		}
		if (alen == blen) flag = 3;
		if (flag == 1) {
			length = alen;
		}
		if (flag == 2 || flag == 3) {
			length = blen;
		}
		vector<int> vta(length, 0);
		vector<int> vtb(length, 0);
		vector<int> vt(length, 0);
		int flag2 = 0;
		for (int i = 0; i < vta.size(); ++i) {
			vta[i] = a[i] - '0';
		}
		for (int i = 0; i < vtb.size(); ++i) {
			vtb[i] = b[i] - '0';
		}
		if (flag == 1) {
			for (int i = vtb.size() - 1; i >= cnt1; --i) {
				vtb[i] = vtb[i - cnt1];
			}
			for (int i = 0; i < cnt1; ++i) {
				vtb[i] = 0;
			}
		}
		if (flag == 2) {
			for (int i = vta.size() - 1; i >= cnt1; --i) {
				vta[i] = vta[i - cnt1];
			}
			for (int i = 0; i < cnt1; ++i) {
				vta[i] = 0;
			}
		}

		for (int i = 0; i < vt.size(); ++i) {
			vt[i] = vta[i] + vtb[i];
		}
		reverse(vt.begin(), vt.end());
		vt.push_back(0);
		for (int i = 0; i < vt.size(); ++i) {
			if (vt[i] == 2) {
				vt[i] = 0;
				vt[i + 1] += 1;
			}
			if (vt[i] == 3) {
				vt[i] = 1;
				vt[i + 1] += 1;
			}
		}
		if (vt[vt.size() - 1] == 0) vt.pop_back();
		reverse(vt.begin(), vt.end());
		string str(vt.size(), '0');
		for (int i = 0; i < vt.size(); ++i) {
			if (vt[i] == 0) str[i] = '0';
			else str[i] = '1';
		}
		return str;
	}
};
