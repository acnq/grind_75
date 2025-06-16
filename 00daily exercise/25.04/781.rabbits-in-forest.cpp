/*
 * @lc app=leetcode.cn id=781 lang=cpp
 * @lcpr version=30204
 *
 * [781] 森林中的兔子
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
    // 相同颜色的兔子看到其他同色的兔子数必相同, 所以给出的答案相同
    //  反之亦然，answers不同的兔子颜色也不同
    
    // e.g. 13只兔子回答5，假设有一只1号色的兔子，则1号色必然有6只
    // 在假设还有一只2号色的兔子，同理2号色也应该有6只，因为要返回最少，
    // 假设1号色，2号色的共12只兔子都在13个回答的兔中，则还剩一个兔子回答5
    // 它只能是3号色的，而且3号色也至少有6只，故最少得兔子数为18

    // 一般地，x只兔子回答y, 至少有\ceiling(x/(y + 1))种不同的颜色，且每种至少y+1只
    // 故兔子至少为\ceiling(x/(y + 1)) * (y + 1)
    
    // 维护哈希表统计answers中不同元素出现的次数，套用公式即可
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> count;
        for(int y : answers) {
            count[y]++;
        }
        int ans = 0;
        for(auto& [y, x]: count) {
            ans += (x + y) / (y + 1) * (y + 1);
            // 注意\ceiling(x / d) = \floor((x + d - 1) / d)
            // 加上除数 + 1一定能实现向上取整
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [10,10,10]\n
// @lcpr case=end

 */

