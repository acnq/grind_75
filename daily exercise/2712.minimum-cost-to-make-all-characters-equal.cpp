/*
 * @lc app=leetcode.cn id=2712 lang=cpp
 * @lcpr version=30204
 *
 * [2712] 使所有字符相等的最小成本
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
    // I. DP
    // suf[i][0]: 第i个字符开始，后缀全部变为0所需的最小成本
    // suf[i][1]: 第i个字符开始，后缀全部变为1所需的最小成本
    // s[i]=1:  suf[i][1] = suf[i + 1][1]
    //          suf[i][0] = suf[i + 1][0] + (n - i)
    // s[i]=0:  suf[i][1] = suf[i + 1][0] + (n - i)
    //          suf[i][0] = suf[i + 1][0]
    // pre[i][0]和pre[i][1]的定义转移类似，遍历i
    // 求min(pre[i][0] + suf[i + 1][0], pre[i][1] + suf[i + 1][1])的最小值

    // II. 一次遍历
    // 1次操作有如下性质:   1. 改变相邻一对相邻字符的关系
    //                     2. 相邻不相等的字符，必须经过一次操作使她们相等
    //                     3. 某两个相邻字符操作结束后，左右相邻字符相等关系不变
public:
    using ll = long long;
    long long minimumCost(string s) {
        // int n = s.size();
        // vector<vector<ll>> suf(n + 1, vector<ll>(2, 0));
        // for (int i = n - 1; i >= 0; i--)
        // {
        //     if (s[i] == '1')
        //     {
        //         suf[i][1] = suf[i + 1][1];
        //         suf[i][0] = suf[i + 1][1] + (n - i);
        //     } else {
        //         suf[i][1] = suf[i + 1][0] + (n - i);
        //         suf[i][0] = suf[i + 1][0];
        //     }
        // }
        
        // vector<ll> pre(2);
        // ll res = 1e18;
        // for (int i = 0; i < n; i++)
        // {
        //     if (s[i] == '1')
        //     {
        //         pre[0] = pre[1] + i + 1;
        //     } else {
        //         pre[1] = pre[0] + i + 1;
        //     }
        //     res = min(res, min(pre[0] + suf[i + 1][0], pre[1] + suf[i + 1][1]));
        // }
        // return res;
        int n = s.size();
        ll res = 0;
        for (int i = 1; i < n; i++)
        {
            if (s[i] != s[i - 1])
            {
                res += min(i, n - i);
            }
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "0011"\n
// @lcpr case=end

// @lcpr case=start
// "010101"\n
// @lcpr case=end

 */

