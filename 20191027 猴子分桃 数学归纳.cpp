// write your code here cpp
#include <bits/stdc++.h> 

using namespace std;

int main() {
	int n;
	while (std::cin >> n) {
		if (n == 0) break;
		long total = pow(5, n) - 4;
		long left = pow(4, n) + n - 4;
		cout << total << " " << left << std::endl;
	}
	return 0;
}
