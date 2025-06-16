// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=1041 lang=cpp
 * @lcpr version=30204
 *
 * [1041] 困于环中的机器人
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
    // 根据提示：仅考虑机器人最后的位置和朝向向量
    // 机器人会转圈的情况有且仅有两种：1. 回到原点 (显然)
    // 2. 不朝北
    // 第二种情况我们这么理解，我们把一次指令的结果看做位置向量和朝向向量的加法
    // 不朝北，说明最后朝向的方向有角度变化，设为a, a一定是n * \pi / 2,  
    // 自己想不清楚，看答案了：
    // 第一步之后的位置向量设为(x, y)
    // 分类，如果朝南，那么第二次位移就是(-x, -y), 直接回到原点并且转过180°，第三步开始循环
    // 如果朝东，说明右转了90°，如此一来，每串指令右转90°，那么可见第一次和第三次方向相反，
    // 第二次和第四次反向，最后都会回到原点，并且也朝北
public:
    vector<vector<int>> directs = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
    bool isRobotBounded(string instructions) {
        vector<int> pos(2, 0);
        int d = 0; 
        
        for(char instr: instructions) {
            switch (instr)
            {
            case 'G':
                pos[0] += directs[d][0];
                pos[1] += directs[d][1];
                break;
            case 'L':
                d = (d + 1) % 4;
                break;
            case 'R':
                d = (d - 1) >= 0 ? d - 1 : 3;
                break;
            default:
                break;
            }
        }
        if ((pos[0] == 0 && pos[1] == 0) || d != 0)
        {
            return true;
        }
        return false;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "GGLLGG"\n
// @lcpr case=end

// @lcpr case=start
// "GG"\n
// @lcpr case=end

// @lcpr case=start
// "GL"\n
// @lcpr case=end

// @lcpr case=start
// "GLRLGLLGLGRGLGL"\n
// @lcpr case=end

 */

