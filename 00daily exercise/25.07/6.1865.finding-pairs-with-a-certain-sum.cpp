/*
 * @lc app=leetcode.cn id=1865 lang=cpp
 * @lcpr version=30204
 *
 * [1865] 找出和为指定值的下标对
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
class FindSumPairs {
    // I. 哈希表
    // 根据提示，nums_1的最大长度小于等于nums_2, 所以对于getPairs(tot)
    // 我们可以将nums_2中的元素放入哈希映射中，枚举nums_1的元素num, 从而在哈希映射中找出键tot-num对应的值
    // 额为存储一份nums2中的元素的哈希映射cnt, add操作直接将cnt[nums2[idx]]-1, nums[idx] + val之后对音的+1
    // getpairs(tot), 枚举nums1中元素num, 答案累加cnt[tot-num]中，返回最终答案。
    // tc. 初始化： O(n + m); add: O(1); getPairs: O(m)
    // sc: O(n + m), add需要额外O(1)的空间
private:
    vector<int> nums1, nums2;
    unordered_map<int, int> cnt;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1 = nums1;
        this->nums2 = nums2;
        for (int num: nums2) {
            cnt[num]++;
        }
    }
    
    void add(int index, int val) {
        cnt[nums2[index]]--;
        nums2[index] += val;
        cnt[nums2[index]]++;
    }
    
    int count(int tot) {
        int ans = 0;
        for (int num: nums1) {
            int rest = tot - num;
            if (cnt.count(rest))
            {
                ans += cnt[rest];
            }
        }
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
// @lc code=end



/*
// @lcpr case=start
// ["FindSumPairs", "count", "add", "count", "count", "add", "add", "count"][[[1, 1, 2, 2, 2, 3], [1, 4, 5, 2, 5, 4]], [7], [3, 2], [8], [4], [0, 1], [1, 1], [7]]\n
// @lcpr case=end

 */

