/*
 * @lc app=leetcode.cn id=921 lang=cpp
 * @lcpr version=30204
 *
 * [921] 使括号有效的最少添加
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
    // I. 贪心
    // 我们不使用栈，而是维护左括号个数和添加个数两个计数器
    // 遇到左括号，左括号个数+1；
    // 遇到右括号，贪心的和左括号匹配：
    // 1. 如果左括号计数>0, 左括号计数-1即可
    // 2. 如果左括号计数=0，则没有左括号可匹配，添加一个左括号
    //    添加计数+1即可
    // 遍历结束后查看左括号计数是否为0，否则需要添加右括号，即：
    // 添加计数要加上剩下的左括号计数
    // 显然这种情况是添加括号最少的
    // tc: O(n), sc: O(1)
public:
    int minAddToMakeValid(string s) {
        int ans = 0;
        int leftCnt = 0;
        for (auto& c: s) {
            if (c == '(') {
                leftCnt++;
            } else {
                if (leftCnt > 0) {
                    leftCnt--;
                } else {
                    ans++;
                }
            }
        }
        ans += leftCnt;
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "())"\n
// @lcpr case=end

// @lcpr case=start
// "((("\n
// @lcpr case=end

 */

