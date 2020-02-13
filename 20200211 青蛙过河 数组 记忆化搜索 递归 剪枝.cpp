// 执行用时 :40 ms, 在所有 C++ 提交中击败了94.12%的用户
// 内存消耗 :13.9 MB, 在所有 C++ 提交中击败了81.25%的用户

class Solution {
public:
	bool canCross(vector<int>& stones) {
		unordered_map<int, bool> m;
		return help(stones, 0, 0, m);
	}

	bool help(vector<int>& stones, int pos, int jump, unordered_map<int, bool>& m) {
		int n = stones.size(), key = pos | jump << 11;
		if (pos >= n - 1) return true;
		if (m.count(key)) return m[key];
		for (int i = pos + 1; i < n; ++i) {
			int dist = stones[i] - stones[pos];
			if (dist < jump - 1) continue;
			if (dist > jump + 1) return m[key] = false;
			if (help(stones, i, dist, m)) return m[key] = true;
		}
		return m[key] = false;
	}
};

// 执行用时 :140 ms, 在所有 C++ 提交中击败了66.29%的用户
// 内存消耗 :35.5 MB, 在所有 C++ 提交中击败了36.81%的用户

class Solution {
public:
	bool canCross(vector<int>& stones) {
		unordered_map<int, unordered_set<int>> m;
		vector<int> dp(stones.size(), 0);
		m[0].insert(0);
		int k = 0;
		for (int i = 1; i < stones.size(); ++i) {
			while (dp[k] + 1 < stones[i] - stones[k]) ++k;
			for (int j = k; j < i; ++j) {
				int t = stones[i] - stones[j];
				if (m[j].count(t - 1) || m[j].count(t) || m[j].count(t + 1)) {
					m[i].insert(t);
					dp[i] = max(dp[i], t);
				}
			}
		}
		return dp.back() > 0;
	}
};


// 执行用时 :616 ms, 在所有 C++ 提交中击败了15.61%的用户
// 内存消耗 :38.9 MB, 在所有 C++ 提交中击败了14.94%的用户
class Solution {
public:
	bool canCross(vector<int>& stones) {
		//第一步只能跳一个不长
		if (stones[1] != stones[0] + 1) {
			return false;
		}
		int endStone = *(--stones.end());//尾端石头
		set<int> stonesSet(++stones.begin(), stones.end());//将vector容器转换为set容器
		map<int, set<int> > myMap;//myMap[i]标记i可跳的不长
		myMap[*stonesSet.begin()].insert(1);//初始只能跳一步到第二个位置
		//顺序访问所有石头
		for (auto stone : stonesSet) {
			//根据上一次到达此地的步长集合，计算下一步可跳的步长
			for (auto nextStone : myMap[stone]) {
				//步长nextStone - 1
				if (nextStone > 1 && stonesSet.find(stone + nextStone - 1) != stonesSet.end()) {
					//如果跳nextStone - 1后到达的石头在stonesSet中，说明stone + nextStone - 1这块石头可由不长nextStone - 1到达
					myMap[stone + nextStone - 1].insert(nextStone - 1);
				}
				//步长nextStone
				if (stonesSet.find(stone + nextStone) != stonesSet.end()) {
					//如果跳nextStone 后到达的石头在stonesSet中，说明stone + nextStone这块石头可由不长nextStone到达
					myMap[stone + nextStone].insert(nextStone);
				}
				//步长nextStone + 1
				if (stonesSet.find(stone + nextStone + 1) != stonesSet.end()) {
					//如果跳nextStone + 1后到达的石头在stonesSet中，说明stone + nextStone + 1这块石头可由不长nextStone + 1到达
					myMap[stone + nextStone + 1].insert(nextStone + 1);
				}
				//如果已经达到了endStone
				if (myMap.count(endStone) > 0) {
					return true;
				}
			}
		}
		return false;
	}
};


// 执行用时 :24 ms, 在所有 C++ 提交中击败了96.83%的用户
// 内存消耗 :12.3 MB, 在所有 C++ 提交中击败了86.81%的用户
class Solution {
private:
	set<int> stonesSet;
public:
	//从nowStone开始搜索能否到达last，beforeStep为到达nowStone的步长
	bool jump(int nowStone, int beforeStep, int last) {
		//如果已经达到了终点
		if ((nowStone + beforeStep + 1) == last || (nowStone + beforeStep) == last || (nowStone + beforeStep - 1) == last) {
			return true;
		}
		//采取贪心策略，每次都先选择beforeStep + 1步长
		if (stonesSet.find(nowStone + beforeStep + 1) != stonesSet.end() && jump(nowStone + beforeStep + 1, beforeStep + 1, last)) {
			return true;
		}
		//再beforeStep步长
		if (stonesSet.find(nowStone + beforeStep) != stonesSet.end() && jump(nowStone + beforeStep, beforeStep, last)) {
			return true;
		}
		//最后beforeStep - 1步长
		if (beforeStep > 1 && stonesSet.find(nowStone + beforeStep - 1) != stonesSet.end() && jump(nowStone + beforeStep - 1, beforeStep - 1, last)) {
			return true;
		}
		return false;
	}
	bool canCross(vector<int>& stones) {
		if (stones[1] != 1) return false;
		int last = stones.back();
		for (int i = 1; i < stones.size(); ++i) {
			if (i > 3 && stones[i - 1] * 2 < stones[i]) {//剪枝算法，stones[i - 1]最多是有步长stones[i - 1]到达
				//stones[i - 1] * 2 < stones[i],说明无论如何stones[i]都不可达
				return false;
			}
			stonesSet.insert(stones[i]);
		}
		return jump(1, 1, last);
	}
};


