/*
 * @lc app=leetcode.cn id=2138 lang=cpp
 * @lcpr version=30204
 *
 * [2138] 将字符串拆分为若干长度为 k 的组
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
    // I. 确定初始下标
    // 第i组对应的下标范围为[k * i, min((k + 1) * i, n) - 1]
    // res保存每组划分后的字符串，cur维护当前下标，当cur合法时
    // res.push_back(s[(k * i):(min((k + 1) * i, n)) - 1])
    // 最后一组加上fill
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> res; 
        int n = s.size();
        int cur = 0;
        while (cur < n)
        {
            res.push_back(s.substr(cur, k));
            cur += k;
        }
        res.back() += string(k - res.back().length(), fill);
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "abcdefghi"\n3\n"x"\n
// @lcpr case=end

// @lcpr case=start
// "abcdefghij"\n3\n"x"\n
// @lcpr case=end

 */

