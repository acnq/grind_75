// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=74 lang=cpp
 * @lcpr version=30204
 *
 * [74] 搜索二维矩阵
 */


// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
    // I. 二次二分查找
    // 和我思路一样，但是我写不出来，
    // 官方用的库函数，感觉可以熟练熟练

    // II. 一次二分查找
    // 矩阵每行拼接在上行的末尾，就会得到升序数组
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // 感觉可以先对列二分，然后再对行二分
        // O(log m + log n) = O(log(mn))
        // 写不出来， 看参考答案了
        // auto row = upper_bound(matrix.begin(), matrix.end(), target, [](const int b, const vector<int>& a) {
        //     return b < a[0];
        // });
        // if (row == matrix.begin())
        // {
        //     return false;
        // }
        // row--;
        // return binary_search(row->begin(), row->end(), target);
        
        int m = matrix.size(), n = matrix[0].size();
        int low = 0, high = m * n - 1;
        while (low <= high)
        {
            int mid = (high - low) / 2 + low;
            int x = matrix[mid / n][mid % n];
            if (x < target)
            {
                low = mid + 1;
            } else if (x > target)
            {
                high = mid - 1;
            } else
            {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,3,5,7],[10,11,16,20],[23,30,34,60]]\n3\n
// @lcpr case=end

// @lcpr case=start
// [[1,3,5,7],[10,11,16,20],[23,30,34,60]]\n13\n
// @lcpr case=end


// @lcpr case=start
// [[1],[3]]\n1\n
// @lcpr case=end

// @lcpr case=start
// [[1],[3]]\n0\n
// @lcpr case=end

// @lcpr case=start
// [[1,3,5,7],[10,11,16,20],[23,30,34,50]]\n30\n
// @lcpr case=end
 */

