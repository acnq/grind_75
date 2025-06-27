/*
 * @lc app=leetcode.cn id=437 lang=cpp
 * @lcpr version=30204
 *
 * [437] 路径总和 III
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
    // I. DFS
    // 穷举所有可能，
    // 定义rootSum(p, val)表示节点p为起点，向下且满足路径总和为val的路径数目
    // 对二叉树每个结点p求出rootSum(p, targetSum), 对所有路径数目求和即为结果
    // rootSum可以递归实现，对左右分别求出rootSum(p, targetSum - val), 加和即可
    // 另外要特判当前节点是否恰好等于targetSum
    // tc: O(N^2), sc: O(N)

    // II. 前缀和
    // 定义节点的前缀和：根节点到当前节点的路径上所有节点的和
    // 先序遍历，记录根节点root到当前节点p的路径上所有节点的前缀和
    // 然后只需要在已保存的前缀和中寻找是否存在前缀和刚好等于当前节点到根节点的前缀和cur-targetSum
    // 空路径前缀和=0
    // 假设访问的节点node, 且root到node的路径：root->p_1 -> ... ->p_k -> node
    // 此时已经计算了p_i和node的前缀和
    // 假设root->node的前缀和为cur, 查找是否存在前缀和恰好为cur-tgtSum
    // 假设从root->p_i的前缀和为cur-targetSum, 则p_{i + 1}->node的所有节点一定为targetSum
    // tc: O(N), sc: O(N)
public:

    // I.
    long long rootSum(TreeNode* root, long long targetSum) {
        if (!root) {
            return 0;
        }
        long long ret = 0;
        if (root->val == targetSum) {
            ret++;
        }
        ret += rootSum(root->left, targetSum - root->val);
        ret += rootSum(root->right, targetSum - root->val);
        return ret;
    }

    // II.
    unordered_map<long long, int> prefix;
    int dfs(TreeNode* root, long long cur, int targetSum) {
        if (!root) {
            return 0;
        }
        int ret = 0;
        cur += root->val;
        if (prefix.count(cur - targetSum)) {
            ret = prefix[cur - targetSum];
        }
        prefix[cur]++;
        ret += dfs(root->left, cur, targetSum);
        ret += dfs(root->right, cur, targetSum);
        prefix[cur]--;
        return ret;
    }

    int pathSum(TreeNode* root, int targetSum) {
        // I.
        // if (!root) {
        //     return 0;
        // }
        // long long ret = rootSum(root, targetSum);
        // ret += pathSum(root->left, targetSum);
        // ret += pathSum(root->right, targetSum);
        // return (int) ret;

        // II.
        prefix[0] = 1;
        return dfs(root, 0, targetSum);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [10,5,-3,3,2,null,11,3,-2,null,1]\n8\n
// @lcpr case=end

// @lcpr case=start
// [5,4,8,11,null,13,4,7,2,null,null,5,1]\n22\n
// @lcpr case=end

 */

