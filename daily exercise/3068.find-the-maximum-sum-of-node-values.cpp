/*
 * @lc app=leetcode.cn id=3068 lang=cpp
 * @lcpr version=30204
 *
 * [3068] 最大节点价值之和
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
    // 这是困难题，难在想到方法.
    // I. 贪心
    // 我们有 a 异或 k 奇数次 = a \cirplus k; a 异或 k 偶数次 = a
    // 所以，如果对一条路径上的每条边都进行了操作，只相当于操作了首位，因为剩下的所有点都进行了两次异或
    // 因而，预期考虑无限可能的路径，不如说，允许的操作是每次对树上任意两点进行异或k的操作，以达到所有节点权重和最大的目的
    // 贪心法： res = \sum_{i=0}^{n - 1}nums[i], diff[i] = (nums[i] \cirplus k) - nums[i]
    // 贪diff, 每次取最大的两个diff，直到遇到负数（这个时候如果是一负一正，还要看和是否为正），
    // 排序diff, 每次取两个作和, 正则加到res上，否则跳出
    // 因为有排序， O(n log n)
    // 注意这样分解问题之后，edges参数已经没有意义了。

    // II. 树形动态规划
    // f[u][0]: u为根的子树，u尚未异或k时，不包括u本身的最大和
    // f[u][1]: ...          异或k时，... 
    // 枚举u的子节点v, 讨论是否操作这两个数字(u, v)
    // 不操作u, v, 子树v的最大值: r_0 = max(f[v][0] + nums[v], f[v][1] + (nums[v] \circplus k))
    // 操作 ..., ...           : r_1 = max(f[v][1] + nums[v], f[v][0] + (nums[v] \circplus k))
    // 转移方程：
    // f[u][0] = max(f[u][0] + r_0, f[u][1] + r_1)
    // f[u][1] = max(f[u][1] + r_0, f[u][0] + r_1)
    // 每考虑一个叶子结点都要如此更新f[u][0:1]。
    // 最后返回时在调用一下r_0, r_1的算法加上nums[u]

    // II. 状态机动态规划
    // 参考I. 问题转化为从nums中选择偶数个数，异或上k后，令总和最大
    // 这次不用贪心，用状态机，
    // f[i][0]: nums[0:i]中偶数个数异或k后的最大元素和
    // f[i][1]: nums[0:i]中奇数个数异或k后的最大元素和
    // f[i + 1][0] = max(f[i][0] + nums[i], f[i][1] + (nums[i] \circplus k))
    // f[i + 1][1] = max(f[i][1] + nums[i], f[i][0] + (nums[i] \circplus k))
    // f[0][0] = 0, f[0][1] = -\infin, res = f[n][0]
    // 用滚动数组压缩第一维，则复杂度下降为O(n), 快于方法1
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        // I.
        // int n = nums.size();
        // long long res = 0;
        // for(int num: nums) {
        //     res += num;
        // }

        // vector<long long> diff(n, 0);
        // for(int i = 0; i < n; i++) {
        //     diff[i] = (nums[i] ^ k) - nums[i];
        // }    

        // sort(diff.begin(), diff.end());
        // reverse(diff.begin(), diff.end());

        // for(int i = 0; i < n - 1; i+=2) {
        //     long long tmp = diff[i] + diff[i + 1];
        //     if(tmp > 0) {
        //         res += tmp;
        //     } else {
        //         break;
        //     }
        // }
        
        // return res;
        
        // II. 
        // using ll = long long;
        // int n = nums.size();
        // vector<vector<int>> g(n);
        // for(auto edge: edges) {
        //     int u = edge[0], v = edge[1];
        //     g[u].push_back(v);
        //     g[v].push_back(u);
        // }

        // function<pair<ll, ll>(int, int)> dfs = [&](int u, int pa) -> pair<ll, ll>{
        //     ll f0 = 0, f1 = LLONG_MIN;
        //     for(auto &v: g[u]) {
        //         if(v != pa) {
        //             auto [r0, r1] = dfs(v, u);
        //             ll t = max(f1 + r0, f0 + r1); 
        //             f0 = max(f0 + r0, f1 + r1);
        //             f1 = t;
        //         }
        //     }
        //     return {max(f0 + nums[u], f1 + (nums[u] ^ k)), max(f1 + nums[u], f0 + (nums[u] ^ k))};
        // };

        // return dfs(0, -1).first;
        using ll = long long;
        int n = nums.size();
        vector<ll> f = {0, LLONG_MIN};
        for(int num: nums) {
            ll tmp = max(f[0] + num, f[1] + (num ^ k));
            f[1] = max(f[1] + num, f[0] + (num ^ k));
            f[0] = tmp;
        }
        return f[0];
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,1]\n3\n[[0,1],[0,2]]\n
// @lcpr case=end

// @lcpr case=start
// [2,3]\n7\n[[0,1]]\n
// @lcpr case=end

// @lcpr case=start
// [7,7,7,7,7,7]\n3\n[[0,1],[0,2],[0,3],[0,4],[0,5]]\n
// @lcpr case=end

 */

