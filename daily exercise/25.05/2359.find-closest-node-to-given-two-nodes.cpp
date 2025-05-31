/*
 * @lc app=leetcode.cn id=2359 lang=cpp
 * @lcpr version=30204
 *
 * [2359] 找到离给定两个节点最近的节点
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
    // I. 循环计算可达性+一次遍历
    // 注意“每个节点至多有一条出边”
    // 所以，我们从某个点（设为x)出发不断沿着出边（唯一的）遍历
    // 总可以得到x可以到达的所有点，以及距离
    // 循环此过程，直到遇不到出边或者这个点已然被遍历（成环）停止
    // 对node_1, node_2调用此过程后，遍历所有点，删选出二者都可以到达的店
    // 选出距离node_1, node_2最远距离最小的点即可
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        auto get = [&](int x) {
            vector<int> d(n, -1);
            int p = x;
            int dis = 0;
            while (p != -1 && d[p] == -1)
            {
                d[p] = dis;
                p = edges[p];
                dis++;
            }
            return d;
        };
        auto d1 = get(node1);
        auto d2 = get(node2);

        int res = -1;
        for (int i = 0; i < n; i++)
        {
            if (d1[i] != -1 && d2[i] != -1 && (res == -1 || max(d1[res], d2[res]) > max(d1[i], d2[i])))
            {
                res = i;
            }
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,2,3,-1]\n0\n1\n
// @lcpr case=end

// @lcpr case=start
// [1,2,-1]\n0\n2\n
// @lcpr case=end

 */

