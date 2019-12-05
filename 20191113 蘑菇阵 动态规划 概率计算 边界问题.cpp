#include <bits/stdc++.h>

using namespace std;
int main() {
	int n, m, k;
	while (cin >> n >> m >> k) {
		vector<vector<int>> table((n + 1), vector<int>(m + 1));  // 记录蘑菇
		vector<vector<double>> p((n + 1), vector<double>(m + 1));  // p[i][j]表示不碰到蘑菇走到i,j的概率
		int x, y;
		for (int i = 0; i < k; ++i) {
			cin >> x >> y;
			table[x][y] = 1;
		}
		p[1][1] = 1.0;  // 起点概率为1
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				if (!(i == 1 && j == 1)) {  // 跳过起点
					p[i][j] = p[i - 1][j] * (j == m ? 1 : 0.5) + p[i][j - 1] * (i == n ? 1 : 0.5);  // 边界的时候，概率为1
					if (table[i][j] == 1)
						p[i][j] = 0;  // 如果该点有蘑菇，概率置为0

				}
			}
		}
		cout << fixed << setprecision(2) << p[n][m] << endl;
	}
	return 0;
}
