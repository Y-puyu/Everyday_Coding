// 执行用时 :24 ms, 在所有 C++ 提交中击败了53.40%的用户
// 内存消耗 :9.7 MB, 在所有 C++ 提交中击败了37.80%的用户

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int m = nums1.size(), n = nums2.size(), left = (m + n + 1) / 2, right = (m + n + 2) / 2;
		return (findKth(nums1, 0, nums2, 0, left) + findKth(nums1, 0, nums2, 0, right)) / 2.0;
	}
	int findKth(vector<int>& nums1, int i, vector<int>& nums2, int j, int k) {
		if (i >= nums1.size()) return nums2[j + k - 1];
		if (j >= nums2.size()) return nums1[i + k - 1];
		if (k == 1) return min(nums1[i], nums2[j]);
		int midVal1 = (i + k / 2 - 1 < nums1.size()) ? nums1[i + k / 2 - 1] : INT_MAX;
		int midVal2 = (j + k / 2 - 1 < nums2.size()) ? nums2[j + k / 2 - 1] : INT_MAX;
		if (midVal1 < midVal2) {
			return findKth(nums1, i + k / 2, nums2, j, k - k / 2);
		}
		else {
			return findKth(nums1, i, nums2, j + k / 2, k - k / 2);
		}
	}
};


// 执行用时 :28 ms, 在所有 C++ 提交中击败了31.59%的用户
// 内存消耗 :16.4 MB, 在所有 C++ 提交中击败了5.08%的用户

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int m = nums1.size(), n = nums2.size();
		return (findKth(nums1, nums2, (m + n + 1) / 2) + findKth(nums1, nums2, (m + n + 2) / 2)) / 2.0;
	}
	int findKth(vector<int> nums1, vector<int> nums2, int k) {
		if (nums1.empty()) return nums2[k - 1];
		if (nums2.empty()) return nums1[k - 1];
		if (k == 1) return min(nums1[0], nums2[0]);
		int i = min((int)nums1.size(), k / 2), j = min((int)nums2.size(), k / 2);
		if (nums1[i - 1] > nums2[j - 1]) {
			return findKth(nums1, vector<int>(nums2.begin() + j, nums2.end()), k - j);
		}
		else {
			return findKth(vector<int>(nums1.begin() + i, nums1.end()), nums2, k - i);
		}
		return 0;
	}
};


// 执行用时 :16 ms, 在所有 C++ 提交中击败了91.82%的用户
// 内存消耗 :9.5 MB, 在所有 C++ 提交中击败了65.56%的用户

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int m = nums1.size(), n = nums2.size();
		if (m < n) return findMedianSortedArrays(nums2, nums1);
		if (n == 0) return ((double)nums1[(m - 1) / 2] + (double)nums1[m / 2]) / 2.0;
		int left = 0, right = n * 2;
		while (left <= right) {
			int mid2 = (left + right) / 2;
			int mid1 = m + n - mid2;
			double L1 = mid1 == 0 ? INT_MIN : nums1[(mid1 - 1) / 2];
			double L2 = mid2 == 0 ? INT_MIN : nums2[(mid2 - 1) / 2];
			double R1 = mid1 == m * 2 ? INT_MAX : nums1[mid1 / 2];
			double R2 = mid2 == n * 2 ? INT_MAX : nums2[mid2 / 2];
			if (L1 > R2) left = mid2 + 1;
			else if (L2 > R1) right = mid2 - 1;
			else return (max(L1, L2) + min(R1, R2)) / 2;
		}
		return -1;
	}
};
