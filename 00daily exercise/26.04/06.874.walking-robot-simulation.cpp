/*
 * @lc app=leetcode.cn id=874 lang=cpp
 * @lcpr version=30204
 *
 * [874] 模拟行走机器人
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
    // I. 哈希表
    // 直接记录移动过程中的最大欧氏距离之平方即为答案
    // 用方向数组dirs = {[-1, 0], [0, 1], [1, 0], [0, -1]}实现
    // 假设坐标(x, y), 方向标号为d, 
    // 往前1单位: x = x + dirs[d][0], y = y + dirs[d][1]
    // 左传： d = (d + 3) mod 4, 右转 d = (d + 1) mod 4
    // tc: O(Cn + m) [C: 向前的步数最大值， C=9, m = |obstacles|]
    // sc: O(m)
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        int px = 0, py = 0, d = 1;
        unordered_set<int> mp;
        for (auto &obstacle: obstacles) {
            mp.emplace(obstacle[0] * 60001 + obstacle[1]);
        } 
        int res = 0;
        for (int c: commands) {
            if (c < 0) {
                d += c == -1 ? 1: -1;
                d %= 4;
                if (d < 0) {
                    d += 4;
                }
            } else {
                for (int i = 0; i < c; i++) {
                    if (mp.count((px + dirs[d][0]) * 60001 + py + dirs[d][1])) {
                        break;
                    }
                    px += dirs[d][0];
                    py += dirs[d][1];
                    res = max(res, px * px + py * py);
                }
            }
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [4,-1,3]\n[]\n
// @lcpr case=end

// @lcpr case=start
// [4,-1,4,-2,4]\n[[2,4]]\n
// @lcpr case=end

// @lcpr case=start
// [6,-1,-1,6]\n[]\n
// @lcpr case=end

 */

