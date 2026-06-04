/*
 * @lc app=leetcode.cn id=3635 lang=cpp
 * @lcpr version=30204
 *
 * [3635] 最早完成陆地和水上游乐设施的时间 II
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
public:
    int solver(vector<int>& start1, vector<int>& duration1, vector<int>& start2, vector<int>& duration2) {
        int finish1 = INT_MAX;
        for (int i = 0; i < start1.size(); i++) {
            finish1 = min(finish1, start1[i] + duration1[i]);
        }

        int finish2 = INT_MAX;
        for (int i = 0; i < start2.size(); i++) {
            finish2 = min(finish2, max(start2[i], finish1) + duration2[i]);
        }
        return finish2;
    }

    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        // I. 就是02.3633的第二种解法，时间复杂度够
        int land_water = solver(landStartTime, landDuration, waterStartTime, waterDuration);
        int water_land = solver(waterStartTime, waterDuration, landStartTime, landDuration);
        return min(land_water, water_land);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,8]\n[4,1]\n[6]\n[3]\n
// @lcpr case=end

// @lcpr case=start
// [5]\n[3]\n[1]\n[10]\n
// @lcpr case=end

 */

