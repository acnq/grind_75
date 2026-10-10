/*
 * @lc app=leetcode.cn id=1541 lang=cpp
 * @lcpr version=30204
 *
 * [1541] 平衡括号字符串的最少插入次数
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
    // I. 贪心
    // 我们直接用计数器代替栈，进行匹配都选距离当前最近的括号
    // 就可以确保平衡，我们维护左括号的个数，
    // 1. 遇到左括号后计数器++
    // 2. 遇到右括号之后，需要两步操作
    //    2.1. 和左括号进行匹配，如果左括号计数>0, 则可以匹配
    //         左括号计数-1, 否则没有匹配，插入数+1;
    //    2.2. 确保有两个连续右括号，判断后一个是否是')', 
    //          则是连续右括号，则下标+2, 否则就需要在当前位置插入
    //          插入次数+1， 下标+1；
    // 遍历结束后，需要检查左括号的个数是否为0，如果不为0，
    // 则说明还有剩下左括号没有匹配，每剩下一个，需要插入两个右括号
    // 插入次数 += 剩下的左括号个数*2
    // 显然上述插入是最少的，因为只有必要的情形下才插入
    // tc: O(n), sc: O(1)
    int minInsertions(string s) {
        int insertions = 0;
        int leftCnt = 0;
        int length = s.length();
        int idx = 0;

        while (idx < length) {
            char c = s[idx];
            if (c == '(') {
                leftCnt++;
                idx++;
            } else {
                if (leftCnt > 0) {
                    leftCnt--;
                } else {
                    insertions++;
                }
                if (idx < length - 1 && s[idx + 1] == ')') {
                    idx += 2;
                } else {
                    insertions++;
                    idx++;
                }
            }
        }
        insertions += leftCnt * 2;
        return insertions;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "(()))"\n
// @lcpr case=end

// @lcpr case=start
// "())"\n
// @lcpr case=end

// @lcpr case=start
// "))())("\n
// @lcpr case=end

// @lcpr case=start
// "(((((("\n
// @lcpr case=end

// @lcpr case=start
// ")))))))"\n
// @lcpr case=end

 */

