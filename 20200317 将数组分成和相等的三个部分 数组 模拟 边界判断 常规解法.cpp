// 执行用时 :64 ms, 在所有 C++ 提交中击败了35.15%的用户
// 内存消耗 :33.2 MB, 在所有 C++ 提交中击败了5.26%的用户

class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        vector<int> vt(A.size() + 1, 0);
        for (int i = 0; i < A.size(); ++i) vt[i + 1] = A[i] + vt[i];
        if (vt.back() % 3 != 0) return false; 
        int tmp = vt.back() / 3;
        int val = 2 * tmp, flag = 0, index = 0;
        for (int i = 1; i < vt.size(); ++i) {
            if (vt[i] == tmp)   {
                index = i;   
                ++flag;
                break;
            }
        }
        for (int i = index + 1; i < vt.size(); ++i) {
            if (vt[i] == val) {
                ++flag;
                if (i == vt.size() - 1) return false;
                break; 
            }
        }
        if (flag == 2) return true;
        return false;
    }
};
