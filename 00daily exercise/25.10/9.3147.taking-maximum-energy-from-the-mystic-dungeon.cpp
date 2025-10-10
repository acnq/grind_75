/*
 * @lc app=leetcode.cn id=3147 lang=cpp
 * @lcpr version=30204
 *
 * [3147] 从魔法师身上吸取的最大能量
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
    // 1. 逆序遍历
    // 如果我们枚举所有起点，需要枚举n次，但如果枚举所有终点
    // 假设终点为i, 路径[i, i - k, i - 2k, ......]
    // 所有前缀和即为可能吸收的能量，找到最大值返回即可
    // 这样tc：O(n) 因为每个元素刚好被遍历一次，sc：O(1)
    // 如果正着遍历，容易重复遍历到，比如(n, n + 2, ...)遍历完了
    // 遇到(n + 2, n + 4, ...)又遍历了，而反向的时候只要从n-k:n遍历
    // 终点，就不会重复
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size(), ans = INT_MIN;
        for (int i = n - k; i < n; i++) {
            int sum = 0;
            for (int j = i; j >= 0; j -= k) {
                sum += energy[j];
                ans = max(ans, sum);
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [5,2,-10,-5,1]\n3\n
// @lcpr case=end

// @lcpr case=start
// [-2,-3,-1]\n2\n
// @lcpr case=end

 */

