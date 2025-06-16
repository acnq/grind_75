/*
 * @lc app=leetcode.cn id=79 lang=cpp
 * @lcpr version=30204
 *
 * [79] 单词搜索
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
class Solution {
    // 回溯
    // check(i, j, k)判断(i, k)出发，能否搜索到单词word[k...],
    // word[k...]表示从k开始的后缀字符，
    // 步骤如下：
    //      board[i][j] != word[k], 返回false
    //      已经访问到末尾，返回true
    //      否则，遍历当前所有相邻位置，如果从某个位置出发能够搜索到word[k+1*], 返回true
    // 还需再维护一个visited数组表示位置是否被访问过
public:
    bool check(vector<vector<char>>& board, vector<vector<int>>& visited, int i, int j, string& s, int k) {
        if (board[i][j] != s[k])
        {
            return false;
        } else if (k == s.length() - 1)
        {
            return true;
        }
        visited[i][j] = true;
        vector<pair<int, int>> dirs{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        bool result = false;
        for(const auto& dir: dirs) {
            int new_i = i + dir.first, new_j = j + dir.second;
            if (new_i >= 0 && new_i < board.size() && new_j >= 0 && new_j < board[0].size())
            {
                if (!visited[new_i][new_j])
                {
                    bool flag = check(board, visited, new_i, new_j, s, k + 1);
                    if (flag)
                    {
                        result = true;
                        break;
                    } // 一个方向能找到就符合条件
                }
            }
        }
        visited[i][j] = false;
        return result;
    } 
    bool exist(vector<vector<char>>& board, string word) {
        int h = board.size(), w = board[0].size();
        vector<vector<int>> visited(h, vector<int>(w));
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                bool flag = check(board, visited, i, j, word, 0);
                if (flag)
                {
                    return true;
                }
            }
        }
        return false;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"\n
// @lcpr case=end

// @lcpr case=start
// [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"SEE"\n
// @lcpr case=end

// @lcpr case=start
// [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCB"\n
// @lcpr case=end

 */

