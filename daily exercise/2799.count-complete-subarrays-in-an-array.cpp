// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=2799 lang=cpp
 * @lcpr version=30204
 *
 * [2799] 统计完全子数组的数目
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
    // I. O(n^2)
    // II. 双指针滑窗 O(n)
    // 固定左边界left, cnt 统计每个元素出现次数
    // 当不同元素个数小于distinct，右移right
    // 一旦等于, 当前窗口[left, right) 一定“完全”
    // 此时right到数组末尾所有子组也都“完全”，一次性计入 n - right + 1个
    
    // 另外：注意移动left时，要在哈希表中移除nums[left] - 1的计数，到0删除
public:
    int countCompleteSubarrays(vector<int>& nums) {
        // I.
        // int n = nums.size(), res = 0;
        // unordered_map<int, int> stat;
        // for(int i = 0; i < n; i++) {
        //     stat[nums[i]]++;
        // }
        // int min_len = stat.size();
        // for(int i = 0; i < n; i++) {
        //     unordered_map<int, int> my_stat;
        //     for(int j = i; j < n; j++) {               
        //         my_stat[nums[j]]++;
        //         if(my_stat.size() == stat.size()) {
        //             res += n - j;
        //             break;
        //         }
        //     }
        // }
        // return res;

        // II. 
        int res = 0;
        unordered_map<int, int> cnt;
        int n = nums.size();
        int right = 0;
        unordered_set<int> distinct(nums.begin(), nums.end());
        int distinct_cnt = distinct.size();

        for(int left = 0; left < n; left++) {
            if(left > 0) {
                int remove = nums[left - 1];
                cnt[remove]--;
                if (cnt[remove] == 0)
                {
                    cnt.erase(remove);
                }
            }
            while (right < n && cnt.size() < distinct_cnt)
            {
                int add = nums[right];
                cnt[add]++;
                right++;
            }
            if (cnt.size() == distinct_cnt)
            {
                res += (n - right + 1);
            }
        }
        return res;
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=countCompleteSubarrays
// paramTypes= ["number[]"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// [1,3,1,2,2]\n
// @lcpr case=end

// @lcpr case=start
// [5,5,5,5]\n
// @lcpr case=end

 */

