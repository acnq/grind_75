/*
 * @lc app=leetcode.cn id=2411 lang=cpp
 * @lcpr version=30204
 *
 * [2411] 按位或最大的最小子数组长度
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
    // I. 记录每个二进制位的最近出现位置
    // nums[i] \in [0, 10^9], 故最多包含31个二进制位
    // 对于这其中的第bit个位
    // 如若为1，那么与任何数位运算后还是1，不必考虑
    // 如果为0，我们只需要找到一个最小的j, s.t. j > i, 且 nums[j]的第bit位为1
    // 这样进行按位或操作时，就能达到最大值，当然，可能不存在这样的j
    // 按照下标顺序首先从大到小遍历nums，用数组pos记录每个二进制位最近一次出现1的位置（默认-1）
    // 遍历到nums[i]时，对bit位操作如下：
    // nums[i][bit] == 1: pos[bit] = i;
    // nums[i][bit] == 0 && pos[bit] != -1: 以i为左边界的子数组获得最大按位或值，右边界至少pos[bit]
    // tc: O(n * log C) (C: nums元素范围)， sc: O(logC) (pos长度)
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> pos(31, -1);
        vector<int> ans(n);

        for (int i = n - 1; i >= 0; i--) {
            int j = i;
            for (int bit = 0; bit < 31; bit++) {
                if(!(nums[i] & (1 << bit))) {
                    // nums[i][bit] == 0
                    if(pos[bit] != -1) {
                        j = max(j, pos[bit]);
                    }
                } else {
                    pos[bit] = i;
                }
            }
            ans[i] = j - i + 1;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,0,2,1,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n
// @lcpr case=end

 */

