/*
 * @lc app=leetcode.cn id=3838 lang=cpp
 * @lcpr version=30204
 *
 * [3838] 带权单词映射
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
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        // O. 4min32s 秒杀
        string ans = "";
        for (string word: words) {
            int weight = 0;
            for (char ch: word) {
                weight += weights[ch - 'a'];
            }
            weight = weight % 26;
            char need = 'z' - weight;
            ans += need;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["abcd","def","xyz"]\n[5,3,12,14,1,2,3,2,10,6,6,9,7,8,7,10,8,9,6,9,9,8,3,7,7,2]\n
// @lcpr case=end

// @lcpr case=start
// ["a","b","c"]\n[1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1]\n
// @lcpr case=end

// @lcpr case=start
// ["abcd"]\n[7,5,3,4,3,5,4,9,4,2,2,7,10,2,5,10,6,1,2,2,4,1,3,4,4,5]\n
// @lcpr case=end

 */

