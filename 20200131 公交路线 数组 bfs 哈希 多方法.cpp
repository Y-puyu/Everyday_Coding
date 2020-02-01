// 执行用时 :116 ms, 在所有 C++ 提交中击败了96.52%的用户
// 内存消耗 :34.4 MB, 在所有 C++ 提交中击败了67.84%的用户
class Solution {
public:
	int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
		if (S == T) return 0;
		int res = 0;
		unordered_map<int, vector<int>> stop2bus;
		queue<int> q{ {S} };
		unordered_set<int> visited;
		for (int i = 0; i < routes.size(); ++i) {
			for (int j : routes[i]) {
				stop2bus[j].push_back(i);
			}
		}
		while (!q.empty()) {
			++res;
			for (int i = q.size(); i > 0; --i) {
				int t = q.front(); q.pop();
				for (int bus : stop2bus[t]) {
					if (visited.count(bus)) continue;
					visited.insert(bus);
					for (int stop : routes[bus]) {
						if (stop == T) return res;
						q.push(stop);
					}
				}
			}
		}
		return -1;
	}
};


// 执行用时 :2228 ms, 在所有 C++ 提交中击败了5.23%的用户
// 内存消耗 :53.3 MB, 在所有 C++ 提交中击败了17.18%的用户
class Solution {
public:
	int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
		if (S == T) return 0;
		unordered_map<int, unordered_set<int>> stop2bus;
		queue<pair<int, int>> q{ {{S, 0}} };
		unordered_set<int> visited;
		for (int i = 0; i < routes.size(); ++i) {
			for (int j : routes[i]) {
				stop2bus[j].insert(i);
			}
		}
		while (!q.empty()) {
			int cur = q.front().first, cnt = q.front().second; q.pop();
			if (cur == T) return cnt;
			for (int bus : stop2bus[cur]) {
				for (int stop : routes[bus]) {
					if (visited.count(stop)) continue;
					visited.insert(stop);
					q.push({ stop, cnt + 1 });
				}
			}
		}
		return -1;
	}
};
