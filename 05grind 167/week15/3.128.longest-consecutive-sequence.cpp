/*
 * @lc app=leetcode.cn id=128 lang=cpp
 * @lcpr version=30204
 *
 * [128] 最长连续序列
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
    int longestConsecutive(vector<int>& nums) {
        // unordered_map<int, int> mp; // lower bound -> upper bound
        // for(int num: nums) {
        //     if (condition)
        //     {
        //         /* code */
        //     }
            
            
        // }

        // 这道题需要反向思考：内外两层寻找为什么没有效率，
        // 因为如果第一层循环遇到n, 而且我们找到了一个序列，例如，n, n + 1, n + 2, ..., n + k
        // 暴力枚举一旦碰到数组中的另一个元素，例如 n + 1, 则我们又会调用相同的算法重新找到相同的序列
        // 解决这一问题我们需要反向运用哈希，前两题都是利用哈希快速找到需要的元素
        // 这里我们尝试利用哈希快速排除不需要的元素，显然，第一层遍历到n时，如果我们在nums中find(哈希意义上)到n-1
        // 那我们可以直接跳过，因为当下次遍历到n-1时，我们能重新导出同样的序列，
        // 只有当我们找到没有n-1的元素时，我们才开始累次find(哈希意义上)n + 1的元素
        // 这样假设nums[1:n]包含m个l_m长的序列，hash_find最多2 * \sum_{m}lm = 2 * n 次
        // 因为hash_find O(1), 整体复杂度O(n)
        // 所以我们这里甚至不需要hash_map, 有hash_set即可
        int res = 0;
        unordered_set<int> hashset;
        for(int num: nums){
            hashset.insert(num); // 去重，便于后续find
        }
        for (int elem: hashset) // 这里不要用nums列举，否则也会超时
        {
            if (hashset.count(elem- 1) == 0)
            {
                int curRes = 0;
                int n = elem;
                while (hashset.count(n + 1))
                {
                    curRes++;
                    n++;
                }
                res = max(curRes, res);
            }
            
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [100,4,200,1,3,2]\n
// @lcpr case=end

// @lcpr case=start
// [0,3,7,2,5,8,4,6,0,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,0,1,2]\n
// @lcpr case=end

 */

