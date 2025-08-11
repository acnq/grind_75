/*
 * @lc app=leetcode.cn id=2438 lang=cpp
 * @lcpr version=30204
 *
 * [2438] 二的幂数组中查询范围内的乘积
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
    // I. 二进制分解 + 直接计算
    // tc: O(q * logn), q = queries.size(); sc: O(logn)
    // II. 二进制分解 + 预处理
    // 提前计算出每一种询问的答案，时间复杂度为 O(log n)，
    // 之后单次询问的时间复杂度减少至 O(1)。
    // tc: O(log^2n + q), sc: O(log^2n)
public:
    static constexpr int mod = 1e9 + 7;
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        // I.
        // vector<int> bins;
        // int rep = 1;
        // while (n) {
        //     if (n % 2 == 1) {
        //         bins.push_back(rep);
        //     } 
        //     n /= 2;
        //     rep *= 2;
        // }
        // vector<int> ans;
        // for (const auto& query: queries) {
        //     int cur = 1;
        //     for (int i = query[0]; i <= query[1]; i++) {
        //         cur = static_cast<long long>(cur) * bins[i] % mod;
        //     }
        //     ans.push_back(cur);
        // }
        // return ans;

        // II.
        vector<int> bins;
        int rep = 1;
        while (n) {
            if (n % 2 == 1) {
                bins.push_back(rep);
            }
            n /= 2;
            rep *= 2;
        }

        int m = bins.size();
        vector<vector<int>> results(m, vector<int>(m));
        for (int i = 0; i < m; i++) {
            int cur = 1;
            for (int j = i; j < m; j++) {
                cur = static_cast<long long>(cur) * bins[j] % mod;
                results[i][j] = cur;
            }
        }

        vector<int> ans;
        for (const auto& query: queries) {
            ans.push_back(results[query[0]][query[1]]);
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 15\n[[0,1],[2,2],[0,3]]\n
// @lcpr case=end

// @lcpr case=start
// 2\n[[0,0]]\n
// @lcpr case=end

 */

