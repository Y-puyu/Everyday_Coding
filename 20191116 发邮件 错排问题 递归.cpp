// write your code here cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
	long long der[21] = { 0, 0, 1 };
	for (int i = 3; i < 21; ++i)
		der[i] = (i - 1) * (der[i - 2] + der[i - 1]);
	int n;
	while (cin >> n)
		cout << der[n] << endl;
	return 0;
}
