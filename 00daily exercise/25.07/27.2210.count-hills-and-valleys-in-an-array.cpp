// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=2210 lang=cpp
 * @lcpr version=30204
 *
 * [2210] 统计数组中峰和谷的数量
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
    int countHillValley(vector<int>& nums) {
        int n = nums.size();
        int cvcount = 0;
        for (int i = 1; i < n - 1; i++) {
            if (nums[i] == nums[i - 1]) {
                continue; // 看了眼提示，发现了这个方法很有效的去重了
            }
            int j = i, k = i;
            while(j >= 0 && nums[j] == nums[i]) {
                j--;
            }
            while(k < n && nums[k] == nums[i]){
                k++;
            }
            if (j < 0 || k >= n) {
                break;
            } else {
                if (nums[j] > nums[i] && nums[k] > nums[i]) {
                    cvcount++;
                } else if (nums[j] < nums[i] && nums[k] < nums[i]) {
                    cvcount++;
                } 
            }
        }
        return cvcount;
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=countHillValley
// paramTypes= ["number[]"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// [2,4,1,1,6,5]\n
// @lcpr case=end

// @lcpr case=start
// [6,6,5,5,4,1]\n
// @lcpr case=end


// @lcpr case=start
// [57,57,57,57,57,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,85,85,85,86,86,86]\n
// @lcpr case=end
 */

