/*
 * @lc app=leetcode.cn id=3333 lang=cpp
 * @lcpr version=30204
 *
 * [3333] 找到初始输入字符串 II
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
    // I. DP + 前缀和优化
    // 首先求出任意长度的结果，再减去长度为[1, k-1]的结果
    // 任意长度的结果用乘法原理，字符在word中连续出现p次，有p种可能
    // 所有p相乘即得到结果
    // 那么如何计算长度<=k-1的结果，DP,首先将所有p记录在频次数组freq,
    // f(i, j): 考虑freq下标<=i的部分构造字符串，并且构造的长度等于j的方案
    // 枚举freq[i]对应的字符的次数，[1, freq[i]], 使用了j'次，那么freq中下标严格<i
    // 的部分应该构造出长度=j - j'的字符串
    // f(i, j) = \sum_{j' = 1}^{freq[i]}f(i - 1, j - j');
    // 初始条件f(-1, 0) = 1: 空字符串是一种方案
    // freq本身长度>=k, 就不用DP了，这是因为freq中每一项都对应至少一个字符，所以构造出的
    // 字符串长度一定不小于k-1,
    // 不过我们这下枚举i,j,j'都需要O(k), 总共O(k^3)的时间复杂度，会超时
    // 我们发现，j-j'是连续的，所以我们可以直接计算f(i - 1, )的前缀和数组g(i - 1, )
    // g(i - 1, j) = \sum_{j'=0}^j f(i - 1, j'), 这样就有
    // f(i, j) = g(i - 1, j - 1) - g(i - 1, j - freq[i] - 1)
    // 复杂度降低为O(k^2)
    // 空间复杂度还可以通过将f, g化为一维来实现

public:
    static const int mod = 1e9 + 7;
    int possibleStringCount(string word, int k) {
        int n = word.size(), cnt = 1;
        vector<int> freq;
        for (int i = 1; i < n; i++)
        {
            if (word[i] == word[i - 1])
            {
                cnt++;
            } else
            {
                freq.push_back(cnt);
                cnt = 1;
            }
        }
        freq.push_back(cnt);

        int ans = 1;
        for (int o: freq) {
            ans = static_cast<long long>(ans) * o % mod;
        }

        if (freq.size() >= k)
        {
            return ans;
        }
        
        vector<int> f(k), g(k, 1);
        f[0] = 1;
        for (int i = 0; i < freq.size(); i++)
        {
            vector<int> f_new(k);
            for (int j = 1; j < k; j++)
            {
                f_new[j] = g[j - 1];
                if (j - freq[i] - 1 >= 0)
                {
                    f_new[j] = (f_new[j] - g[j - freq[i] - 1] + mod) % mod;
                }
            }
            vector<int> g_new(k);
            g_new[0] = f_new[0];
            for (int j = 1; j < k; j++)
            {
                g_new[j] = (g_new[j - 1] + f_new[j]) % mod;
            }
            f = move(f_new);
            g = move(g_new);
        }
        return (ans - g[k - 1] + mod) % mod;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "aabbccdd"\n7\n
// @lcpr case=end

// @lcpr case=start
// "aabbccdd"\n8\n
// @lcpr case=end

// @lcpr case=start
// "aaabbb"\n3\n
// @lcpr case=end

 */

