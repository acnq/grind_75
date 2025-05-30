// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=1128 lang=cpp
 * @lcpr version=30204
 *
 * [1128] 等价多米诺骨牌对的数量
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
    // 哈希法，暴力枚举会超时
    // 注意domino[i] = [a, b], 1 <= a, b <= 9, 直接当做一个十进制数a * 10 + b 即可
public:
    // bool dominoEquiv(vector<int> domino1, vector<int> domino2) {
    //     int a = domino1[0], b = domino1[1], c = domino2[0], d = domino2[1];
    //     if ((a == c && b == d) || (a == d && b == c))
    //     {
    //         return true;
    //     } else {
    //         return false;
    //     }
    // }


    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        
        int res = 0;
        int n = dominoes.size();
        unordered_map<int, int> stats;
        for (int i = 0; i < n; i++)
        {
            // 官方题解解决方案：强制规定小者在前一位
            // int domin_value = 10 * dominoes[i][0] + dominoes[i][1];
            int domin_value = 0;
            if (dominoes[i][0] > dominoes[i][1])
            {
                domin_value = 10 * dominoes[i][1] + dominoes[i][0];
            } else {
                domin_value = 10 * dominoes[i][0] + dominoes[i][1];
            }
            
            res += stats[domin_value];
            stats[domin_value]++;
            // res = max(stats[domin_value], res);
        }
        return res;
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=numEquivDominoPairs
// paramTypes= ["number[][]"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// [[1,2],[2,1],[3,4],[5,6]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2],[1,2],[1,1],[1,2],[2,2]]\n
// @lcpr case=end

 */

