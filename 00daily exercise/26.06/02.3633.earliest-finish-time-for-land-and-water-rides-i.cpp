/*
 * @lc app=leetcode.cn id=3633 lang=cpp
 * @lcpr version=30204
 *
 * [3633] 最早完成陆地和水上游乐设施的时间 I
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
    // I. 枚举 + 分类讨论
    // 先考虑先玩陆地项目再玩水上项目，然后再考虑对调，
    // 比较两种顺序下的最小值，以“先陆地，后水上”为例
    // 1. 分别计算所有陆地项目的“开始时间+持续时间”
    // 2. 玩第二个项目时，分类：
    //      1. 已经开放则立刻开始，总时间为：
    //          "第一个项目的结束时间 + 水上项目的结束时间"
    //      2. 还没开放，则需要等到开放方可，总时间为：
    //          "水上项目的开始时间+水上项目的持续时间"
    // 同样方法计算“先水上，后陆地”的最早完成时间
    // 枚举组合返回最小即可
    // tc: O(n * m), sc: O(1)

    // II. 线性枚举 + 分类讨论
    // 我们不首先区分陆地和水上，只是分析第一类项目和第二类项目
    // 固定第二类项目，最终完成时间：
    //  max(finish1, start2) + duration2
    // finish1: 第一类项目的结束时间，我们发现此值对finish1单调不减
    // 于是我们只要保留第一类项目中的最早结束时间即可
    // 所以，分别让第一类项目取陆地/水上，取出最早结束的项目
    // 然后遍历所有第二类项目，找到最早结束的时间即可
    // tc: O(n + m) sc: O(1)
public:
    // II. 
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
        // I.
        // int n = landStartTime.size();
        // int m = waterStartTime.size();
        // int res = INT_MAX;
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < m; j++) {
        //         int land = landStartTime[i] + landDuration[i];
        //         int land_water = max(land, waterStartTime[j]) + waterDuration[j];
        //         res = min(res, land_water);

        //         int water = waterStartTime[j] + waterDuration[j];
        //         int water_land = max(water, landStartTime[i]) + landDuration[i];
        //         res = min(res, water_land);
        //     }
        // }
        // return res;

        // II.
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

