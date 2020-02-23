// 执行用时 :12 ms, 在所有 C++ 提交中击败了53.83%的用户
// 内存消耗 :10.1 MB, 在所有 C++ 提交中击败了5.29%的用户

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty())
            return false;
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (target == matrix[i][j])
                    return true;
            }
        }
        return false;
    }
};


// 执行用时 :12 ms, 在所有 C++ 提交中击败了53.83%的用户
// 内存消耗 :9.8 MB, 在所有 C++ 提交中击败了22.75%的用户

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) 
            return false;
        int left = 0, right = matrix.size();
        while (left < right) {
            int mid = (left + right) / 2;
            if (matrix[mid][0] == target) 
                return true;
            if (matrix[mid][0] <= target) 
            left = mid + 1;
            else 
                right = mid;
        }
        int tmp = (right > 0) ? (right - 1) : right;
        left = 0;
        right = matrix[tmp].size();
        while (left < right) {
            int mid = (left + right) / 2;
            if (matrix[tmp][mid] == target)     
                return true;
            if (matrix[tmp][mid] < target) 
                left = mid + 1;
            else 
                right = mid;
        }
        return false;
    }
};


// 执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
// 内存消耗 :10 MB, 在所有 C++ 提交中击败了5.29%的用户
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty())   
            return false;
        int i = 0, j = (int)matrix[0].size() - 1;
        while (i < matrix.size() && j >= 0) {
            if (matrix[i][j] == target) 
                return true;
            else if 
                (matrix[i][j] > target) --j;
            else 
                ++i;
        }   
        return false;
    }
};
