// Topic link：https://www.nowcoder.com/questionTerminal/2d3f6ddd82da445d804c95db22dcc471?orderByHotValue=1&page=1&onlyReference=false
// 同步CSDN

#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> myv;
	myv.resize(n);
	for (int i = 0; i < n; ++i)
		cin >> myv[i];
	int ret = 1;
	for (int i = 1; i < n - 1; i++) {
		// 找出波谷波峰
		if ((myv[i - 1] < myv[i] && myv[i] > myv[i + 1])
			|| (myv[i - 1] > myv[i] && myv[i] < myv[i + 1])) {
			ret++;
			// 这里处理上面的情况二

			i++;
		}
	}
	cout << ret << endl;
	return 0;
}