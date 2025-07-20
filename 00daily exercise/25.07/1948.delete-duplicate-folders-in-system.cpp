/*
 * @lc app=leetcode.cn id=1948 lang=cpp
 * @lcpr version=30204
 *
 * [1948] 删除系统中的重复文件夹
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
struct Trie{
    // 当前节点的序列化表示
    string serial;
    // 当前节点的子节点
    unordered_map<string, Trie*> children;
};

class Solution {
    // I. 子树序列化
    // 第一步：给定的paths, 构造出树形表示：多叉树，根为/, 非根节点为文件夹
    // 第二步：从根节点开始一次遍历，如果两个节点(x, y)的“子文件夹结构”（子文件夹的子文件夹递归到空）
    //        完全相同，则x, y都要进行删除，为了得到某一节点的子文件夹结构，首先遍历完该节点的所有子
    //        再回溯遍历该节点本身，这实际上对应着“后序遍历”，同时记录该节点的结构
    // 第三步：从根节点开始二次遍历，遍历到x，如果x的结构出现在存储中超过一次，那么就说明存在与x相同的文件夹
    //        删除x并回溯，否则x就是唯一的，将从根节点开始到他的路径计入答案，并继续遍历x的子
    // 第一步可以直接用trie实现
    // 第二步的难点在于存储树节点的“结构”，参考T297二叉树序列化，我们实现一个多叉树序列化
    // serial(x)记录x的序列化表示，具体如下：
    //  1. x为叶，=> serial(x) = "" (空串)
    //  2. x非叶，有子y_1, y_2, ..., y_k, serial(x) = y1(serial(y1))y2(serial(y2))...y_k(serial(yk))
    //      为了避免顺序不同，y_i序列化之后凭借之前要排序，可以直接字典序排列
    // 第三部进行深度优先搜索路径的哈希就可以了
public:
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        // 根节点
        Trie* root = new Trie();
        
        for (const vector<string>& path: paths) {
            Trie* cur = root;
            for (const string& node: path) {
                if (!cur->children.count(node)) {
                    cur->children[node] = new Trie();
                }
                cur = cur->children[node];
            }
        }

        // 哈希表记录每一种序列化出现次数
        unordered_map<string, int> freq;
        // dfs后序遍历，计算节点结构的序列化表示
        function<void(Trie*)> construct = [&](Trie* node) {
            // 叶节点，序列化表示空串，无需操作
            if (node->children.empty()) {
                return;
            }

            vector<string> v;
            // 若非叶结点，计算子节点结构的序列化
            for (const auto& [folder, child]: node->children) {
                construct(child);
                v.push_back(folder + "(" + child->serial + ")");
            }
            // 排序
            sort(v.begin(), v.end());
            for (string& s: v) {
                node->serial += move(s);
            }
            // 计入哈希
            freq[node->serial]++;
        };

        construct(root);

        vector<vector<string>> ans;
        // 记录根节点到当前的路径
        vector<string> path;

        function<void(Trie*)> operate = [&](Trie* node) {
            // 序列化超过一次就要删除
            if (freq[node->serial] > 1) {
                return;
            }
            // 否则加入答案
            if (!path.empty()) {
                ans.push_back(path);
            }
            for (const auto& [folder, child]: node->children) {
                path.push_back(folder);
                operate(child);
                path.pop_back();
            }
        };

        operate(root);
        return ans;
    };
};
// @lc code=end



/*
// @lcpr case=start
// [["a"],["c"],["d"],["a","b"],["c","b"],["d","a"]]\n
// @lcpr case=end

// @lcpr case=start
// [["a"],["c"],["a","b"],["c","b"],["a","b","x"],["a","b","x","y"],["w"],["w","y"]]\n
// @lcpr case=end

// @lcpr case=start
// [["a","b"],["c","d"],["c"],["a"]]\n
// @lcpr case=end

// @lcpr case=start
// [["a"],["a","x"],["a","x","y"],["a","z"],["b"],["b","x"],["b","x","y"],["b","z"]]\n
// @lcpr case=end

// @lcpr case=start
// [["a"],["a","x"],["a","x","y"],["a","z"],["b"],["b","x"],["b","x","y"],["b","z"],["b","w"]]\n
// @lcpr case=end

 */

