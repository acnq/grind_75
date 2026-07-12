/*
 * @lc app=leetcode.cn id=3532 lang=cpp
 * @lcpr version=30204
 *
 * [3532] 针对图的路径存在性查询 I
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

#include <ranges>
// @lcpr-template-end
// @lc code=start
class Solution {
    // I. 二分查找
    // nums已经按照非递增排序，所以如果两个节点ij联通
    // 那么ij之间任何一个节点也和他们联通，
    // 于是我们知道：最终整个nums被划分为若干区间
    // 1. 两个相邻区间，边界处插值>maxDiff
    // 2. 每个区间内不任意两个节点互相联通
    // 所以对于每个查询，两个节点在同一区间则存在路径
    // 我们只要记录每个区间的右端点，
    // 通过二分查找快速定位待查询节点所在区间的右端点，
    // 进而判断两点是否处于同一区间
    // tc: O(n + qlogn), q: 查询私处，n = |nums|, sc: O(n)
    //
    // II. 并查集
    // 我们直接用一个数组来标记每个节点所属的连通集的编号
    // tags[i]: i所属的集合编号，如果tages[i] = tags[j], 则ij在同集合内
    // 遍历中：
    // 1. nums[i] - nums[i - 1] > maxDiff: tags[i] 设为tags[i - 1] + 1;
    // 否则，tags[i] 申威tags[i - 1]
    // tc: O(n + q); sc: O(n)
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        // I.
        // vector<int> rights;
        // for (int i = 1; i < n; i++) {
        //     if (nums[i] - nums[i - 1] > maxDiff) {
        //         rights.push_back(i - 1);
        //     }
        // }
        // rights.push_back(n - 1);

        // vector<bool> res(queries.size());
        // for (int i = 0; i < queries.size(); i++) {
        //     int x = queries[i][0];
        //     int y = queries[i][1];

        //     res[i] = lower_bound(rights.begin(), rights.end(), x) == lower_bound(rights.begin(), rights.end(), y);
        // }
        // return res;

        // II.
        vector<int> tags(n);

        for (int i = 1; i < n; i++) {
            if (nums[i] - nums[i - 1] >maxDiff) {
                tags[i] = tags[i - 1] + 1;
            } else {
                tags[i] = tags[i - 1];
            }
        }

        vector<bool> res(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            int x = queries[i][0];
            int y = queries[i][1];
            res[i] = tags[x] == tags[y];
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 2\n[1,3]\n1\n[[0,0],[0,1]]\n
// @lcpr case=end

// @lcpr case=start
// 4\n[2,5,6,8]\n2\n[[0,1],[0,2],[1,3],[2,3]]\n
// @lcpr case=end

 */

