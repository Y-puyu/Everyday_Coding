#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	while (cin >> n) {
		int count = 0;
		while (n) {
			if ((n & 1) == 1)
				count += 1;
			n >>= 1;
		}
		cout << count << endl;
	}

	return 0;
}