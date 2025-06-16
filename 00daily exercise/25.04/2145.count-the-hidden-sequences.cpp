/*
 * @lc app=leetcode.cn id=2145 lang=cpp
 * @lcpr version=30204
 *
 * [2145] 统计隐藏数组数目
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
    // I.
    // 首先，隐藏数组a_0, a_1,..., a_n如果满足diff
    // 那么a_0 + k, a_1 + k, ..., a_n + k 必然也满足diff
    // 这样就可以任意指定a_0, 不妨设a_0 = -
    // 继续，考虑a_i \in [lower, upper]
    // 记数组最大最小元素为a_i, a_j, 有 lower<= a_i <= a_j <= upper
    // 则a_i \in [lower, upper-(a_j - a_i)]
    // 注意a_j - a_i可以直接用diff数组表示，\sum_{k=i}^j differences[k]
    // 所以符合要求数组数目为：upper - (a_j - a_i) - lower + 1
    // i.e. (upper - lower) - (a_j - a_i) + 1
    // 这就是长度为a_j - a_i的小窗口在upper-lower的大窗口中滑动时，能放置位置的数量
    // 注意，还原数组的过程中，我们只需要记录最大值最小值即可, 我们用cur表示当前值，
    // 如果某一时刻最大值最小值之差大于upper-lower, 返回0
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int x = 0, y = 0, cur = 0;
        for(int d: differences) {
            cur += d;
            x = min(x, cur);
            y = max(y, cur);
            if (y - x > upper - lower)
            {
                return 0;
            }
        }
        return (upper - lower) - (y - x) + 1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,-3,4]\n1\n6\n
// @lcpr case=end

// @lcpr case=start
// [3,-4,5,1,-2]\n-4\n5\n
// @lcpr case=end

// @lcpr case=start
// [4,-7,2]\n3\n6\n
// @lcpr case=end

 */

