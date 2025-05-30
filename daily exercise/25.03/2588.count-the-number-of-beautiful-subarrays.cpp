/*
 * @lc app=leetcode.cn id=2588 lang=cpp
 * @lcpr version=30204
 *
 * [2588] 统计美丽子数组数目
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
    long long beautifulSubarrays(vector<int>& nums) {
        int mask = 0; // p[i]
        unordered_map<long, long> cnt; // cnt[x]
        cnt[0] = 1;
        long long ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int num = nums[i];
            mask = mask ^ num;
            ans += cnt[mask]; // 这里也是cnt[mask] (见T560), 
            // 因为 以 i 为结尾的美丽子数组的数目
            cnt[mask]++;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [4,3,1,2,4]\n
// @lcpr case=end

// @lcpr case=start
// [1,10,4]\n
// @lcpr case=end

 */

