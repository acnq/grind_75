/*
 * @lc app=leetcode.cn id=96 lang=cpp
 * @lcpr version=30204
 *
 * [96] 不同的二叉搜索树
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
    // I. DP
    // 遍历每个数字i，作为树根，1:(i-1)作为左子树，(i+1):n作为右子树，
    // 然后递归建立左右子树，显然，由于每次根都不同，保证了每棵树都无重复
    // def: G(n): 长度为n的序列能构成的不同二叉树的个数
    //      F(i, n): 以i为根，长度为n的序列的不同二叉树个数(i\in[1, n])
    // G(n) = \sum_{i=1}^nF(i, n); F(i, n) = G(i - 1) * G(n - i)
    // 有G(n) = \sum_{i=1}^n G(i - 1)* G(n - i), 另有G(0) = G(1) = 1, 

    // II. 数学
    // G(n)就是卡塔兰数C_n, C_0 = 1, C_{n + 1} = \frac{2(2n + 1)}{n + 2} C_n
public:
    int numTrees(int n) {
        // I.
        // vector<int> G(n + 1, 0);
        // G[0] = 1;
        // G[1] = 1;

        // for (int i = 2; i <= n; i++)
        // {
        //     for (int j = 1; j <= i; j++)
        //     {
        //         G[i] += G[j - 1] * G[i - j];
        //     }
        // }
        // return G[n];

        long long C = 1;
        for (int i = 0; i < n; i++)
        {
            C = C * 2 * (2 * i + 1) / (i + 2);
        }
        return (int) C;
        
    }
};
// @lc code=end



/*
// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */

