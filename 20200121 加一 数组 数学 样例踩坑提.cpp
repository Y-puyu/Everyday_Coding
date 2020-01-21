class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		for (int i = (int)digits.size() - 1; i >= 0; --i) {
			if (digits[i] == 9) {
				digits[i] = 0;
			}
			else {
				digits[i]++;
				break;
			}
		}
		if (digits[0] == 0) {
			digits.push_back(0);
			digits[0] = 1;
		}
		return digits;
	}
};


class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		int i = digits.size() - 1;
		digits[i] += 1;
		if (digits[i] == 10) {
			while (i >= 1 && digits[i] == 10) {
				digits[i] = 0;
				digits[i - 1] += 1;
				--i;
			}

		}
		reverse(digits.begin(), digits.end());
		if (digits[digits.size() - 1] == 10) {
			digits[digits.size() - 1] = 0;
			digits.push_back(1);
		}
		reverse(digits.begin(), digits.end());
		return digits;
	}
};