/*
 * @lc app=leetcode.cn id=1470 lang=cpp
 * @lcpr version=30204
 *
 * [1470] 重新排列数组
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
    vector<int> shuffle(vector<int>& nums, int n) {
        // O.
        // vector<int> ans(2 * n, 0);
        // for(int i = 0; i < 2 * n; i++) {
        //     if (i < n) {
        //         ans[2 * i] = nums[i];
        //     }
        //     if (i >= n) {
        //         int tmp = i - n;
        //         ans[2 * tmp + 1] = nums[i];
        //     }
        // }
        // return ans;

        // I.
        vector<int> ans(2 * n);
        for (int i = 0; i < n; i++)
        {
            ans[2 * i] = nums[i];
            ans[2 * i + 1] = nums[i + n];
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,5,1,3,4,7]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,4,3,2,1]\n4\n
// @lcpr case=end

// @lcpr case=start
// [1,1,2,2]\n2\n
// @lcpr case=end

 */

