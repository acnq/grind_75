/*
 * @lc app=leetcode.cn id=1931 lang=cpp
 * @lcpr version=30204
 *
 * [1931] 用三种不同颜色为网格涂色
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
    // I. 状态压缩DP
    // 原问题=>
    // 1. 一行内相邻格子的颜色不同；
    // 2. 相邻行之间同列格子颜色不同
    // 故：
    // 1. 首先枚举一行涂色的方案数
    // 2. 通过动态规划，计算整个m * n的涂色方案数
    // m < 5, 看成行的长度，方便枚举，n<1000, 看成列长度
    // 思路与算法
    // 1. 枚举一行的算法
    // 红绿蓝看做012，一种涂色对应长度为m的三进制数，范围[0, 3^m)
    // 枚举整数->转换为三进制串->判断是否满足相邻数位均不相同
    // 2. DP整个阵列
    // f[i][mask]: 表示[0:i]行已经进行涂色，而且第i行的涂色方案对应的三进制表示为mask的前提下 的总方案数
    // f[i][mask] = \sum_{mask 与 mask'同位上的数字均不相同}f[i - 1][mask']
    // 答案：所有满足mask \in [0, 3^m)的 f[n - 1][mask]之和

    // 注意f[0]的问题，mask任意相邻的两个数位均不相同则f[0][mask] = 1, 否则为0
    // f[i][*] 总是从f[i - 1][*]而来，可以用两个长度为3^m的一位数组滚动化
public:
    static constexpr int mod = 1e9 + 7;
    int colorTheGrid(int m, int n) {
        // 哈希map valid存储所有满足要求的对一行进行涂色的方案
        // 键表示mask, 值表示mask的三进制串（以列表形式存储）
        unordered_map<int, vector<int>> valid;

        // 在[0, 3^m)范围内枚举满足要求的mask
        int mask_end = pow(3, m);
        for (int mask = 0; mask < mask_end; mask++)
        {
            vector<int> color;
            int mm = mask;
            for (int i = 0; i < m; i++)
            {
                color.push_back(mm % 3);
                mm /= 3;
            }
            bool check = true;
            for (int i = 0; i < m - 1; i++)
            {
                if (color[i] == color[i + 1])
                {
                    check = false;
                    break;
                }
            }
            
            if (check)
            {
                valid[mask] = move(color);
            }
        }

        // 预处理所有的(mask1, mask2)二元组，
        // 满足mask1和mask2作为相邻行时，同一列上两个格子的颜色不同
        unordered_map<int, vector<int>> adjacent;
        for(const auto& [mask1, color1]: valid) {
            for (const auto& [mask2, color2]: valid)
            {
                bool check = true;
                for (int i = 0; i < m; i++)
                {
                    if (color1[i] == color2[i])
                    {
                        check = false;
                        break;
                    }
                }

                if (check)
                {
                    adjacent[mask1].push_back(mask2);
                }                
            }
        }
        
        vector<int> f(mask_end);
        for(const auto& [mask, _]: valid) {
            f[mask] = 1;
        }
        for (int i = 1; i < n; i++)
        {
            vector<int> g(mask_end);
            for(const auto& [mask2, _]: valid) {
                for(int mask1: adjacent[mask2]) {
                    g[mask2] += f[mask1];
                    if (g[mask2] >= mod)
                    {
                        g[mask2] -= mod;
                    }
                }
            }
            f = move(g);
        }

        int ans = 0;
        for(int num: f) {
            ans += num;
            if (ans >= mod)
            {
                ans -= mod;
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 1\n1\n
// @lcpr case=end

// @lcpr case=start
// 1\n2\n
// @lcpr case=end

// @lcpr case=start
// 5\n5\n
// @lcpr case=end

 */

