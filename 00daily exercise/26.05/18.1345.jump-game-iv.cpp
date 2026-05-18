/*
 * @lc app=leetcode.cn id=1345 lang=cpp
 * @lcpr version=30204
 *
 * [1345] 跳跃游戏 IV
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
    // 我们可以把数组抽象为一个无向图，可以跳转的位置都用无向边链接
    // 然后求首个元素到最后一个元素的最短路径即可，
    // 然而，注意到BFS的tc O(V + E), E可以达到n^2, 容易超时
    // 普通BFS, 每个边都要访问一次，但是对于无权图，其实不必要
    // 第一次访问某个子图，子图所有其他节点都会入队，而第二次访问到时
    // 所有其他节点或者在队中，或者已经被访问过了，所以不用再访问子图
    // 为此，我们首先找到所有值相同的子图，用哈希保存，
    // 一旦入队，将其清空，就不会访问边了。
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int, vector<int>> idxSameValue;
        for (int i = 0; i < arr.size(); i++) {
            idxSameValue[arr[i]].push_back(i);
        }

        unordered_set<int> visIdx;
        queue<pair<int, int>> q;
        q.emplace(0, 0);
        visIdx.emplace(0);
        while(!q.empty()) {
            auto [idx, step] = q.front();
            q.pop();
            if (idx == arr.size() - 1) {
                return step;
            }
            int v = arr[idx];
            step++;
            if (idxSameValue.count(v)) {
                for (auto& i: idxSameValue[v]) {
                    if (!visIdx.count(i)) {
                        visIdx.emplace(i);
                        q.emplace(i, step);
                    }
                }
                idxSameValue.erase(v);
            }
            if (idx + 1 < arr.size() && !visIdx.count(idx + 1)) {
                visIdx.emplace(idx + 1);
                q.emplace(idx + 1, step);
            }
            if (idx - 1 >= 0 && !visIdx.count(idx - 1)) {
                visIdx.emplace(idx - 1);
                q.emplace(idx - 1, step);
            }
        }
        return -1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [100,-23,-23,404,100,23,23,23,3,404]\n
// @lcpr case=end

// @lcpr case=start
// [7]\n
// @lcpr case=end

// @lcpr case=start
// [7,6,9,6,9,6,9,7]\n
// @lcpr case=end

 */

