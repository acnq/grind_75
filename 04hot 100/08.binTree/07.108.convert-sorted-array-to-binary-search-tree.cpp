// @lcpr-before-debug-begin




// @lcpr-before-debug-end

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
    int val; TreeNode* left; TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {}
};

class Solution {
public:
    TreeNode* invInorder(vector<int> nums, int left, int right) {
        if (left > right) {
            return nullptr;
        }
        int mid = (left + right) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = invInorder(nums, left, mid - 1);
        root->right = invInorder(nums, mid + 1, right);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        // 之前grind 167 写过，尽可能写对叭
        // 关键是将序列看做中序排列，不需要AVL或者红黑树
        return invInorder(nums, 0, nums.size() - 1);
        // 9min, 看了眼函数接口的写法
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

