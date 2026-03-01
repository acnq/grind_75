/*
 * @lc app=leetcode.cn id=1689 lang=cpp
 * @lcpr version=30204
 *
 * [1689] 十-二进制数的最少数目
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
    // I. 遍历
    // 对于n每一位上的值x, 只要最多x个0-1数即可，所以遍历即可
    // tc: O(len(n)), sc: O(1)
public:
    int minPartitions(string n) {
        int ans = 0;
        for (char digit: n) {
            int x = digit - '0';
            ans = max(x, ans);
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "32"\n
// @lcpr case=end

// @lcpr case=start
// "82734"\n
// @lcpr case=end

// @lcpr case=start
// "27346209830709182346"\n
// @lcpr case=end

 */

