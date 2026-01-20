/*
 * @lc app=leetcode.cn id=3315 lang=cpp
 * @lcpr version=30204
 *
 * [3315] 构造最小位运算数组 II
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
    // O. 和T3314的区别在于nums[i]可能的范围更大了
    // 但是首先，T3314的解法（至少C++）不会超时
    // 下面的解法是渴望复杂度<O(nlogm)的方案的
    // I. lowbit
    // 按照T3314的解法，我们知道目标是求得num:nums中最右边的0右侧1置0的数字
    // e.g. 101111 => 100111
    // 如何把这个过程O(1)完成呢？
    // 我们首先找到“最右侧的0”，这个过程我们首先将num取反，（对于例子，我们得到010000）
    // 然后找到~num最右侧的1，其他置0（这个操作交lowbit,这一步得到了lowbit(~num)) 
    // (对于例子，还是10000, 但是注意其他最右侧0之右还有0的数，会不一样)
    // 然后我们取“最右侧右边的那位”，lowbit(~num)右移一位（对于例子，的1000）
    // 最后我们把num和右移之后的结果res取异或就可以了，后者最右侧1右侧的位和num相同被置0
    // 此位右侧，res都是0，num都是1，得1和num一致，此位左侧，res也都是0，num若是0得0,1得1，也不变
    // (对于例子，101111 \circplus 1000 = 100111)
    // 计算lowbit两种做法：
    // 1. lowbit(i) = (i & -i)
    // 2. lowbit(~nums) = (nums + 1) & (~nums)
    // 首先，将nums=~i带入，注意到负数的二进制表示-i = (~nums) + 1
    //      可得到两者等价
    // 然后，我们证明1. i如果一串0结尾（假设n个，那么右边第n+1位为1），
    // 取反之后，还是n个1结尾，右起第n+1位为0，+1则第n+1位为1，右侧n个又变回0
    // 考虑这二者的＆，显然右起n+2位之外因为有取反，总是有一个为0，和之后也是0
    // 右起第n+1位均为1，得1，右起n个则因为i是一串0，也得0，得证。
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        // 1.
        // for (int& x: nums) {
        //     if (x == 2) {
        //         x = -1; // 最右侧的0就在最右侧，再右侧没有了
        //     } else {
        //         int t = ~x;
        //         x ^= (t & -t) >> 1;
        //     }
        // }
        // return nums;
        // 2.
        for (int& x: nums) {
            if (x == 2) {
                x = -1;
            } else {
                x ^= ((x + 1) & ~x) >> 1;
            }
        }
        return nums;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,3,5,7]\n
// @lcpr case=end

// @lcpr case=start
// [11,13,31]\n
// @lcpr case=end

 */

