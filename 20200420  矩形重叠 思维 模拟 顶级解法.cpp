// 执行用时 :4 ms, 在所有 C++ 提交中击败了62.18%的用户
// 内存消耗 :9.3 MB, 在所有 C++ 提交中击败了7.14%的用户

class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        return !(rec1[2] <= rec2[0] ||   // 左
                 rec1[3] <= rec2[1] ||   // 下
                 rec1[0] >= rec2[2] ||   // 右
                 rec1[1] >= rec2[3]);    // 上
    }
};



// 执行用时 :4 ms, 在所有 C++ 提交中击败了62.18%的用户
// 内存消耗 :9.1 MB, 在所有 C++ 提交中击败了7.14%的用户

class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        bool x_overlap = !(rec1[2] <= rec2[0] || rec2[2] <= rec1[0]);
        bool y_overlap = !(rec1[3] <= rec2[1] || rec2[3] <= rec1[1]);
        return x_overlap && y_overlap;
    }
};
