/*
 * @lc app=leetcode.cn id=7 lang=cpp
 * @lcpr version=30204
 *
 * [7] 整数反转
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
    // 要是没有辅助栈或是数组，我们使用如下数学方法：
    // 弹出x末尾数字digit：digit = x % 10; x /= 10. 
    // 数字digit加入rev末尾：rev = rev * 10 + digit
    // 注意题目要判断反转后的数是否超过了32位有负号整数的范围[-2^{31}, 2^{31} - 1]
    // 因此我们需要再推入数字前，判断是否满足-2^{31} <= 10 * rev + digit <= 2^{31} - 1
    // 因为我们无法使用64位整数，所以我们要思考其他方案
    // x > 0， 记INT_MAX = 2^{31} - 1 = 2147483647;
    // INT_MAX = \floor{INT_MAX / 10} * 10 + (INT_MAX mod 10)
    //         = \floor{INT_MAX / 10} * 10 + 7
    // 故有： rev * 10 + digit <= INT_MAX => rev * 10 + digit <= \floor{INT_MAX / 10} * 10 + 7
    // 移项有：(rev - \floor{INT_MAX / 10}) * 10 <= 7 - digit
    // 所以比较rev和\floor{INT_MAX}, >则不等式必然不成立，=则仅当digit <= 7 时上式成立，
    // <则digit <= 9则不等式成立, 而这显然，所以不等式也必然成立
    // 注意到当=时若还能推入数字，则x与INT_MAX位数相同，且digit为x最高位，
    // 因为x<=INT_MAX, 所以digit也不会超过INT_MAX最高位，digit <= 2, 以此取=,不等式依旧必然成立
    // 所以条件转化为，rev <= \floor{INT_MAX / 10}则不等式成立
    // 综上：
    // -2^{31} <= rev * 10 + digit <= 2^{31} - 1
    // 等价于 \ceil{-2^{31} / 10} <= rev <= \floor{(2^{31} - 1) / 10}
    // 不在范围内，按题意，返回0
public:
    int reverse(int x) {
        int rev = 0;
        while (x != 0)
        {
            if (rev < INT_MIN / 10 || rev > INT_MAX / 10)
            {
                return 0;
            }
            int digit = x % 10;
            x /= 10;
            rev = rev * 10 + digit;
        }
        return rev;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 123\n
// @lcpr case=end

// @lcpr case=start
// -123\n
// @lcpr case=end

// @lcpr case=start
// 120\n
// @lcpr case=end

// @lcpr case=start
// 0\n
// @lcpr case=end

 */

