/*
 * @lc app=leetcode.cn id=1559 lang=cpp
 * @lcpr version=30204
 *
 * [1559] 二维网格图中探测环
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

#include <numeric>
// @lcpr-template-end
// @lc code=start

class UnionFind {
public:
    vector<int> parent;
    vector<int> size;
    int n; 
    int setCnt; // 目前分了几个并查集

    UnionFind(int _n): n(_n), setCnt(_n), parent(_n), size(_n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }

    int findset(int x) {
        return parent[x] == x ? x : parent[x] = findset(parent[x]);
    }

    void unite(int x, int y) {
        if (size[x] < size[y]) {
            swap(x, y);
        }
        parent[y] = x;
        size[x] += size[y];
        setCnt--;
    }

    bool findAndUnite(int x, int y) {
        int parentX = findset(x);
        int parentY = findset(y);
        if (parentX != parentY) {
            unite(parentX, parentY);
            return true;
        }
        return false;
    }
};
class Solution {
    // I. 并查集
    // 对于图中任意一条边(x, y), 我们将x, y对应的集合合并，
    //  如果x, y已经属于同一个集合，则x,y已经连通，再有边(x, y)
    // 说明图中有环
    // 遍历数组grid中的每处，如若该位置与其上方或左侧的值相同
    // 就有了一条边，将这两个位置合并，
    // 这样保证每条边的两个节点只会被合并一次
    // 构造并查集时，(i, j) -> i * n + j 映射坐标
    // (i, j)上方-> (i - 1) * n + j
    // (i, j) 左侧 -> i * n + j - 1
    //
    // tc: O(mn \alpha(mn)), sc: O(mn)
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        UnionFind uf(m * n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i > 0 && grid[i][j] == grid[i - 1][j]) {
                    if (!uf.findAndUnite(i * n + j, (i - 1) * n + j)) {
                        return true;
                    }
                }

                if (j > 0 && grid[i][j] == grid[i][j - 1]) {
                    if (!uf.findAndUnite(i * n + j, i * n + j - 1)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [["a","a","a","a"],["a","b","b","a"],["a","b","b","a"],["a","a","a","a"]]\n
// @lcpr case=end

// @lcpr case=start
// [["c","c","c","a"],["c","d","c","c"],["c","c","e","c"],["f","c","c","c"]]\n
// @lcpr case=end

// @lcpr case=start
// [["a","b","b"],["b","z","b"],["b","b","a"]]\n
// @lcpr case=end

 */

