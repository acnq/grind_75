// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=1925 lang=cpp
 * @lcpr version=30204
 *
 * [1925] 统计平方和三元组的数目
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

#include <cmath>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int countTriples(int n) {
        int cnt = 0;
        for(int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                float c = sqrt(i * i + j * j);
                if ((c <= n) && (c - int(c) < 1e-4)) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=countTriples
// paramTypes= ["number"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// 5\n
// @lcpr case=end

// @lcpr case=start
// 10\n
// @lcpr case=end

 */

