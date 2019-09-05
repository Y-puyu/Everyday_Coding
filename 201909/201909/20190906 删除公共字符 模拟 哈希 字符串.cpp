// Topic link：https://www.nowcoder.com/practice/f0db4c36573d459cae44ac90b90c6212?tpId=85&&tqId=29868&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking
// 同步CSDN

#include <iostream>
#include <string>

using namespace std;

int main() {
	// 在此不能用cin接收，因为cin遇到空格即结束
	// 在OJ中IO输入字符串最好使用getline
	string str1, str2;
	// cin >> str1;
	// cin >> str2;
	getline(cin, str1);
	getline(cin, str2);

	// 采用hash映射思想先str2统计字符出现的次数
	int hashtable[256] = { 0 };
	for (size_t i = 0; i < str2.size(); i++) {
		hashtable[str2[i]]++;
	}
	// 遍历str1,str1[i]映射hashtable对应位置为0，则表示这个字符在
	// str2中没有出现过，则将他+=到ret。注意这里最好不要str1.erase(i)
	// 因为边遍历，边erase容易出错
	string ret;
	for (size_t i = 0; i < str1.size(); ++i) {
		if (hashtable[str1[i]] == 0) {
			ret += str1[i];
		}
	}
	cout << ret << endl;
	return 0;
}