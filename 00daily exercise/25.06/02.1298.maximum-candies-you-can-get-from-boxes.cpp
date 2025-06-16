/*
 * @lc app=leetcode.cn id=1298 lang=cpp
 * @lcpr version=30204
 *
 * [1298] 你能从盒子里获得的最大糖果数
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
    // BFS + 队列
    // 获得糖果 <- 获得盒子+获得对应的钥匙
    // 用数组hasbox表示目前拥有的盒子，canopen表示目前的钥匙
    // 初始：拥有initialBoxes中的盒子，能打开其中status的值为0对应的盒子

public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n = status.size();
        vector<bool> canopen(n), hasbox(n), used(n);
        for (int i = 0; i < n; i++)
        {
            canopen[i] = (status[i] == 1);
        }
        queue<int> q;
        int ans = 0;
        for(int box: initialBoxes) {
            hasbox[box] = true;
            if (canopen[box])
            {
                q.push(box);
                used[box] = true;
                ans += candies[box];
            }
        }

        while (!q.empty())
        {
            int bigbox = q.front();
            q.pop();
            for(int key: keys[bigbox]) {
                canopen[key] = true;
                if (!used[key] && hasbox[key])
                {
                    q.push(key);
                    used[key] = true;
                    ans += candies[key];
                }
            }
            for(int box: containedBoxes[bigbox]) {
                hasbox[box] = true;
                if (!used[box] && canopen[box])
                {
                    q.push(box);
                    used[box] = true;
                    ans += candies[box];
                }
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,0,1,0]\n[7,5,4,100]\n[[],[],[1],[]]\n[[1,2],[3],[],[]]\n[0]\n
// @lcpr case=end

// @lcpr case=start
// [1,0,0,0,0,0]\n[1,1,1,1,1,1]\n[[1,2,3,4,5],[],[],[],[],[]]\n[[1,2,3,4,5],[],[],[],[],[]]\n[0]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,1]\n[100,1,100]\n[[],[0,2],[]]\n[[],[],[]]\n[1]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n[100]\n[[]]\n[[]]\n[]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,1]\n[2,3,2]\n[[],[],[]]\n[[],[],[]]\n[2,1,0]\n
// @lcpr case=end

 */

