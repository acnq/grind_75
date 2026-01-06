/*
 * @lc app=leetcode.cn id=1339 lang=cpp
 * @lcpr version=30204
 *
 * [1339] 分裂二叉树的最大乘积
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
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
};
class Solution {
    // I. 数学
    // 我们记二叉树所有元素值之和为sum_r, 这个可以通过DFS计算
    // 假设我们删除的边的两个端点u,v, u为v的父，则删除这条边之后
    //  有一个以v为根节点的二叉树，记其中的元素和为sum_v; 
    //  另一个子树以原二叉树的根节点root为根节点，元素和sum_r - sum_v
    // 我们需要找到v, s.t. (sum_v) * (sum_r - sum_v)
    // 我们可以遍历v并DFS计算sum_v, 找出目标的最大值，
    // 考虑到我们需要对1e9+7取模，不能在计算的时候取模
    // (因为原本大的，取模之后不一定大)
    // 所以我们使用均值不等式，sum_r为定制，sum_v越接近sum_r的一半
    //  二者的积越大，只需要存储最接近sum_r一半的那个sum_v,最后计算积取模
    // tc: O(N) sc: O(1)

private:
    int mode = 1e9+7;
    int sum = 0;
    int best = 0;
public:
    void dfs(TreeNode* node) {
        // 计算sum_root
        if (!node) {
            return;
        }
        sum += node->val;
        dfs(node->left);
        dfs(node->right);
    }
    int dfs2(TreeNode* node) {
        if (!node) {
            return 0;
        }
        int cur = dfs2(node->left) + dfs2(node->right) + node->val;
        // cur对应当前node的sum_v
        if (abs(cur * 2 - sum) < abs(best * 2 - sum)) {
            // 判断cur是否被best更接近sum的一半
            best = cur;
        }
        return cur;
    }
    int maxProduct(TreeNode* root) {
        dfs(root);
        dfs2(root);
        return (long long) best * (sum - best) % mode;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5,6]\n
// @lcpr case=end

// @lcpr case=start
// [1,null,2,3,4,null,null,5,6]\n
// @lcpr case=end

// @lcpr case=start
// [2,3,9,10,7,8,6,5,4,11,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,1]\n
// @lcpr case=end

 */

