// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=3625 lang=cpp
 * @lcpr version=30204
 *
 * [3625] 统计梯形的数目 II
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

#include <map>
// @lcpr-template-end
// @lc code=start
class Solution {
    // 哈希：
    // 我们此时需要统计不同斜率对应的梯形数量
    // 同时为了判断是否共线，还要引入截距区分不同线段
    // 对于平行四边形，可以通过相同中点的不同斜率的两条线段来确定
    // 我们用哈希表套vector的形式统计相同斜率线段的截距(slopeToIntercept)，
    // 以及相同中点线段的斜率(midToSlope)，分别统计平行四边形和矩形的数目
    // p_y(p_y - 1) / 2条，分别在两个不同高度上选择一条边即可组成
    // tc: O(n), sc: O(n)
public:
    int countTrapezoids(vector<vector<int>>& points) {
        int n = points.size();
        int inf = 1e9 + 7;
        unordered_map<float, vector<float>> slopeToIntercept;
        unordered_map<int, vector<float>> midToSlope;

        int ans = 0;
        for (int i = 0; i < n; i++) {
            int x1 = points[i][0];
            int y1 = points[i][1];
            for (int j = i + 1; j < n; j++) {
                int x2 = points[j][0];
                int y2 = points[j][1];
                int dx = x1 - x2;
                int dy = y1 - y2;
                float k, b;
                if (x2 == x1) {
                    k = inf;
                    b = x1;
                } else {
                    k = (float)(y2 - y1) / (x2 - x1);
                    b = (float)(y1 * dx - x1 * dy) / dx;
                }
                int mid = (x1 + x2) * 10000 + (y1 + y2);
                slopeToIntercept[k].push_back(b);
                midToSlope[mid].push_back(k);
            }
        }

        for (auto& [_, sti]: slopeToIntercept) {
            if (sti.size() == 1) {
                continue;
            }
            map<float, int> cnt;
            for (float b: sti) {
                cnt[b]++;
            }
            int sum = 0;
            for (auto& [_, count]: cnt) {
                ans += sum * count;
                sum += count;
            }
        }

        for (auto& [_, mts]: midToSlope) {
            if (mts.size() == 1) {
                continue;
            }
            map<float, int> cnt;
            for (float k: mts) {
                cnt[k]++;
            }
            int sum = 0;
            for (auto& [_, count]: cnt) {
                ans -= sum * count;
                sum += count;
            }
        }
        return ans;
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=countTrapezoids
// paramTypes= ["number[][]"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// [[1,0],[2,0],[3,0],[2,2],[3,2]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,0],[1,0],[0,1],[2,1]]\n
// @lcpr case=end

 */

