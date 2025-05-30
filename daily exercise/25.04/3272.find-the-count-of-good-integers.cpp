/*
 * @lc app=leetcode.cn id=3272 lang=cpp
 * @lcpr version=30204
 *
 * [3272] 统计好整数的数目
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

#include <cstdio>
#include <cstdlib>
#include <string>
// @lcpr-template-end
// @lc code=start
class Solution {
    // n % 2 == 0: 回文数左边前n/2与右边n/2倒序相同
    // 左半边前n/2取值范围[0, 10^{n/2}), 因为不能有前导0
    // 共有10^{n/2} - 10^{(n - 2)/2}
    // n % 2 == 1: 左半边和右半边(n - 1) / 2倒序相同，中间第
    // (n + 1) / 2取值范围[0, 9], 考虑前导0，有10^{(n + 1) / 2} - 10^{(n - 1) / 2}
    // 综上，长度为n的回文整数有10^{\floor{(n + 1) / 2}} - 10^{\floor{(n - 1) / 2}}
    // 由题意：n \in [1, 10]

    // 最多不超过10^5个k回文数，
    // 令： m = \floor{(n - 1) / 2}, base = 10^m
    // 回文数左半边，取值在[base, base*10), 这些数如果被k整除，则就是k回文

    // 对于不同的k回文，重排列每一位形成好整数，为避免相同数位的重复计算，
    // 将字符串按照字典序排序，用哈希表dict记录排列后的字符串，
    // 假定定长n的字符串'0'-'9'出现的次数为'c_0, c_1, ..., c_9',
    // 不考虑前导0，多重排列数为(n!)/(\Prod_{i=0}^9(c_i!))
    // 考虑前导0，首先要从(n - c_0)个不为0的字符中选一个放在首位，剩下的同样求多重全排列即可，有
    // (n-c_0)(n - 1)!/(\Prod_{i=0}^9(c_i!))

    // 枚举dict中合法的字符串s, 统计其中0-9出现的统计数目，存储在cnt,根据cnt按照排列组合
    // 计算出s可构成的不同组合方案，累加导结果中即可
public:
    long long countGoodIntegers(int n, int k) {
        unordered_set<string> dict;
        int base = pow(10, (n - 1) / 2);
        int skip = n & 1;
        /*枚举n个数位的回文数*/
        for (int i = base; i < base * 10; i++)
        {
            string s = to_string(i);
            s += string(s.rbegin() + skip, s.rend());
            long long palindromicInteger = stoll(s);
            /* 若当前回文数为k回文数*/
            if (palindromicInteger % k == 0)
            {
                sort(s.begin(), s.end());
                dict.emplace(s);
            }
        }

        vector<long long> factorial(n + 1, 1);
        long long ans = 0;
        for (int i = 1; i <= n; i++)
        {
            factorial[i] = factorial[i - 1] * i;
        }
        for(const string& s: dict) {
            vector<int> cnt(10);
            for(char c: s) {
                cnt[c - '0']++;
            }

            /* 计算排列组合 */
            long long tot = (n - cnt[0]) * factorial[n - 1];
            for(int x: cnt) 
            {
                tot /= factorial[x];
            }
            ans += tot;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 3\n5\n
// @lcpr case=end

// @lcpr case=start
// 1\n4\n
// @lcpr case=end

// @lcpr case=start
// 5\n6\n
// @lcpr case=end

 */

