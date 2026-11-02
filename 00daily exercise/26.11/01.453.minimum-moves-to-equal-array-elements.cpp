/*
 * @lc app=leetcode.cn id=453 lang=cpp
 * @lcpr version=30204
 *
 * [453] 最小操作次数使数组元素相等
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
    // I. 数学
    // 我们因为只需要求出操作此书，所以不需要考虑绝对元素大小
    // 只考虑相对变化即可：使得n-1个元素+1, 等价于使得一个元素少1
    // 我们因而只需要计算所有元素减少到最小元素的值所需的操作即可
    // 计算公式 \sum_{i=0}^{n-1}nums[i] - min(nums) * n
    // 累加\sum_{i=0}^{n-1}(nums[i] - min(nums))即可
    // tc: O(n), sc: O(1)
public:
    int minMoves(vector<int>& nums) {
        int minNum = *min_element(nums.begin(), nums.end());
        int res = 0;
        for (int num : nums) {
            res += num - minNum;
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,1]\n
// @lcpr case=end

 */

