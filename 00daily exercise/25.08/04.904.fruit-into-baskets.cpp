/*
 * @lc app=leetcode.cn id=904 lang=cpp
 * @lcpr version=30204
 *
 * [904] 水果成篮
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
    // I. 滑动窗口
    // 用哈希表存储窗口内的数字（种类）和每个数字出现的次数
    // 每次right移动，将fruits[right]加入哈希表。
    // 如果哈希表中出现超过两个键值对（不满足要求了），就要移动left
    // 并且将fruits[left]从哈希表中移除，直到满足要求为止
    // 注意哈希表不会把值为0的键值对自动移除，所以要额外检查处理一下
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int, int> cnt;

        int left = 0, ans = 0;
        for (int right = 0; right < n; right++) {
            cnt[fruits[right]]++;
            while (cnt.size() > 2) {
                auto it = cnt.find(fruits[left]);
                it->second--;
                if (it->second == 0) {
                    cnt.erase(it);
                }
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [0,1,2,2]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,2,2]\n
// @lcpr case=end

// @lcpr case=start
// [3,3,3,1,2,1,1,2,3,3,4]\n
// @lcpr case=end

 */

