// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=2078 lang=cpp
 * @lcpr version=30204
 *
 * [2078] 两栋颜色不同且距离最远的房子
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
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int le = colors[0];
        int ri = colors[n - 1];
        int res = 0;

        for (int i = n - 1; i > 0; i--) {
            if (colors[i] != le) {
                res = i - 0;
                break;
            }
        }

        for (int i = 0; i < n; i++) {
            if (colors[i] != ri) {
                res = max(res, n - 1 - i);
                break;
            }
        }

        return res;
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=maxDistance
// paramTypes= ["number[]"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// [1,1,1,6,1,1,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,8,3,8,3]\n
// @lcpr case=end

// @lcpr case=start
// [0,1]\n
// @lcpr case=end

// @lcpr case=start
// [6,6,6,6,6,6,6,6,6,19,19,6,6]\n
// @lcpr case=end
 */

