// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=543 lang=cpp
 * @lcpr version=30204
 *
 * [543] 二叉树的直径
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
    int val; TreeNode* left; TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {}
};

class Solution {
    // 思路有问题，完全可以不经过root
    // I. DFS
    // 已知求得最大深度的算法d(node)之后
    // 我们要搜索每个结点的d_node的值（左子树深度+右子树深度+1)
    // 然后记录最大值。
public:
    // O.
    // int maxDepth(TreeNode* root) {
    //     if (root == nullptr) {
    //         return 0;
    //     } else {
    //         return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    //     }
    // }
    int depth(TreeNode* root, int& ans) {
        if (root == nullptr) {
            return 0;
        } else {
            int L = depth(root->left, ans);
            int R = depth(root->right, ans);
            ans = max(ans, L + R + 1);
            return max(L, R) + 1;
        }
    }
    int diameterOfBinaryTree(TreeNode* root) {
        // O
        // if (root == nullptr) {
        //     return 0;
        // } else {
        //     return maxDepth(root->left) + maxDepth(root->right);
        // }

        // I.
        int ans = 1;
        depth(root, ans);
        return ans - 1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5]\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n
// @lcpr case=end


// @lcpr case=start
// [4,-7,-3,null,null,-9,-3,9,-7,-4,null,6,null,-6,-6,null,null,0,6,5,null,9,null,null,-1,-4,null,null,null,-2]\n
// @lcpr case=end
 */

