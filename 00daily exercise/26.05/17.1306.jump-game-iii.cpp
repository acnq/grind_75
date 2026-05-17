/*
 * @lc app=leetcode.cn id=1306 lang=cpp
 * @lcpr version=30204
 *
 * [1306] 跳跃游戏 III
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
    // 直接搜索从start开始能够到达的位置，如果某个位置对应0，则返回True
    // 具体而言，start入队，每次搜索取出队首u, 
    // 记录到达的位置u + arr[u], u - arr[u], 如果
    // 在范围[0, len(arr))内，且没有被搜索，入队尾
    // 在所有都被搜索且没有找到0，返回False
    // tc: O(n), sc: O(n)
public:
    bool canReach(vector<int>& arr, int start) {
        if (arr[start] == 0) {
            return true;
        }

        int n = arr.size();
        vector<bool> used(n);
        queue<int> q;
        q.push(start);
        used[start] = true;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            if (u + arr[u] < n && !used[u + arr[u]]) {
                if (arr[u + arr[u]] == 0) {
                    return true;
                }
                q.push(u + arr[u]);
                used[u + arr[u]] = true;
            }
            if (u - arr[u] > 0 && !used[u -arr[u]]) {
                if (arr[u - arr[u]] == 0) {
                    return true;
                }
                q.push(u - arr[u]);
                used[u - arr[u]] = true;
            }
        }
        return false;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [4,2,3,0,3,1,2]\n5\n
// @lcpr case=end

// @lcpr case=start
// [4,2,3,0,3,1,2]\n0\n
// @lcpr case=end

// @lcpr case=start
// [3,0,2,1,2]\n2\n
// @lcpr case=end

 */

