#include <bits/stdc++.h>

using namespace std;

int main() {
	string num = "222333444555666777788899991234567890";
	string str;
	int length;
	while (cin >> length) {
		set<string> data;
		int cnt;
		for (int i = 0; i < length; ++i) {
			cnt = 0;
			string res;
			cin >> str;
			for (int j = 0; j < str.length(); ++j) {
				if (str[j] >= 'A' && str[j] <= 'Z') {
					res += num[str[j] - 'A'];
					cnt++;
					if (cnt == 3)
						res += "-";
				}
				else if (str[j] >= '0' && str[j] <= '9') {
					res += str[j];
					cnt++;
					if (cnt == 3)
						res += "-";
				}
			}
			data.insert(res);
		}
		for (set<string>::iterator it = data.begin(); it != data.end(); ++it)
			cout << *it << endl;
		cout << endl;
	}
	return 0;
}
