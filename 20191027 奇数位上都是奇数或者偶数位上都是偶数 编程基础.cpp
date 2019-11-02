class Solution {
public:
	/**
	 *  奇数位上都是奇数或者偶数位上都是偶数
	 *  输入：数组arr，长度大于2
	 *  len：arr的长度
	 *  将arr调整成奇数位上都是奇数或者偶数位上都是偶数
	 */
	void oddInOddEvenInEven(vector<int>& arr, int len) {
		long i = 0, j = 1;
		while (i < len && j < len) {
			if ((arr[i] % 2) == 0) {
				i += 2;
				continue;
			}
			if ((arr[j] % 2) != 0) {
				j += 2;
				continue;
			}
			swap(arr[i], arr[j]);
		}
	}
};
