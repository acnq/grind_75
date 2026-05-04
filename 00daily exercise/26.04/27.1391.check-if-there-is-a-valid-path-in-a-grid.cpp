/*
 * @lc app=leetcode.cn id=1391 lang=cpp
 * @lcpr version=30204
 *
 * [1391] 检查网格中是否存在有效路径
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
    // O. 静态连通性
    // 如果首先给出了整个网格的信息，在查询过程中不改变图
    // 就是静态连通性，这些题目可以用DFS, BFS和并查集解决，本题使用并查集
    // 我们同样可以用id = x * n + y来压缩维度
    // 
    // I. 相邻关系建图
    // 实现四个函数detectL(x, y), detectR(x, y), detectU(x, y), detectD(x, y)
    // (x, y)链接了左右上下四个方向分别调用对应的函数，
    // e.g. grid[x][y] = 1, 则调用detectL(x, y)和detectR(x, y)
    // e.g. detectL(x, y)调用时，考虑左边的单元格(x, y - 1),必须与右侧
    //    (x, y)相连，那么grid[x][y - 1]值必须为[1, 4, 6]中的一个
    //    所以detectL(x, y), 首先考虑(x, y - 1)是否存在，
    //    若存在则判断grid[x][y - 1]是否满足要求, 其余类似
    // 于是我们遍历整个网络，根据grid值调用四个函数的两个，
    //  满足要求时将该单元格与相邻的单元格相连（合并并查集）
    // 遍历结束后，判断左上角和右下角是否属于同一个集合即可
    // tc: O(t * \alpha(t)), sc: O(t)
    // 
    // II. 单元格性质建图
    // 四个方向编号：
    //       0
    //       ^
    //       |
    //  3 <-- --> 1
    //       |
    //       v
    //       2
    // 每个单元格都可以用一个长度为4的二进制数表示
    // 二进制数的第i位=1 => 该单元格在第i个方向存在街道
    // 如此，每个单元格对应的二进制数中都恰好有2个1
    // 于是我们发现，满足如下条件两个相邻单元格才能相连
    //  - 0 方向 -> 上方要有2方向
    //  - 1 ... ->  右     3
    //  - 2     ->  下     0    
    //  - 3     ->  左     1
    //  - i     ->  i     (i + 2) % 4
    // 于是我们遍历整个网络，每个单元格(x, y), 枚举它4个相邻的单元格
    // 第i个方向的相邻单元格，它和(x, y)相连当且仅当(x, y)对应的
    // 二进制第i位和相邻单元格对应的二进制第(i + 2) % 4 均为1
    // 遍历结束后，判断左上角和右下角是否属于同一个集合即可
public:
    static constexpr int MAX_N = 300 * 300 + 5; // m, n <= 300
    // II.
    static constexpr int patterns[7] = {0, 0b1010, 0b0101, 0b1100, 0b0110, 0b1001, 0b0011};
    static constexpr int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    struct DisjointSet {
        int f[MAX_N];

        DisjointSet() {
            for (int i = 0; i < MAX_N; i++) {
                f[i] = i;
            }
        }

        int find(int x) {
            return x == f[x] ? x : f[x] = find(f[x]);
        }

        void merge(int x, int y) {
            f[find(x)] = find(y);
        }
    } ds;

    bool hasValidPath(vector<vector<int>>& grid) {
        // I. 
        // int m = grid.size(), n = grid[0].size();

        // auto getId = [&] (int x, int y) {
        //     return x * n + y;
        // };

        // auto detectL = [&] (int x, int y) {
        //     if (y - 1 >= 0 && (grid[x][y - 1] == 4 || grid[x][y - 1] == 6 || grid[x][y - 1] == 1)) {
        //         ds.merge(getId(x, y), getId(x, y - 1));
        //     }
        // };

        // auto detectR = [&] (int x, int y) {
        //     if (y + 1 < n && (grid[x][y + 1] == 3 || grid[x][y + 1] == 5 || grid[x][y + 1] == 1)) {
        //         ds.merge(getId(x, y), getId(x, y + 1));
        //     }
        // };

        // auto detectU = [&] (int x, int y) {
        //     if (x - 1 >= 0 && (grid[x - 1][y] == 3 || grid[x - 1][y] == 4 || grid[x - 1][y] == 2)) {
        //         ds.merge(getId(x, y), getId(x - 1, y));
        //     }
        // };

        // auto detectD = [&] (int x, int y) {
        //     if (x + 1 < m && (grid[x + 1][y] == 5 || grid[x + 1][y] == 6 || grid[x + 1][y] == 2)) {
        //         ds.merge(getId(x, y), getId(x + 1, y));
        //     }
        // };

        // auto handler = [&] (int x, int y) {
        //     switch (grid[x][y]) {
        //         case 1: {
        //             detectL(x, y); detectR(x, y);
        //         } break;
        //         case 2: {
        //             detectU(x, y); detectD(x, y);
        //         } break;
        //         case 3: {
        //             detectL(x, y); detectD(x, y);
        //         } break;
        //         case 4: {
        //             detectR(x, y); detectD(x, y);
        //         } break;
        //         case 5: {
        //             detectL(x, y); detectU(x, y);
        //         } break;
        //         case 6: {
        //             detectR(x, y); detectU(x, y);
        //         }
        //     }
        // };

        // for (int i = 0; i < m; i ++) {
        //     for (int j = 0; j < n; j++) {
        //         handler(i, j);
        //     }
        // }

        // return ds.find(getId(0, 0)) == ds.find(getId(m - 1, n - 1));

        // II. 
        int m = grid.size(), n = grid[0].size();

        auto getId = [&](int x, int y) {
            return x * n + y;
        };

        auto handler = [&] (int x, int y) {
            int pattern = patterns[grid[x][y]];
            for (int i = 0; i < 4; i++) {
                if (pattern & (1 << i)) {
                    int sx = x + dirs[i][0];
                    int sy = y + dirs[i][1];
                    if (sx >= 0 && sx < m && sy >= 0 && sy < n && (patterns[grid[sx][sy]] & (1 << ((i + 2) % 4)))) {
                        ds.merge(getId(x, y), getId(sx, sy));
                    }
                }
            }
        };

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                handler(i, j);
            }
        }

        return ds.find(getId(0, 0)) == ds.find(getId(m - 1, n - 1));
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[2,4,3],[6,5,2]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,1],[1,2,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,1,2]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,1,1,1,1,1,3]]\n
// @lcpr case=end

// @lcpr case=start
// [[2],[2],[2],[2],[2],[2],[6]]\n
// @lcpr case=end

 */

