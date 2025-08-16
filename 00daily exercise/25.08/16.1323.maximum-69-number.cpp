// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=1323 lang=cpp
 * @lcpr version=30204
 *
 * [1323] 6 和 9 组成的最大数字
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
    int maximum69Number (int num) {
        vector<int> digits;
        while (num > 0) {
            digits.push_back(num % 10);
            num /= 10;
        }
        reverse(digits.begin(), digits.end());
        int ans = 0;
        bool isfirst = true; 
        for (int digit: digits) {
            if (digit == 6 && isfirst) {
                isfirst = false;
                ans *= 10;
                ans += 9;
            } else {                
                ans *= 10;
                ans += digit;
            }
            
        }
        return ans;
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=maximum69Number
// paramTypes= ["number"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// 9669\n
// @lcpr case=end

// @lcpr case=start
// 9996\n
// @lcpr case=end

// @lcpr case=start
// 9999\n
// @lcpr case=end

 */

