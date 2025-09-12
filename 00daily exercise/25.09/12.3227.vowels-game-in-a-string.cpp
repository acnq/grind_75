/*
 * @lc app=leetcode.cn id=3227 lang=cpp
 * @lcpr version=30204
 *
 * [3227] 字符串元音游戏
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

#include <ranges> // 
// @lcpr-template-end
// @lc code=start
class Solution {
    // I. 贪心
    // 这题像是一个脑筋急转弯
    // 如果s中没有元音，则小红第一回合直接失败；
    // 如果s中至少有一个元音，小红总可以获胜
    // 1. 假设有奇数个，小红先手，直接移除整个，
    //    第二回合小明移除的必须非空，故小明直接失败
    // 2. 假设有偶数个，小红先手移除奇数个，第二回合小明移除偶数个后
    //    还有奇数个字符，接下来一回合夏红移除整个字符串直接获胜
    // 所以检查字符串是否有元音即可
    // tc: O(n); sc: O(1)
public:
    bool doesAliceWin(string s) {
        return std::any_of(s.begin(), s.end(), [](char c) {
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        });
    }
};
// @lc code=end



/*
// @lcpr case=start
// "leetcoder"\n
// @lcpr case=end

// @lcpr case=start
// "bbcd"\n
// @lcpr case=end

 */

