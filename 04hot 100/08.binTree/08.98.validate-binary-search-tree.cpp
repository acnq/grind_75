/*
 * @lc app=leetcode.cn id=98 lang=cpp
 * @lcpr version=30204
 *
 * [98] 验证二叉搜索树
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
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {}
};

class Solution {
    // I. 递归
    // 不能用O.的写法只考虑根节点，相反，我们需要左右子树的所有节点都满足约束条件
    // 那么问题在于，我们需要同时返回子树的最大值和最小值么？
    // 给出一个更简易的接口：check(root, lower, upper)判断root为根的子树，然后判断值
    // 是否在(lower, uppder) (注意是开区间)之内，一旦违反返回false, 就不需要额外返回了。
    // 注意node.val 在+-2^(31) - 1之内，所以得用long

    // II. 中序遍历
    // 满足条件的二叉搜索树中序遍历的结果一定是升序的，否则不是
    // 参考答案用迭代方案些中序遍历，这样在遍历的同时可以直接判断
public:
    // I. 
    bool check(TreeNode* root, long long lower, long long upper) {
        if (root == nullptr) {
            return true;
        }
        if (root->val <= lower || root->val >= upper) {
            return false; // 注意开区间，相等也不行
        } else {
            return check(root->left, lower, root->val) && check(root->right, root->val, upper);
        }
    }
    bool isValidBST(TreeNode* root) {
        // O.
        // if (root == nullptr) {
        //     return true;
        // }
        // if (!isValidBST(root->left) || !isValidBST(root->right)) {
        //     return false;
        // }
        // if (root->left != nullptr && root->left->val > root->val) {
        //     return false;
        // } 
        // if (root->right != nullptr && root->right->val < root->val) {
        //     return false;
        // }
        // return true;
        // 这种写法有问题：[5,4,6,null,null,3,7]是一个反例

        // I.
        // return check(root, -LONG_MAX, LONG_MAX);

        // II. 
        stack<TreeNode*> stk;
        long long inorder = (long long)INT_MIN - 1;
        // 中序遍历的上一个元素；

        while (root != nullptr || (!stk.empty())) {
            while (root != nullptr) {
                stk.push(root);
                root = root->left;
            }

            root = stk.top();
            stk.pop();
            if (root ->val <= inorder) { 
                // 如若中序遍历得到的节点元素<=前一个，直接返回不是
                return false;
            }
            inorder = root->val;
            root = root->right;
        }
        return true;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,1,3]\n
// @lcpr case=end

// @lcpr case=start
// [5,1,4,null,null,3,6]\n
// @lcpr case=end

 */

