// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=78 lang=cpp
 * @lcpr version=30204
 *
 * [78] 子集
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

#include <cmath> // pow?
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    vector<int> tobin(int i) {
        vector<int> res;
        while(i > 0) {
            if(i % 2) {
                res.push_back(1);
            } else {
                res.push_back(0);
            }
            i = i / 2;
        }
        // reverse(res.begin(), res.end());
        return res;
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        for(int i = 0; i < (int)pow(2, n); i++) {
            // 获取i的二进制序列
            vector<int> bini = tobin(i);
            vector<int> subset;
            for(int j = 0; j < bini.size(); j++) {
                if(bini[j] == 1) {
                    subset.push_back(nums[j]);
                }
            }
            res.push_back(subset);
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n
// @lcpr case=end

 */

