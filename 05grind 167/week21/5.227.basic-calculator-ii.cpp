/*
 * @lc app=leetcode.cn id=227 lang=cpp
 * @lcpr version=30204
 *
 * [227] 基本计算器 II
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

#include <numeric> // numeric
// @lcpr-template-end
// @lc code=start
class Solution {
    // I. 栈
    // 保存乘除计算后的整数的值。对于加减号后的数字，将其直接压入栈中；
    // 乘除号后的数字, 直接和栈顶计算，替换栈顶元素为计算后的结果。
    // 遍历到运算符或者字符串末尾，即可认为是遍历到了数字末尾，处理数字
    // 遍历完字符串s后，栈中元素做加法即可。 
public:
    int calculate(string s) {
        vector<int> stk;
        char preSign = '+';
        int num = 0;
        int n = s.length();
        for (int i = 0; i < n; i++)
        {
            if (isdigit(s[i]))
            {
                num = num * 10 + int(s[i] - '0');
            }
            if (!isdigit(s[i]) && s[i] != ' ' || i == n - 1)
            {
                switch (preSign)
                {
                case '+':
                    stk.push_back(num);
                    break;
                case '-':
                    stk.push_back(-num);
                    break;
                case '*':
                    stk.back() *= num;
                    break;
                default:
                    stk.back() /= num;
                }
                preSign = s[i];
                num = 0;
            }
        }
        return accumulate(stk.begin(), stk.end(), 0);
    }
};
// @lc code=end



/*
// @lcpr case=start
// "3+2*2"\n
// @lcpr case=end

// @lcpr case=start
// " 3/2 "\n
// @lcpr case=end

// @lcpr case=start
// " 3+5 / 2 "\n
// @lcpr case=end

 */

