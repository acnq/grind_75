// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=1855 lang=cpp
 * @lcpr version=30204
 *
 * [1855] 下标对中的最大距离
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
    // I. 双指针
    // 遍历nums2中的下标j, 寻找此时符合要求的nums1中的最小下标
    // 假设j对应最小下标i, j变为j+1时，因为nums2[j]>=nums[j+1]
    // 那么nums1中可取元素的上界不会增加，又考虑到nums1非递增
    // 则j+1对应的下标i'一定满足i'>=i
    // 
    // 于是我们在遍历j的同时维护i, res维护(i, j)的最大距离，
    // 初始化为0
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int i = 0;
        int res = 0;
        for (int j = 0; j < n2; j++) {
            while(i < n1 && nums1[i] > nums2[j]) {
                i++;
            }
            if (i < n1) {
                res = max(res, j - i);
            }
        }
        return res;
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=maxDistance
// paramTypes= ["number[]","number[]"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// [55,30,5,4,2]\n[100,20,10,10,5]\n
// @lcpr case=end

// @lcpr case=start
// [2,2,2]\n[10,10,1]\n
// @lcpr case=end

// @lcpr case=start
// [30,29,19,5]\n[25,25,25,25,25]\n
// @lcpr case=end

 */

