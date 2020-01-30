class Solution {
public:
	vector<vector<int>> dirs = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} };
	int longestIncreasingPath(vector<vector<int>>& matrix) {
		if (matrix.empty() || matrix[0].empty()) return 0;
		int res = 1, m = matrix.size(), n = matrix[0].size();
		vector<vector<int>> dp(m, vector<int>(n, 0));
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				res = max(res, dfs(matrix, dp, i, j));
			}
		}
		return res;
	}
	int dfs(vector<vector<int>> &matrix, vector<vector<int>> &dp, int i, int j) {
		if (dp[i][j]) return dp[i][j];
		int mx = 1, m = matrix.size(), n = matrix[0].size();
		for (auto a : dirs) {
			int x = i + a[0], y = j + a[1];
			if (x < 0 || x >= m || y < 0 || y >= n || matrix[x][y] <= matrix[i][j]) continue;
			int len = 1 + dfs(matrix, dp, x, y);
			mx = max(mx, len);
		}
		dp[i][j] = mx;
		return mx;
	}
};


class Solution {
public:
	int longestIncreasingPath(vector<vector<int>>& matrix) {
		if (matrix.empty() || matrix[0].empty()) return 0;
		int m = matrix.size(), n = matrix[0].size(), res = 1;
		vector<vector<int>> dirs{ {0,-1},{-1,0},{0,1},{1,0} };
		vector<vector<int>> dp(m, vector<int>(n, 0));
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (dp[i][j] > 0) continue;
				queue<pair<int, int>> q{ {{i, j}} };
				int cnt = 1;
				while (!q.empty()) {
					++cnt;
					int len = q.size();
					for (int k = 0; k < len; ++k) {
						auto t = q.front(); q.pop();
						for (auto dir : dirs) {
							int x = t.first + dir[0], y = t.second + dir[1];
							if (x < 0 || x >= m || y < 0 || y >= n ||
								matrix[x][y] <= matrix[t.first][t.second] || cnt <= dp[x][y]) continue;
							dp[x][y] = cnt;
							res = max(res, cnt);
							q.push({ x, y });
						}
					}
				}
			}
		}
		return res;
	}
};


class Point {
public:
	int x, y, v;
	Point(int ix, int iy, int iv) {
		x = ix;
		y = iy;
		v = iv;
	}
};

class Solution {
public:
	int longestIncreasingPath(vector<vector<int>>& matrix) {
		if (matrix.size() == 0)
			return 0;
		const int rows = matrix.size();
		const int cols = matrix[0].size();
		vector<vector<int>> dp(rows, vector<int>(cols, 1));
		vector<Point> vp;
		vp.reserve(rows * cols);
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				vp.push_back(Point(i, j, matrix[i][j]));
			}
		}
		// 采用lambda表达式，根据读入数据依次创建坐标点,并根据升序排序
		sort(vp.begin(), vp.end(), [](const Point &lhs, const Point &rhs) {
			return lhs.v < rhs.v;
		});
		int ret = 1;
		for (const auto &p : vp) {
			auto x = p.x;
			auto y = p.y;
			auto v = p.v;
			// 寻找附近比当前矮的点的最高DP值
			if (x > 0 && matrix[x - 1][y] < v && dp[x - 1][y] + 1 > dp[x][y])
				dp[x][y] = dp[x - 1][y] + 1;
			if (x < rows - 1 && matrix[x + 1][y] < v && dp[x + 1][y] + 1 > dp[x][y])
				dp[x][y] = dp[x + 1][y] + 1;
			if (y > 0 && matrix[x][y - 1] < v && dp[x][y - 1] + 1 > dp[x][y])
				dp[x][y] = dp[x][y - 1] + 1;
			if (y < cols - 1 && matrix[x][y + 1] < v && dp[x][y + 1] + 1 > dp[x][y])
				dp[x][y] = dp[x][y + 1] + 1;
			if (dp[x][y] > ret)
				ret = dp[x][y];
		}
		return ret;
	}
};


class Solution {
public:
	int longestIncreasingPath(vector<vector<int>>& matrix) {
		queue<int> qx, qy;
		const int rows = matrix.size();
		if (!rows)
			return 0;
		const int cols = matrix[0].size();
		const vector<int> dx = { 1, -1, 0, 0 };
		const vector<int> dy = { 0, 0, 1, -1 };
		vector<vector<int>> in(rows, vector<int>(cols, 0));
		vector<vector<int>> dp(rows, vector<int>(cols, 1));
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && matrix[i][j] < matrix[nx][ny]) {
						in[nx][ny]++;
					}
				}
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++) {
				if (!in[i][j]) {
					qx.push(i);
					qy.push(j);
				}
			}
		int ret = 0;
		while (!qx.empty()) {
			int i = qx.front();
			int j = qy.front();
			qx.pop();
			qy.pop();
			if (dp[i][j] > ret)
				ret = dp[i][j];
			int nv = dp[i][j] + 1;
			for (int k = 0; k < 4; k++) {
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && matrix[i][j] < matrix[nx][ny]) {
					if (dp[nx][ny] < nv)
						dp[nx][ny] = nv;
					in[nx][ny]--;
					if (!in[nx][ny]) {
						qx.push(nx);
						qy.push(ny);
					}
				}
			}
		}
		return ret;
	}
};
