// write your code here cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
	string str1, str2;
	while (cin >> str1 >> str2) {
		int count = 0, pos = 0;
		// 在str1中寻找str2,直至寻找不到
		while ((pos = str1.find(str2, pos)) != -1) {
			pos += str2.size();    // 跳过str2串整体长度
			++count;               // 计数
		}
		cout << count << endl;
	}
	return 0;
}
