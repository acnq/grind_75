/*
 * @lc app=leetcode.cn id=212 lang=cpp
 * @lcpr version=30204
 *
 * [212] 单词搜索 II
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

#include <set> 
// @lcpr-template-end
// @lc code=start

struct TrieNode
{
    string word;
    unordered_map<char, TrieNode*> children;
    TrieNode() {
        this->word = "";
    }
};

void insertTrie(TrieNode* root, const string& word) {
    TrieNode* node = root;
    for (auto c: word) {
        if (!node->children.count(c))
        {
            node->children[c] = new TrieNode();
        }
        node = node->children[c];
    }
    node->word = word; // 叶节点有word，其他没有。
}

class Solution {
    // I. 回溯 + 字典树
    // 字典树可以实现O(|S|)插入字符串或查询前缀的长度
    // 需要遍历二维网格中的每一个单元格；然后深度搜索从该单元格出发的所有路径，
    // 找到其中对应words中的单词路径
    // 因为题目要求同个单元格内字母在“一个单词”中不能被重复使用；
    // 所以在DFS中，没经过个单元格，都要将单元格字母临时修改为特殊字符（'#'), 避免再次经过
    // 如果当前路径是words中的单词，则将其添加到结果集中，如果当前路径是words中任意一个单词的前缀
    // 则继续搜索；反之，如果不是words中任意一个单词的前缀，则剪枝，
    // 具体实现中，注意同一个单词可以出现在多个不同路径中出现，所以我们需要使用哈希集合去重
    // 回溯过程中，我们不需要每一步都判断当前路径是否是words中任意一个单词的前缀；
    // 而是可以记录下路径中每个单元格所对应的前缀树结点，
    // 每次只需要判断新增单元格的字母是否是上一个单元格对应前缀树节点的子节点即可。
    // tc: O(m * n * 3^{l - 1}); sc: O(k * l)

    // II. 删除被匹配的单词
    // 我们可以将匹配到前缀树移除，来避免重复寻找相同的单词，
    // 这样可以保证每个单词只能匹配一次。
public:
    int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    // I.
    // bool dfs(vector<vector<char>>& board, int x, int y, TrieNode* root, set<string>& res) {
    //     char ch = board[x][y];
    //     if (!root->children.count(ch))
    //     {
    //         return false;
    //     }
    //     root = root->children[ch];
    //     if (root->word.size() > 0)
    //     {
    //         res.insert(root->word); // 到达叶节点了
    //     }
    //     board[x][y] = '#';
    //     for (int i = 0; i < 4; i++)
    //     {
    //         int nx = x + dirs[i][0];
    //         int ny = y + dirs[i][1];
    //         if (nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size())
    //         {
    //             if (board[nx][ny] != '#')
    //             {
    //                 dfs(board, nx, ny, root,res);
    //             }
    //         }
    //     }
        
    //     board[x][y] = ch;
    //     return true;
    // }

    // II.
    bool dfs(vector<vector<char>>& board, int x, int y, TrieNode* root, set<string>& res) {
        char ch = board[x][y];

        if (root == nullptr || !root->children.count(ch))
        {
            return false;
        }
        
        TrieNode* nxt = root->children[ch];
        if (nxt->word.size() > 0)
        {
            res.insert(nxt->word);
            nxt->word = "";
        }
        if (!nxt->children.empty())
        {
            board[x][y] = '#';
            for (int i = 0; i < 4; i++)
            {
                int nx = x + dirs[i][0];
                int ny = y + dirs[i][1];
                if (nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size())
                {
                    if (board[nx][ny] != '#')
                    {
                        dfs(board, nx, ny, nxt, res);
                    }
                }
            }
            board[x][y] = ch;
        }
        if (nxt->children.empty())
        {
            root->children.erase(ch);
        }
        return true;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        set<string> res;
        vector<string> ans;

        for (auto& word: words) {
            insertTrie(root, word);
        }
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                dfs(board, i, j, root, res);
            }
        }
        for (auto& word: res) {
            ans.emplace_back(word);
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]]\n["oath","pea","eat","rain"]\n
// @lcpr case=end

// @lcpr case=start
// [["a","b"],["c","d"]]\n["abcb"]\n
// @lcpr case=end

 */

