/*
 * @lc app=leetcode.cn id=1018 lang=cpp
 * @lcpr version=30204
 *
 * [1018] 可被 5 整除的二进制前缀
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
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n = nums.size();
        vector<bool> answer(n, 0);
        long prefix = 0;
        for (int i = 0; i < n; i++) {
            prefix += nums[i];
            if (prefix % 5 == 0) {
                answer[i] = true;
            } else {
                answer[i] = false;
            }
            prefix = prefix * 2 % 5; // 保留余数即可，否则溢出
        }
        return answer;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [0,1,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,1]\n
// @lcpr case=end

 */

