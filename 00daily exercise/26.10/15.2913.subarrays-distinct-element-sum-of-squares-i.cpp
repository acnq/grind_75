// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=2913 lang=cpp
 * @lcpr version=30204
 *
 * [2913] 子数组不同元素数目的平方和 I
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

#include <set>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int sumCounts(vector<int>& nums) {
        // 我的方法（21min)
        // int n = nums.size();
        // if (n == 1) {
        //     return 1;
        // }
        // int ret = 0;
        // // 不要在这里初始化set
        // for (int i = 0; i < n; i++) {
        //     for (int j = i; j < n; j++) {
        //         unordered_set<int> set; // 注意他初始化的位置
        //         for (int k = i; k <= j; k ++) {
        //             set.insert(nums[k]);
        //         }
        //         int cnt = set.size();
        //         ret += cnt * cnt;
        //     }
        // }
        // return ret;
    
        // 官方（少用一次循环）
        int n = nums.size(), res = 0;
        for (int i = 0; i < n; i++) {
            unordered_set<int> s;
            for (int j = i; j < n; j++) {
                s.insert(nums[j]);
                res += s.size() * s.size();
            }
        }
        return res;
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=sumCounts
// paramTypes= ["number[]"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// [1,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [2,2]\n
// @lcpr case=end

 */

