/*
 * @lc app=leetcode.cn id=1288 lang=cpp
 * @lcpr version=30204
 *
 * [1288] 删除被覆盖区间
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
    // I. 枚举
    // 对列表中每个区间p, 枚举其余区间判断是否被覆盖
    // tc: O(N^2), sc: O(1)
    // II. 排序 + 遍历
    // 假设左端点都不相同；
    // 我们将所有区间按照左端点递增排序，那么对于排完的区间[li, ri);
    // 之前的[lj, rj), 一定有lj < li, 所以对此，有j < i且rj >= ri;
    // 那么[li, ri)一定会比覆盖，所以只要在[li, ri)之前的区间
    // 的右端点最大值r_max = max(r1, r2, ......, r_{i-1})
    // r_max >= ri, 那么区间[li, ri)一定会被覆盖；
    // 之后的区间lj > li, 所以[li, ri)肯定不会被覆盖
    // 所以我们排序只需要判断r_max >= ri, 并不断更新r_max即可
    // 如果左端点相同，那么排序之后的区间lj >= li, 如果有lj=li
    // 第i个区间还是会被后面的区间覆盖，所以我们以左端点为地关键字
    // 右端点为第二关键字且递减排序，这样即使有lj = li, 也一定有
    // rj < ri, 所以保持了结论：后面的不可能覆盖前面的。
    // tc: O(NlogN), sc: O(logN)
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        // I.
        // int n = intervals.size();
        // int ans = n;
        // for (int i = 0; i < intervals.size(); i++) {
        //     for (int j = 0; j < intervals.size(); j++) {
        //         if (i != j && intervals[j][0] <= intervals[i][0] && intervals[i][1] <= intervals[j][1]) {
        //             ans--;
        //             break;
        //         }
        //     }
        // }
        // return ans;

        // II.
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), [](const vector<int>& u, const vector<int>& v){
            return u[0] < v[0] || (u[0] == v[0] && u[1] > v[1]);
        });
        int ans = n;
        int rmax = intervals[0][1];
        for (int i = 1; i < n; i++) {
            if (intervals[i][1] <= rmax) {
                ans--;
            } else {
                rmax = max(rmax, intervals[i][1]);
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,4],[3,6],[2,8]]\n
// @lcpr case=end

 */

