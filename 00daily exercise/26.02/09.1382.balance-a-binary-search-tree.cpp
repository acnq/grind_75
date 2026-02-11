/*
 * @lc app=leetcode.cn id=1382 lang=cpp
 * @lcpr version=30204
 *
 * [1382] 将二叉搜索树变平衡
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
    // I. 贪心构造
    // 首先将二叉搜索树转化为有序序列，然后递归建树，i.e., 对区间[L, R]:
    // 取mid = \floor((L + R) / 2), i.e.中心位置作为当前节点的值;
    // 如若L <= mid - 1, 递归将区间[L, mid-1]作为左子树
    // 如若mid + 1 <= R, 递归将区间[mid+1, R]作为右子树
    // 证明：
    // 首先我们有：对于一个长度为x的区间，如上的构造方法得到的树高度h(x) = \floor(log_2 x) + 1
    // 引理：长度为k的区间与长度为k + 1的区间（k>=1）按此方法构造出的二叉树最大高差不超过1
    //   证明：h(k + 1) - h(k) = \floor(log_2(k + 1)) - \floor(log_2(k)) <= 1
    //         设k = 2^r + b, 其中0<=b<2^r, k \in[2^r, 2^{r + 1}], RHS = r + 1;
    //          k + 1 \in (2^r, 2^{r + 1}), LHS = \floor{log_2(k + 1)}
    //         \floor{x} <= x 显然成立，引理得证，
    // 最后我们用数归完成这个证明：
    //  假设区间为k, k=1;k=2均显然成立；
    //  我们假设k=m && k = m + 1时正确成立
    //   1. 由引理：长度为m/m+1区间构造出的子树都是平衡的，高度差不超过1；
    //   2. k = 2(m + 1) - 1, 根是第m+1个元素的值，左右均为长度m的区间，由1，知正确
    //   3. k = 2(m + 1), 根也是第m+1个元素的值，左右区间分别为m, m+1, 由1, 也知算法正确
    // 由此知道算法覆盖所有k>=1的情况。
    // tc: O(n),sc: O(n)
public:
    vector<int> inorderSeq;
    
    void getInorder(TreeNode* o) {
        if (o->left) {
            getInorder(o->left);
        }
        inorderSeq.push_back(o->val);
        if (o->right) {
            getInorder(o->right);
        }
    }

    TreeNode* build(int l, int r) {
        int mid = (l + r) >> 1;
        TreeNode* o = new TreeNode(inorderSeq[mid]);
        if (l <= mid - 1) {
            o->left = build(l, mid - 1);
        }
        if (mid + 1 <= r) {
            o->right = build(mid + 1, r);
        }
        return o;
    }
    TreeNode* balanceBST(TreeNode* root) {
        getInorder(root);
        return build(0, inorderSeq.size() - 1);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,null,2,null,3,null,4,null,null]\n
// @lcpr case=end

// @lcpr case=start
// [2,1,3]\n
// @lcpr case=end

 */

