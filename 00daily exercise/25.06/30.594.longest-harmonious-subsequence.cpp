/*
 * @lc app=leetcode.cn id=594 lang=cpp
 * @lcpr version=30204
 *
 * [594] 最长和谐子序列
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
    // I. 枚举
    // 枚举当前元素x, 找到所有等于x或者x+1的元素个数，就可以找到子序列长度
    // 实际处理时，首先对数组排序（因为我们之关系子序列的长度而不关心序列内容）
    // 相邻元素差1就是需要的子序列
    // 然后，我们使用滑动窗口，begin指向第一个连续相同元的首元素，end指向第二个连续相同元的尾元素
    // 二者差1，则当前和谐子序列长度为end-begin + 1
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int begin = 0;
        int res = 0;
        for (int end = 0; end < nums.size(); end++)
        {
            while (nums[end] - nums[begin] > 1)
            {
                begin++;
            }
            if (nums[end] - nums[begin] == 1)
            {
                res = max(res, end - begin + 1);
            }
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,3,2,2,5,2,3,7]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,1,1]\n
// @lcpr case=end

 */

