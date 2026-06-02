/*
 * @lc app=leetcode.cn id=2144 lang=cpp
 * @lcpr version=30204
 *
 * [2144] 打折购买糖果的最小开销
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
    // I. 贪心
    // 将糖果价格从高到低排序，3个一组，花钱购买两个，赠送第三个即可
    // 首先这一定是赠送数量最多的方案（显然，反证法可证）
    // 同样的，因为我们免费获得的糖果要小于购买的糖果，所以
    // 也可以知道此方案能获得价格尽可能高的糖果。
    // 于是，我们将cost从高到低排序，免费获得下标模3余2的糖果方案开销最小
    // 跳过这些糖果将开销返回作为答案即可。
    // tc: O(nlogn), sc: O(logn)
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end(), greater<int>());
        int res = 0;
        int n = cost.size();
        for (int i = 0; i < n; i++) {
            if (i % 3 != 2) {
                res += cost[i];
            }
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [6,5,7,9,2,2]\n
// @lcpr case=end

// @lcpr case=start
// [5,5]\n
// @lcpr case=end

 */

