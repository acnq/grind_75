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

    // III. 分块预处理
    // nums 从左到右k个一组进行分组，最后一组的元素可以不到k个， 求出nums[i]:nums[i+k-1]的最大值，有两种情况
    // 1. i是k的倍数，那么，num[i]:nums[i+k-1]恰为一个分组=>预处理每个分组中的最大值即可
    // 2. i不是k的倍数，则nums[i]:nums[i+k-1]会分跨两组，假设j是k的倍数，且i < j <= i + k - 1
    //    则nums[i]:nums[j-1]为第一个分组的后缀，num[j]:nums[i+k-1]就是第二分组的前缀 => 预处理每个分组中的前缀最大值和后缀最大值
    // prefixMax[i]: 下标i对应的分组中，以i结尾的前缀最大值；
    // suffixMax[i]:  ... ...       ,以i开始的后缀最大值
    // prefixMax[i] = { nums[i],                        i是k的倍数
    //                { max{prefixMax[i - 1], nums[i]}, i不是...
    // suffixMax[i] = { nums[i],                        i+1是k的倍数
    //                { max(suffixMax[i + 1], nums[i]), i+1不是...
    // suffixMax[n - 1] = nums[n - 1], prefixMax[0] = nums[0]
    // 注意无论哪种情况， 窗口中最大值都是max{suffixMax[i], prefixMax[i + k - 1]}
    // 这就是稀疏表

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
        // int n = nums.size();
        // deque<int> q;
        // for (int i = 0; i < k; i++)
        // {
        //     while (!q.empty() && nums[i] >= nums[q.back()])
        //     {
        //         q.pop_back();
        //     }
        //     q.push_back(i);
        // }
        // vector<int> ans = {nums[q.front()]};
        // for (int i = k; i < n; i++)
        // {
        //     while (!q.empty() && nums[i] >= nums[q.back()])
        //     {
        //         q.pop_back();
        //     }
        //     q.push_back(i);
        //     while (q.front() <= i - k)
        //     {
        //         q.pop_front();
        //     }
        //     ans.push_back(nums[q.front()]);
        // }
        // return ans;

        int n = nums.size();
        vector<int> prefixMax(n), suffixMax(n);
        for (int i = 0; i < n; i++)
        {
            if (i % k == 0)
            {
                prefixMax[i] = nums[i];
            } else {
                prefixMax[i] = max(prefixMax[i - 1], nums[i]);
            }
        }

        for (int i = n - 1; i >= 0; i--)
        {
            if (i == n - 1 || (i + 1) % k == 0)
            {
                suffixMax[i] = nums[i];
            } else {
                suffixMax[i] = max(suffixMax[i + 1], nums[i]);
            }
        }
        
        vector<int> ans;
        for (int i = 0; i <= n - k; i++)
        {
            ans.push_back(max(suffixMax[i], prefixMax[i + k - 1]));
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

