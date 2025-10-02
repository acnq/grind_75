/*
 * @lc app=leetcode.cn id=3100 lang=cpp
 * @lcpr version=30204
 *
 * [3100] 换水问题 II
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
    // 只要剩下的空瓶数量empty >= numExchange，就可以换到一瓶水
    // 算上这瓶水喝完的空瓶；empty的数量减少numExchang-1个
    // tc: O(\sqrt{n}), sc: O(1)
    // II. 数学
    // 令交换次数t, 交换的总空瓶数为empty, 产生的总空瓶数为total
    // empty <= total, 找到最大的t使得不等式成立
    // empty = \sum_{i=0}^{t-1}(numExchange + i) = t * numExchange + t(t-1)/2
    // total = numBottles + t
    // 带入不等式：
    // t * numExchange + t(t - 1)/2 <= numBottles + t
    // 求根公式解出即可
    // tc = sc = O(1)
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        // 我的解法:
        // int emptyBtl = numBottles, res = numBottles, fullBtl = 0;
        // while (emptyBtl >= numExchange) {
        //     while (emptyBtl >= numExchange) {
        //         emptyBtl -= numExchange;
        //         numExchange++;
        //         fullBtl++;
        //     }
        //     emptyBtl += fullBtl;
        //     res += fullBtl;
        //     fullBtl = 0;
        // }
        // return res;
        // I. 模拟
        // int ans = numBottles;
        // for (int empty = numBottles; empty >= numExchange; numExchange++) {
        //     ans++;
        //     empty -= numExchange - 1;
        // }
        // return ans;
        // II. 数学
        int a = 1;
        int b = 2 * numExchange - 3;
        int c = - 2 * numBottles;
        double delta = (double) b * b - 4.0 * a * c;
        int t = (int)ceil((-b + sqrt(delta)) / (2.0 * a));
        return numBottles + t - 1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 13\n6\n
// @lcpr case=end

// @lcpr case=start
// 10\n3\n
// @lcpr case=end

 */

