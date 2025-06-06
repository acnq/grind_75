// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=646 lang=cpp
 * @lcpr version=30204
 *
 * [646] 最长数对链
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
    // s[i]: 以i结尾的LIS长度
    // s[i] = max_{ nums[j][1] < pairs[i][0] }{s[j]} + 1;
    // I. DP 如上
    // II. 贪心+二分查找
    // arr[i]: 长度为i+1的数对链末尾可以取得的最小值，二分查找更新
    // III. 纯粹贪心
    // 我们要让数对链增长慢，只需要挑选所有满足条件的数对中，第二个数字最小的那个
    // 这样，我们首先将输入按照第二个数字排序，
    // 然后不断判断第一个数字能否大于前一个数对的第二个数字即可。
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        // sort(pairs.begin(), pairs.end());
        // int n = pairs.size();
        // vector<int> lis(n, 0);
        // for (int i = 0; i < n; i++)
        // {
        //     int tmp_max = 0;
        //     for (int j = 0; j < i; j++)
        //     {
        //         if (pairs[j][1] < pairs[i][0])
        //         {
        //             tmp_max = max(tmp_max, lis[j]);
        //         }
        //     }
        //     lis[i] = tmp_max + 1;
        // }
        // return *max_element(lis.begin(), lis.end());
        // // 在完成300之后算是秒杀题了，15min a.c.,

        // sort(pairs.begin(), pairs.end());
        // vector<int> arr;
        // for(auto p: pairs) {
        //     int x = p[0], y = p[1];
        //     if (arr.size() == 0 || x > arr.back())
        //     {
        //         arr.emplace_back(y);
        //     } else {
        //         int idx = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        //         arr[idx] = min(arr[idx], y);
        //     }
        // }
        // return arr.size();

        int curr = INT_MIN, res = 0;
        sort(pairs.begin(), pairs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        for (auto& p: pairs) {
            if (curr < p[0])
            {
                curr = p[1];
                res++;
            }
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,2], [2,3], [3,4]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2],[7,8],[4,5]]\n
// @lcpr case=end

 */

