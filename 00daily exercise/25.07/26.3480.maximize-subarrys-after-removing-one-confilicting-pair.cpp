// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=3480 lang=cpp
 * @lcpr version=30204
 * 这题目leetcode的插件没有收录，我是仿照格式自己写的
 * 估计用点击测试和debug会有问题
 * [1957] 删除字符使字符串变好
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
    // 首先枚举左端点i, 假设不包含冲突对的情况下，获取子数组的右端点j的取值返回
    // 如果冲突对conflictingPair[k] = [ak, bk], 设定ak < bk, 
    // 如若i > ak: 无论j如何取值，都不会同时包含ak, bk
    // 如若i <= ak: j < bk方可
    // 令b1 = min_{ak >= i} bk, 所以j有如下约束
    // i <= j < min(b1, n + 1)
    // 所以左端点为i的合法子数组数目为min(n + 1, b1) - i,
    // 为了快速计算b1, 用数组bMin1, bMin2记录相同a的最小b和次小b, 
    // b1可以通过计算bMin1的后缀最小值解
    // 之后，考虑恰好删除一个冲突对后，合法子数组数目的计算。
    // 左端点为i的子数组，右端点j取值范围和b1有关，如果删除的冲突对不涉及b1, 那么左端点为i的合法子数组数目不变
    // 设b1在bMin1的下标为ib1, i.e. bMin1[ib1] = b1, 
    // 使用delCount[ib1]记录删除掉b1对应的冲突对后，可以增加的合法子数组的数量
    // b2: bMin1在下标i的后缀次小值，那么删掉b1后，b1' = min(b2, bMin2[ib1]), b2 ini:= INT_MAX
    // 增加的合法子数组为min(b1', n + 1) - min(b1, n + 1), 累加到delCount[ib1]
    // 所以恰好删除一个冲突后，可以得到的最大合法子数组的数量
    // 等于不删除冲突对的最大合法子数组数量+删除一个冲突对后增加的合法子数组数量delCount的最大值
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        vector<int> bMin1(n + 1, INT_MAX), bMin2(n + 1, INT_MAX);
        // bMin1, bMin2: 冲突对如果有相同的a, bMin1记录对应的最小b, bMin2记录对应的次小b
        for(const auto& pair: conflictingPairs) {
            int a = min(pair[0], pair[1]), b = max(pair[0], pair[1]);
            if (bMin1[a] > b) {
                bMin2[a] = bMin1[a];
                bMin1[a] = b;
            } else if (bMin2[a] > b) {
                bMin2[a] = b;
            }
        }
        long long res = 0;
        int ib1 = n, b2 = INT_MAX;
        // ib1: 假设b1在bMin1的下标为ib1, i.e. bMin1[ib1] = b1
        vector<long long> delCount(n + 1, 0);
        for (int i = n; i >= 1; i--) {
            if (bMin1[ib1] > bMin1[i]) {
                b2 = min(b2, bMin1[ib1]);
                ib1 = i;
            } else {
                b2 = min(b2, bMin1[i]);
            }
            res += min(bMin1[ib1], n + 1) - i;
            delCount[ib1] += min(min(b2, bMin2[ib1]), n + 1) - min(bMin1[ib1], n + 1);
        }
        res = res + *max_element(delCount.begin(), delCount.end());
        return res;
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=maxSubarrays
// paramTypes= ["number","number[][]"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// 4\n[[2, 3], [1, 4]]
// @lcpr case=end

// @lcpr case=start
// 5\n[[1,2],[2,5],[3,5]]
// @lcpr case=end

 */

