// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=235 lang=cpp
 * @lcpr version=30204
 *
 * [235] 二叉搜索树的最近公共祖先
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // vector<TreeNode*> getPath(TreeNode* root, TreeNode* target) {
    //     vector<TreeNode*> path;
    //     TreeNode* p = root;
    //     int tgt = target->val;
    //     while (tgt != p->val)
    //     {
    //         path.push_back(p);
    //         if (p->val > tgt)
    //         {
    //             p = p->left;
    //         } else if (p->val < tgt)
    //         {
    //             p = p->right;
    //         } else {
    //             break;
    //         }
    //     }
    //     path.push_back(p);
    //     return path;
    // }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // vector<TreeNode*> path1 = getPath(root, p);
        // vector<TreeNode*> path2 = getPath(root, q);
        // int N = min(path1.size(), path2.size());
        // int M = max(path1.size(), path2.size());
        // for (int i = 0; i < N; i++)
        // {
        //     if (path1[i] != path2[i])
        //     {
        //         int res = i - 1;
        //         return path1[res];
        //     }
        // }
        // if (path1.size() < path2.size())
        // {
        //     return path1[path1.size() - 1];
        // } else {
        //     return path2[path2.size() - 1];
        // }
        //     vector<TreeNode*> path;
        TreeNode* cur = root;
        int p_v = p->val;
        int q_v = q->val;
        while (p_v != cur->val && q_v != cur->val)
        {
            if (cur->val > p_v && cur->val > q_v)
            {
                cur = cur->left;
            } else if (cur->val < p_v && cur->val < q_v)
            {
                cur = cur->right;
            } else {
                break;
            }
        }
        
        return cur;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [6,2,8,0,4,7,9,null,null,3,5]\n2\n8\n
// @lcpr case=end

// @lcpr case=start
// [6,2,8,0,4,7,9,null,null,3,5]\n2\n4\n
// @lcpr case=end

 */

