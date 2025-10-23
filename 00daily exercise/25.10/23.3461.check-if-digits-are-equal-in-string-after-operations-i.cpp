/*
 * @lc app=leetcode.cn id=3461 lang=cpp
 * @lcpr version=30204
 *
 * [3461] 判断操作后字符串中的数字是否相等 I
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
    bool hasSameDigits(string s) {
        int n = s.size();
        string tmp = s;
        while (tmp.size() > 2) {
            string next = "";
            for (int i = 0; i < tmp.size() - 1; i++) {
                int digit = ((tmp[i] - '0') + (tmp[i + 1] - '0')) % 10;
                char dc = '0' + digit;
                next.push_back(dc);
            }
            tmp = next;
        }
        if (tmp[0] == tmp[1]) {
            return true;
        } else {
            return false;
        }
    }
};
// @lc code=end



/*
// @lcpr case=start
// "3902"\n
// @lcpr case=end

// @lcpr case=start
// "34789"\n
// @lcpr case=end

 */

