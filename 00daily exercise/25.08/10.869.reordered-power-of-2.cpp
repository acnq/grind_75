/*
 * @lc app=leetcode.cn id=869 lang=cpp
 * @lcpr version=30204
 *
 * [869] 重新排序得到 2 的幂
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

#include <string>
// @lcpr-template-end
// @lc code=start

// II.
string countDigits(int n) {
    string cnt(10, 0);
    while(n) {
        cnt[n % 10]++;
        n /= 10;
    }
    return cnt;
}

unordered_set<string> powerOf2Digits;

int init = []() {
    for (int n = 1; n <= 1e9; n <<= 1) {
        powerOf2Digits.insert(countDigits(n));
    }
    return 0;
}();

class Solution {
    // I. 搜索回溯 + 位运算
    // 1. 获取全排列
    // 2. 判断这个数是否为2的幂
    // tc: O(m!) m = \floor(log_{10}n)+ 1, sc: O(m)

    // II. 预处理 + 哈希
    // 只要a/b的十进制表示中，0-9每个字符出现的次数相同，则a,b在此问题中等价
    // 有：2^{29} < 10^9 < 2^30, [1, 10^9]共有30个2的幂，
    // 我们对这30个数字预处理其十进制表示的字符数组，记录在长度为10的字符串哈希中
    // 对于数字n, 同样统计字符数组的出现次数，然后去哈希表查找，存在则满足，否则必然不满足
public:
    // I.
    // vector<int> vis;
    // bool isPowerOfTwo(int n) {
    //     return (n & (n - 1)) == 0;
    // }
    // bool backtrack(string& nums, int idx, int num) {
    //     if (idx == nums.length()) {
    //         return isPowerOfTwo(num);
    //     }
    //     for (int i = 0; i < nums.length(); i++) {
    //         // 无前导零
    //         if ((num == 0 && nums[i] == '0') || vis[i] || (i > 0 && !vis[i - 1] && nums[i] == nums[i - 1])) {
    //             continue;
    //         }
    //         vis[i] = 1;
    //         if (backtrack(nums, idx + 1, num * 10 + nums[i] - '0')) {
    //             return true;
    //         }
    //         vis[i] = 0;
    //     }
    //     return false;
    // }

    bool reorderedPowerOf2(int n) {
        // I.
        // string nums = to_string(n);
        // sort(nums.begin(), nums.end());
        // vis.resize(nums.length());
        // return backtrack(nums, 0, 0);

        // II.
        return powerOf2Digits.count(countDigits(n));
    }
};
// @lc code=end



/*
// @lcpr case=start
// 1\n
// @lcpr case=end

// @lcpr case=start
// 10\n
// @lcpr case=end

 */

