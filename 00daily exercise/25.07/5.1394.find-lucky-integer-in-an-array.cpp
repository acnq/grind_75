/*
 * @lc app=leetcode.cn id=1394 lang=cpp
 * @lcpr version=30204
 *
 * [1394] 找出数组中的幸运数
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
    int findLucky(vector<int>& arr) {
        int ans = -1;
        unordered_map<int, int> stats;
        for(int i = 0; i < arr.size(); i++) {
            stats[arr[i]]++;
        }
        for(auto [k, v]: stats) {
            if (k == v) {
                ans = max(ans, k);
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,2,3,4]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,2,3,3,3]\n
// @lcpr case=end

// @lcpr case=start
// [2,2,2,3,3]\n
// @lcpr case=end

// @lcpr case=start
// [5]\n
// @lcpr case=end

// @lcpr case=start
// [7,7,7,7,7,7,7]\n
// @lcpr case=end

 */

