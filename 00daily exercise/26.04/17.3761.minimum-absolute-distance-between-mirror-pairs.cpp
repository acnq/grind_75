/*
 * @lc app=leetcode.cn id=3761 lang=cpp
 * @lcpr version=30204
 *
 * [3761] 镜像对之间最小绝对距离
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
    // I. 一次遍历
    // 维护哈希表prev, prev[v]:最近的满足reverse(nums[j]) = v的j
    // 令x = nums[i]
    // x在prev中出现过，说明存在j，s.t. reverse(nums[j]) = x, 
    //    因此(j, i)是一组镜像对，i - prev(x)即可
    // 随后计算reverse(x), prev[reverse(x)] = i, 表示当前下标和后续元素配对
    // 这样对于同个键，我们会始终保留最近下标
public:
    int minMirrorPairDistance(vector<int>& nums) {
        auto reverseNum = [](int x) {
            int y = 0;
            while (x > 0) {
                y = y * 10 + x % 10;
                x /= 10;
            }
            return y;
        };

        int n = nums.size();
        unordered_map<int, int> prev;
        int ans = n + 1;
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            if (prev.count(x)) {
                ans = min(ans, i - prev[x]);
            }
            prev[reverseNum(x)] = i;
        }

        return ans == n + 1 ? -1: ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [12,21,45,33,54]\n
// @lcpr case=end

// @lcpr case=start
// [120,21]\n
// @lcpr case=end

// @lcpr case=start
// [21,120]\n
// @lcpr case=end

 */

