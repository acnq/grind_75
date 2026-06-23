/*
 * @lc app=leetcode.cn id=3699 lang=cpp
 * @lcpr version=30204
 *
 * [3699] 锯齿形数组的总数 I
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

#include <numeric>
// @lcpr-template-end
// @lc code=start
class Solution {
    // I. DP + 前缀和优化
    // 设状态dp[i][dir][j]表示锯齿数组z长度为i+1,
    //  末尾两个元素排列方案为dir, 且z[i] = j时的方案总数
    // 其中l <= j <= r;
    // dir = 0: z[i - 1] > z[i];
    // dir = 1: z[i - 1] < z[i];
    // (按题意没有两个元素相等的情况)
    // 因为锯齿数组只关心相邻元素的排列，所以dp[i]仅取决于dp[i-1]
    // 又根据定义，dir=0的状态只能从dir=1的状态转移过来（排列必须交错）
    //             反之亦然
    // dp[i][0][j] 对应的前一个状态的末尾元素j'应当严格大于当前j
    // 同理dp[i][1][j] 对应的j'应该严格小于j
    // 所以有：
    // dp[i][0][j] = \sum_{k=j+1}^{m-1}dp[i-1][1][k]
    // dp[i][1][j] = \sum_{k=0}^{j-1}dp[i-1][0][k]
    // m = r - l + 1
    // 上面两个式子用前缀和sum[i][dir]（代表锯齿数组长度为i, 末尾排列为dir
    // 时，方案数的前缀和）简化，
    // sum[i][dir][j] = \sum_{k=0}^{j-1}dp[i][dir][k]
    // sum[i][dir][0] = 0;
    // dp[i][0][j] = sum[i - 1][1][m] - sum[i - 1][1][j + 1]
    // dp[i][1][j] = sum[i - 1][0][j]
    // dp[0]均为1
    // 实现时，dp第二维拆成dp0和dp1,，并滚动数组的j维度即可
    // tc: O(nm), sc: O(m)
public:
    int zigZagArrays(int n, int l, int r) {
        constexpr int MOD = 1'000'000'007;
        int m = r - l + 1;
        vector<int> dp0(m, 0);
        vector<int> dp1(m, 0);
        vector<int> sum0(m + 1, 0);
        vector<int> sum1(m + 1, 0);

        for (int i = 0; i < m; i++) {
            dp0[i] = dp1[i] = 1;
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                sum0[j + 1] = (sum0[j] + dp0[j]) % MOD;
                sum1[j + 1] = (sum1[j] + dp1[j]) % MOD;
            }

            for (int j = 0; j < m; j++) {
                dp0[j] = (sum1[m] - sum1[j + 1] + MOD) % MOD;
                dp1[j] = sum0[j];
            }
        }

        auto op = [](int acc, int x) {return (acc + x) % MOD;};
        auto ans0 = std::reduce(dp0.begin(), dp0.end(), 0, op);
        auto ans1 = std::reduce(dp1.begin(), dp1.end(), 0, op);

        return (ans0 + ans1) % MOD;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 3\n4\n5\n
// @lcpr case=end

// @lcpr case=start
// 3\n1\n3\n
// @lcpr case=end

 */

