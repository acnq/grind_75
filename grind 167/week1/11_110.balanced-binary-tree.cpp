/*
 * @lc app=leetcode.cn id=110 lang=cpp
 * @lcpr version=30204
 *
 * [110] 平衡二叉树
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
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    // int height(TreeNode* root) {
    //     if (root == nullptr)
    //     {
    //         return 0;
    //     } else {
    //         return 1 + max(height(root->left), height(root->right));
    //     }
        
    // }
    int height_judge(TreeNode* root) {
        if(root == nullptr) {
            return 0;
        } else {
            int rheight = height_judge(root->right);
            int lheight = height_judge(root->left);
            if (abs(lheight - rheight) <= 1  && lheight != -1 && rheight != -1)
            {
                return max(lheight, rheight) + 1;
            } else {
                return -1;
            }
            
        }
    }
    bool isBalanced(TreeNode* root) {
        // if (root == nullptr)
        // {
        //     return true;
        // }
        
        // if ((abs(height(root->left) - height(root->right)) <= 1) && isBalanced(root->left) && isBalanced(root->right))
        // {
        //     return true;
        // } else {
        //     return false;
        // }
        if (height_judge(root) == -1)
        {
            return false;
        } else {
            return true;
        }
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,9,20,null,null,15,7]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,2,3,3,null,null,4,4]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */

