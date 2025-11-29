// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=1262 lang=cpp
 * @lcpr version=30204
 *
 * [1262] 可被三整除的最大和
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

#include <numeric>
// @lcpr-template-end
// @lc code=start
class Solution {
    // I. 正向思维贪心
    // 我们首先把数组中的数字按照模3的余数分为abc3部分（分别余012）
    // 我们可以选取a中所有的数，而对于bc, 则需要根据情况
    // 假设我们在b中选取了cnt_b个，c中选取了cnt_c个，
    // 则这些数模3的余为
    // (cnt_b + 2 * cnt_c) mod 3 = (cnt_b - cnt_c) mod 3
    // 若上式为0，只需要cnt_b和cnt_c模3同余即可
    // cnt_b 至少为|b| - 2, 如若不然(i.e. cnt_b <= |b| - 3)
    // 可以从b再选取3个数字，使得cnt_b依然模3余1，同理
    // cnt_c至少为|c| - 2
    // 故cnt_b \in {|b| - 2, |b| - 1, |b|}
    //   cnt_c \in {|c| - 2, |c| - 1, |c|}
    // 我们最多枚举3 * 3 = 9中，贪心地从大到小选择，即可
    // tc: O(nlogn), sc: O(n)

    // II 逆向思维贪心
    // 枚举b/c分别丢弃了多少个数字
    // tot: nums所有元素和
    // tot % 3 == 0: 不需要丢弃任何数
    // tot % 3 == 1: 丢弃b中最小的1个数，或者丢弃c中最小的2个数
    // tot % 3 == 2: 丢弃b中最小的2个数，或者丢弃c中最小的1个数
    // 同样对b,c排序，选出b/c最小的1个或2个数
    // tc: O(nlogn), sc: O(n)

    // III. 动态规划
    // f(i, j): 前i个数字选取若干数，并且他们的和模3余j时
    //          这些数的和的最大值 (i >= 1, 0 <= j < 3)
    // f(i, j) = max{f(i - 1, j), f(i - 1, (j - nums[i]) mod 3) + nums[i]}
    // f(0, 0) = 0; f(0, 1) = f(0, 2) = -\infin(因为不合法，且我们需要最大)
    // 注意到(j - nums[i]) mod 3可能会出现负数，我们需要正向枚举
    // { f(i - 1, j) -> f(i, j)
    // { f(i - 1, j) + nums[i] -> f(i, (j + nums[i]) mod 3)
    // f(i, (j + nums[i - 1]) mod 3) = max{f(i - 1, (j + nums[i - 1]) mod 3), f(i - 1, j) + nums[i - 1]}
    // 注意到i一定是从i-1转移而来的，我们可以减少数组的一个维度
    // tc: O(n), sc: O(n) -> O(1)
public:
    int maxSumDivThree(vector<int>& nums) {
        // I.
        // let v[0] = a, v[1] = b, v[2] = c
        // vector<int> v[3];
        // for (int num: nums) {
        //     v[num % 3].push_back(num);
        // }
        // sort(v[1].begin(), v[1].end(), greater<int>());
        // sort(v[2].begin(), v[2].end(), greater<int>());

        // int ans = 0;
        // int lb = v[1].size(), lc = v[2].size();
        // for (int cntb = lb - 2; cntb <= lb; cntb++) {
        //     if (cntb >= 0) {
        //         for (int cntc = lc - 2; cntc <= lc; cntc++) {
        //             if (cntc >= 0 && (cntb - cntc) % 3 == 0) {
        //                 ans = max(ans, 
        //                     accumulate(v[1].begin(), v[1].begin() + cntb, 0) 
        //                 + accumulate(v[2].begin(), v[2].begin() + cntc, 0));
        //             }
        //         }
        //     }
        // }
        // return ans + accumulate(v[0].begin(), v[0].end(), 0);

        // II.
        // let v[0] = a, v[1] = b, v[2] = c
        // vector<int> v[3];
        // for (int num:nums) {
        //     v[num % 3].push_back(num);
        // }

        // sort(v[1].begin(), v[1].end(), greater<int>());
        // sort(v[2].begin(), v[2].end(), greater<int>());
        // int tot = accumulate(nums.begin(), nums.end(), 0);
        // int remove = INT_MAX;

        // if (tot % 3 == 0) {
        //     remove = 0;
        // } else if (tot % 3 == 1) {
        //     if (v[1].size() >= 1) {
        //         remove = min(remove, v[1].end()[-1]);
        //     }
        //     if (v[2].size() >= 2) {
        //         remove = min(remove, v[2].end()[-2] + v[2].end()[-1]);
        //     }
        // } else {
        //     if (v[1].size() >= 2) {
        //         remove = min(remove, v[1].end()[-2] + v[1].end()[-1]);
        //     }
        //     if (v[2].size() >= 1) {
        //         remove = min(remove, v[2].end()[-1]);
        //     }
        // }
        // return tot - remove;

        // III. a我的写法
        // int n = nums.size();
        // vector<vector<int>> f(n + 1, vector<int>(3, 0));
        // f[0][0] = 0;
        // f[0][1] = INT_MIN;
        // f[0][2] = INT_MIN;
        // for (int i = 1; i < n + 1; i++) {
        //     for (int j = 0; j < 3; j++) {
        //         f[i][(j + nums[i - 1] % 3) % 3] = max(f[i - 1][(j + nums[i - 1] % 3) % 3], f[i - 1][j] + nums[i - 1]);
        //     }
        // }
        // return f[n][0];
        // III. b 官方写法：
        vector<int> f = {0, INT_MIN, INT_MIN};
        for (int num: nums) {
            vector<int> g = f;
            for (int i = 0; i < 3; i++) {
                g[(i + num % 3) % 3] = max(g[(i + num % 3) % 3], f[i] + num);
            }
            f = move(g);
        }
        return f[0];
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=maxSumDivThree
// paramTypes= ["number[]"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// [3,6,5,1,8]\n
// @lcpr case=end

// @lcpr case=start
// [4]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,4]\n
// @lcpr case=end

 */

