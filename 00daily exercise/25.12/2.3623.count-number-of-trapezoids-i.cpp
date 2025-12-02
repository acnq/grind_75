// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=3623 lang=cpp
 * @lcpr version=30204
 *
 * [3623] 统计梯形的数目 I
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
    // 哈希：
    // 我们只需要统计不同高度的y值有多少个即可
    // (因为水平梯形按照定义只需要和x轴平行即可)
    // 假设高度为y的点有p_y个，那么这个高度上的点能够组成的边有
    // p_y(p_y - 1) / 2条，分别在两个不同高度上选择一条边即可组成
    // tc: O(n), sc: O(n)
public:
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int, int> pointNum;
        const int mod = 1e9 + 7;
        long long ans = 0, sum = 0;
        for (auto& point: points) {
            pointNum[point[1]]++;
        }
        for (auto& [_, pNum]: pointNum) {
            long long edge = (long long)pNum * (pNum - 1) / 2;
            ans += edge * sum;
            sum += edge;
        }
        return ans % mod;
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=countTrapezoids
// paramTypes= ["number[][]"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// [[1,0],[2,0],[3,0],[2,2],[3,2]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,0],[1,0],[0,1],[2,1]]\n
// @lcpr case=end

 */

