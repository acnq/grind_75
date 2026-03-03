/*
 * @lc app=leetcode.cn id=1536 lang=cpp
 * @lcpr version=30204
 *
 * [1536] 排布二进制网格的最少交换次数
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
    // I. 贪心
    // 我们从上到下逐行确定，假设考虑到第i行，0:(i-1)均已经确定
    // 我们要求第i行满足条件为末尾连续0个数>=(n - i - 1), 
    // 需要考虑从[i:(n-1)]中选一行逐行交换到i, 我们贪心的选择离第i行最近的那一行即可
    // 理由：注意到越到后面约束越宽松，所以能交换到第i行的行，必然也能交换到[(i+1):(n-1)]的行上
    // 实现细节：为了避免每次判断当前行是否满足末尾连续0个数的限制条件时都要从后往前遍历
    // 我们先用O(n^2)的操作预处理每行最后一个1所在的位置，记为pos[i]
    // 这样我们从上到下，对于第i行，找到i:(n-1)行中是的pos[j] <= i成立的最近一行j即可，交换j-i次累加即可
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> pos(n, -1);
        for (int i = 0; i < n; i++) {
            for (int j = n - 1; j >= 0; --j) {
                if (grid[i][j] == 1) {
                    pos[i] = j;
                    break;
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            int k = -1;
            for (int j = i; j < n; j++) {
                if (pos[j] <= i) {
                    ans += j - i;
                    k = j;
                    break;
                }
            }
            if (~k) { // k != -1的写法
                for (int j = k; j > i; --j) {
                    swap(pos[j], pos[j - 1]); // 模拟把k一步步挪到i
                }
            } else {
                return -1;
            }
        }

        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[0,0,1],[1,1,0],[1,0,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,1,1,0],[0,1,1,0],[0,1,1,0],[0,1,1,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,0,0],[1,1,0],[1,1,1]]\n
// @lcpr case=end

 */

