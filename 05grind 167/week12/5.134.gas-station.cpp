/*
 * @lc app=leetcode.cn id=134 lang=cpp
 * @lcpr version=30204
 *
 * [134] 加油站
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
    // 从头到尾遍历每个加油站，设为当前加油站为起点，判断能否行驶一周
    // 假设当前站x，假设每经过一个加油站就加一次油，最后可以到达的加油站为y
    // 有 \sum_{i=x}^y gas[i] < \sum_{i=x}^y cost[i]
    // \sum_{i=x}^j gas[i] >= \sum_{i=x}^j cost[i] \forall j \in [x, y)
    // 考虑任意一个位于x,y之间的加油站（包括x/y本身）z, 判断从此出发能否到达y, 可以有不等式
    // \sum_{i=z}^y gas[i] = \sum_{i=x}^y gas[i] - \sum_{i=x}^{z-1}gas[i]
    //                     < \sum_{i=x}^y cost[i] - \sum_{i=x}^{z-1}gas[i]
    //                     < \sum_{i=x}^y cost[i] - \sum_{i=x}^{z-1}cost[i]
    //                     = \sum_{i=z}^y cost[i]
    // 也就是说，如果x不能到达y, 那么从x,y之间任何一个加油站出发，都无法到达y
    // 所以首先检查第0个加油站，如果不能环绕一周，那么就从第一个无法到达的加油站开始检查
    // tc: O(n); sc: O(1)
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int i = 0;
        while (i < n)
        {
            int gasSum = 0, costSum = 0;
            int cnt = 0;
            while (cnt < n)
            {
                int j = (i + cnt) % n;
                gasSum += gas[j];
                costSum += cost[j];
                if (costSum > gasSum)
                {
                    break;
                }
                cnt++;
            }
            if (cnt == n)
            {
                return i;
            } else {
                i = i + cnt + 1;
            }
        }
        return -1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5]\n[3,4,5,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [2,3,4]\n[3,4,3]\n
// @lcpr case=end

 */

