// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=3314 lang=cpp
 * @lcpr version=30204
 *
 * [3314] 构造最小位运算数组 I
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
    // I. 位运算
    // ans + 1: ans从低位到高位第一个0变为1，该0之前全部低位1变为0
    // ans | (ans + 1): ans低位到高位首个0变为1
    // 所以对于x二进制从低位到高位首个0之前的所有1，任取1个1变为0
    // 都可以得到一个ans, s.t. ans | (ans + 1) = x
    // 要求最小的ans, 找到每个x中第一个0的位置pos, 并将pos-1处的1变为0即可
    // 代码逻辑：d判断当前二进制位是否为0，假设当前位为1，ans = x - d (当前位置置0)
    //          然后d左移一位，判断下一位是否为0，如果是0，则没有更小的ans了
    // 只有x = 2, ans = -1, 因为2是指数，而且最低位0之前没有更低位1，导致无答案
    // tc: O(nlogm), sc: O(1)
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        for (int& x: nums) {
            int res = -1;
            int d = 1;
            while ((x & d) != 0) {
                res = x - d;
                d <<= 1;
            }
            x = res;
        }
        return nums;
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=minBitwiseArray
// paramTypes= ["number[]"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// [2,3,5,7]\n
// @lcpr case=end

// @lcpr case=start
// [11,13,31]\n
// @lcpr case=end

 */

