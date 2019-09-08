// Topic link：https://www.nowcoder.com/practice/bd891093881d4ddf9e56e7cc8416562d?tpId=85&&tqId=29864&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking
// 同步CSDN

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	string str, res, cur;
	cin >> str;
	for (int i = 0; i <= str.length(); i++)
	{
		// 数字+=到cur
		if (str[i] >= '0' && str[i] <= '9')
		{
			cur += str[i];
		}
		else
		{
			// 找出更长的字符串，则更新字符串
			if (res.size() < cur.size())
				res = cur;
			else
				cur.clear();
		}
	}
	cout << res;
	return 0;
}









