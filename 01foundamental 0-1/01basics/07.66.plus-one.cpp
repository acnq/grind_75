// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=66 lang=cpp
 * @lcpr version=30204
 *
 * [66] 加一
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
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> res(digits.begin(), digits.end());
        int n = digits.size();
        if (digits[n - 1] != 9)
        {
            res[n - 1]++;
            return res;
        }
        int i = n - 1;
        while (i >= 0 && digits[i] == 9)
        {
            res[i] = 0;
            i--;
        }
        if (i != -1)
        {
            res[i]++;
            return res;
        } else {
            vector<int> ret(n + 1, 0);
            ret[0] = 1;
            return ret;
        }
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [4,3,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [9]\n
// @lcpr case=end

 */

