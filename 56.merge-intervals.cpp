/*
 * @lc app=leetcode.cn id=56 lang=cpp
 * @lcpr version=30204
 *
 * [56] 合并区间
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
    // 用merged存储最终答案
    // 列表左端点升序排序，第一个区间加入merged
    // 当前区间的左端点在数组merged中最后一个区间的右端点之后，则不会重合，放在merged末尾
    // 否则重合，更新最后一个区间的右端点，使其成为较大值
    
    // 反证法：假设两个区间本应合并但没有，则存在a[i], a[j], a[k]
    // a[i], a[k] 可以合并，但i,j;j,k不能合并
    // s.t. a[i].end < a[j].start; i,j不能合并
    //      a[j].end < a[k].start; j,k不能合并
    //      a[i].end >=a[k].start; i,k能合并
    // (1)(2) 与 (3) 矛盾，所以一定能合并

public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 0)
        {
            return {};
        }
        sort(intervals.begin(), intervals.end());
        vector<vector<int>>  merged;
        for (int i = 0; i < intervals.size(); i++)
        {
            int L = intervals[i][0], R = intervals[i][1];
            if (!merged.size() || merged.back()[1] < L)
            {
                merged.push_back({L, R});
            } else {
                merged.back()[1] = max(merged.back()[1], R);
            }
        }
        return merged;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,3],[2,6],[8,10],[15,18]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,4],[4,5]]\n
// @lcpr case=end

 */

