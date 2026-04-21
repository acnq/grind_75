/*
 * @lc app=leetcode.cn id=1722 lang=cpp
 * @lcpr version=30204
 *
 * [1722] 执行交换操作后的最小汉明距离
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
    // I 哈希+并查集
    // 用并查集预处理来记录不同的集合，每个集合代表能够交换的所有下标
    // 然后我们遍历target数组，对于其中的每个元素，下标可以归属为某个元素
    // 如果这个集合存在对应于target当前下标的元素，则这个元素数量-1，
    // 否则汉明距离+1
    //
    //
private:
    vector<int> fa;
    vector<int> rank;
    // 路径压缩
    int find(int x) {
        if (fa[x] != x) {
            fa[x] = find(fa[x]);
        }
        return fa[x];
    }
    void Union(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        // 按秩合并
        if (rank[x] < rank[y]) {
            swap(x, y);
        }
        fa[y] = x;
        if (rank[x] == rank[y]) {
            rank[x]++;
        }
    }
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        fa.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++) {
            fa[i] = i;
        }
        for (auto& pair: allowedSwaps) {
            Union(pair[0], pair[1]);
        }
        unordered_map<int, unordered_map<int, int>> sets;
        // sets[f][val] 表示以f为根的并查集包含元素val的个数
        for (int i = 0; i < n; i++) {
            int f = find(i);
            sets[f][source[i]]++;
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            int f = find(i);
            if (sets[f][target[i]] > 0) {
                sets[f][target[i]]--;
            } else {
                ans++;
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4]\n[2,1,4,5]\n[[0,1],[2,3]]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4]\n[1,3,2,4]\n[]\n
// @lcpr case=end

// @lcpr case=start
// [5,1,2,4,3]\n[1,5,4,2,3]\n[[0,4],[4,2],[1,3],[1,4]]\n
// @lcpr case=end

 */

