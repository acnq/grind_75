/*
 * @lc app=leetcode.cn id=1888 lang=cpp
 * @lcpr version=30204
 *
 * [1888] 使二进制字符串字符交替的最少反转次数
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
    // I. 前后缀和
    // 1.我们可以将操作2安排在操作1之前，因为操作1无法改变字符值
    // 2.n = len(s), 如果n为偶，则只能通过操作2将其变为交替字符串
    //   操作2可以得到的只有0101...01和1010...10两种形式，
    //   二者会通过操作1互相转化，可以证明，操作1因为不会改变字符值，
    //   无法对开始不是的字符转化为以上两种形式有所帮助
    // 3. n为奇则不同，交替字符串也仅有0101...010和1010...101两种形式
    //      但是（以第一种为例）除了通过操作2直接打到效果，还有
    //      操作2最后得到01...010|01...01, 或者10...10|01...010的形势
    //      经过一次操作1将|前移到后面，最终可以得到相同的效果，
    //      所以s可以是一个交替字符串，也可以是两个首尾在拼合处以'00'拼合而成
    //      第二种也是，只是这时首尾以'11'拼合而成
    // 我们用pre[i][j]表示对于字符串s[0:i], 以类型2操作修改为以j结尾的交替字符串
    // 所需要的最少操作数，j\in{0, 1}
    // { pre[i][0] = pre[i - 1][1] + II(s[i], 1)
    // { pre[i][1] = pre[i - 1][0] + II(s[i], 0)
    // 
    // { II(x, y) = 1, x = y
    // { II(x, y) = 0, x != y, 示性函数
    // 同理对于后缀suf[i][j]有类似递推
    // { suf[i][0] = suf[i + 1][1] + II(s[i], 1)
    // { suf[i][1] = suf[i + 1][0] + II(s[i], 0)
    // 解得pre, suf后
    // 答案如果是交替字符串，有min(pre[n - 1][0], pre[n - 1][1]
    // 如果是两个交替字符串的拼合，还可以为pre[i][0] + suf[i + 1][0]
    // 和pre[i][1] + suf[i + 1][1]中的最小值
    // n是偶数则不用计算suf
    // tc: sc: 
public:
    int minFlips(string s) {
        // 示性函数
        auto I = [](char ch, int x) -> int {
            return ch - '0' == x;
        };

        int n = s.size();
        vector<vector<int>> pre(n, vector<int>(2));

        for (int i = 0; i < n; i++) {
            pre[i][0] = (i == 0 ? 0 : pre[i - 1][1]) + I(s[i], 1);
            pre[i][1] = (i == 0 ? 0 : pre[i - 1][0]) + I(s[i], 0);
        }

        int ans = min(pre[n - 1][0], pre[n - 1][1]);

        if (n % 2 == 1) {
            vector<vector<int>> suf(n, vector<int>(2));
            for (int i = n - 1; i >= 0; i--) {
                suf[i][0] = (i == n - 1 ? 0 : suf[i + 1][1]) + I(s[i], 1);
                suf[i][1] = (i == n - 1 ? 0 : suf[i + 1][0]) + I(s[i], 0);
            }

            for (int i = 0; i + 1 < n; i++) {
                ans = min(ans, pre[i][0] + suf[i + 1][0]);
                ans = min(ans, pre[i][1] + suf[i + 1][1]);
            }
        }

        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "111000"\n
// @lcpr case=end

// @lcpr case=start
// "010"\n
// @lcpr case=end

// @lcpr case=start
// "1110"\n
// @lcpr case=end

 */

