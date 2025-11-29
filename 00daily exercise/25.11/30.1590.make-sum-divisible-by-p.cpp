/*
 * @lc app=leetcode.cn id=1590 lang=cpp
 * @lcpr version=30204
 *
 * [1590] 使数组和能被 P 整除
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
    // I. 前缀和
    // 引理1：y mod p = x 且 (y - z) mod p = 0; => z mod p = x
    // 引理2: (y - z) mod p = x => z mod p = (y - x) mod p
    // 均显然
    // 记前i(不含)元素的前缀和为f_i，记数组总和模p余x, x=0直接返回0
    // 考虑最右元素为nums[i]的所有子数组，假设最左元素nums[j]
    // 二者之间的和为f_{i+1} - f_j, 对应长度为i-j+1
    // 由引理1，若余下的子数组可被p整除，(f_{i+1} - f_j) mod p = x
    // 由引理2，推知f_j mod p = (f_{i+1} - x) mod p
    // 所以我们当f_{i+1}已知，可以首先找到所有满足上式的f_j,
    // 由于需要移除最短子数组，只需要对所有f_j保存最大下标即可
    // 如果余数为负，(f_{i+1} - x) mod p = (f_{i+1} - x + p) mod p 
public:
    int minSubarray(vector<int>& nums, int p) {
        int x = 0;
        for (auto num: nums) {
            x = (x + num) % p; // 防止溢出的技巧
        }
        if (x == 0) {
            return 0;
        }   
        unordered_map<int, int> idx;
        int y = 0, res = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            idx[y] = i; // f_{i+1} mod p = y, 因此哈希表记录 y 对应的下标为 i
            y = (y + nums[i]) % p;
            if (idx.count((y - x + p) % p) > 0) {
                res = min(res, i - idx[(y - x + p) % p] + 1);
            }
        }
        return res == nums.size() ? -1: res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,1,4,2]\n6\n
// @lcpr case=end

// @lcpr case=start
// [6,3,5,2]\n9\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n7\n
// @lcpr case=end

// @lcpr case=start
// [1000000000,1000000000,1000000000]\n3\n
// @lcpr case=end

 */

