// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=1161 lang=cpp
 * @lcpr version=30204
 *
 * [1161] 最大层内元素和
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
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
};
class Solution {
public:
    vector<int> sum;
    void dfs(TreeNode* node, int level) {

        if (node == nullptr) {
            return;
        }

        if (level == sum.size()) {
            // 到达sum的长度, 看题解看出来的
            sum.push_back(node->val);
        } else {
            sum[level] += node->val;
        }
        
        dfs(node->left, level + 1);
        dfs(node->right, level + 1);
    }
    int maxLevelSum(TreeNode* root) {
        // I.深度优先（通过记录层级来保持）
        // dfs(root, 0);
        // // int max = INT_MIN, max_idx = -1;
        // // for(int i = 0; i < sum.size(); i++) {
        // //     cout << sum[i] << endl;
        // // }
        // // for (int i = 0; i < sum.size(); i++) {
        // //     if (sum[i] > max) {
        // //         max_idx = i;
        // //         max = sum[i];
        // //     }
        // // }
        // // 这一部分官方题解写的更好，但我的也对
        // int max_idx = 0;
        // for (int i = 0; i < sum.size(); i++) {
        //     if (sum[i] > sum[max_idx]) {
        //         max_idx = i;
        //     }
        // }
        // return max_idx + 1;
        // 广度优先
        int ans = 1, maxSum = root->val;
        vector<TreeNode*> q = {root}; // 层序遍历的队列
        for (int level = 1; !q.empty(); level++) {
            vector<TreeNode*> nq; // next queue
            int sum = 0;
            for (auto node: q) {
                // q始终维护一层的节点
                sum += node->val;
                if (node->left) {
                    nq.emplace_back(node->left);
                }
                if (node->right) {
                    nq.emplace_back(node->right);
                }
            }
            if (sum > maxSum) {
                maxSum = sum;
                ans = level;
            }
            q = move(nq); // 移动复制函数，将nq赋值给q
        }
        return ans;
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=maxLevelSum
// paramTypes= ["number[]"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// [1,7,0,7,-8,null,null]\n
// @lcpr case=end

// @lcpr case=start
// [989,null,10250,98693,-89388,null,null,null,-32127]\n
// @lcpr case=end

 */

