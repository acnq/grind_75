/*
 * @lc app=leetcode.cn id=3741 lang=cpp
 * @lcpr version=30204
 *
 * [3741] 三个相等元素之间的最小距离 II
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
    // I. 遍历+哈希表
    // 三元组就是广义三角形的三边之和，不管顺序如何
    // 设最右侧的下标为k, 最左侧为i, 所求距离为2 * (k - i)
    // 我们维护前驱数组或者后继数组，快速求解当前元素的前驱及后继
    // 以后继为例，设next[i]记录nums[i]在nums中下个元素出现的位置
    // 倒序遍历nums，配合哈希表记录nums[i]即可求得
    // 遍历nums, 借助next数组，O(1)内求得与nums[i]相同的两个相邻后继，
    // 即可有答案
    // 
    // tc: O(n), sc: O(n)
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        vector<int> next(n, -1);
        unordered_map<int, int> occ; // nums[i] -> i
        int ans = n + 1;

        for (int i = n - 1; i >= 0; i--) {
            if (occ.count(nums[i])) {
                next[i] = occ[nums[i]];
            }
            occ[nums[i]] = i;
        }

        for(int i = 0; i < n; i++) {
            int secondPos = next[i];
            if (secondPos != -1) {
                int thirdPos = next[secondPos];
                if (thirdPos != -1) {
                    ans = min(ans, thirdPos - i);
                }
            }
        }

        return ans == n + 1 ? -1: ans * 2;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,1,1,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,2,3,2,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */

