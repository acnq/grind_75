/*
 * @lc app=leetcode.cn id=2272 lang=cpp
 * @lcpr version=30204
 *
 * [2272] 最大波动的子字符串
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
public:
    // 枚举“出现次数最多的字符”c_0以及“出现次数最少得字符”c_1，
    // 映射字符串s为一个数组：
    //  c_0 -> +1
    //  c_1 -> -1
    //  其他-> 0
    // 任意一个子串对应的子数组的和，就是“c_0出现的次数-c_1出现的次数”
    // 求出映射数组的最大子段和（和最大的子数组的和）= 最大波动值

    // 如何计算最大子段和？而且要求子数组必须至少包含一个+1和一个-1
    // 但不包含+1的话结果一定<0, 所以会在最后取最大化的时候优化掉，
    // 所以只要求包含-1即可
    // f[i]： i结尾的子数组的最大和
    // g[i]:  i结尾且包含-1的子数组的最大和
    // f[-1] = 0, g[-1] = -\infin, d_i: s[i]映射的数值
    // d_i = 0: f[i] = f[i - 1], g[i] = g[i - 1]
    // d_i = 1: f[i] = max{f[i - 1], 0} + 1, g[i] = g[i - 1] + 1
    // d_i = -1: f[i] = max{f[i - 1], 0} - 1, g[i] = max{f[i - 1], g[i - 1], 0} - 1
    // 答案为max(g)
    int largestVariance(string s) {
        unordered_map<char, vector<int>> pos;
        for (int i = 0; i < s.size(); i++)
        {
            pos[s[i]].push_back(i); // 存储每个字符出现的位置
        }
        
        int ans = 0;
        for (auto&& [c0, pos0]: pos)
        {
            for (auto&& [c1, pos1]: pos)
            {
                if (c0 != c1)
                {
                    int i = 0, j = 0;
                    int f = 0, g = INT_MIN;
                    while (i < pos0.size() || j < pos1.size())
                    {
                        if (j == pos1.size() || (i < pos0.size() && pos0[i] < pos1[j]))
                        {
                            tie(f, g) = tuple{max(f, 0) + 1, g + 1};
                            i++; // c_0对应的idx < c_1对应的idx: 相当于遇到+1(c0对应的值);
                        } else {
                            tie(f, g) = tuple{max(f, 0) - 1, max({f, g, 0}) - 1};
                            j++; // c_0对应的idx >= c_1对应的idx: 相当于遇到-1(c1对应的值);
                        }
                        ans = max(ans, g);
                    }
                }
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "aababbb"\n
// @lcpr case=end

// @lcpr case=start
// "abcde"\n
// @lcpr case=end

 */

