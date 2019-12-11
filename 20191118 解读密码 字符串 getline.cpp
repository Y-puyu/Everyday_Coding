// write your code here cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
	string s;
	while (getline(cin, s)) {
		int len = s.length();
		for (int i = 0; i < len; ++i)
			if (s[i] >= '0' && s[i] <= '9')
				cout << s[i];
		cout << endl;
	}
	return 0;
}
