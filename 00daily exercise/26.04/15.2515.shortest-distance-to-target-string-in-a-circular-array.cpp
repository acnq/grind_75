// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=2515 lang=cpp
 * @lcpr version=30204
 *
 * [2515] 到目标字符串的最短距离
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
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int ans = n;
        for (int i = 0; i < n; i++) {
            if (words[i] == target) {
                int endIdx = i;
                int dist = abs(endIdx - startIndex);
                ans = min(ans, min(dist, n - dist)); // 这步看了眼答案，有点难
            }
        }
        return ans == n ? -1 : ans;
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=closestTarget
// paramTypes= ["string[]","string","number"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// ["hello","i","am","leetcode","hello"]\n"hello"\n1\n
// @lcpr case=end

// @lcpr case=start
// ["a","b","leetcode"]\n"leetcode"\n0\n
// @lcpr case=end

// @lcpr case=start
// ["i","eat","leetcode"]\n"ate"\n0\n
// @lcpr case=end

 */

