/*
 * @lc app=leetcode.cn id=263 lang=cpp
 * @lcpr version=30204
 *
 * [263] 丑数
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
    bool isUgly(int n) {
        // O.
        // if (n <= 0) {
        //     return false;
        // }
        // while(n > 0) {
        //     while (n % 2 == 0) {
        //         n /= 2;
        //         cout << n <<endl;
        //     }
        //     while (n % 3 == 0) {
        //         n /= 3;
        //         cout << n << endl;
        //     }
        //     while (n % 5 == 0) {
        //         n /= 5;
        //         cout << n << endl;
        //     }
        //     if (n != 1) {
        //         return false;
        //     } else {
        //         return true;
        //     }
        // }
        // return true; 

        // I.
        if (n <= 0)
        {
            return false;
        }
        vector<int> factors = {2, 3, 5};
        for (int factor: factors) {
            while (n % factor == 0)
            {
                n /= factor;
            }
        }
        return n == 1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 6\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

// @lcpr case=start
// 14\n
// @lcpr case=end

 */

