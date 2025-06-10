/*
 * @lc app=leetcode.cn id=268 lang=cpp
 * @lcpr version=30204
 *
 * [268] 丢失的数字
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
    // 这次看到了线型复杂度是进阶的，
    // 直接暴力搜索也可以
    // 突然想到直接数学加减法即可

    // I. 排序
    // 确实数字式第一个和元素不相等的下标，没有则k=n
    // 不过有一步排序, O(n logn)

    // II. 哈希表
    // 因为哈希查找是O(1), 所以能降到O(1)

    // III. 位运算
    // 我们给这个数组后面接上从0到n的每个整数
    // 然后全部异或起来，则由于丢失的数字只出现一次，异或的结果就是答案
    // 也是一个tc: O(n), sc: O(1)的算法

    // IV. 数学
    // 如上

public:
    int missingNumber(vector<int>& nums) {
        // int n = nums.size();
        // int idea_sum = (1 + n) * n / 2;
        // int sum = 0;
        // for(int i = 0; i < n; i++) {
        //     sum += nums[i];
        // }
        // return idea_sum - sum;
        // 6min, 还得是数学

        // sort(nums.begin(), nums.end());
        // int n = nums.size();
        // for(int i = 0; i < n; i++) {
        //     if(nums[i] != i) {
        //         return i;
        //     }
        // }
        // return n;

        // unordered_set<int> seen;
        // int n = nums.size();
        // for(int i = 0; i < n; i++) {
        //     seen.insert(nums[i]);
        // }
        // int missing = -1;
        // for(int i = 0; i <= n; i++) {
        //     if(seen.count(i) == 0) {
        //         missing = i;
        //         break;
        //     }
        // }
        // return missing;

        int res = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            res ^= nums[i];
        }
        for(int i = 0; i <= n; i++) {
            res ^= i;
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,0,1]\n
// @lcpr case=end

// @lcpr case=start
// [0,1]\n
// @lcpr case=end

// @lcpr case=start
// [9,6,4,2,3,5,7,0,1]\n
// @lcpr case=end

 */

