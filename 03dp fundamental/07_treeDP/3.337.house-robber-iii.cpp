/*
 * @lc app=leetcode.cn id=337 lang=cpp
 * @lcpr version=30204
 *
 * [337] 打家劫舍 III
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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

struct TreeNode
{
    int val; TreeNode* left; TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// II.
struct SubtreeStatus
{
    int selected;
    int notSelected;
};

class Solution {
    // I. DP
    // f(o)表示选择o节点的情况下，o节点的子树上被选择的节点的最大值权值和
    // g(o)表示不选择o的情况下，o节点的子树上被选择的节点的最大权值和；
    // l/r分别为o的左右孩子
    // 1. o被选中，l/r不能选中，f(o) = g(l) + g(r);
    // 2. o不被选中，则l/r能被选中也可以不被选中，g(o) = max{f(l), g(l)} + max{f(r), g(r)}
    // 所以我们可以用哈希表来存储f,g的函数值，DFS获得f,g, max{f(root), g(root)}即是答案

    // II. 滚动数组优化
public:
    // I.
    // unordered_map<TreeNode*, int> f, g;
    // void dfs(TreeNode* node) {
    //     if (!node)
    //     {
    //         return;
    //     }
    //     dfs(node->left);
    //     dfs(node->right);
    //     f[node] = node->val + g[node->left] + g[node->right];
    //     g[node] = max(f[node->left], g[node->left]) + max(f[node->right], g[node->right]);
    // }

    // II.
    SubtreeStatus dfs(TreeNode* node) {
        if (!node)
        {
            return {0, 0};
        }
        auto l = dfs(node->left);
        auto r = dfs(node->right);
        int selected = node->val + l.notSelected + r.notSelected;
        int notSelected = max(l.selected, l.notSelected) + max(r.selected, r.notSelected);
        return {selected, notSelected};
    }

    int rob(TreeNode* root) {
        // I.
        // dfs(root);
        // return max(f[root], g[root]);

        // II.
        auto rootStatus = dfs(root);
        return max(rootStatus.selected, rootStatus.notSelected);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,2,3,null,3,null,1]\n
// @lcpr case=end

// @lcpr case=start
// [3,4,5,1,3,null,1]\n
// @lcpr case=end

 */

