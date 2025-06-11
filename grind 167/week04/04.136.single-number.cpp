/*
 * @lc app=leetcode.cn id=136 lang=cpp
 * @lcpr version=30204
 *
 * [136] 只出现一次的数字
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
    // 吃完了一顿饭之后都完全没有思路
    // 主要常数空间复杂度太难了
    // 瞄了眼提示，发现确实能用^嘬
    // 感觉确实不太懂这些技巧性的题目
    // 第一道没法自己做出来的简单题
public:
    int singleNumber(vector<int>& nums) {
        int ret = 0;
        for(int num: nums) {
            ret ^= num;
        }
        return ret;
    }
    // 看评论感觉这道题数电的同学反而反应更快，确实是基础知识不一样导致思路不一样
};
// @lc code=end



/*
// @lcpr case=start
// [2,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [4,1,2,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */

