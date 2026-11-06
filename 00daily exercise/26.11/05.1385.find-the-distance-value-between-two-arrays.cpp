// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=1385 lang=cpp
 * @lcpr version=30204
 *
 * [1385] 两个数组间的距离值
 */


// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <cmath>
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
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        // O: 直接法 tc: O(n * m), sc: O(1)
        // int cnt = 0;
        // for (int i = 0; i < arr1.size(); i++) {
        //     bool ok = true; // 这个地方卡了，ok不能放在循环最外层
        //     for (int j = 0; j < arr2.size(); j++) {
        //         int diff = abs(arr1[i] - arr2[j]);
        //         if (diff <= d) {
        //             ok = false;
        //             break;
        //         }
        //     }
        //     if (ok) {
        //         cnt++;
        //     }
        // }
        // return cnt;

        // II. 二分查找: tc: O((n + m)logm), sc: O(1)
        // 找到大于等于x_i的第一个y_j和小于x的第一个y_j即可
        // 我们对arr2排序，对每个x_i, arr2中二分查找y_i即可
        sort(arr2.begin(), arr2.end());
        int cnt = 0;
        for (auto& x: arr1) {
            unsigned p = lower_bound(arr2.begin(), arr2.end(), x) - arr2.begin();
            bool ok = true;
            if (p < arr2.size()) {
                ok &= (arr2[p] - x > d);
            }
            if (p - 1 >= 0 && p - 1 <= arr2.size()) {
                ok &= (x - arr2[p - 1] > d);
            }
            cnt += ok;
        }
        return cnt;
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=findTheDistanceValue
// paramTypes= ["number[]","number[]","number"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// [4,5,8]\n[10,9,1,8]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,4,2,3]\n[-4,-3,6,10,20,30]\n3\n
// @lcpr case=end

// @lcpr case=start
// [2,1,100,3]\n[-5,-2,10,-3,7]\n6\n
// @lcpr case=end

 */

