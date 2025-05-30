/*
 * @lc app=leetcode.cn id=838 lang=cpp
 * @lcpr version=30204
 *
 * [838] 推多米诺
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
    // I. BFS
    // 我们考虑按时间步长模拟，向左翻倒的骨牌，如果他有治理的左边紧邻的牌，则会对他施加向左的力
    // 向右的话，考虑右边紧邻的骨牌
    // 分析每个时刻受力的骨牌，单侧受力->倒向此侧；双侧受力->不动
    // 一个时间步之后，新翻到的骨牌又会如上影响其他直立的骨牌，但注意不会影响已经翻到的牌
    // 使用bfs: 用一个队列q模拟搜索顺序，time记录骨牌确定状态的时间步，force记录收到的力

    // II. 块化模拟
    // 枚举所有“连续的”没有被推动的骨牌，根据这段骨牌两边的骨牌情况（如果有的话）的推倒方向决定状态
    // 1. 两边骨牌同向，这段连续的骨牌都会倒向同一方向
    // 2. 相对（左向右右向左），这段连续的骨牌会向中间倒
    // 3. 相反（左右左右向右），这段连续的骨牌会保持竖立
    // 考虑边界情况：左边没有骨牌=>左边右移块向左倒的骨牌，右侧同理
    // 双指针i,j枚举所有连续的没有推动的骨牌，（left, right表示推倒的方向）
public:
    string pushDominoes(string dominoes) {
        // I.
        // int n = dominoes.size();
        // queue<int> q;
        // vector<int> time(n, -1);
        // vector<string> force(n);

        // for (int i = 0; i < n; i++)
        // {
        //     if (dominoes[i] != '.')
        //     {
        //         q.emplace(i);
        //         time[i] = 0;
        //         force[i].push_back(dominoes[i]);
        //     }
        // }

        // string res(n, '.');
        // while (!q.empty())
        // {
        //     int i = q.front();
        //     q.pop();
        //     if (force[i].size() == 1)
        //     {
        //         char f = force[i][0];
        //         res[i] = f;
        //         int ni = (f == 'L') ? (i - 1) : (i + 1);
        //         if (ni >= 0 && ni < n)
        //         {
        //             int t = time[i];
        //             if (time[ni] == -1)
        //             {
        //                 q.emplace(ni);
        //                 time[ni] = t + 1;
        //                 force[ni].push_back(f);
        //             } else if (time[ni] == t + 1)
        //             {
        //                 force[ni].push_back(f);
        //             }
        //         }
        //     }
        // }
        // return res;

        // II.
        int n = dominoes.size(), i = 0;
        char left = 'L';
        while (i < n)
        {
            int j = i;
            while (j < n && dominoes[j] == '.')
            { // 找到一段连续的没有被推动的骨牌
                j++;
            }
            char right = j < n ? dominoes[j] : 'R';
            if (left == right)
            { // 方向相同，则倒向同一方向
                while (i < j)
                { 
                    dominoes[i++] = right;
                }
            } else if (left == 'R' && right == 'L')
            { // 方向相对，那么就从两侧向中间倒
                int k = j - 1;
                while (i < k)
                {
                    dominoes[i++] = 'R';
                    dominoes[k--] = 'L';
                }
            }
            left = right;
            i = j + 1;
        }
        return dominoes;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "RR.L"\n
// @lcpr case=end

// @lcpr case=start
// ".L.R...LR..L.."\n
// @lcpr case=end

 */

