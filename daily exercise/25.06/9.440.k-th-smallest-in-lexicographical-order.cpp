/*
 * @lc app=leetcode.cn id=440 lang=cpp
 * @lcpr version=30204
 *
 * [440] 字典序的第K小数字
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
    // I. 字典树
    // 显然排序方案会超时 O(n * logn)
    // 假设我们有一棵字典树，那么我们前序遍历该字典树，
    // 即可从小到大获得第k个节点。如果要构建字典树, TC: O(k)
    // 在思考一下，我们不需要显式的构建字典树，因为节点i的子节点显然为
    // (10i, 10i + 1, ......, 10i + 9), 设当前字典树的第i小的节点为n_i
    // 则需要找到前序遍历继续往后k - i个节点，设n_i右侧的兄弟为n_{i+1}
    // 以n_i为根结点构成的子树的节点数目为step(n_i), 则可能性如下：
    // 1. step(n_i) <= k - i, 直接跳过子树，从其兄弟节点n_{i+1}开始找k - i - step(n_i)个结点
    // 2. step(n_i) > k - i, 在子树中，子树第一个子为10 * n_i, 然后开始查找k - i - 1个节点
    // 3. 重复直到找到k小的节点
    // 那么子树step(n_i)的大小如何呢？
    // 我们需要层级遍历，first_i: i层最左侧子节点，last_i：i层最右侧
    // first_i = 10 * first_{i-1}, last_i = 10 * last_{i - 1} + 9
    // 第i层共有last_i - first_i + 1个节点，注意最右侧需要和n取个最小值
    // min(n, last_i), 不断迭代直到first_i > n则终止向下搜索。
    // TC: O(10 * (log_{10} n)^2) = O(log^2 n) 
public:
    int getSteps(int cur, long n) {
        int steps = 0;
        long first = cur;
        long last = cur;
        while(first <= n) {
            steps += min(last, n) - first + 1;
            first = first * 10;
            last = last * 10 + 9;
        }
        return steps;
    }
    int findKthNumber(int n, int k) {
        int cur = 1;
        k--;
        while(k > 0) {
            int steps = getSteps(cur, n);
            if (steps <= k) {
                k -= steps;
                cur++;
            } else {
                cur = cur * 10;
                k--;
            }
        }
        return cur;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 13\n2\n
// @lcpr case=end

// @lcpr case=start
// 1\n1\n
// @lcpr case=end

 */

