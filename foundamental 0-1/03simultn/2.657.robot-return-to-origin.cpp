// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=657 lang=cpp
 * @lcpr version=30204
 *
 * [657] 机器人能否返回原点
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
public:
    bool judgeCircle(string moves) {
        vector<int> pos(2, 0);
        for(char mv: moves) {
            switch (mv)
            {
            case 'U':
                pos[1]++;
                break;
            case 'D':
                pos[1]--;
                break;
            case 'R':
                pos[0]--;
                break;
            case 'L':
                pos[0]++;
                break;
            default:
                break;
            }
        }
        if (pos[0] == 0 && pos[1] == 0)
        {
            return true;
        } else {
            return false;
        }
        
    }
};
// @lc code=end



/*
// @lcpr case=start
// "UD"\n
// @lcpr case=end

// @lcpr case=start
// "LL"\n
// @lcpr case=end

// @lcpr case=start
// "RLUURDDDLU"\n
// @lcpr case=end

 */

