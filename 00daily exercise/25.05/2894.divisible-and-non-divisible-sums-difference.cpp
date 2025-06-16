// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=2894 lang=cpp
 * @lcpr version=30204
 *
 * [2894] 分类求和并作差
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
    int differenceOfSums(int n, int m) {
        int sum = (1 + n) * n / 2;
        int num2 = 0;
        for(int i = 1; i <= n; i++) {
            if (i % m == 0)
            {
                num2 += i;
            }
        }
        return sum - 2 * num2;
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=differenceOfSums
// paramTypes= ["number","number"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// 10\n3\n
// @lcpr case=end

// @lcpr case=start
// 5\n6\n
// @lcpr case=end

// @lcpr case=start
// 5\n1\n
// @lcpr case=end

 */

