// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=757 lang=cpp
 * @lcpr version=30204
 *
 * [757] 设置交集大小至少为2
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
    // I. 贪心
    // 从简化部分开始分析，假设交集大小为1，
    // 为了更好分析我们将intervals按照[s, e]序进行升序排序
    // 设排序后intervals = {[s1, e1], ......, [sn, en]}, n: 集合大小
    // \forall i, j \in [1, n], i < j: si <= sj
    // 我们首先思考最后一个集合[sn,en], 最优的元素应该尽可能把之前
    // 区间覆盖，那么sn一定是最优的，一位对于前面的某个区间[si,ei]
    // ei < sn: 最后一个区间中无论哪个数字都不会再[si, ei]中
    // ei >= sn: sn >= si, sn一定在区间[si, ei]中
    // 于是我们获得了谈心的思路：
    // 排序后倒序遍历，每次选取与当前交集集合相交为空的区间的最左边元素
    // 然后往前判断是否有区间能因此产生交集，能则跳过即可，
    // 如果交集大小m > 1, 我们额外记录每个区间与最后交集集合中相交的元素
    // (记录到m个为止), 从后往前处理，如果相交元素<m个，从该区间左边界
    // 开始往后添加不在交集集合中的元素，并往前更新，重复直到该区间与交集元素集合
    // 有m个元素相交
    // 最后进行改进：s升序e降序，这样可以实现，与交集集合相交元素<m个的区间
    // 不足的元素都是在区间开始的部分
    // tc: O(nlogn + nm), sc:O(nm), m = 2
public:
    void help(vector<vector<int>>& intervals, vector<vector<int>>& temp, int pos, int num) {
        for (int i = pos; i >= 0; i--) {
            if (intervals[i][1] < num) {
                break; // 右边<num, 则肯定不能覆盖num
            }
            temp[i].push_back(num);
        }
    }

    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int res = 0;
        int m = 2;
        sort(intervals.begin(), intervals.end(), [&](vector<int>& a, vector<int>& b) {
            if (a[0] == b[0]) {
                return a[1] > b[1];
            }
            return a[0] < b[0];
        });
        vector<vector<int>> temp(n);
        // temp[i]: 已经命中第i个区间的所有交集集合中的点（最多记录2个）
        for (int i = n - 1; i >= 0; i--) {
            for (int j = intervals[i][0], k = temp[i].size(); k < m; j++, k++) {
                res++; // k读取temp, 表示interval[i]需要补的点
                help(intervals, temp, i - 1, j);
            }
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,3],[3,7],[8,9]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,3],[1,4],[2,5],[3,5]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2],[2,3],[2,4],[4,5]]\n
// @lcpr case=end

 */

