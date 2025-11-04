/*
 * @lc app=leetcode.cn id=2125 lang=cpp
 * @lcpr version=30204
 *
 * [2125] 银行中的激光束数量
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
    // I. 直接计数
    // 只需要统计每一行的安全设备数，记为cnt,
    // 以及上一个不为0的行安全设备个数，记为last,
    // cnt * last即为此行激光束个数，遍历所有行，维护cnt, last
    // 累加cnt * last，即可得到总数
public:
    int numberOfBeams(vector<string>& bank) {
        int last = 0, ans = 0;
        for (const string& line: bank) {
            int cnt = count_if(line.begin(), line.end(), [](char ch) {
                return ch == '1';
            });
            if (cnt != 0) {
                ans += last * cnt;
                last = cnt;
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["011001","000000","010100","001000"]\n
// @lcpr case=end

// @lcpr case=start
// ["000","111","000"]\n
// @lcpr case=end

 */

