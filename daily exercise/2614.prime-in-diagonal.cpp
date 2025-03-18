/*
 * @lc app=leetcode.cn id=2614 lang=cpp
 * @lcpr version=30204
 *
 * [2614] 对角线上的质数
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
    bool isPrime(int n) {
        if(n == 1 || n == 0) { // 1 特殊情况
            return false;
        }
        if(n == 2 || n == 3) { // 2. 特殊情况
            return true;
        }
        int limit = sqrt(n);
        for (int i = 2; i <= limit; i++) // 别漏了“=”
        {
            if (n % i == 0) // "n % i" 而非“i % n"
            {
                return false;
            }
        }
        return true;
    }
    int diagonalPrime(vector<vector<int>>& nums) {
        int maxPrime = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (isPrime(nums[i][i]))
            {
                maxPrime = max(maxPrime, nums[i][i]);
            }
            if (isPrime(nums[i][nums.size() - i - 1]))
            {
                maxPrime = max(maxPrime, nums[i][nums.size() - i - 1]);
            }
        }
        return maxPrime;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,2,3],[5,6,7],[9,10,11]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,3],[5,17,7],[9,11,10]]\n
// @lcpr case=end

 */

