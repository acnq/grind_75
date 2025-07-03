/*
 * @lc app=leetcode.cn id=16 lang=cpp
 * @lcpr version=30204
 *
 * [16] 最接近的三数之和
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
    // I. 排序 + 双指针
    // 如果枚举三元组tc会达到O(N^3), 容易超时
    // 考虑枚举第一个元素a, 剩下两个元素b,c希望他们的和最接近target - a,
    // 当然，如果元素没有规律可言，还是要两重枚举，因此，我们首先要对数组升序排列
    // 首先枚举a = arr[i], 然后在[i + 1, n)范围内枚举b,c
    // 这两个元素我们用双指针的方案，p_b/p_c分别指向b/c; 分别初始化为i+1, n-1(左右边界)
    // 如果a + b + c >= target, p_c左移，<则右移
    // 有几个小优化：=target的时候，直接返回target作为答案，因为不可能有比这个更接近的值了
    // 其次，指针移动跳过元素时，可以跳过所有相同元素。
    // tc: O(N^2), sc: O(logN)(排序的栈空间)
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int best = 1e7;

        // 根据差值的绝对值更新
        auto update = [&](int cur) {
            if (abs(cur - target) < abs(best - target))
            {
                best = cur;
            }
        };

        // 枚举a
        for (int i = 0; i < n; i++)
        {
            // 保证和上一次枚举元素不同
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            // 使用双指针枚举b/c;
            int j = i + 1, k = n - 1;
            while (j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                // 和为target直接返回
                if (sum == target)
                {
                    return target;
                }
                update(sum);
                if (sum > target)
                {
                    // 移动c对应的指针
                    int k0 = k - 1;
                    // 到下一个不相等的元素
                    while (j < k0 && nums[k0] == nums[k])
                    {
                        k0--;
                    }
                    k = k0;
                } else {
                    // 和小于target, 移动b对应的指针
                    int j0 = j + 1;
                    // 到下一个不相等的元素
                    while (j0 < k && nums[j0] == nums[j])
                    {
                        j0++;
                    }
                    j = j0;
                }
            }
        }
        return best;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [-1,2,1,-4]\n1\n
// @lcpr case=end

// @lcpr case=start
// [0,0,0]\n1\n
// @lcpr case=end

 */

