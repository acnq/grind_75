// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=1275 lang=cpp
 * @lcpr version=30204
 *
 * [1275] 找出井字棋的获胜者
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
    // I. 枚举
    // 与其用数学统计，不如直接枚举情况
public:
    bool line(vector<vector<int>>& line) {
        if (line.size() < 3)
        {
            return false;
        }
        // row_line and col_line
        vector<int> rowcnt(3, 0);
        vector<int> colcnt(3, 0);
        for(int i = 0; i < line.size(); i++) {
            switch (line[i][0])
            {
            case 0:
                rowcnt[0]++;
                break;
            case 1:
                rowcnt[1]++;
                break;
            case 2:
                rowcnt[2]++;
                break;
            default:
                break;
            }

            switch (line[i][1])
            {
            case 0:
                colcnt[0]++;
                break;
            case 1:
                colcnt[1]++;
                break;
            case 2:
                colcnt[2]++;
                break;
            default:
                break;
            }
        }
        if (count(rowcnt.begin(), rowcnt.end(), 3) || count(colcnt.begin(), colcnt.end(), 3))
        {
            return true;
        }
        // diag
        int mdiag_cnt = 0, sdiag_cnt = 0;
        for(int i = 0; i < line.size(); i++) {
            if (line[i][0] == line[i][1])
            {
                mdiag_cnt++;
            }
            if (line[i][0] + line[i][1] == 2)
            {
                sdiag_cnt++;
            }
        }
        if (mdiag_cnt == 3 || sdiag_cnt == 3)
        {
            return true;
        }
        return false;
    }

    // I. 
    bool checkwin(unordered_set<int>& S, vector<vector<int>>& wins) {
        for (auto win: wins) {
            bool flag = true;
            for (auto pos: win) {
                if (!S.count(pos))
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                return true;
            }
        }
        return false;
    }
    string tictactoe(vector<vector<int>>& moves) {
        string ans;
        int n = moves.size();
        vector<vector<int>> As, Bs;
        for(int i = 0; i < n; i++) {
            if(i % 2 == 0) {
                As.push_back(moves[i]);
            } else {
                Bs.push_back(moves[i]);
            }
        }
        if (line(As) || line(Bs))
        {
            return line(As) ? "A" : "B";
        } else {
            return n == 9 ? "Draw" : "Pending"; 
        }
        // 写了五十分钟，感觉很繁琐

        // I.
        vector<vector<int>> wins = {
            {0, 1, 2},
            {3, 4, 5},
            {6, 7, 8},
            {0, 3, 6},
            {1, 4, 7},
            {2, 5, 8},
            {0, 4, 8},
            {2, 4, 6}
        };
        unordered_set<int> A, B;
        for (int i = 0; i < moves.size(); i++)
        {
            int pos = moves[i][0] * 3 + moves[i][1];
            if (i % 2 == 0) {
                A.insert(pos);
                if (checkwin(A, wins))
                {
                    return "A";
                }
            } else {
                B.insert(pos);
                if (checkwin(B, wins))
                {
                    return "B";
                }
                
            }
        }
        
        return (moves.size() == 9 ? "Draw" : "Pending");
        
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=tictactoe
// paramTypes= ["number[][]"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// [[0,0],[2,0],[1,1],[2,1],[2,2]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,0],[1,1],[0,1],[0,2],[1,0],[2,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,0],[1,1],[2,0],[1,0],[1,2],[2,1],[0,1],[0,2],[2,2]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,2],[2,2],[1,0],[0,0],[1,2],[2,0],[1,1]]\n
// @lcpr case=end


 */

