// @lcpr-before-debug-begin




// @lcpr-before-debug-end

// @before-stub-for-debug-begin
#include <vector>
#include <string>

using namespace std;
// @before-stub-for-debug-end

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

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};


class Solution {
public:

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // make sure target belong to root beforehead;
        TreeNode* cur = root;
        int pval = p->val;
        int qval = q->val;
        while (cur != nullptr)
        {
            
            int cval = cur-> val;
            if(cval > pval && cval > qval) {
                cur = cur->left;
            } else if (cval < pval && cval < qval)
            {            
                cur = cur->right;
            } else {
                break;
            }
        }
        // path.push_back(cur);
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

