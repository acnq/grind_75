/*
 * @lc app=leetcode.cn id=2977 lang=cpp
 * @lcpr version=30204
 *
 * [2977] 转换字符串的最小成本 II
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

// I.
struct Trie {
    Trie* child[26];
    int id; // 字符串编号，对应G的哪个节点

    Trie() {
        for (int i = 0; i < 26; i++) {
            child[i] = nullptr;
        }
        id = -1;
    }
};

int add(Trie* node, const string& word, int& index) {
    for (char ch: word) {
        int i = ch - 'a';
        if (!node->child[i]) {
            node->child[i] = new Trie();
        }
        node = node->child[i];
    }
    if (node->id == -1) {
        node->id = ++index; // 中间节点都是-1,防止错误替换
    }
    return node->id;
}

void update(long long& x, long long y) {
    if (x == -1 || y < x) {
        x = y;
    }
}

class Solution {
    // I. 字典树+Floyd+DP
    // source转换成target允许分割为不同部分，每个部分进行转化，拼接得到targt
    // f[i]: sourc到下标i为止的前缀部分转换为target对应部分的最小成本
    //      1. 如果source[i] = target[i], 无需转换
    //          f[i] = f[i - 1]
    //      2. 一般情况，我们取任意长度后缀，记x = source(j + 1:i] (左开右闭)
    //         转换为y = target(j + 1:i]的最小成本为G(x, y), 有：
    //          f[i] = f[j] + G(x, y)
    // 维护f[i]的最小值，f[-1] = 0, 答案=f[n - 1]
    // 如何得到G(x, y)? 沿用上一题(T2976)的Floyd算法
    //  1. original和changed的每个“字符串”赋予唯一的编号，共得到p(1 <= p <= 2m, m=|original|)个编号
    //  (因为最坏情况是original和changed的每个元素各不相同，于是需要2m个编号)
    //  2. p个字符串看做G上的节点，每一组(original[i], changed[i], cost[i]), 简历有向边
    //  3. x = source(j + 1:i]转换为y = target(j + 1:i]的最小成本，首先判断x,y是否有对应节点，有便是图上G对应节点的最短路径
    // 注意到动态规划本身有O(n^2)的复杂度，给予字符串的对比又有O(n)复杂度，总复杂度O(n^3)超出限制
    // 我们使用字典树，DP中增加i, j不变，对应的后缀每次会多出一个字符，
    // 对应字典上往子节点遍历的操作，这样在DP中先遍历j再遍历i, 就可以O(1)时间字典树移动得到编号
    // tc: O(n^2 + m^3 + mL) (n = |source|, m = |original|, L: original, changed中字符串的平均长度)
    //      (DP + 计算最短路+构造字典树)
    // sc: O(n + m ^ 2 + mL)
public:
    static constexpr int inf = INT_MAX / 2;
    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        int n = source.size();
        int m = original.size();
        Trie* root = new Trie();

        int p = -1; // 每个字符串的唯一编号
        vector<vector<int>> G(m * 2, vector<int>(m * 2, inf));
        for (int i = 0; i < m * 2; i++) {
            G[i][i] = 0;
        }
        for (int i = 0; i < m; i++) {
            int x = add(root, original[i], p);
            int y = add(root, changed[i], p);
            G[x][y] = min(G[x][y], cost[i]);
        }

        for (int k = 0; k <= p; k++) {
            for (int i = 0; i <= p; i++) {
                for (int j = 0; j <= p; j++) {
                    G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
                }
            }
        }

        vector<long long> f(n, -1);
        for (int j = 0; j < n; j++) {
            if (j > 0 && f[j - 1] == -1) {
                continue;
            }
            long long base = (j == 0 ? 0 : f[j - 1]);
            if (source[j] == target[j]) {
                update(f[j], base);
            }
            Trie* u = root;
            Trie* v = root;
            for (int i = j; i < n; i++) {
                u = u->child[source[i] - 'a'];
                v = v->child[target[i] - 'a'];
                if (!u || !v) {
                    break;
                }
                if (u->id != -1 && v->id != -1 && G[u->id][v->id] != inf) {
                    update(f[i], base + G[u->id][v->id]);
                }
            }
        }
        return f[n - 1];
    }
};
// @lc code=end



/*
// @lcpr case=start
// "abcd"\n"acbe"\n["a","b","c","c","e","d"]\n["b","c","b","e","b","e"]\n[2,5,5,1,2,20]\n
// @lcpr case=end

// @lcpr case=start
// "abcdefgh"\n"acdeeghh"\n["bcd","fgh","thh"]\n["cde","thh","ghh"]\n[1,3,5]\n
// @lcpr case=end

// @lcpr case=start
// "abcdefgh"\n"addddddd"\n["bcd","defgh"]\n["ddd","ddddd"]\n[100,1578]\n
// @lcpr case=end

 */

