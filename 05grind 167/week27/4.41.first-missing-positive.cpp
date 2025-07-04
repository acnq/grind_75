/*
 * @lc app=leetcode.cn id=41 lang=cpp
 * @lcpr version=30204
 *
 * [41] 缺失的第一个正数
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
    // 如果没有额外的时空复杂度要求
    // 1. 将数组所有的数放入哈希表，随后从1开始依次枚举正整数，判断有否
    //      TC: O(N); SC: O(N);
    // 2. 从1开始依次枚举正整数，并遍历数组，判断其是否在数组中
    //      TC: O(N^2); SC: O(1)
    // 真正满足TC:O(N), SC:O(1)的算法并不存在，我们需要“修改”数组来存储
    
    // I. hash
    /// 改造1:
    // 注意到，长度为N的数组，答案只能在[1, N + 1](如果[1, N]出现了，答案N + 1, 否则一定在[1, N]中)
    // 所以首先，哈希表的范围在[1, N], 而给定数组恰好长度N, 不如把他设计成哈希表。
    //      遍历数组，对于遍历到的x, 在[1, N]范围内，数组第x-1个位置标记一下，
    //      结束遍历后，如果每个位置都打上标记，那么答案是N + 1, 否则就是最小的没有打标记+1
    // 那么怎么设计标记呢？首先，我们只在意[1, N]中的数，所以遍历的时候不在这个范围的数修改成
    //  任意大于N的数，这样至少所有数都正数，于是，标记就可设计为-1
    //  总结：
    //      1. 数组中所有<=0的元素改为N + 1;
    //      2. 遍历每个数x, 原本对应的数（如果被标记过，没有也一样）为|x|,
    //          如果|x| \in [1, N], 给数组第|x|-1个位置的数字乘上-1，如果已经有了，不要重复添加
    //      3. 遍历完后，如果每个都是负数了，那么答案N+1,否则就是第一个位置+1
    
    // II. 置换
    // 我们定义一个数组恢复的操作
    // 第一次遍历到数x = nums[i], x \in [1, N], 我们就知道x应当出现在x - 1的位置，交换nums[i]和nums[x - 1]
    // 与I不同，这次我们直接交换nums[i]和nums[x - 1](这还是O(1)), 这样就相当于x回到了顺序排列的正确位置
    // 但当然，新的nums[i]还是在[1, N]范围内，我们需要继续进行交换，直到x \in [1, N]
    // 注意到，上面的方案是没法避免死循环, 比如nums[i] = nums[x - 1], 就会无限交换
    // 但这种情况下，nums[i] = x已经在nums[x - 1]的位置上了，直接跳出循环，遍历下一个
    // 每次交换都会得到某一个数交换到递增序列的正确位置，最多N次，整个方法时间复杂度O(N)

public:
    int firstMissingPositive(vector<int>& nums) {
        // int n = nums.size();
        // for(int& num: nums) {
        //     if(num <= 0) {
        //         num = n + 1;
        //     }
        // } 
        // for(int i = 0; i < n; i++) {
        //     int num = abs(nums[i]);
        //     if(num <= n) {
        //         nums[num - 1] = -abs(nums[num - 1]);
        //     }
        // }

        // for(int i = 0; i < n; i++) {
        //     if(nums[i] > 0) {
        //         return i + 1;
        //     }
        // }
        // return n + 1;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            while(nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                swap(nums[nums[i] - 1], nums[i]);
            }
        }
        for(int i = 0; i < n; i++) {
            if(nums[i] != i + 1) {
                return i + 1;
            }
        }

        return n + 1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,0]\n
// @lcpr case=end

// @lcpr case=start
// [3,4,-1,1]\n
// @lcpr case=end

// @lcpr case=start
// [7,8,9,11,12]\n
// @lcpr case=end

 */

