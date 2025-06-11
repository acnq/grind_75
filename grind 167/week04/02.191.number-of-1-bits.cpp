/*
 * @lc app=leetcode.cn id=191 lang=cpp
 * @lcpr version=30204
 *
 * [191] 位1的个数
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
    // I. 循环检查
    // tc: O(k), k: int型二进制位

    // II. 位运算
    // n & (n - 1): 把n中最低位的1变为0的结果
    // 循环上述步骤，直到n=0
    // tc: O(logn)
public:
    int hammingWeight(int n) {
        // int ans = 0;
        // while (n > 0) {
        //     if(n % 2 == 1) {
        //         ans++;
        //     }
        //     n /= 2;
        // }
        // return ans;
        // 秒杀题，1’36“

        int ret = 0;
        while(n) {
            n &= n - 1;
            ret++;
        }
        return ret;

    }
};
// @lc code=end



/*
// @lcpr case=start
// 11\n
// @lcpr case=end

// @lcpr case=start
// 128\n
// @lcpr case=end

// @lcpr case=start
// 2147483645\n
// @lcpr case=end

 */

