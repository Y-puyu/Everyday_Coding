// Topic link：https://www.nowcoder.com/practice/02d8d42b197646a5bbd0a98785bb3a34?tpId=85&&tqId=29857&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking
// 同步CSDN

// 第一思路
#include <iostream>

using namespace std;

int main()
{
	int arr[4] = { 0 };
	for (int i = 0; i < 4; ++i)
	{
		cin >> arr[i];
	}
	double A = (arr[0] + arr[2]) / 2.0;
	double B = (arr[1] + arr[3]) / 2.0;
	double C = (arr[3] - B);

	if ((A < 0 || B < 0 || C < 0)
		|| ((int)A != A || (int)B != B || (int)C != C))
		cout << "No" << endl;
	else
		cout << A << " " << B << " " << C;
	return 0;
}

// 第二思路
#include <iostream>

using namespace std;

int main()
{
	int arr[4] = { 0 };
	for (int i = 0; i < 4; ++i)
	{
		cin >> arr[i];
	}
	double A = (arr[0] + arr[2]) / 2.0;
	double B1 = (arr[1] + arr[3]) / 2.0;
	double B2 = (arr[2] - arr[0]) / 2.0;
	double C = (arr[3] - arr[1]) / 2.0;

	if ((A < 0 || B1 < 0 || B2 < 0 || C < 0)
		|| B1 != B2)
		cout << "No" << endl;
	else
		cout << A << " " << B1 << " " << C;
	return 0;
}