// Topic link：https://www.nowcoder.com/practice/ee5de2e7c45a46a090c1ced2fdc62355?tpId=85&&tqId=29867&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking
// 同步CSDN

// 第一思路
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	string mys;
	// 在此需要使用getline ,cin>>mys遇到空格即停止接收
	getline(cin, mys);

	// 逆置全句
	reverse(mys.begin(), mys.end());
	// 逆置单词
	auto start = mys.begin();
	while (start != mys.end()) {
		auto end = start;
		while (end != mys.end() && *end != ' ')
			end++;

		reverse(start, end);
		if (end != mys.end())
			start = end + 1;
		else
			start = end;
	}
	cout << mys << endl;
	return 0;
}

// 第二思路
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	string mys1, mys2;
	cin >> mys2;
	while (cin >> mys1)
		mys2 = mys1 + ' ' + mys2;
	cout << mys2 << endl;
	return 0;
}