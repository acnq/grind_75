/*
 * @lc app=leetcode.cn id=787 lang=cpp
 * @lcpr version=30204
 *
 * [787] K 站中转内最便宜的航班
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
    // I: dp
    // f[t][i]: 通过恰好i次航班，从出发城市src到达城市i需要的最小花费
    // 枚举最后一次航班的起点，有f[t][i] = \min_{(j, i) \in flights}(f[t - 1][j] + cost(j, i))
    // 因为中转k次，也就是最多搭乘k + 1次航班，最终答案为
    // \min_{t \in [1, k + 1]}(f[t][dist])
    // 初始化时有f[0][i] = { 0;      i = src
    //                    { \infin; i != src
    // 真的需要二重循环枚举t和i取最小值么？
    // 一重循环枚举t, 随后枚举flights中每个航班(j, i, cost);
    // 然后不断用f[t - 1][j] + cost更新f[t][i]
    // tc: O((m + n)k); m = |flights|; sc: O(nk)

    // II. 滚动数组
    // f[t][i]只会从f[t-1][]转移而来，我们也可以用两个长度为n的一维数组来进行状态转移。
    // tc不变；sc: O(n)
public:
    static constexpr int INF = 10000 * 101 + 1;
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // I.
        // vector<vector<int>> f(k + 2, vector<int>(n, INF));
        // f[0][src] = 0;
        // for (int t = 1; t <= k + 1; t++)
        // {
        //     for(auto&& flight: flights) {
        //         int j = flight[0], i = flight[1], cost = flight[2];
        //         f[t][i] = min(f[t][i], f[t - 1][j] + cost);
        //     }
        // }
        // int ans = INF;
        // for (int t = 1; t <= k + 1; t++)
        // {
        //     ans = min(ans, f[t][dst]);
        // }
        // return (ans == INF ? -1 : ans);

        // II.
        vector<int> f(n, INF);
        f[src] = 0;
        int ans = INF;
        for (int t = 1; t <= k + 1; t++)
        {
            vector<int> g(n, INF);
            for (auto&& flight: flights) {
                int j = flight[0], i = flight[1], cost = flight[2];
                g[i] = min(g[i], f[j] + cost);
            }
            f = move(g);
            ans = min(ans, f[dst]);
        }
        return (ans == INF ? -1: ans);
    }
};
// @lc code=end



/*
// @lcpr case=start
// 4\n[[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]]\n0\n3\n1\n
// @lcpr case=end

// @lcpr case=start
// 3\n[[0,1,100],[1,2,100],[0,2,500]]\n0\n2\n1\n
// @lcpr case=end

// @lcpr case=start
// 3\n[[0,1,100],[1,2,100],[0,2,500]]\n0\n2\n0\n
// @lcpr case=end

 */

