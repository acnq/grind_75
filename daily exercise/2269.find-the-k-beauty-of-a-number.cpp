// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=2269 lang=cpp
 * @lcpr version=30204
 *
 * [2269] 找到一个数字的 K 美丽值
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
    int divisorSubstrings(int num, int k) {
        string num_s = to_string(num); // num_s: num string 
        int res = 0; // returned beauty value;
        for (int i = 0; i < num_s.size() - k + 1; i++)
        {
            string snum_s = num_s.substr(i, k); // snum_s: subnum_string
            int snum = stoi(snum_s);
            if (snum != 0 && num % snum == 0)
            {
                res++;
            }
        }
        return res; 
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=divisorSubstrings
// paramTypes= ["number","number"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// 240\n2\n
// @lcpr case=end

// @lcpr case=start
// 430043\n2\n
// @lcpr case=end

 */

