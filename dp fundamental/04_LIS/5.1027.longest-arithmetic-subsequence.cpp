/*
 * @lc app=leetcode.cn id=1027 lang=cpp
 * @lcpr version=30204
 *
 * [1027] 最长等差数列
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
    // las[v] = (len, dif): 以v结尾的最长等差子序列的长度和公差
    // 想了想这样如果v对应两个等长不等公差的等差序列就会很麻烦，直接看答案了

    // I. DP
    // f[i][d][num]: nums下标<=i的元素，构造公差为d的等差序列，并且最后一个元素为num时
    // 等差数列长度的最大值。考虑当前的第i个元素是否作为末项加入等差数列
    // 1. 不加入，那么f[i][d][num] = f[i - 1][d][num];
    // 2. 加入：2.1 已知的等差列长度至少为2，末项nums[i] => 倒数第二项nums[i] - d
    //              f[i][d][nums[i]] = f[i - 1][d][nums[i] - d] + 1
    //              当然nums[i] - d要落在nums最大最小值之间，
    //          2.2. nums[i]单独形成等差数列： f[i][d][nums[i]] = 1
    // ans = max_{i,j}f[n - 1][i][j], n = nums.size()
    // d \in [-diff, diff], diff = *max_elem(nums) - *min_elem(nums)

    // 优化：
    // f[i][d][nums[i]]只会依赖于f[i - 1][d][nums[i]], 可以省去一维
    // f[d][nums[i]] = f[d][nums[i] - d] + 1 or f[d][nums[i]] = 1
    // 同样，f[d][...]也只会从f[d][...]转移而来，我们可以继续省去，外围用d枚举
    // 内部直接选择f[nums[i]] = f[nums[i] - d] + 1 or 1
    // ans 至少为1，所以我们只需要在以f[nums[i] - d] + 1更新时，更新答案
    // 最后还是要枚举d, 感觉这样也确实，很难直接从序列中导出公差

public:
    int longestArithSeqLength(vector<int>& nums) {
        auto [minit, maxit] = minmax_element(nums.begin(), nums.end());
        int diff = *maxit - *minit;
        int ans = 1;
        for (int d = -diff; d <= diff; d++)
        {
            vector<int> f(*maxit + 1, -1);
            for(int num: nums)
            {
                if (int prev = num - d; prev >= *minit && prev <= *maxit && f[prev] != -1)
                {
                    f[num] = max(f[num], f[prev] + 1);
                    ans = max(ans, f[num]);
                }
                f[num] = max(f[num], 1);
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,6,9,12]\n
// @lcpr case=end

// @lcpr case=start
// [9,4,7,2,10]\n
// @lcpr case=end

// @lcpr case=start
// [20,1,15,3,10,5,8]\n
// @lcpr case=end

 */

