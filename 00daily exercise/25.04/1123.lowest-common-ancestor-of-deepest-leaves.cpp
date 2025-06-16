/*
 * @lc app=leetcode.cn id=1123 lang=cpp
 * @lcpr version=30204
 *
 * [1123] 最深叶节点的最近公共祖先
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
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
};

class Solution {
    // 所有深度最大的节点，都是树的叶节点
    // 把最深的叶节点的最近公共祖先，称为lca
    // dfs:
    // 当前子树的最大深度和lca, 
    // 左子树更深，则最深叶节点在左子树中，返回{左子树深度+1， 左子树lca节点}
    // 右子树更深，             右子树 , 返回{右子树深度+1,  右子树lca节点}
    // 左右一样深，则左右两树都有最深叶节点，返回{左子树+1， 当前节点}
    // 出口：空节点深度=0, lca=空
public:
    pair<TreeNode*, int> f(TreeNode* root) {
        if (!root)
        {
            return {root, 0};
        }

        auto left = f(root->left);
        auto right = f(root->right);

        if (left.second > right.second)
        {
            return {left.first, left.second + 1};
        }
        if (left.second < right.second)
        {
            return {right.first, right.second + 1};
        }
        return {root, left.second + 1};
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return f(root).first;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,5,1,6,2,0,8,null,null,7,4]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

// @lcpr case=start
// [0,1,3,null,2]\n
// @lcpr case=end

 */

