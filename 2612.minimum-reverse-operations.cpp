/*
 * @lc app=leetcode.cn id=2612 lang=cpp
 * @lcpr version=30204
 *
 * [2612] 最少翻转操作数
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

#include <set>
#include <numeric>
// @lcpr-template-end
// @lc code=start
class Solution {
    // I. BFS+ Balanced Tree
    // 子数组[L, R]中的任意下标i, 翻转后下标为L + R - i
    // 子数组滑动时，对于下标i来说，可以翻转到达的位置k-i-1, k-i+1，...
    // (注意是增加2而不是1，因为L,R同时增加/减少了1)
    // 如果不考虑数组边界，那么对于下标i, 翻转位置为k-i-1, ..., k+i-1
    // 如果考虑边界约束，最左边，L=0, R=k-1, 反转后还是0 + (k-1)-i = k-i-1
    // 最右边：L = n - k, R = n - 1, i翻转后(n - k) + (n - 1) - i = 2n - k - i - 1
    // 所以i1次翻转范围是[max(i-k+1, k-i-1), min(i+k-1, 2n-k-i-1)]
    // 平衡树分别维护偶下标和奇下标，BFS检查所有位置，平衡树维护尚未到达的位置
    // banned中的下标不需要添加到平衡树中即可

    // II. BFS + Union Set
    // 通过删除一个元素，可以与下一个元素合并
    int find(vector<int>& f, int x) {
        return f[x] == x ? x : f[x] = find(f, f[x]);
    }

    void merge(vector<int>& f, int x, int y) {
        int fx = find(f, x), fy = find(f, y);
        f[fx] = fy;
    }

public:
    vector<int> minReverseOperations(int n, int p, vector<int>& banned, int k) {
        // unordered_set<int> ban{banned.begin(), banned.end()};
        // set<int> sets[2]; // 两个set<int>的数组,就是需要的平衡树
        // for (int i = 0; i < n; i++)
        // {
        //     if (i != p && !ban.count(i)) // count做多返回1
        //     {
        //         sets[i % 2].insert(i);
        //     }
        // }
        
        // vector<int> ans(n, -1);
        // queue<int> q;
        // q.push(p);
        // ans[p] = 0;
        // while (!q.empty())
        // {
        //     int i = q.front();
        //     q.pop();
        //     int mn = max(i - k + 1, k - i - 1);
        //     int mx = min(i + k - 1, n * 2 - k - i - 1);
        //     auto it = sets[mx % 2].lower_bound(mn);
        //     while (it != sets[mx % 2].end())
        //     {
        //         if (*it > mx)
        //         {
        //             break;
        //         }
        //         ans[*it] = ans[i] + 1; // i再翻转就能到it
        //         q.push(*it);
        //         it = sets[mn % 2].erase(it);
        //     }
        // }
        // return ans;
        vector<vector<int>> fa(2, vector<int>(n + 2));
        iota(fa[0].begin(), fa[0].end(), 0);
        iota(fa[1].begin(), fa[1].end(), 0);
        for (int ban : banned)
        {
            merge(fa[ban % 2], ban, ban + 2);
        }
        vector<int> ans(n, - 1);
        queue<int> q;
        q.push(p);
        ans[p] = 0;
        merge(fa[p % 2], p, p + 2);
        while (!q.empty())
        {
            int i = q.front();
            q.pop();
            int mn = max(i - k + 1, k - i - 1);
            int mx = min(i + k - 1, n * 2 - k - i - 1);
            for (int j = mn; j <= mx;)
            {
                int fi = find(fa[mn % 2], j);
                if (fi > mx)
                {
                    break;  
                }
                ans[fi] = ans[i] + 1;
                q.push(fi);
                merge(fa[mn % 2], fi, fi + 2);
                j = fi + 2;
            }
        }
        
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 4\n0\n[1,2]\n4\n
// @lcpr case=end

// @lcpr case=start
// 5\n0\n[2,4]\n3\n
// @lcpr case=end

// @lcpr case=start
// 4\n2\n[0,1,3]\n1\n
// @lcpr case=end

 */

