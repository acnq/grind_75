/*
 * @lc app=leetcode.cn id=1498 lang=cpp
 * @lcpr version=30204
 *
 * [1498] 满足条件的子序列数目
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
    // I. 贡献计算
    // 注意两个点：1. 子序列不需要连续；2. 本题只关心子序列的最大最小值，不关心顺序
    // 固定子序列的最小值v_min, 则这个子序列的最大值v_max要满足v_max <= target - v_min
    // 这样有2v_min <= target => v_min \leq \floor{target / 2}
    // 呈上，固定v_min, 求出v_max的所有可能值，他需要在[v_min, target - v_min]之间
    // 满足条件的v_min要通过枚举找到，而找到之后，要确定区间[v_min, target - v_min]中数的个数x
    // 但注意到v_min必取，所以这里的贡献应该是2^{x-1}
    // 我们可以首先预计算出所有2^i mod (10^9 + 7)的情况，然后排序原序列
    // 枚举v_min, 对每个v_min二分出最大的v_max, 二者差的绝对值设为x, 则当前的贡献就是2^x
public:
    static constexpr int P = int(1E9) + 7;
    static constexpr int MAX_N = int(1E5) + 5;
    int f[MAX_N];

    void pretreat() {
        // 均摊下来，预处理会比每次快速幂快
        f[0] = 1;
        for (int i = 1; i < MAX_N; i++)
        {
            f[i] = (long long)f[i - 1] * 2 % P;
        }
    }

    int numSubseq(vector<int>& nums, int target) {
        pretreat();
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (int i = 0; i < nums.size() && nums[i] * 2 <= target; i++)
        {
            int maxVal = target - nums[i]; // nums[i]就是枚举的v_min
            int pos = upper_bound(nums.begin(), nums.end(), maxVal) - nums.begin() - 1;
            // 注意看上一行取最大值位置的语法
            int contrib = (pos >= i) ? f[pos - i] : 0;
            ans = (ans + contrib) % P;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,5,6,7]\n9\n
// @lcpr case=end

// @lcpr case=start
// [3,3,6,8]\n10\n
// @lcpr case=end

// @lcpr case=start
// [2,3,3,4,6,7]\n12\n
// @lcpr case=end

 */

