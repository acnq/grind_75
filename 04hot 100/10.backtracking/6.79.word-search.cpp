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
    // I. 回溯
    // check(i, j, k), 判断以网格(i, j)出发，能否搜索到单词word[k:]
    // 步骤如下：
    // 1. board[i][j] != word[k], 当前字符不匹配，返回False
    // 2. 已经访问到字符串末尾，且字符依然匹配，返回true
    // 3. 遍历当前位置的所有相邻位置，如果某个相邻位置能找到子串word[(k+1):]
    //    返回true，否则返回False。
    // 对于每个位置(i, j)都要调用check(i, j, 0)进行检查；一处返回true就能找到
    // 额外维护vis数组，用于标识是否被访问，以免遍历相邻位置时重复访问遍历过的进入死循环。
    // tc: \Theta(MN * 3^L) (MN: board大小，L: word长度)； sc: O(MN)
public:
    bool check(vector<vector<char>>& board, vector<vector<int>>& vis, int i, int j, string& s, int k) {
        if (board[i][j] != s[k])
        {
            return false;
        } else if (k == s.length() - 1)
        {
            return true;
        }
        vis[i][j] = true;
        vector<pair<int, int>> dirs{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        bool res = false;
        for (const auto& dir: dirs) {
            int ni = i + dir.first, nj = j + dir.second;
            if (ni >= 0 && ni < board.size() && nj >= 0 && nj < board[0].size())
            {
                if (!vis[ni][nj])
                {
                    bool flag = check(board, vis, ni, nj, s, k + 1);
                    if (flag)
                    {
                        res = true;
                        break;
                    }
                }
            }
        }
        vis[i][j] = false;
        return res;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int h = board.size(), w = board[0].size();
        vector<vector<int>> vis(h, vector<int>(w));

        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                bool flag = check(board, vis, i, j, word, 0);
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

