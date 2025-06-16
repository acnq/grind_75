/*
 * @lc app=leetcode.cn id=1964 lang=cpp
 * @lcpr version=30204
 *
 * [1964] 找出到每个位置为止最长的有效障碍赛跑路线
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
    // 按照T300的解法II写;
    // d[i]: 长度为i的最长上升子序列的末尾元素的最小值
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int> d, ans;
        for(int ob: obstacles) {
            if (d.empty() || ob >= d.back())
            {
                d.push_back(ob);
                ans.push_back(d.size());
            } else {
                // 将 300 题解中的二分查找改为 API 调用使得代码更加直观
                // 如果是最长严格递增子序列，这里是 lower_bound
                // 如果是最长递增子序列，这里是 upper_bound
                int loc = upper_bound(d.begin(), d.end(), ob) - d.begin();
                ans.push_back(loc + 1);
                d[loc] = ob;
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,2]\n
// @lcpr case=end

// @lcpr case=start
// [2,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [3,1,5,6,4,2]\n
// @lcpr case=end

 */

