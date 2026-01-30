/*
 * @lc app=leetcode.cn id=2976 lang=cpp
 * @lcpr version=30204
 *
 * [2976] 转换字符串的最小成本 I
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
    // I. Floyd 算法
    // 最小成本等于每一组source[i]转换成target[i]的最小成本之和
    // 构造有向图G, G的节点是小写字母，每一组(original[i], changed[i], cost[i])
    // 我们在G中建立original[i]->changed[i]的有向边，边权重为cost[i]
    // 于是source[i]转换为target[i]的最小成本就是G中source[i]到target[i]的最短路径
    // G最多|\Sigma| = 26个节点，最多2000条边（题目规定original, changed, cost的长度<2000)
    // tc: O(n + m + |\Sigma|^3) (n: source长度，m: org长度）sc: O(|\Sigma|^2|) 
public:
    static constexpr int inf = INT_MAX / 2;
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<int>> G(26, vector<int>(26, inf));
        for (int i = 0; i < 26; i++) {
            G[i][i] = 0;
        }
        int m = original.size();
        for (int i = 0; i < m; i++) {
            int idx = original[i] - 'a';
            int idy = changed[i] - 'a';
            G[idx][idy] = min(G[idx][idy], cost[i]);
        }

        for (int k = 0; k < 26; k++) {
            // k必须在最外层，表示经过k个中间字母
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
                }
            }
        }

        int n = source.size();
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            int idx = source[i] - 'a';
            int idy = target[i] - 'a';
            if (G[idx][idy] == inf) {
                return -1;
            }
            ans += G[idx][idy];
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "abcd"\n"acbe"\n["a","b","c","c","e","d"]\n["b","c","b","e","b","e"]\n[2,5,5,1,2,20]\n
// @lcpr case=end

// @lcpr case=start
// "aaaa"\n"bbbb"\n["a","c"]\n["c","b"]\n[1,2]\n
// @lcpr case=end

// @lcpr case=start
// "abcd"\n"abce"\n["a"]\n["e"]\n[10000]\n
// @lcpr case=end

 */

