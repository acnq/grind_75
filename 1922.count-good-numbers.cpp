/*
 * @lc app=leetcode.cn id=1922 lang=cpp
 * @lcpr version=30204
 *
 * [1922] 统计好数字的数目
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
    // 偶数下标选项：0,2,4,6,8,5种选项
    // n-长度字符串有\floor{(n + 1) / 2}个偶下标
    // 技术下标选项：2,3,5,7,4种选项
    // n-长度字符串有\floor{n/2}个奇下标
    // 因此，好数字的总数为 
    // 5^{\floor{(n + 1) / 2}} * 4^{\floor{n/2}}
    // 可以使用快速幂进行计算
public:
    static constexpr int mod = 1000000007;
    // 快速幂求出x^y % mod
    int quickmul(int x, long long y){
        int ret = 1, mul = x;
        while (y > 0)
        {
            if (y % 2 == 1)
            {
                ret = (long long)ret * mul % mod;
            }
            mul = (long long) mul * mul % mod;
            y /= 2;
        }
        return ret;
    };
    int countGoodNumbers(long long n) {
        return (long long)quickmul(5, (n + 1) / 2) * quickmul(4, n / 2) % mod;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 1\n
// @lcpr case=end

// @lcpr case=start
// 4\n
// @lcpr case=end

// @lcpr case=start
// 50\n
// @lcpr case=end

 */

