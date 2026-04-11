/*
 * @lc app=leetcode.cn id=3655 lang=cpp
 * @lcpr version=30204
 *
 * [3655] 区间乘法查询后的异或 II
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
    // 如果每个查询复杂度为n, q次查询总计O(nq), 会超时
    // 如果k >= \sqrt{n}, 最多查询n / k <= \sqrt{n}, tc: O(q\sqrt{n})
    // 如果k < \sqrt{n}, 则复杂度过高
    // 我们把查询按k值分组，相同k一起处理，对于同k的查询[l,r,v]
    // 我们实际上是在l, l+k, l+2k上做区间乘法
    // 我们构造差分数组dif, 初始化为1，我们找到最后一个需要处理的元素的下一个位置R
    // dif[l] = dif[l] * v, dif[R] = dif[R] * v^(-1)
    // （由费马小定理，求解v^(M-2)即可，M = 10^9+7）
    // 这样单次查询的tc: O(logM)
    // 最后遍历数组dif[i] := dif[i] * dif[i - k], 得到累乘量
    // 然后更新到原数组，tc=O(n), 总体O(n\sqrt{n} + q\logM)
    // R: 最后下标为l + \floor{(r - l) / k} * k,
    // R  = l + \floor{(r - l) / k + 1} * k, 最大为n + k
    //
    // tc: O((n + q)\sqrt{n} + q\logM); sc: O(\sqrt{n} + q)
public:
    const int mod = 1e9 + 7;
    using ll = long long;
    int pow(ll x, ll y) { // 快速幂
        ll res = 1;
        for (; y; y >>= 1) {
            if (y & 1) {
                res = res * x % mod;
            }
            x = x * x % mod;
        }
        return res;
    }

    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int T = sqrt(n);
        vector<vector<vector<int>>> groups(T);
        for (auto& q: queries) {
            int l = q[0], r = q[1], k = q[2], v = q[3];
            if (k < T) {
                groups[k].push_back({l, r, v});
            } else {
                for (int i = l; i <= r; i += k) {
                    nums[i] = 1ll * nums[i] * v % mod;
                }
            }
        }

        vector<ll> dif(n + T);
        for (int k = 1; k < T; k++) {
            if (groups[k].empty()) {
                continue;
            }
            fill(dif.begin(), dif.end(), 1);
            for (auto& q: groups[k]) {
                int l = q[0], r = q[1], v = q[2];
                dif[l] = dif[l] * v % mod;
                int R = ((r - l) / k + 1) * k + l;
                dif[R] = dif[R] * pow(v, mod - 2) % mod;
            }

            for (int i = k; i < n; i++) {
                dif[i] = dif[i] * dif[i - k] % mod;
            }
            for (int i = 0; i < n; i++) {
                nums[i] = 1ll * nums[i] * dif[i] % mod;
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            res = res ^ nums[i];
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,1,1]\n[[0,2,1,4]]\n
// @lcpr case=end

// @lcpr case=start
// [2,3,1,5,4]\n[[1,4,2,3],[0,2,1,2]]\n
// @lcpr case=end

 */

