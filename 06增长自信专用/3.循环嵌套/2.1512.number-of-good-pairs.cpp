/*
 * @lc app=leetcode.cn id=1512 lang=cpp
 * @lcpr version=30204
 *
 * [1512] 好数对的数目
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
    int numIdenticalPairs(vector<int>& nums) {
        int res = 0;
        for(int i = 0; i < nums.size(); i++) {
            for(int j = i + 1; j < nums.size(); j++) {
                if(nums[i] == nums[j]) {
                    res++;
                }
            }
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,1,1,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,1,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

 */

