// 执行用时 :28 ms, 在所有 C++ 提交中击败了18.64%的用户
// 内存消耗 :11.4 MB, 在所有 C++ 提交中击败了54.94%的用户

class Solution {
public:
	vector<string> topKFrequent(vector<string>& words, int k) {
		vector<string> res(k);
		unordered_map<string, int> freq;
		auto cmp = [](pair<string, int>& a, pair<string, int>& b) {
			return a.second > b.second || (a.second == b.second && a.first < b.first);
		};
		priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(cmp) > q(cmp);
		for (auto word : words) ++freq[word];
		for (auto f : freq) {
			q.push(f);
			if (q.size() > k) q.pop();
		}
		for (int i = res.size() - 1; i >= 0; --i) {
			res[i] = q.top().first; q.pop();
		}
		return res;
	}
};


// 执行用时 :20 ms, 在所有 C++ 提交中击败了71.21%的用户
// 内存消耗 :12.3 MB, 在所有 C++ 提交中击败了5.06%的用户

class Solution {
public:
	vector<string> topKFrequent(vector<string>& words, int k) {
		vector<string> res;
		unordered_map<string, int> freq;
		map<int, set<string>> m;
		for (string word : words) ++freq[word];
		for (auto a : freq) {
			m[a.second].insert(a.first);
		}
		for (auto it = m.rbegin(); it != m.rend(); ++it) {
			if (k <= 0) break;
			auto t = it->second;
			vector<string> v(t.begin(), t.end());
			if (k >= t.size()) {
				res.insert(res.end(), v.begin(), v.end());
			}
			else {
				res.insert(res.end(), v.begin(), v.begin() + k);
			}
			k -= t.size();
		}
		return res;
	}
};


// 执行用时 :24 ms, 在所有 C++ 提交中击败了39.77%的用户
// 内存消耗 :12.1 MB, 在所有 C++ 提交中击败了5.06%的用户

class Solution {
public:

	class Compare {
	public:
		// 在set中进行排序时的比较规则
		bool operator()(const pair<string, int>& left, const pair<string, int>& right) const { // 坑点，为什么去掉const 就直接爆炸了？？？
			return left.second > right.second;
		}
	};

	vector<string> topKFrequent(vector<string>& words, int k) {
		// 用 <单词，单词出现次数> 构建键值对，然后将vector中的单词放进去，统计每个单词出现的次数
		map<string, int> m;
		for (int i = 0; i < words.size(); ++i)
			++(m[words[i]]);

		// 将单词按照其出现次数进行排序，出现相同次数的单词集中在一块
		multiset<pair<string, int>, Compare> ms(m.begin(), m.end());

		// 将相同次数的单词放在set中，然后再放到vector中   
		set<string> s;
		int count = 0;
		int leftCount = k;

		vector<string> ret;
		for (auto& e : ms) {
			if (!s.empty()) {
				// 相同次数的单词已经全部放到set中
				if (count != e.second) {
					if (s.size() < leftCount) {
						ret.insert(ret.end(), s.begin(), s.end());
						leftCount -= s.size();
						s.clear();
					}
					else {
						break;
					}
				}
			}

			count = e.second;
			s.insert(e.first);
		}

		for (auto& e : s) {
			if (0 == leftCount)
				break;

			ret.push_back(e);
			leftCount--;
		}
		return ret;
	}
};


// 执行用时 :24 ms, 在所有 C++ 提交中击败了39.77%的用户
// 内存消耗 :12.1 MB, 在所有 C++ 提交中击败了5.06%的用户

class Solution {
public:

	class Compare {
	public:
		// 在set中进行排序时的比较规则
		bool operator()(const pair<string, int>& left, const pair<string, int>& right) const { // 坑点，为什么去掉const 就直接爆炸了？？？
			return left.second > right.second;
		}
	};

	vector<string> topKFrequent(vector<string>& words, int k) {
		// 用 <单词，单词出现次数> 构建键值对，然后将vector中的单词放进去，统计每个单词出现的次数
		map<string, int> m;
		for (int i = 0; i < words.size(); ++i)
			++(m[words[i]]);

		// 将单词按照其出现次数进行排序，出现相同次数的单词集中在一块
		multiset<pair<string, int>, Compare> ms(m.begin(), m.end());

		// 将相同次数的单词放在set中，然后再放到vector中   
		set<string> s;
		int count = 0;
		int leftCount = k;

		vector<string> ret;
		for (auto& e : ms) {
			if (!s.empty()) {
				// 相同次数的单词已经全部放到set中
				if (count != e.second) {
					if (s.size() < leftCount) {
						ret.insert(ret.end(), s.begin(), s.end());
						leftCount -= s.size();
						s.clear();
					}
					else {
						break;
					}
				}
			}

			count = e.second;
			s.insert(e.first);
		}

		for (auto& e : s) {
			if (0 == leftCount)
				break;

			ret.push_back(e);
			leftCount--;
		}
		return ret;
	}
};
