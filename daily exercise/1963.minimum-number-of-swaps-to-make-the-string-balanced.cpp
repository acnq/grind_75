/*
 * @lc app=leetcode.cn id=1963 lang=cpp
 * @lcpr version=30204
 *
 * [1963] 使字符串平衡的最小交换次数
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
    // cnt[i] 表示s[0:i]的前缀和，[记为1，]为-1，则所有前缀和>=0, s平衡
    // 给出一个猜想：
    // cnt最小值为cnt[i*], 需要交换的最小次数为 \ceiling(-cnt[i*] / 2)
    // 证明：cnt[i*]表示遍历时，栈最多欠了-cnt[i*]个左括号，于是需要补上左括号，
    // 但补上左括号唯一的方法就是将浅眠的右括号与后面的左括号交换，交换一次cnt[i*]的值增加2
    // 于是需要交换\ceiling(-cnt[i*] / 2)
    //  证明这种方法的存在性：（数归）
    //      1.-cnt[i] = 0 => 平衡，需要交换0次
    //      2.假设-cnt[i*] = k => 需要交换次数与猜想相符
    //        当-cnt[i*] = k + 2时：
    //          记cnt第一个负数位置在first, s[first]为右括号；
    //          记cnt最后一个负数位置在last， last != n - 1(因为s中左右括号数量相同cnt[n - 1] = 0)
    //              s[last + 1]一定是左括号
    //          交换s[first], s[last + 1], [0, first - 1] 和[last + 1, n - 1)内的下标cnt均不变
    //          且均为非负，而在[first, last]内对应的cnt均+2，因为所有负数都在这里，所以cnt[i*]+2
    //          一次交换归纳为-cnt[i*] = k
    // 算法中，枚举i, 返回\ceiling(-cnt[i*] / 2)的最小值即可
public:
    int minSwaps(string s) {
        int cnt = 0, mincnt = 0;
        for (char ch: s)
        {
            if (ch == '[')
            {
                cnt ++;
            } else {
                cnt--;
                mincnt = min(mincnt, cnt);
            }
        }
        return (-mincnt + 1) / 2;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "][]["\n
// @lcpr case=end

// @lcpr case=start
// "]]][[["\n
// @lcpr case=end

// @lcpr case=start
// "[]"\n
// @lcpr case=end

 */

