/*
 * @lc app=leetcode.cn id=1578 lang=cpp
 * @lcpr version=30204
 *
 * [1578] 使绳子变成彩色的最短时间
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
    // 贪心：
    // 如果colors中有若干相邻重复颜色
    // 则这些颜色最多保留一个元素，我们只需贪心的
    // 保留这些颜色中删除成本最高的颜色
    // tc: O(n), sc: O(1)
public:
    int minCost(string colors, vector<int>& neededTime) {
        int i = 0, len = colors.length();
        int ret = 0;
        while (i < len) {
            char ch = colors[i];
            int maxValue = 0;
            int sum = 0;

            while (i < len && colors[i] == ch) {
                maxValue = max(maxValue, neededTime[i]);
                sum += neededTime[i];
                i++;
            }
            ret += sum - maxValue;
        }   
        return ret;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "abaac"\n[1,2,3,4,5]\n
// @lcpr case=end

// @lcpr case=start
// "abc"\n[1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// "aabaa"\n[1,2,3,4,1]\n
// @lcpr case=end

 */

