/*
 * @lc app=leetcode.cn id=31 lang=cpp
 * @lcpr version=30204
 *
 * [31] 下一个排列
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
public:
    // I. 两遍扫描
    // 对于长度为n的排列a:
    // 1. 从后向前查找第一个顺序对(i, i + 1), s.t. a[i] < a[i + 1]
    //    这样被交换的数字即为a[i], a[i+1:n-1]必定是下降序列
    // 2. 在a[i+1:n-1)中从后向前查找第一个元素j, s.t. a[i] < a[j], 
    // 3. a[i]和a[j]交换，这样a[i+1:n)依旧是降序，这时我们还要反转[i+1, n)使其升序
    // 注意，如果步骤1找不到顺序对，说明当前序列已经最大，跳过步骤2执行步骤3，即可得到最小升序序列
    // 这其实就是C++标准库的next_permutation实现方案
    // tc: O(N); sc: O(1)
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
        while (i >= 0 && nums[i] >= nums[i + 1])
        {
            i--;
        }
        if (i >= 0)
        {
            int j = nums.size() - 1;
            while (j >= 0 && nums[i] >= nums[j])
            {
                j--;
            }
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [3,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,5]\n
// @lcpr case=end

 */

