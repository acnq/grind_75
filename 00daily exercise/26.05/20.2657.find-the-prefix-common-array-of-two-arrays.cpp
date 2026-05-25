/*
 * @lc app=leetcode.cn id=2657 lang=cpp
 * @lcpr version=30204
 *
 * [2657] 找到两个数组的前缀公共数组
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

#include <bit>
// @lcpr-template-end
// @lc code=start
class Solution {
    // I. 哈希
    // C[i]: i以之前同时在A,B中出现的数字个数
    // cntA: A中已经出现的元素; cntB: B中已经出现的元素
    // cnt: A/B共同出现的元素
    // 对每个位置i:
    // cntB是否包含A[i], 是则cnt添加A[i]
    // cntA       B[i],           B[i]
    // cnt: 当前公共元素的数目
    // tc: O(n), sc: O(n)

    // II. 位运算
    // 1 <= A[i],B[i] <= n <= 50 (条件)
    // 我们压缩乘二进制，第i位表示存在数字i, 按位与就是交
    // 交集的大小就是二进制中1的个数
    // tc: O(n), sc: O(1)
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        // I. 哈希：
        int n = A.size();
        unordered_set<int> cntA, cntB;
        unordered_set<int> cnt;
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            cntA.emplace(A[i]);
            cntB.emplace(B[i]);
            if (cntB.count(A[i])) {
                cnt.emplace(A[i]);
            }
            if (cntA.count(B[i])) {
                cnt.emplace(B[i]);
            }
            ans.emplace_back(cnt.size());
        }
        return ans;

        // II.
        // uint64_t p = 0, q = 0;
        // for (int i = 0; i < A.size(); i++) {
        //     p |= 1ULL << A[i];
        //     q |= 1ULL << B[i];
        //     A[i] = popcount(p & q); // <bit> 中统计1个数的标准库函数
        // }
        // return A;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,3,2,4]\n[3,1,2,4]\n
// @lcpr case=end

// @lcpr case=start
// [2,3,1]\n[3,1,2]\n
// @lcpr case=end

 */

