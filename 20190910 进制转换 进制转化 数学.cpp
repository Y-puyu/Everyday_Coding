// Topic link：https://www.nowcoder.com/practice/ac61207721a34b74b06597fe6eb67c52?tpId=85&&tqId=29862&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking
// 同步CSDN

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	//要考虑进制大于9的情况，还要考虑负数
	string s, s1 = "0123456789ABCDEF";
	int m, n;
	cin >> m >> n;
	bool flag = false;

	// 如果为负数，则转成正数，并标记一下
	if (m < 0)
	{
		m = -m;
		flag = true;
	}

	// 按照进制换算成对应的字符添加到s
	while (m)
	{
		s += s1[m % n];
		m /= n;
	}

	// 如果为负数，结果加上符号
	if (flag)
		s += '-';

	// 类似辗转相除倒序的情况，需要逆置
	reverse(s.begin(), s.end());
	cout << s << endl;
	return 0;
}