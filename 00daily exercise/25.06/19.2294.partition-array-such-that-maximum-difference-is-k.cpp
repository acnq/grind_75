/*
 * @lc app=leetcode.cn id=2294 lang=cpp
 * @lcpr version=30204
 *
 * [2294] 划分数组使最大差为 K
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
    // I. 排序 + 贪心
    // 简单来说，容易想到贪心思路，即让每一组
    // 中的数字最多，由于顺序不影响分组，所以先排序。
    // 遍历数组nums, 新建分组，记录当前最小值rec, 
    // 记录当前元素nums[i], 如若nums[i] - rec > k, 则需要新建分组
    // tc: O(n logn); 
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = 1;
        int rec = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] - rec > k) {
                ans++;
                rec = nums[i];
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,6,1,2,5]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n1\n
// @lcpr case=end

// @lcpr case=start
// [2,2,4,5]\n0\n
// @lcpr case=end

 */

