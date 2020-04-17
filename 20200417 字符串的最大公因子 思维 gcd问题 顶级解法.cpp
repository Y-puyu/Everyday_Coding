// 执行用时 :4 ms, 在所有 C++ 提交中击败了93.06%的用户
// 内存消耗 :8.8 MB, 在所有 C++ 提交中击败了100.00%的用户

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if (str1 + str2 != str2 + str1) return "";
        // __gcd() 为c++自带的求最大公约数的函数
        return str1.substr(0, __gcd((int)str1.length(), (int)str2.length())); 
    }
};
