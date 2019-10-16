class Gloves {
public:
	int findMinimum(int n, vector<int> left, vector<int> right) {
		// write code here
		int leftSum = 0, leftMin = INT_MAX;
		int rightSum = 0, rightMin = INT_MAX;
		int sum = 0;

		// 遍历每一种颜色的左右手套序列
		for (int i = 0; i < n; ++i) {
			// 对于有0存在的颜色手套，累加
			if (left[i] * right[i] == 0)
				sum += left[i] + right[i];
			else {
				leftSum += left[i];
				rightSum += right[i];
				leftMin = min(leftMin, left[i]);
				rightMin = min(rightMin, right[i]);
			}
		}
		// 结果为有左右都有数量的手套序列的结果+有0存在的手套数+1，即能够保证
		return sum + min(leftSum - leftMin + 1, rightSum - rightMin + 1) + 1;
	}
};