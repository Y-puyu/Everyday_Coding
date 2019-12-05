#include <bits/stdc++.h>

using namespace std;

int main() {
	string s1, s2;
	int len1, len2;
	while (cin >> s1 >> s2 >> len1 >> len2) {
		// 只包含小写字母的字符串可以看成26进制的数制
		// 将s1和s2补长到len2长度
		s1.append(len2 - s1.size(), 'a');
		s2.append(len2 - s2.size(), (char)('z' + 1));

		// 确认s1和s2的两个字符串每个位置上的差值
		vector<int> arr;
		for (int i = 0; i < len2; ++i)
			arr.push_back(s2[i] - s1[i]);
		// 确认len1和len2之间可组成的不同字符串的个数
		int result = 0;
		for (int i = len1; i <= len2; ++i)
			for (int k = 0; k < i; ++k)
				result += arr[k] * pow(26, i - 1 - k);
		// 所有字符串最后都不包含是s2自身，所有最后要减1
		cout << result - 1 << endl;
	}
	return 0;
}
