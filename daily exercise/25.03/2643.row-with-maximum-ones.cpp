/*
 * @lc app=leetcode.cn id=2643 lang=cpp
 * @lcpr version=30204
 *
 * [2643] 一最多的行
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
    // 本质上也是秒杀题，一开始思考有没有比O(mn)更小的算法，
    // 害怕下文的算法会超时
    // 后来想了想不可能有比O(mn)小的算法，因为每行每个元素都得考虑
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int max1 = 0;
        int max1idx = 0; // 不要写成-1， 不然mat每个元素都是0会返回-1，不合题意
        for (int i = 0; i < m; i++)
        {
            int ones = 0;
            for (int j = 0; j < n; j++)
            {    
                if (mat[i][j] == 1)
                {
                    ones ++;
                }
            }
            if (ones > max1)
            {
                max1 = ones;
                max1idx = i;
            }
            
        }
        return {max1idx, max1};
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[0,1],[1,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,0,0],[0,1,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,0],[1,1],[0,0]]\n
// @lcpr case=end

 */

