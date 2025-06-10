// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=9 lang=cpp
 * @lcpr version=30204
 *
 * [9] 回文数
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

#include <cmath> // need a pow;
// @lcpr-template-end
// @lc code=start
class Solution {
    // 感觉纯数学这个方法不行，因为有0的话总没法取出来
    // 进阶问能不能不用字符串，那数组不是一样的么/笑哭
    // 先用数组来讲叭
    // 
    // I. 反转一般数字
    // 和那道回文链表一样的思路
    // 那么我们怎么知道反转了一半呢？
    // 原始数字/10, 反转数字*10， 那么原数字 <= 反转数字，则一半已经到达
    // tc O(logN), sc O(1)
public:
    bool isPalindrome(int x) {
        // x = abs(x);
        // int len = 0, x_c = x;
        // while(x_c > 0) {
        //     x_c /= 10;
        //     len++;
        // }

        // while(x > 0) {
        //     if( x / 10 == 0) {
        //         return true;
        //     }
        //     int tail = x % 10;
        //     int head = x / (int) pow(10, (len - 1));
        //     if(tail != head) {
        //         return false;
        //     }
        //     x -= head * pow(10, (len - 1));
        //     x /= 10;
        //     len--;
        // }
        // return true;

        // if(x < 0) {
        //     return false;
        // } else if(x == 0) {
        //     return true;
        // } else {
        //     vector<int> lst;
        //     while(x > 0) {
        //         lst.push_back(x % 10);
        //         x /= 10;
        //     }
        //     int n = lst.size();
        //     for(int i = 0, j = n - 1; i < j; i++, j--) {
        //         if(lst[i] != lst[j]) {
        //             return false;
        //         }
        //     }
        //     return true;
        // }

        if(x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }
        int reverted = 0;
        while(x > reverted) {
            reverted = reverted * 10 + x % 10;
            x /= 10;
        }
        // 数字为奇数时，reverted会比x多一位，我们得去掉
        return x == reverted || x == (reverted / 10);
    }
};
// @lc code=end



/*
// @lcpr case=start
// 121\n
// @lcpr case=end

// @lcpr case=start
// -121\n
// @lcpr case=end

// @lcpr case=start
// 10\n
// @lcpr case=end

 */

