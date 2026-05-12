/*
 * @lc app=leetcode.cn id=788 lang=cpp
 * @lcpr version=30204
 *
 * [788] 旋转数字
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
class Solution {
    // I. 枚举每个数
    // 好数需要满足其他条件
    //      数中没有出现3,4,7；
    //      数中至少出现一次2/5/6/9 (因为旋转数字需要和原本不同)
    //      0/1/8没有要求
    // 枚举[1, n]每个正整数，判断是否满足上述要求即可
    // 
    // tc: O(n logn), sc: O(logn)
    // II. 数位DP
    // f(pos, bound, diff)为满足如下要求的好数的个数：
    // 过于刻奇，略
private:
    static constexpr int check[10] = {0, 0, 1, -1, -1, 1, 1, -1, 0, 1};
public:
    int rotatedDigits(int n) {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            string num = to_string(i);
            bool valid = true, diff = false;
            for (char ch: num) {
                if (check[ch - '0'] == -1) {
                    valid = false;
                } else if (check[ch - '0'] == 1) {
                    diff = true;
                }
            }
            if (valid && diff) {
                ans++;
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 10\n
// @lcpr case=end

 */

