// Topic link：https://www.nowcoder.com/questionTerminal/6736cc3ffd1444a4a0057dee89be789b?orderByHotValue=1&page=1&onlyReference=false
// 同步CSDN



#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	// 注意在此会有多组测试用例，需要持续接收
	int n;
	while (cin >> n) {
		long long sum = 0;
		vector<int> a;
			a.resize(3 * n);
		for (int i = 0; i < (3 * n); i++) {
			cin >> a[i];
		}
		// 排序，然后取a向量下标从n开始，后续步长为2，相加即可
		std::sort(a.begin(), a.end());
		for (int i = n; i <= 3 * n - 2; i += 2) {
			sum += a[i];
		}
		cout << sum << endl;
	}
}





