/*
 * @lc app=leetcode.cn id=1061 lang=cpp
 * @lcpr version=30204
 *
 * [1061] 按字典序排列最小的等效字符串
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
class UnionFind
{
private:
public:
    vector<int> f; // 存储元素i的父节点f[i]
    int n;

    UnionFind(int n) : n(n) {
        f.resize(n);
        for (int i = 0; i < n; i++)
        {
            f[i] = i; // 初始化代表元素：父=自身
        }
    };
    int find(int x) {
        if (f[x] != x)
        { // 只有代表满足父=自身
            f[x] = find(f[x]);
        }
        return f[x];
    }
    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y)
        {
            return;
        }
        if (x > y)
        {
            swap(x, y);
        }
        // 总是让字典序更小的作为集合代表字符
        f[y] = x;
    }
};

class Solution {
    // I. 并查集
    // 等价字符集看做无向图中的联通块，同一个块中的点（字符）互相等价
    // 根据是s1, s2构建连通集，然后为每个baseStr中每个字符找到所在联通块中字典序最小的字符即可
    // 手动实现并查集，见上
public:

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        UnionFind uf(26);
        for (int i = 0; i < s1.size(); i++)
        {
            int x = s1[i] - 'a';
            int y = s2[i] - 'a';
            uf.unite(x, y);
        }
        for (int i = 0; i < baseStr.size(); i++)
        {
            baseStr[i] = 'a' + uf.find(baseStr[i] - 'a');
        }
        return baseStr;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "parker"\n"morris"\n"parser"\n
// @lcpr case=end

// @lcpr case=start
// "hello"\n"world"\n"hold"\n
// @lcpr case=end

// @lcpr case=start
// "leetcode"\n"programs"\n"sourcecode"\n
// @lcpr case=end

 */

