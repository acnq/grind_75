/*
 * @lc app=leetcode.cn id=239 lang=cpp
 * @lcpr version=30204
 *
 * [239] 滑动窗口最大值
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
    // 注意到，两个相邻的的滑动窗口，有k-1个元素相同，变化的只有一个元素

    // I. 优先队列
    // 注意不是每次左移都要有元素从优先队列出去
    // 仅当之前的最大值的坐标小于当前滑窗的左坐标时才出列
    // 为此，我们要在队列中储存最大元素的坐标
    // 
    // 复杂度：存取优先队列的复杂度为O(logn), 故总体为O(n log n)

    // II. 单调队列 (队列元素单调的双端队列)
    // 我们发现，对于滑动窗口中的任意两个元素i<j, 一旦nums[i]<=nums[j]
    // 那么我们有结论：主要i还在窗口中，j必然也在，因此nums[i]一定不会是任何滑窗中的最大值
    // 所以我们可以把滑窗中的非最大值永久移除
    // 设定一个双端队列，保存所有未被永久移除的元素下标，这些下标从小到大排序，而且他们在数组中对应的nums也是严格递减的
    // 滑窗右移，在新元素被放入之前，要保持队列性质，需要比较新元素和队尾元素
    // 新元素大，则队尾元素就要被移除，弹出队列，不断操作，直到队列为空或者此次的新元素小于队尾
    //
    // 复杂度：由于从优先队列进步为了操作O(n)的队列，总体优化为O(n);

    // III. 

public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // I.
        // int n = nums.size();
        // priority_queue<pair<int, int>> que;
        // for (int i = 0; i < k; i++)
        // {
        //     que.emplace(nums[i], i);
        // }
        // vector<int> res = {que.top().first};
        // for (int j = k; j < n; j++)
        // {
        //     que.emplace(nums[j], j);
        //     while (que.top().second <= j - k)
        //     {
        //         que.pop();
        //     }
        //     res.push_back(que.top().first);
        // }
        // return res;

        // II.
        int n = nums.size();
        deque<int> q;
        for (int i = 0; i < k; i++)
        {
            while (!q.empty() && nums[i] >= nums[q.back()])
            {
                q.pop_back();
            }
            q.push_back(i);
        }
        vector<int> ans = {nums[q.front()]};
        for (int i = k; i < n; i++)
        {
            while (!q.empty() && nums[i] >= nums[q.back()])
            {
                q.pop_back();
            }
            q.push_back(i);
            while (q.front() <= i - k)
            {
                q.pop_front();
            }
            ans.push_back(nums[q.front()]);
        }
        return ans;
        
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,3,-1,-3,5,3,6,7]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1]\n1\n
// @lcpr case=end

 */

