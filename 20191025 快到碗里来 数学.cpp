#include <bits/stdc++.h> 

using namespace std;

int main() {
	double n, r;
	while (cin >> n >> r) {
		if (n > (2 * r * 3.1415926))
			cout << "No" << endl;
		else
			cout << "Yes" << endl;
	}
	return 0;
}