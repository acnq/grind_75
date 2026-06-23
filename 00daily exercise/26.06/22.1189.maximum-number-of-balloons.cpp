/*
 * @lc app=leetcode.cn id=1189 lang=cpp
 * @lcpr version=30204
 *
 * [1189] “气球” 的最大数量
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
    // I.统计
    // 我们统计每个所需字符出现的次数，其中l,o除以2
    // 然后计算这些字符最小的出现次数即可
public:
    int maxNumberOfBalloons(string text) {
        vector<int> cnt(5);
        for (auto& ch: text) {
            if (ch == 'b') {
                cnt[0]++;
            } else if (ch == 'a') {
                cnt[1]++;
            } else if (ch == 'l') {
                cnt[2]++;
            } else if (ch == 'o') {
                cnt[3]++;
            } else if (ch == 'n') {
                cnt[4]++;
            }
        }
        cnt[2] /= 2;
        cnt[3] /= 2;
        return *min_element(cnt.begin(), cnt.end());
    }
};
// @lc code=end



/*
// @lcpr case=start
// "nlaebolko"\n
// @lcpr case=end

// @lcpr case=start
// "loonbalxballpoon"\n
// @lcpr case=end

// @lcpr case=start
// "leetcode"\n
// @lcpr case=end

 */

