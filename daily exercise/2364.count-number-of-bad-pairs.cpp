/*
 * @lc app=leetcode.cn id=2364 lang=cpp
 * @lcpr version=30204
 *
 * [2364] 统计坏数对的数目
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
    // I 暴力枚举
    // 会超时
    // II. 公式变形+哈希
    // j - i != nums[j] - nums[i]
    // => j - nums[j] != i - nums[i]
    // 我们使用哈希结构保存不同的k - nums[k]的个数
    // 并且在遍历k的时候，计算与当前k - nums[k]不同的个数
    // 将结果累加导答案中即可
public:
    long long countBadPairs(vector<int>& nums) {
        // I.
        // int n = nums.size();
        // long long cnt = 0;
        // for(int i = 0; i < n; i++) {
        //     for(int j = i + 1; j < n; j++) {
        //         if(j - i != nums[j] - nums[i]) {
        //             cnt++;
        //         }
        //     }
        // }
        // return cnt;

        // II.
        using ll = long long;
        ll res = 0;
        unordered_map<int, int> mp;
        for (int k = 0; k < nums.size(); k++)
        {
            res += k - mp[k - nums[k]];
            mp[k - nums[k]]++;
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [4,1,3,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5]\n
// @lcpr case=end

 */

