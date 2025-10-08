// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=2300 lang=cpp
 * @lcpr version=30204
 *
 * [2300] 咒语和药水的成功对数
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

#include <numeric> // iota
// @lcpr-template-end
// @lc code=start
class Solution {
    // I. 二分
    // tc: O(mlogm + nlogm), sc: O(logm)

    // II. 双指针
    // 对spells的*下标*按照其位置上的值升序排列，变为idx, 
    // 然后对potions降序排列
    // 初始化结果数组res, 长度为n
    // i, j双指针指向idx和potions的起始，i遍历idx, 对于指向的咒语spells[idx[i]]
    // 若有spells[idx[i]] * potions[j] >= success (1), 则
    // 任意i < k < n, 都有spells[idx[k]] * potions[j] >= sucess
    // 按定义：spells[idx[k]] >= spells[idx[i]]
    // 因此，每个i, j不断右移直到j不满足 (1)或者j >= m - 1
    // 移动结束后，res[idx[i]] = j
    // 随着i的增大，j的位置只曾不减，所以i右移的复杂度为O(n)
    // tc: O(n logn + m logm) sc； O(n + logn + logm)
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        // 我的写法
        // vector<int> res;
        // sort(potions.begin(), potions.end());
        // int m = potions.size();
        // for (int i = 0; i < spells.size(); i++) {
        //     double target = 1.0 * success / spells[i];
        //     int tar_pos = lower_bound(potions.begin(), potions.end(), target) - potions.begin();
        //     res.push_back(m - tar_pos);
        // }
        // return res;

        // I. 与吾同也
        // sort(potions.begin(), potions.end());
        // vector<int> res;
        // for (auto& i: spells) {
        //     long long t = (success + i - 1) / i - 1; // 
        //     res.push_back(potions.size() - (upper_bound(potions.begin(), potions.end(), t) - potions.begin()));
        // }

        // II.
        vector<int> res(spells.size());
        vector<int> idx(spells.size());
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b) {
            return spells[a] < spells[b];
        });
        sort(potions.begin(), potions.end(), [](int a, int b){
            return a > b;
        });
        for (int i = 0, j = 0; i < spells.size(); i++) {
            int p = idx[i];
            int v = spells[p];
            while (j < potions.size() && (long long)potions[j] * v >= success) {
                j++;
            }
            res[p] = j;
        }
        return res;
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=successfulPairs
// paramTypes= ["number[]","number[]","number"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// [5,1,3]\n[1,2,3,4,5]\n7\n
// @lcpr case=end

// @lcpr case=start
// [3,1,2]\n[8,5,8]\n16\n
// @lcpr case=end

 */

