// write your code here cpp
#include <bits/stdc++.h>

using namespace std;

int count(string table[], char ch, int x, int y) {
	int maxc = 0;
	int dir[4][2][2] = { {{-1, 0},{1, 0}}, {{0, -1}, {0, 1}}, {{-1, -1}, {1, 1}}, {{-1, 1}, {1, -1}} };
	for (int i = 0; i < 4; ++i) {  // 四种方向
		int c = 0;
		for (int j = 0; j < 2; ++j) {  // 两个小方向
			int nx = x, ny = y;
			while (nx >= 0 && nx < 20 && ny >= 0 && ny < 20 && table[nx][ny] == ch) {
				nx += dir[i][j][0];
				ny += dir[i][j][1];
				++c;
			}
		}
		maxc = (maxc > c ? maxc : c);
	}
	return maxc - 1;  // 统计两个方向（如横向的左右两个方向的时候，当前棋子被计算了两次）
}

int solve(string table[]) {
	for (int i = 0; i < 20; ++i) {
		for (int j = 0; j < 20; ++j) {
			if (table[i][j] == '*' || table[i][j] == '+')
				if (count(table, table[i][j], i, j) >= 5)
					return true;
		}
	}
	return false;
}

int main() {
	string table[20];
	while (cin >> table[0]) {
		for (int i = 1; i < 20; ++i)
			cin >> table[i];
		cout << (solve(table) ? "Yes" : "No") << endl;
	}
	return 0;
}
