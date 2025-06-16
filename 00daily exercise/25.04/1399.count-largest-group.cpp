// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=1399 lang=cpp
 * @lcpr version=30204
 *
 * [1399] 统计最大组的数目
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
    int digit_sum(int n) {
        int sum = 0;
        while (n != 0)
        {
            sum += n % 10;
            n = n / 10; 
        }
        return sum;
    }
    int countLargestGroup(int n) {
        unordered_map<int, int> stat;
        int res = 0, 
        int max_val = 0; // max_i = 0;
        for(int i = 1; i <= n; i++) {
            stat[digit_sum(i)]++;
        } 
        // 根据提示
        // unordered_map<int, int> stat2;
        for(auto& [key, value] : stat) {
            max_val = max(max_val, value);
        }
        for(auto& [key, value]: stat) {
            if (value == max_val)
            {
                res++;
            }
            
        }
        return res;
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=countLargestGroup
// paramTypes= ["number"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// 13\n
// @lcpr case=end

// @lcpr case=start
// 2\n
// @lcpr case=end

// @lcpr case=start
// 15\n
// @lcpr case=end

// @lcpr case=start
// 24\n
// @lcpr case=end

 */

