// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=2597 lang=cpp
 * @lcpr version=30204
 *
 * [2597] 美丽子集的数目
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
#include <map>
#include <cmath>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    // void dfs(int i, vector<int> nums, int k, unordered_map<int, int>& cnt, int& ans) {
    //     if (i == nums.size())
    //     {
    //         ans++;
    //         return;
    //     }
    //     // 不选择nums[i]
    //     dfs(i + 1, nums, k, cnt, ans);

    //     // 选择 nums[i], 前提是不能有nums[i] - k 或者 nums[i] + k
    //     if (cnt[nums[i] - k] == 0 && cnt[nums[i] + k] == 0)
    //     {
    //         cnt[nums[i]]++; // 选取并记录次数
    //         dfs(i + 1, nums, k, cnt, ans); // 递归探索下一步
    //         cnt[nums[i]]--; // 回溯，但先撤销选择
    //     }
    //     return;
    // };

    int beautifulSubsets(vector<int>& nums, int k) {

        // 这个回溯方案内存不够
        // int ans = 0;
        // unordered_map<int, int> cnt;
        // dfs(0, nums, k, cnt, ans);
        // return ans - 1; // 去除空集

        // 考虑模k同余相同的分组，不同组内选择肯定不会相差k
        // 只需要考虑组内选择方法既可以了
        // arr := nums 模k相同的某一数组，去重
        // cnt[i]: arr[i] 出现的次数
        // 只有与arr[i] 相邻的数可能与arr[i] 相差k
        // f(i, 0) := arr[i] 不加入子集
        // f(i, 1) := arr[i] 加入子集
        // 不加入： f(i, 0) = f(i - 1, 0) + f(i - 1, 1)
        // 加入：arr[i-1] - arr[i] 不能为k
        //     : 因为nums可能有多个数字有值arr[i]，至少选择其中一个有2^(cnt[i]) - 1个方法
        //     : f(i, 1) = { (f(i - 1, 0) + f(i - 1, 1)) * (2^(cnt[i]) - 1); arr[i] - arr[i - 1] != k
        //     :         = { f(i - 1, 0) * (2^(cnt[i]) - 1), arr[i] - arr[i - 1] = k
        // f(0, 0) = 1,
        // f(0, 1) = 2^cnt[0] - 1;
        // ans = f(n - 1, 0) + f(n - 1, 1)
        unordered_map<int, map<int, int>> groups;
        for (int i = 0; i < nums.size(); i++)
        {
            int a = nums[i];
            groups[a % k][a]++;
        }
        // 对固定余r(模k), cnt[i] = groups[r][i]
        int ans = 1;
        for (int ii = 0; ii < groups.size(); ii++) // 对于每个余r内部
        {
            map<int, int> g = groups[ii]; 
            // 必须是map以实现排序，key表示不重复元素，value表示nums中key重复的次数
            // arr = {key}, cnt = {value}

            int m = g.size(); // m = arr.size()
            vector<vector<int>> f(m, vector<int>(2, 0));
            f[0][0] = 1;
            f[0][1] = pow(2, g.begin()->second) - 1;
            int i = 1; 
            for (auto it = next(g.begin()); it != g.end(); it++, i++)
            {
                f[i][0] = f[i - 1][0] + f[i - 1][1];
                if (it->first - prev(it)->first == k)
                {
                    f[i][1] = f[i - 1][0] * (pow(2, it->second) - 1);
                } else {
                    f[i][1] = (f[i - 1][0] + f[i - 1][1]) * (pow(2, it->second) - 1);
                }
            }
            ans *= f[m - 1][0] + f[m - 1][1]; //不同的余r之间用乘法法则即可
        }
        return ans - 1; // 去除空集
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=beutifulSubsets
// paramTypes= ["number[]","number"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// [10,4,5, 7, 2, 1]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1]\n1\n
// @lcpr case=end

 */

