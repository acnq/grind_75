/*
 * @lc app=leetcode.cn id=2553 lang=cpp
 * @lcpr version=30204
 *
 * [2553] 分割数组中数字的数位
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
public:
    vector<int> split(int num) {
        vector<int> res;
        while (num > 0) {
            int d = num % 10;
            res.push_back(d);
            num = num / 10;
        }
        return res;
    }
    vector<int> separateDigits(vector<int>& nums) {
        // vector<int> res;
        // for (int num: nums) {
        //     if (num < 10) {
        //         res.push_back(num);
        //     } else {
        //         vector<int> spltd = split(num);
        //         reverse(spltd.begin(), spltd.end());
        //         for (int i = 0; i < spltd.size(); i++) {
        //             res.push_back(spltd[i]);
        //         }
        //     }
        // }
        // return res;

        // 标准答案：我们直接逆序遍历就可以避免reverse
        vector<int> res;
        for (auto x: nums) {
            vector<int> tmp;
            while (x > 0) {
                tmp.push_back(x % 10);
                x /= 10;
            }
            for (int i = tmp.size() - 1; i >= 0; i--) {
                res.push_back(tmp[i]);
            }
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [13,25,83,77]\n
// @lcpr case=end

// @lcpr case=start
// [7,1,3,9]\n
// @lcpr case=end

 */

