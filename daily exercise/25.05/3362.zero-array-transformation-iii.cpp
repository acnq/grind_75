// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=3362 lang=cpp
 * @lcpr version=30204
 *
 * [3362] 零数组变换 III
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
    // 看提示是否可以贪心做？
    // 较长（i.e. li-ri较大）的query先操作，变0即可返回，
    // 证明？
    // 不行的，单纯按长度贪心有反例：共N+2个，第一个能把1-N置零，第二个把2-(N+1)置零
    // 第三个3-（N+2), 最后一个把(N+1)-(N+2)置零，贪心会选上1,2,3;但正确答案是1,4
    // 官方解析：
    // I. 贪心 + 优先队列
    // 首先考虑nums中下标为i的元素，要在左端点<=i的query的右端点扔进大根堆中候选
    // 考虑从这些候选区间中选出部分进行-1操作，以求nums[i]能减少至<=0，大根堆保证了
    // 能跨越区间更大的更佳，
    // 注意diff[l]--始终是不必要的，因为相当于已经被presum--涵盖了，取出的query li总是<i的。
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), m = queries.size();
        sort(queries.begin(), queries.end()); // sort for 2d vector is by-default lexicographic
        priority_queue<int> heap;

        vector<int> diff(n + 1);
        diff[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            diff[i] = nums[i] - nums[i - 1];
        }
        int presum = 0;
        
        for (int i = 0, j = 0; i < n; i++)
        {
            presum += diff[i];
            cout << queries[j][0] << endl;
            while (j < m && queries[j][0] <= i)
            {
                heap.push(queries[j][1]);
                j++;
            }
            while (!heap.empty() && presum > 0 && heap.top() >= i)
            {
                int ri = heap.top();
                diff[ri + 1]++;
                presum--;
                heap.pop();
            }
            
            if (presum > 0)
            {
                return -1;
            }
        }
        return heap.size();      
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=maxRemoval
// paramTypes= ["number[]","number[][]"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// [2,0,2]\n[[0,2],[0,2],[1,1]]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,1,1]\n[[1,3],[0,2],[1,3],[1,2]]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4]\n[[0,3]]\n
// @lcpr case=end

 */

