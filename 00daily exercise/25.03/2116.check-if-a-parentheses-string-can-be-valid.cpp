/*
 * @lc app=leetcode.cn id=2116 lang=cpp
 * @lcpr version=30204
 *
 * [2116] 判断一个括号字符串是否有效
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
    // I. 数学
    // 考虑字符串的"分数"： 初值为0，遍历，遇到(, +1, 遇到), -1;
    // 有效括号 <=> 字符串分数为0，且任意前缀分数>=0
    // 给出“有效前缀”的定义：括号字符串某个前缀字符串，
    // 她本身及其所有前缀分数均>=0, 称这个前缀为有效前缀
    // 对字符串s, 定义最大分数数组mx和最小有效分数数组
    // mx[i + 1]: s[0:i]可以达到的最大分数
    // mn[i + 1]: s[0:i]可以达到的最小分数，以及作为有效前缀所需的最小分数二者的较大值
    // "作为有效前缀所需的最小分数"取值为0（若i为偶数），或1（i为奇数）, i.e. (i + 1) mod 2
    // mx[0] = mn[0] = 0
    // algo:
    //  locked[i] = 1: s[i]无法更改，mx[i + 1] = mx[i] + diff,
    //                  diff为s[i]的分数， mn[i + 1] = max(mn[i] + diff, (i + 1)mod2)
    //  locked[i] = 0: s[i]可以更改，mx[i + 1] = mx[i] + 1
    //                  mn[i + 1] = max(mn[i] - 1, (i + 1)mod2)
    // 一旦mx[i] < mn[i], s[0:i]便无法变换为有效前缀
    // (因为mx[i] < mn[i] => s[0:i]可达的最大值 < max(s[0:i]可达的最小值，s[0:i]作为有效前缀所需最小分数)，
    // 而s[0:i]可达最大值总>=s[0:i]可达最小值，
    // 所以上式成立=> s[0:i]可达的最大值<s[0:i]作为有效前缀所需的最小分数
    // 故 s无法变为有效串), 立刻返回false
    // 遍历完成后，还要确定s是否可以通过变换使得分数为0，
    // <=> mn[n]=0是否成立，是返回true，否则返回false

    // mx, mn之和紧邻的元素有关，故可以化为int而非数组
    // mx = mn = 0
    // locked[i] = 1: mx = mx + diff, mn = max(mn + diff, (i + 1)mod2)
    // locked[i] = 0: mx = mx + 1, mn = max(mn - 1, (i + 1)mod2);
    //
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();
        int mx = 0; // s[0:i]可以达到的最大分数
        int mn = 0; // s[0:i]可以达到的最小分数和 最小有效前缀对应分数 的较大值
        for (int i = 0; i < n; i++)
        {
            if (locked[i] == '1')
            {
                int diff;
                if (s[i] == '(')
                {
                    diff = 1;
                } else {
                    diff = -1;
                }
                mx += diff;
                mn = max(mn + diff, (i + 1) % 2);
            } else {
                mx++;
                mn = max(mn - 1, (i + 1) % 2);
            }
            if (mx < mn)
            {
                return false;
            }
        }
        
        return mn == 0;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "))()))"\n"010100"\n
// @lcpr case=end

// @lcpr case=start
// "()()"\n"0000"\n
// @lcpr case=end

// @lcpr case=start
// ")"\n"0"\n
// @lcpr case=end

// @lcpr case=start
// "(((())(((())"\n"111111010111"\n
// @lcpr case=end

 */

