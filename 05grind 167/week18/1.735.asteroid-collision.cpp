/*
 * @lc app=leetcode.cn id=735 lang=cpp
 * @lcpr version=30204
 *
 * [735] 小行星碰撞
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
    // I. 栈模拟
    // 从左到右遍历行星aster: asteroids, 使用alive记录行星aster还是否存在
    // 行星aster存在且aster < 0, 栈顶元素非空且>0, 说明移动方向相对，如果栈顶元素绝对值更大
    // 则行星aster爆炸，将alive设为false, 
    // 如果栈顶元素<=-aster, 则栈顶元素表示的行星爆炸，出栈。
    // 重复以上判断直到不满足条件，如果最后alive为真，说明aster不会爆炸，aster入栈
    // 我们用边长数组模拟栈。
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;
        for (auto aster: asteroids) {
            bool alive = true;
            while (alive && aster < 0 && !st.empty() && st.back() > 0)
            {
                alive = st.back() < -aster; // aster是否存在
                if (st.back() <= -aster)
                {
                    // 栈顶行星爆炸；
                    st.pop_back();
                }
            }
            if (alive)
            {
                st.push_back(aster);
            }
        }
        return st;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [5,10,-5]\n
// @lcpr case=end

// @lcpr case=start
// [8,-8]\n
// @lcpr case=end

// @lcpr case=start
// [10,2,-5]\n
// @lcpr case=end

 */

