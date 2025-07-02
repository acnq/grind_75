/*
 * @lc app=leetcode.cn id=662 lang=cpp
 * @lcpr version=30204
 *
 * [662] 二叉树最大宽度
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
    int val; TreeNode* left; TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
};

class Solution {
    // I. BFS
    // 求出每一层的宽度然后求出最大值即可，
    // 因为两端点之间的null也要计入宽度，因此可以对节点编号
    // idx的左子结点编号记为2 * idx, 右子节点2 * idx + 1, 
    // 每层宽度计算时，=每层节点的最大编号-最小编号+1
    // tc/sc: O(n)

    // II. DFS
    // 依照上述编号，遍历时先左后右，因此每一层最先访问到的时最左节点
    // 就是每一层编号的最小值，记录下来进行后续比较。一次深度优先搜索中，
    // 需要当前节点到当前最左节点的宽度，然后再对子节点深搜，更新最大宽度即可。
    // tc/sc: O(n)
public:
    int widthOfBinaryTree(TreeNode* root) {
        // I.
        // unsigned long long res = 1;
        // vector<pair<TreeNode*, unsigned long long>> arr;
        // arr.emplace_back(root, 1L);
        // while (!arr.empty())
        // {
        //     vector<pair<TreeNode*, unsigned long long>> tmp;
        //     for(auto &[node, idx]: arr) {
        //         if (node->left)
        //         {
        //             tmp.emplace_back(node->left, idx * 2);
        //         }
        //         if (node->right)
        //         {
        //             tmp.emplace_back(node->right, idx * 2 + 1);
        //         }
        //     }
        //     res = max(res, arr.back().second - arr[0].second + 1);
        //     arr = move(tmp);
        // }
        // return res;

        // II.
        using ULL = unsigned long long;
        unordered_map<int, ULL> levelMin;
        function<ULL(TreeNode*, int, ULL)> dfs = [&](TreeNode* node, int depth, ULL idx) -> ULL {
            if (node == nullptr)
            {
                return 0LL;
            }
            if (!levelMin.count(depth))
            {
                levelMin[depth] = idx; // 每层最先访问的是最左的，即每层最小值
            }
            return max({idx - levelMin[depth] + 1LL, dfs(node->left, depth + 1, idx * 2), dfs(node->right, depth + 1, idx * 2 + 1)});
        };
        return dfs(root, 1, 1LL);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,3,2,5,3,null,9]\n
// @lcpr case=end

// @lcpr case=start
// [1,3,2,5,null,null,9,6,null,7]\n
// @lcpr case=end

// @lcpr case=start
// [1,3,2,5]\n
// @lcpr case=end

 */

