// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=2169 lang=cpp
 * @lcpr version=30204
 *
 * [2169] 得到 0 的操作数
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
    int countOperations(int num1, int num2) {
        // int tmp1 = num1, tmp2 = num2;
        // int cnt = 0;
        // while(tmp1 > 0 && tmp2 > 0) {
        //     if (tmp1 > tmp2) {
        //         tmp2 -= tmp1;
        //         cnt++;
        //     } else {
        //         tmp1 -= tmp2;
        //         cnt++;
        //     }
        // }
        // return cnt;
        // 标准写法用了辗转相除
        int res = 0;
        while (num1 && num2) {
            res += num1 / num2;
            num1 %= num2;
            swap(num1, num2);
        }
        return res;
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=countOperations
// paramTypes= ["number","number"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// 2\n3\n
// @lcpr case=end

// @lcpr case=start
// 10\n10\n
// @lcpr case=end

 */

