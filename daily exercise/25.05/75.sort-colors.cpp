// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=75 lang=cpp
 * @lcpr version=30204
 *
 * [75] 颜色分类
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
    void sortColors(vector<int>& nums) {
        // I. 
        // 单指针两遍，
        // 先把0都放到前面
        // int ptr = 0;
        // for(int i = 0; i < nums.size(); i++) {
        //     if(nums[i] == 0) {
        //         swap(nums[i], nums[ptr]);
        //         ptr++;
        //     }
        // }
        // // 再把1都放到0后面 (不要试图把2放到后面，递推)
        // for(int i = ptr; i < nums.size(); i++) { // 不要写ptr + 1, 不然[1, 2, 1]有问题
        //     if(nums[i] == 1) {
        //         swap(nums[i], nums[ptr]);
        //         ptr++;
        //     }
        // }

        // II. 双向双指针
        // 遍历到0和p_0交换，到2和p_2交换
        // int n = nums.size();
        // int p_0 = 0, p_2 = n - 1;
        // for(int i = 0; i <= p_2; i++) {
            
        //     // i和p_2交换之后可能还是2，所以要while到非2为止
        //     while(i <= p_2 && nums[i] == 2) {
        //         swap(nums[i], nums[p_2]);
        //         p_2--;
        //     }

        //     // i和p_2交换之后可能是0，所以0的逻辑要放到2之后
        //     if(nums[i] == 0) {
        //         swap(nums[i], nums[p_0]);
        //         p_0++; // p_0 一定不会指向0，因为++
        //     }
        // }
        
        // 单项双指针
        
        int n = nums.size();
        int p_0 = 0, p_1 = 0; // 指向已排序后最后一个0/1的后一个
        for(int i = 0; i < n; i++) {
            if(nums[i] == 1) {
                swap(nums[i], nums[p_1]);
                p_1++;
            }
            if(nums[i] == 0) {
                swap(nums[i], nums[p_0]);
                
                if(p_0 < p_1) { // 不是while不然死循环
                    swap(nums[i], nums[p_1]);
                    // p_0++;
                    // p_1++;
                }
                p_0++;
                p_1++;
            }
        }
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,0,2,1,1,0]\n
// @lcpr case=end

// @lcpr case=start
// [2,0,1]\n
// @lcpr case=end

 */

