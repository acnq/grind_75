/*
 * @lc app=leetcode.cn id=1975 lang=cpp
 * @lcpr version=30204
 *
 * [1975] 最大方阵和
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
    // 对于方阵中任意两个负元素，一定存在一系列操作是的此二者变为正，其余元素不变
    //          一个正元素和一个负元素，也一定存在一系列操作使二者交换正负，其余元素不变
    //  证明：直接获取链接两元素的有向路径，按顺序对二者每个元素和下一个元素执行一次操作
    //       那么路径上除了端点之外都执行了两次操作（正负不变），端点一次（改变正负）得证
    // 由此可知，如果方阵存在一个元素0和一个负数，可以直接让那个负数变正，其余不变
    // 再由此可知，如果方阵存在0，则经过有限步骤一定能把所有元素变为非负
    //            如果无0，则考虑是否有奇数个负元素，如果有奇数个，则由以上可以让负数仅余1个
    //                    且位置任意
    //                    如果是偶数个，则通过一系列操作可以让方阵所有负数转正
    // 由此可得算法
    // 1. 如果有0，方阵最大和即为所有元素绝对值和
    // 2.    没有，且负数有偶数个，最大和也为所有元素绝对值之和
    // 3.    没有，且负数有奇数个，最大和即为所有元素绝对值之和减去最小元素的绝对值的两倍
    // 注意第一种情况可以直接并入后两种，
    // 遍历方阵，维护负元素个数、绝对值最小元素和所有元素绝对值之和即可
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int cnt = 0; // 负元素个数
        long long total = 0; // 所有元素绝对值之和
        int mn = INT_MAX; // 方阵绝对值最小元素
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                mn = min(mn, abs(matrix[i][j]));
                if (matrix[i][j] < 0) {
                    cnt++;
                }
                total += abs(matrix[i][j]);
            }
        }
        if (cnt % 2 == 0) {
            return total;
        } else {
            return total - 2 * mn;
        }
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,-1],[-1,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,3],[-1,-2,-3],[1,2,3]]\n
// @lcpr case=end

 */

