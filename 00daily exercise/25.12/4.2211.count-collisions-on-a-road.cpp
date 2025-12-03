/*
 * @lc app=leetcode.cn id=2211 lang=cpp
 * @lcpr version=30204
 *
 * [2211] 统计道路上的碰撞次数
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
    // I. 模拟
    // 首先，停留的车辆不会计算碰撞，我们从左到右遍历
    // 用flag来记录左侧车辆的状况
    // 如果左侧没有，或者左侧车辆全部左移，flag = -1
    // 如果左侧有车辆碰撞，他们自然会在某点停止，flag = 0
    // 如果左侧有车辆右移，flag=右移车辆的数量
    // 这时考虑当前车辆，又需要三种情况：
    // 1. 当前车辆左移，flag >= 0 => 碰撞次数+=(flag+1), 然后flag重置为0
    // 2. 当前车辆不动，flag > 0, 则碰撞次数+=flag, flag重置为0
    // 3. 当前车辆右移，flag < 0, 则flag = 1, 否则flag += 1
    // tc: O(n), sc: O(1)
    // II. 计数
    // 我们定义连续的向外侧行使且中间未被反向或静止车辆阻断的部分为“外移车辆"
    // 那么，左外移车辆和右外移车辆不会互相碰撞，其余的移动车辆都会恰好发生一次碰撞

public:
    int countCollisions(string directions) {
        // I.
        // int res = 0;
        // int flag = -1;
        // for (auto c: directions) {
        //     if (c == 'L') {
        //         if (flag >= 0) {
        //             res += flag + 1;
        //             flag = 0;
        //         }
        //     } else if (c == 'S') {
        //         if (flag > 0) {
        //             res += flag;
        //         }
        //         flag = 0;
        //     } else {
        //         if (flag >= 0) {
        //             flag++;
        //         } else {
        //             flag = 1;
        //         }
        //     }
        // }
        // return res;

        // II.
        int n = directions.size();
        int l = 0, r = n - 1;

        while (l < n && directions[l] == 'L') {
            l++;
        }
        while (r >= l && directions[r] == 'R') {
            r--;
        }

        int res = 0;
        for (int i = l; i <= r; i++) {
            if (directions[i] != 'S') {
                res++;
            }
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "RLRSLL"\n
// @lcpr case=end

// @lcpr case=start
// "LLRR"\n
// @lcpr case=end

 */

