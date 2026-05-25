/*
 * @lc app=leetcode.cn id=1340 lang=cpp
 * @lcpr version=30204
 *
 * [1340] 跳跃游戏 V
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
    // I. 记忆化搜索
    // dp[i]: 从i开始最多可访问的下标个数
    // dp[i] = max(dp[j]) + 1
    // j 有如下约束：
    // 0 <= j < arr.size: j在数组内
    // i - d <= j <= i + d: j和i的距离不超过d；
    // arr[j] 到 arr[i]的所有元素除了arr[i]之外都必须严格小于arr[i]
    // 所以对于i, 我们最多左右扫描d个元素即可
    // 我们发现DP传统无法解决，因为子结构在左右两侧都有，可以用记忆化搜索
    // 需要访问dp[j], 如果已经计算过直接返回，否则计算dp[j],然后状态转移
    // 我们发现，dp[i]不会搜索回dp[i](拓扑序无环)
    // 因为arr[j] 一定小于arr[i], 没搜索一层，高度一定更小，
    // 所以绝无可能出现环, 记忆化搜索必然在有有限时间内结束
    //
    // tc: O(Nd), sc: O(N);
private:
    vector<int> f;
public:
    void dfs(vector<int>& arr, int id, int d, int n) {
        if (f[id] != -1) {
            return;
        }
        f[id] = 1;
        // 两边搜索
        for (int i = id - 1; i >= 0 && id - i <= d && arr[id] > arr[i]; i--) {
            dfs(arr, i, d, n);
            f[id] = max(f[id], f[i] + 1);
        }
        for (int i = id + 1; i < n  && i - id <= d && arr[id] > arr[i]; i++) {
            dfs(arr, i, d, n);
            f[id] = max(f[id], f[i] + 1);
        }
    }

    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        f.resize(n, -1);
        for (int i = 0; i < n; i++) {
            dfs(arr, i, d, n);
        }
        return *max_element(f.begin(), f.end());
    }
};
// @lc code=end



/*
// @lcpr case=start
// [6,4,14,6,8,13,9,7,10,6,12]\n2\n
// @lcpr case=end

// @lcpr case=start
// [3,3,3,3,3]\n3\n
// @lcpr case=end

// @lcpr case=start
// [7,6,5,4,3,2,1]\n1\n
// @lcpr case=end

// @lcpr case=start
// [7,1,7,1,7,1]\n2\n
// @lcpr case=end

// @lcpr case=start
// [66]\n1\n
// @lcpr case=end

 */

