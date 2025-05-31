/*
 * @lc app=leetcode.cn id=338 lang=cpp
 * @lcpr version=30204
 *
 * [338] 比特位计数
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
    int numBits(int n) {
        int res = 0;
        while(n > 0) {
            if(n % 2 == 1) {
                res++;
            }
            n /= 2;
        }
        return res;
    }
    vector<int> countBits(int n) {
        // vector<int> res;
        // for(int i = 0; i <= n; i++) {
        //     res.push_back(numBits(i));
        // }
        // return res;

        // O(N)的方法很多，挑一个思路比较理解的，需要如下思考
        // 维护“最低有效位”
        // x >> 1 = \floor{x / 2}, 如果bits[\floor{x / 2}]已知，就可以动态规划
        // x 为偶数 bits[x] = bits[\floor{x / 2}]
        // x 为奇数 bits[x] = bits[\floor{x / 2}] + 1
        // 统一为 bits[x] = bits[\florr{x / 2}] + x % 2;
        // 用位操作 bits[x] = bist[x >> 1] + (x & 1)
        vector<int> bits(n + 1, 0);
        for (int i = 0; i < n + 1; i++)
        {
            bits[i] = bits[i >> 1] + (i & 1);
        }
        return bits;
        

    }
};
// @lc code=end



/*
// @lcpr case=start
// 2\n
// @lcpr case=end

// @lcpr case=start
// 5\n
// @lcpr case=end

 */

