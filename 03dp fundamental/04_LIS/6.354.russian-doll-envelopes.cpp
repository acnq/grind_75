// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=354 lang=cpp
 * @lcpr version=30204
 *
 * [354] 俄罗斯套娃信封问题
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
    // O(N logN) 可以
    // 先参考一下T646的题解，
    // les[i]: 长度为i + 1的信封链末尾可以取得的最小值，二分查找更新
    // evlp可以包含les.back(), les.push_back(evlp[1])
    // 否则二分查找找到最靠右的大于evlp[1]的les[i]对应的i，修改为evlp[1]
public:
    static bool compare(vector<int> env1, vector<int> env2) {
        if (env1[0] < env2[0])
        {
            return true;
        } else if(env1[0] > env2[0]) 
        {
            return false;
        } else 
        {
            return env1[1] > env2[1];
        }
        // 首先按照字典序排列, 注意第二项要反向 
        // 这样下一步排列的时候只要考虑第二项的大小即可
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), compare);
        int n = envelopes.size();
        vector<int> les; // longest envelop subsequence
        // les.push_back(envelopes[0][1]);
        for(auto evlp: envelopes) {
            if (les.size() == 0 || evlp[1] > les.back())
            {
                les.push_back(evlp[1]);
            } else {
                int idx = lower_bound(les.begin(), les.end(), evlp[1]) - les.begin();
                les[idx] = min(les[idx], evlp[1]);
            }
        }
        return les.size();
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[5,4],[6,4],[6,7],[2,3]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,1],[1,1],[1,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[4,5],[4,6],[6,7],[2,3],[1,1]]\n
// @lcpr case=end

 */

