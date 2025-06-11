/*
 * @lc app=leetcode.cn id=57 lang=cpp
 * @lcpr version=30204
 *
 * [57] 插入区间
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
    // S_1 = [l_1, r_1], S_2 = [l_2, r_2] 不重叠的充要条件
    // 1. S_1 在 S_2 左侧： r_1 < l_2;
    // 2. S_1 在 S_2 右侧： l_1 > r_2;
    // 否则他们有交集 [max(l_1, l_2), min(r_1, r_2)]
    // 并集[min(l_1, l_2), max(r_1, r_2)]
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // 找出所有与区间S = [left, right]重叠的区间集合X';
        // X' 中所有区间连同S合并成一个大区间；
        // 返回不与X'重叠的区间以及合并后的大区间

        int N = intervals.size();
        int left = newInterval[0];
        int right = newInterval[1];
        bool placed = false;
        vector<vector<int>> ans;

        // 遍历到区间[l_i, r_i]:
        // r_i < left, 说明[l_i, r_i]与S不重叠在其左侧，放入答案；
        // l_i > right, 说明[l_i, r_i]与S不重叠在其右侧，放入答案；
        // 否则，[l_i, r_i]与S重叠，无需将S与[l_i, r_i]加入答案
        // 我们需要将S与[l_i, r_i]合并，S更新为[l_i, r_i]的并集
        // 遇到第一个l_i > right，则以后都不会与S重叠，直接将S加入答案
        // 如果到最后都不存在这样的区间，则结束后，S加入答案
        for (int i = 0; i < N; i++)
        {
            vector<int> interval = intervals[i];
            if (interval[0] > right)
            {
                // 插入区间的右侧且无交集
                if (!placed)
                {
                    ans.push_back({left, right});
                    placed = true;// 以后都不会与S重叠
                }
                ans.push_back(interval);
                
            } else if (interval[1] < left)
            {
                // 插入区间的左侧且无交集
                ans.push_back(interval);
            } else {
                // 与插入区间有交集，计算他们的并集
                left = min(left, interval[0]);
                right = max(right, interval[1]);
            }
        }
        if (!placed)
        {
            ans.push_back({left, right});
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,3],[6,9]]\n[2,5]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2],[3,5],[6,7],[8,10],[12,16]]\n[4,8]\n
// @lcpr case=end

 */

