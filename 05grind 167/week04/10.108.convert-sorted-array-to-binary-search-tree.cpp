/*
 * @lc app=leetcode.cn id=108 lang=cpp
 * @lcpr version=30204
 *
 * [108] 将有序数组转换为二叉搜索树
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
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
    // 完全没思路，看到题干还以为要用AVL, 直接大脑宕机看答案了TAT
    // 
    // 题眼在这里：将这个序列看做中序遍历的结果，
    // 当然，仅有中序遍历是无法重建一棵树的，即便要求树平衡也不行
    // 但是，如果我们选择这个序列的中点作为根，并且对于左右部分都递归重复此操作
    // 那么结果一定不会是不平衡的。平衡树的结果不同，是因为长度为偶数的情况下，
    // 可以选择中间偏左，或者中间偏右的元素作为根。下面三种方法使用了不同策略应对偶数长度
    // I. 左派
    // 中序遍历，根下标设为mid = (l + r) / 2;

    // II. 右派
    // 中序，根下标设为mid = (l + r + 1) / 2;

    // III.混沌派
    // 中序，根设定为随机值 mid = (l + r + rand() % 2) / 2
public:
    TreeNode* helper(vector<int>& nums, int left, int right) {
        if(left > right) {
            return nullptr;
        }
        // I.
        // int mid = (left + right) / 2;
        // II.
        // int mid = (left + right + 1) / 2;
        // III.
        int mid = (left + right + rand() % 2) / 2;

        TreeNode* root = new TreeNode(nums[mid]);
        root->left = helper(nums, left, mid - 1);
        root->right = helper(nums, mid + 1, right);
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [-10,-3,0,5,9]\n
// @lcpr case=end

// @lcpr case=start
// [1,3]\n
// @lcpr case=end

 */

