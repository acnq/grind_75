// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=3477 lang=cpp
 * @lcpr version=30204
 *
 * [3477] 水果成篮 II
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
    int numOfUplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int ans = 0;
        for(int fruit: fruits) {
            int i = 0;
            for(i = 0; i < baskets.size(); i++) {
                if (fruit <= baskets[i]) {
                    baskets[i] = 0;
                    break;
                }
            }
            if (i == baskets.size()) {
                ans++;
            }
        }
        return ans;
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=numOfUplacedFruits
// paramTypes= ["number[]","number[]"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// [4,2,5]\n[3,5,4]\n
// @lcpr case=end

// @lcpr case=start
// [3,6,1]\n[6,4,7]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,2,2]\n
// @lcpr case=end

// @lcpr case=start
// [3,3,3,1,2,1,1,2,3,3,4]\n
// @lcpr case=end

 */

