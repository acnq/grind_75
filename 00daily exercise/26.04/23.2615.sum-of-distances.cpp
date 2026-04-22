// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=2615 lang=cpp
 * @lcpr version=30204
 *
 * [2615] 等值距离和
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
    // I. 分组 + 前缀和
    // 首先我们将所有nums[i]相同的i分到同一组（哈希表）中
    // 对于某组下标i_0 < i_1 < ...... < i_{m-1}考虑如何快速计算每个i_k对应答案
    // res[i_k] = \sum_{p = 0} ^{m - 1}|i_k - i_p|
    // 因为显然下标是有序的，我们可以拆分
    // res[i_k] = \sum_{p=0}^{k-1}(i_k - i_p) + \sum_{p=i+1}^{m-1}(i_k - i_p)
    // 令S = \sum_{p=0}^{m-1}i_p (组内所有下标和)
    // P_k = \sum_{p=0}^{k-1}i_p (前缀和)
    // 左边：
    // \sum_{p=0}^{k-1}(i_k - i_p) = \sum_{p=0}^{k-1}i_k - \sum_{p=0}^{k-1}i_p = k * i_k - P_k
    // 右边：
    // \sum_{p=i+1}^{m-1}(i_k - i_p) = (S - P_k - a_k) - (m - k - 1) * i_k
    // 合并有
    // res[i_k] = S - 2P_k + i_k * (2k - m)
    // 这样通过维护P_k即可在O(m)内计算组内答案，所有组大小和为n, 总用时O(n)
    //
    // tc: O(n), sc: O(n)
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> groups;
        for (int i = 0; i < n; i++) {
            groups[nums[i]].push_back(i);
        }
        vector<long long> res(n);
        for (const auto& p: groups) {
            const auto& group = p.second;
            long long total = accumulate(group.begin(), group.end(), 0LL);
            long long prefix = 0;
            for (int i = 0; i < group.size(); i++) {
                res[group[i]] = total - prefix * 2 + group[i] * (2 * i - group.size());
                prefix += group[i];
            }
        }
        return res;
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=distance
// paramTypes= ["number[]"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// [1,3,1,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [0,5,3]\n
// @lcpr case=end

 */

