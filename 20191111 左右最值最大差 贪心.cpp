class MaxGap {
public:
	int findMaxGap(vector<int> A, int n) {
		// write code here
		vector<int> mxL(n, 0);    // 记录i位左侧最大值
		vector<int> mxR(n, 0);    // 记录i位右侧最大值
		int ma = INT_MIN;
		for (int i = 0; i < n; ++i) {    // 左侧
			if (i == 0)
				mxL[i] = A[i];
			else
				mxL[i] = max(A[i], mxL[i - 1]);    // 第i位左侧的最大值就是i - 1位最大值和i的值的较大值
		}
		for (int i = n - 1; i >= 0; --i) {     // 右侧
			if (i == n - 1)
				mxR[i] = A[i];
			else
				mxR[i] = max(A[i], mxR[i + 1]);
		}
		// 例如输入数据为 [2,7,3,1,1] 
		// mxL 中的值为: [2,7,7,7,7]
		// mxR 中的值为: [7,7,3,1,1]
		int res = INT_MIN;
		// 接下来的循环就依次求差找最大值即可
		for (int i = 0; i < n - 1; ++i)    // 求差
			res = max(res, abs(mxL[i] - mxR[i + 1]));
		return res;
	}
};
