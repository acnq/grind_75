// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=1200 lang=cpp
 * @lcpr version=30204
 *
 * [1200] 最小绝对差
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
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        // O. 我的写法 11min
        // vector<vector<int>> ret;
        // int n = arr.size();
        // int mindiff = INT_MAX;
        // sort(arr.begin(), arr.end());
        // for (int i = 0; i + 1 < n; i++) {
        //     int diff = abs(arr[i + 1] - arr[i]);
        //     if (diff < mindiff) {
        //         mindiff = diff;
        //         ret.clear();
        //         vector<int> pair = {arr[i + 1], arr[i]};
        //         sort(pair.begin(), pair.end());
        //         ret.push_back(pair);
        //     } else if (diff == mindiff) {
        //         vector<int> pair = {arr[i + 1], arr[i]};
        //         sort(pair.begin(), pair.end());
        //         ret.push_back(pair);
        //     } else {
        //         continue;
        //     }
        // }
        // return ret;

        // I. 排序+遍历
        int n = arr.size();
        sort(arr.begin(), arr.end());

        int best = INT_MAX;
        vector<vector<int>> ans;

        for (int i = 0; i < n - 1; i++) {
            if (int delta = arr[i + 1] - arr[i]; delta < best) {
                best = delta;
                ans = {{arr[i], arr[i + 1]}};
            } else if (delta == best) {
                ans.emplace_back(initializer_list<int>{arr[i], arr[i + 1]});
            }
        }
        return ans;
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=minimumAbsDifference
// paramTypes= ["number[]"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// [4,2,1,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,3,6,10,15]\n
// @lcpr case=end

// @lcpr case=start
// [3,8,-10,23,19,-4,-14,27]\n
// @lcpr case=end

 */

