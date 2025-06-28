/*
 * @lc app=leetcode.cn id=131 lang=cpp
 * @lcpr version=30204
 *
 * [131] 分割回文串
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
    // I. 回溯+DP预处理
    // 假设当前搜索到第i个字符，且s[0:(i-1)]位置已经被成功分割，
    // 且答案被放入了答案数组ans, 那么我们需要枚举下一个回文串的右边界j, s.t.s[i:j]回文
    // 这个子问题我们从小（i)到大依次枚举j, 用DP判断当前s[i:j]是否回文
    // 是则加入答案，i = j+1进行下一轮搜索，回溯时要将s[i:j]移除恢复现场
    // DP判断的时候可以预处理，f(i, j)表示s[i:j]是否回文
    // f(i, j) = { True; i >= j
    //           { f(i + 1, j - 1) \and (s[i] = s[j]); else
    // 预处理完所有s[i:j], 之后判断就只需要O(1)
    // tc: O(n * 2^n) [长度为n的字符串有2^(n - 1)种划分]，预处理O(n^2)渐进可忽略
    // sc: O(n^2), f的大小

    // II. 回溯 + 记忆化搜索
    // 预处理的部分改为记忆化， sc/tc不变
public:
    vector<vector<int>> f;
    vector<vector<string>> ret;
    vector<string> ans;
    int n;

    // I.
    // void dfs(const string& s, int i) {
    //     if (i == n)
    //     {
    //         ret.push_back(ans);
    //         return;
    //     }
    //     for (int j = i; j < n; j++)
    //     {
    //         if (f[i][j])
    //         {
    //             ans.push_back(s.substr(i, j - i + 1));
    //             dfs(s, j + 1);
    //             ans.pop_back();
    //         }
    //     }
    // }

    // II.
    // 记忆化搜索中，f[i][j] = 0 表示未搜索，1 表示是回文串，-1 表示不是回文串
    int isPalindrome(const string& s, int i, int j) {
        if (f[i][j])
        {
            return f[i][j];
        }

        if (i >= j)
        {
            return f[i][j] = 1;
        }
        return f[i][j] = ((s[i] == s[j]) ? isPalindrome(s, i + 1, j - 1) : -1);
    }

    void dfs(const string& s, int i) {
        if (i == n)
        {
            ret.push_back(ans);
            return;
        }
        for (int j = i; j < n; j++)
        {
            if (isPalindrome(s, i, j) == 1)
            {
                ans.push_back(s.substr(i, j - i + 1));
                dfs(s, j + 1);
                ans.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        // I.
        // n = s.size();
        // f.assign(n, vector<int>(n, true));

        // for (int i = n - 1; i >= 0; i--)
        // {
        //     for (int j = i + 1; j < n; j++)
        //     {
        //         f[i][j] = (s[i] == s[j]) && f[i + 1][j - 1];
        //     }
        // }
        // dfs(s, 0);
        // return ret;

        n = s.size();
        f.assign(n, vector<int>(n));

        dfs(s, 0);
        return ret;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "aab"\n
// @lcpr case=end

// @lcpr case=start
// "a"\n
// @lcpr case=end

 */

