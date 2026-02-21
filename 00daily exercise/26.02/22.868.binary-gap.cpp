// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=868 lang=cpp
 * @lcpr version=30204
 *
 * [868] 二进制间距
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
    // O. 我的：12min
    // I. 答案：不需要中间的容器，用last记录上一个1的位置即可
    // tc: O(logn), sc: O(1)
public:
    int binaryGap(int n) {
        // vector<int> res;
        // while (n > 0) {
        //     res.push_back(n % 2);
        //     n /= 2;
        // }
        // int last = -1, gap = 0, mgap = 0;
        // for (int i = 0; i < res.size(); i++) {
        //     if (res[i] == 1) {
        //         gap = last != -1 ? i - last : INT_MAX;
        //         mgap = gap == INT_MAX ? mgap : max(mgap, gap);
        //         last = i;
        //     }
        // }
        // return mgap;

        // I.
        int last = -1, ans = 0;
        for (int i = 0; n; i++) {
            if (n & 1) {
                
                if (last != -1) {
                    ans = max(ans, i - last);
                }
                last = i;
            } // 如果最低位不是1，则直接右移即可
            n >>= 1;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 22\n
// @lcpr case=end

// @lcpr case=start
// 8\n
// @lcpr case=end

// @lcpr case=start
// 5\n
// @lcpr case=end

 */

