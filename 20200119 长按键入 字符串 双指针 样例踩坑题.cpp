// 遍历name代码展示：
class Solution {
public:
	bool isLongPressedName(string name, string typed) {
		for (int i = 0, j = 0; i < name.length(); ++i) {
			while (name[i] == name[i + 1]) {
				++i;
				++j;
			}
			int flag = j;
			while (typed[j] == name[i]) {
				++j;
			}

			if (flag == j) return false;
		}
		return true;
	}
};

// 以上代码遇到name = “aaall” typed = “daalll” 类似于这样的样例，
// name的重复元素会将typed覆盖掉连续的一部分。修改如下：
class Solution {
public:
	bool isLongPressedName(string name, string typed) {
		for (int i = 0, j = 0; i < name.length(); ++i) {
			while ((name[i] == name[i + 1]) && (name[i] == typed[j])) {
				++i;
				++j;
			}
			int flag = j;
			while (typed[j] == name[i]) {
				++j;
			}

			if (flag == j) return false;
		}
		return true;
	}
};
// 该flag位置必须在两while之间，若flag放置最前方，
// 当name = “saeed”，flag = "ssaaedd"会发生调用两次情况1的while，修改了j的大小，导致输出true。

// 遍历typed代码展示：
bool isLongPressedName(string name, string typed) {
	int j = 0, len = name.size();
	for (int i = 0; i < typed.size(); i++) {
		if (typed[i] == name[j] && j < len) {
			j++;
			continue;
		}
		else if (j > 0 && typed[i] == name[j - 1]) //首字母不同时j-1超出索引范围
			continue;
		else
			return false;
	}
	if (j == len)
		return true;
	else
		return false;
}
