// 执行用时 :32 ms, 在所有 C++ 提交中击败了27.41%的用户
// 内存消耗 :9.5 MB, 在所有 C++ 提交中击败了30.34%的用户

class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};


// 执行用时 :12 ms, 在所有 C++ 提交中击败了17.42%的用户
// 内存消耗 :14.7 MB, 在所有 C++ 提交中击败了5.15%的用户

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> v1(256, 0), v2(256, 0);
        for (auto e : s) ++v1[e];
        for (auto e : s) ++v2[e];
        for (int i = 0; i < v1.size(); ++i) 
            if (v1[i] != v2[i]) return false;
        return true;
    }
};
