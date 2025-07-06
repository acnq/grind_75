/*
 * @lc app=leetcode.cn id=1281 lang=cpp
 * @lcpr version=30204
 *
 * [1281] 整数的各位积和之差
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
    int subtractProductAndSum(int n) {
        int digitSum = 0, digitProd = 1;
        while(n > 0) {
            int tmp = n % 10;
            cout << tmp << endl;
            digitSum += tmp;
            digitProd *= tmp;
            n = n / 10;
        }
        return digitProd - digitSum;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 234\n
// @lcpr case=end

// @lcpr case=start
// 4421\n
// @lcpr case=end

 */

