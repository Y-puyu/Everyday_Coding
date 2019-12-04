#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	while (cin >> n) {
		stack<string> str;
		int max = 0;
		for (int i = 0; i < n; i++) {
			string name, state;
			cin >> name >> state;
			if (state == "connect") {
				str.push(name);
				if (str.size() > max)
					max = str.size();
			}
			else
				str.pop();
		}
		cout << max << endl;
	}
	return 0;
}
