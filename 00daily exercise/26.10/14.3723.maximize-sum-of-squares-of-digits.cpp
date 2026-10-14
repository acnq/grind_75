/*
 * @lc app=leetcode.cn id=3723 lang=cpp
 * @lcpr version=30204
 *
 * [3723] 数位平方和的最大值
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
    // 贪心
    // num位的整数数位和最大9 * num, sum > 9 * num, 则不存在
    // 这样的好整数，直接返回空
    // 考虑到平方函数是凸的，我们知道在数位总和固定时，数值集中到
    // 尽量少的数位上最好，（e.g. 9^2 > 4^2 + 5^2), 
    // 我们直接在高位上填充9，总共填充\floor{sum / 9}个，
    // 如果有 sum mod 9 > 0, 再天众一个sum mod 9 即可
    // 如果还有剩余位，全部填充0即可
public:
    string maxSumOfSquares(int num, int sum) {
        // 我的实现：
        // if (sum > num * 9) { return "";}
        // string ret(num, '0');
        // int num9 = sum / 9;
        // for (int i = 0; i < num9; i++) {
        //     ret[i] = '9';
        // }
        // if (num9 < num) {
        //     ret[num9] = '0' + sum % 9;
        // }
        // return ret;

        // 官方答案：
        if (sum > 9 * num) { return "";}
        int r = sum % 9;
        string ans(sum / 9, '9');
        if (r > 0) {
            ans.push_back('0' + r);
        }
        ans.append(num - (int)ans.size(), '0');
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 2\n3\n
// @lcpr case=end

// @lcpr case=start
// 2\n17\n
// @lcpr case=end

// @lcpr case=start
// 1\n10\n
// @lcpr case=end

 */

