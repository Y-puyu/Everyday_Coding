#include <bits/stdc++.h>

using namespace std;

int main() {
	string str;
	while (cin >> str) {
		int num[256] = { 0 };
		for (int i = 0; i < str.size(); ++i) {
			num[str[i]]++;
		}

		int j;
		for (j = 0; j < str.size(); ++j) {
			if (num[str[j]] == 1) {
				cout << str[j] << endl;
				break;
			}
		}

		if (j >= str.size())
			cout << -1 << endl;
	}
	return 0;
}
