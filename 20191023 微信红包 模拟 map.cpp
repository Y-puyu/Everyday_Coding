class Gift {
public:
	int getValue(vector<int> gifts, int n) {
		// write code here
		sort(gifts.begin(), gifts.end());
		// 超过一半的数排序之后必然在中间
		int middle = gifts[n / 2];
		int count = 0;
		for (int i = 0; i < n; ++i) {
			if (gifts[i] == middle)
				count++;
		}

		// 如果个数大于一半，则存在超过一半的数
		if (count > n / 2)
			return middle;
		else
			return 0;
	}
};


class Gift {
public:
	int getValue(vector<int> gifts, int n) {
		// write code here
		map<int, int> count;
		int middle = gifts.size() / 2;
		for (const auto& e : gifts)
			++count[e];
		for (const auto& e : count) {
			if (e.second >= middle)
				return e.first;
		}
		return 0;
	}
};
