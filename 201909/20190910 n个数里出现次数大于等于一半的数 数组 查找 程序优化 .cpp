// Topic link：https://www.nowcoder.com/practice/eac8c671a0c345b38aa0c07aba40097b?tpId=85&&tqId=29866&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking
// 同步CSDN

// 第一思路
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	vector<int> myv;
	while (cin >> n)
		myv.push_back(n);
	sort(myv.begin(), myv.end());
	cout << myv[myv.size() / 2 - 1] << endl;
	return 0;
}

// 第二思路
#include <vector>
#include <iostream>

using namespace std;

int main()
{
	int n;
	vector<int> myv;
	while (cin >> n)
		myv.push_back(n);

	int count = 0;
	int temp = myv[0];
	for (int i = 0; i < myv.size(); ++i)
	{
		if (myv[i] == temp)
			count++;
		else
			count--;

		if (count == 0)
		{
			temp = myv[i];
			count++;
		}
	}
	cout << temp << endl;
	return 0;
}
