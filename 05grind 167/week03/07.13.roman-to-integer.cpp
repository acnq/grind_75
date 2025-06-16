// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=13 lang=cpp
 * @lcpr version=30204
 *
 * [13] 罗马数字转整数
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
    // M...MM[CM] ---
    //       [D] C...C [XC] ---
    //       [CD] ---  [L] X...X [IX].
    //                 [XL] ---  [V] I...I
    //                           [IV].
    int romanToInt(string s) {
        // int res = 0;
        // int n = s.size();
        // for(int i = 0; i < n; i++) {
        //     if(s[i] == 'M') {
        //         res += 1000;
        //     }
        //     if(s[i] == 'D') {
        //         res += 500;
        //     }
        //     if(s[i] == 'C') {
        //         if(i < n && s[i + 1] == 'M') {
        //             res += 900;
        //             i++;
        //         } else if(i < n && s[i + 1] == 'D') {
        //             res += 400;
        //             i++;
        //         } else {
        //             res += 100;
        //         }
        //     }
            
        //     if(s[i] == 'L') {
        //         res += 50;
        //     }
        //     if(s[i] == 'X') {
        //         if(i < n && s[i + 1] == 'C') {
        //             res += 90;
        //             i++;
        //         } else if(i < n && s[i + 1] == 'L') {
        //             res += 40;
        //             i++;
        //         } else {
        //             res += 10;
        //         }
        //     }
            
        //     if(s[i] == 'V') {
        //         res += 5;
        //     }
        //     if(s[i] == 'I') {
        //         if(i < n && s[i + 1] == 'X') {
        //             res += 9;
        //             i++;
        //         } else if(i < n && s[i + 1] == 'V') {
        //             res += 4;
        //             i++;
        //         } else {
        //             res += 1;
        //         }
        //     }
        // }
        // return res;
        // 官方题解：
        // 同样适用累加的方案，但是仔细想想，为什么一定要把CM, CDe.t.c看做整体呢？
        // 我们保持这样的原则：若一个数字右侧的数比他大，那么此数字符号取反即可
        unordered_map<char, int> symbolValue = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000},
        };
        int ans = 0;
        int n = s.length();
        for(int i = 0; i < n; i++) {
            int value = symbolValue[s[i]];
            if (i < n - 1 && value < symbolValue[s[i + 1]]) {
                ans -= value;
            } else {
                ans += value;
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "III"\n
// @lcpr case=end

// @lcpr case=start
// "IV"\n
// @lcpr case=end

// @lcpr case=start
// "IX"\n
// @lcpr case=end

// @lcpr case=start
// "LVIII"\n
// @lcpr case=end

// @lcpr case=start
// "MCMXCIV"\n
// @lcpr case=end

 */

