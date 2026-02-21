/*
 * @lc app=leetcode.cn id=761 lang=cpp
 * @lcpr version=30204
 *
 * [761] 特殊的二进制字符串
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

#include <numeric>
// @lcpr-template-end
// @lc code=start
class Solution {
    // 如果我们把1看成'(',0看成')'，那么特殊子串实际上就是有效的括号
    // I. 分治
    // 一个特殊字符串，一定是1(左括号)开始, 0（右括号）结束
    //      :1.显然，若0开始则第一个单字符子串不符合要求，
    //      :2.因为01数量相等，且任意前缀1的数量>=0的，所以任意后缀0的数量>=1的，故结尾必须为0
    // 注意到要交换的子串也必须是特殊的，我们这么思考
    // 如果一个字符串无法完整的拆成多个特殊子串，那么首位1和末位0不会出现在任何交换中
    //      证明: (仅给出首位1的证明，末尾0的证明类似)
    //            如果首位1包含在可以交换的特殊子串u中，那么我们可以证明，s去除u的后缀v也是特殊子串
    //            我们注意到，特殊子串u为一前缀, 包含等量的01，v也包含等量的01
    //            不仅如此，下面证明v的每个前缀都满足特殊子串的条件
    //            在统计到v的第i位时，v[:i]和之前的u拼接起来(记为u + v[:i])也是一个特殊前缀
    //            所以u + v[:i]中1多于等于0，而我们已经证明u中1和0一样多，所以任意i, v[:i]也是1多于等于0
    //            立刻得到v满足特殊字符串的前缀要求，所以v必须是特殊子串，
    //            这就是说，s被拆成了特殊子串uv, 矛盾
    // 为此，我们可以直接移除首尾的1和0，考虑剩余部分
    // 如果可以完整拆分成多个特殊子序列，我们首先将每个单元拆分递归拆分到不可拆分为止（如前所证，都是前面n个1后面n个0的形式）
    // 之后我们进行合并操作，所有特殊字符串按照字典序降序排列（开头最大）然后拼接即可
    // (因为按题意我们可以任意排序相邻的特殊字符串，那么实际上就可以实现一个冒泡排序得到全局字典序最大的结果)
    // 技巧：
    //      那么怎么拆分特殊子序列呢？其实我们只要从头开始遍历，用计数器遇1加1，遇0减1，回归0则得到一个特殊子序列
    //      当递归到字符串长度<=2时，子串不为空就为'10', 都已经是字典序最大的子串，直接返回即可
    // tc: O(n^2), sc: O(n)
public:
    string makeLargestSpecial(string s) {
        if (s.size() <= 2) {
            return s; // 题目保证s为特殊字符串
        }
        int cnt = 0, left = 0;
        vector<string> subs;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') {
                cnt++;
            } else {
                cnt--;
                if (cnt == 0) {
                    // 得到特殊子串
                    subs.push_back("1" + makeLargestSpecial(s.substr(left + 1, i - left - 1)) + "0");
                    // 将最外层的1,0剥掉进入递归
                    left = i + 1;
                }
            }
        }

        sort(subs.begin(), subs.end(), greater<string>{}); // string比较默认用字典序
        string ans = accumulate(subs.begin(), subs.end(), ""s); // 初始值不能是"",这样变成常量，没有重载+操作
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "11011000"\n
// @lcpr case=end

// @lcpr case=start
// "10"\n
// @lcpr case=end

 */

