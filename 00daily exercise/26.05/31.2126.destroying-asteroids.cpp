/*
 * @lc app=leetcode.cn id=2126 lang=cpp
 * @lcpr version=30204
 *
 * [2126] 摧毁小行星
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
    // 显然，在两个不同质量小行星的场景下，优先摧毁较小的能摧毁更多
    // 那么我们只要对数组升序排列之后模拟并维护行星碰撞后的质量mass即可
    // tc: O(n), sc: O(logn) (排序的栈空间)
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        long long mass1 = mass;
        for (const int asteroids: asteroids) {
            // 顺序遍历
            if (mass1 < asteroids) {
                return false;
            }
            mass1 += asteroids;
        }
        return true; // 遍历完毕则成功摧毁所有
    }
};
// @lc code=end



/*
// @lcpr case=start
// 10\n[3,9,19,5,21]\n
// @lcpr case=end

// @lcpr case=start
// 5\n[4,9,23,4]\n
// @lcpr case=end

 */

