/*
 * @lc app=leetcode.cn id=1833 lang=cpp
 * @lcpr version=30204
 *
 * [1833] 雪糕的最大数量
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
    // 我们贪心即可，将costs排序，从小到大累加即可
    // 可以证明，贪心是合理的，因为如果没有局部最优，将这个雪糕
    // 改成更便宜的一定花费更少
    // tc: O(nlogn), sc: O(logn)
    // II. 记数排序
    // 用数组freq记录costs每个元素出现的次数，
    // freq[i]: i在costs中出现的次数，这样可以更快做乘法
    // 因为costs最大值（记为C）不超过10^5, 故用时会更短
    // tc: O(n + C), tc: O(C)
public:
    int maxIceCream(vector<int>& costs, int coins) {
        // I.
        // sort(costs.begin(), costs.end());
        // int count = 0;
        // int n = costs.size();
        // for (int i = 0; i < n; i++) {
        //     int cost = costs[i];
        //     if (coins >= cost) {
        //         coins -= cost;
        //         count++;
        //     } else {
        //         break;
        //     }
        // }
        // return count;

        // II.
        vector<int> freq(100001);
        for (int& cost: costs) {
            freq[cost]++;
        }
        int count = 0;
        for (int i = 1; i <= 100000; i++) {
            if (coins >= i) {
                int curCount = min(freq[i], coins / i);
                count += curCount;
                coins -= i * curCount;
            } else {
                break;
            }
        }
        return count;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,3,2,4,1]\n7\n
// @lcpr case=end

// @lcpr case=start
// [10,6,8,7,7,8]\n5\n
// @lcpr case=end

// @lcpr case=start
// [1,6,3,1,2,5]\n20\n
// @lcpr case=end

 */

