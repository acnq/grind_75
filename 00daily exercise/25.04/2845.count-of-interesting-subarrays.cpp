/*
 * @lc app=leetcode.cn id=2845 lang=cpp
 * @lcpr version=30204
 *
 * [2845] 统计趣味子数组的数目
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
    // I. 前缀和
    // 因为要考虑子区间内某特定元素出现的次数
    // 所以我们考虑前缀和 sum[i]: nums[0:i]满足 x mod modulo == k 的元素数目
    // nums[l:r]中的数目即为 sum[r] - sum[l - 1]
    // cnt % modulo == k => 
    // (sum[r] - sum[l - 1]) mod modulo == k
    // i.e. (sum[r] - k + modulo) mod modulo = sum[l - 1] mod modulo
    // 这样一来，对于索引r, 寻找索引l满足上式即可得到一个趣味数组nums[l:r]
    // 用哈希表cnt存储当前已经遍历的前缀中，sum[i] mod modulo 的数目，
    // 每次从小到大枚举r, 快速找到以r为右边界的趣味子数组的数目
    // 这样就找到满足条件的左边界l的数目
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n = nums.size();
        unordered_map<int, int> cnt;
        long long res = 0;
        int prefix = 0;
        cnt[0] = 1;
        for (int i = 0; i < n; i++)
        {
            prefix += nums[i] % modulo == k;
            res += cnt[(prefix - k + modulo) % modulo];
            cnt[prefix % modulo]++;
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,2,4]\n2\n1\n
// @lcpr case=end

// @lcpr case=start
// [3,1,9,6]\n3\n0\n
// @lcpr case=end

 */

