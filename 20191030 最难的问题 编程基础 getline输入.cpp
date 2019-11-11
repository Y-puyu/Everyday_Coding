// write your code here cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
	string st;
	while (getline(cin, st)) {
		for (int i = 0; i < st.size(); ++i) {
			if (st[i] == ' ')
				i++;
			st[i] -= 5;
			if (st[i] < 'A')
				st[i] += 26;
		}
		cout << st << endl;
	}
	return 0;
}
