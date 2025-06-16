// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=1035 lang=cpp
 * @lcpr version=30204
 *
 * [1035] 不相交的线
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
    // mucl[i][j]: nums[0:i-1]和nums[0:j-1]的不相交线的最大数量
    // mucl[0][j] = mucl[i][0] = 0;
    // 和上一题一样，也有mucl关于i, j递增
    // mucl[i][j] = { max(mucl[i - 1][j], mucl[i][j - 1]); if nums[j-1] != nums[i - 1]\
    //              { 1 + mucl[i - 1][j - 1]             ; else
    // 标准答案给出了形式化说明：
    // k条互不相交的直线分别连接了nums_1, nums_2的k对相等的元素，且这k对在两个数组中的相对顺序必须一致
    // 因此这k对自然就构成了两组序列的公共子序列LCS, 照搬代码即可
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> mucl(n + 1, vector<int>(m + 1));
        for (int i = 0; i < n; i++)
        {
            mucl[i][0] = 0;
        }
        for (int j = 0; j < m; j++)
        {
            mucl[0][j] = 0;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (nums1[i - 1] != nums2[j - 1])
                {
                    mucl[i][j] = max(mucl[i - 1][j], mucl[i][j - 1]);
                } else {
                    mucl[i][j] = 1 + mucl[i - 1][j - 1];
                }              
            }
        }
        ans = mucl[n][m];
        return ans;
        // 这不和上一题的代码一样摸一样么，上一题做出来这题秒杀啊，
        // 21'32'' a.c.
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,4,2]\n[1,2,4]\n
// @lcpr case=end

// @lcpr case=start
// [2,5,1,2,5]\n[10,5,2,1,5,2]\n
// @lcpr case=end

// @lcpr case=start
// [1,3,7,1,7,5]\n[1,9,2,5,1]\n
// @lcpr case=end

 */

