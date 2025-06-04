// @lcpr-before-debug-begin




// @lcpr-before-debug-end

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
    // I.
    // 感觉需要先排序
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());
        vector<int> prev = intervals[0];
        for(int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= prev[1] && intervals[i][0] >= prev[0] && intervals[i][1] <= prev[1] && intervals[i][1] >= prev[0])
            { // 后一个区间在前一个区间内
                continue;
            } else if (intervals[i][0] <= prev[1] && intervals[i][0] >= prev[0])
            {
                prev[1] = intervals[i][1];
            } else {
                res.push_back(prev);
                prev = intervals[i];
            }
        }
        res.push_back(prev);
        return res;
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

// @lcpr case=start
// [[1,4],[2, 3]]\n
// @lcpr case=end
 */

