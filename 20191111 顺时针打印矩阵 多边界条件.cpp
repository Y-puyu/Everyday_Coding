class Printer {
public:
	vector<int> clockwisePrint(vector<vector<int> > mat, int n, int m) {
		// write code here
		vector<int> ret;
		int x1 = 0, y1 = 0;  // 左上角坐标
		int x2 = n - 1, y2 = m - 1;  // 右下角坐标
		while (x1 <= x2 && y1 <= y2) {
			for (int j = y1; j <= y2; ++j)
				ret.push_back(mat[x1][j]);
			for (int i = x1 + 1; i < x2; ++i)
				ret.push_back(mat[i][y2]);
			for (int j = y2; x1 < x2 && j >= y1; --j)  // x1 < x2只有不是单一的横行时才会执行这个循环
				ret.push_back(mat[x2][j]);
			for (int i = x2 - 1; y1 < y2 && i > x1; --i)  // y1 < y2只有在不是单一的竖列时菜执行这个循环
				ret.push_back(mat[i][y1]);
			++x1;
			++y1;
			--x2;
			--y2;
		}
		return ret;
	}
};
