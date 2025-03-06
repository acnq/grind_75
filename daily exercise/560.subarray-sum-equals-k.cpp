// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=560 lang=cpp
 * @lcpr version=30204
 *
 * [560] 和为 K 的子数组
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
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        cnt[0] = 1;
        int sum = 0, res = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int num = nums[i];
            sum += num;
            if (cnt.find(sum - k) != cnt.end())
            {
                res += cnt[sum - k]; // 这里必须是sum - k 
                // 而不是 res++, 因为和为sum - k的子序列已经有了cnt[sum - k]种
                // 而不是只有一种
            }
            cnt[sum]++;
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1]\n0\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n3\n
// @lcpr case=end

 */

