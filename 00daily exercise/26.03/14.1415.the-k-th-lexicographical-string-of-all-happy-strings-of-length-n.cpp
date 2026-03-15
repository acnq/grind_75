/*
 * @lc app=leetcode.cn id=1415 lang=cpp
 * @lcpr version=30204
 *
 * [1415] 长度为 n 的开心字符串中字典序第 k 小的字符串
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
    // I. 数学
    // 显然,任意开心字符串,首个元素有3种填法,后续都是2种
    // 所以长度为n的开心字符串数量为3*2^{n-1}, k > 3 * 2^{n - 1},
    // 直接返回空即可
    // 若k小于此,从首个元素开始讨论,'a'在[1, 2^{n-1}]之间,
    // 类似的可以确定
public:
    string getHappyString(int n, int k) {
        vector<char> chs = {'a', 'b', 'c'};
        string res;
        if (k > 3 * (1 << (n - 1))) {
            return res;
        }
        for (int i = 0; i < n; i++) {
            int count = 1 << (n - i - 1);
            for (char c: chs) {
                if (!res.empty() && res.back() == c) {
                    continue;
                }
                if (k <= count) {
                    res.push_back(c);
                    break;
                }
                k -= count;
            }
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 1\n3\n
// @lcpr case=end

// @lcpr case=start
// 1\n4\n
// @lcpr case=end

// @lcpr case=start
// 3\n9\n
// @lcpr case=end

// @lcpr case=start
// 2\n7\n
// @lcpr case=end

// @lcpr case=start
// 10\n100\n
// @lcpr case=end

 */

