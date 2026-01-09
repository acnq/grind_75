/*
 * @lc app=leetcode.cn id=865 lang=cpp
 * @lcpr version=30204
 *
 * [865] 具有所有最深节点的最小子树
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


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    // I. 递归
    // 首先，最深节点一定是叶节点，我们把最深的叶节点的最近公共祖先，称为lca
    // 递归深度搜索，返回当前子树的最大深度d和lca节点，若为空，返回0和空节点
    // 递归搜索左右子树，比较深度，哪边深，最深叶节点在哪边，返回
    // 如果左/右子树更深，返回{左/右子树深度+1，左/右子树lca节点}
    // 如果左右子树一样深，返回{深度+1, 当前节点}
    // 返回根节点的lca即可
    // tc: O(n), sc: O(d) (n:树的节点数量，d:树的深度)
public:
    pair<TreeNode*, int> f(TreeNode* root){
        if (!root) {
            return {root, 0};
        }
        auto left = f(root->left);
        auto right = f(root->right);

        if (left.second > right.second) {
            return {left.first, left.second + 1};
        }
        if (left.second < right.second) {
            return {right.first, right.second + 1};
        }
        return {root, left.second + 1};
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
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

