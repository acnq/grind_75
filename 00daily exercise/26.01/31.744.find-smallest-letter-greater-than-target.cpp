/*
 * @lc app=leetcode.cn id=744 lang=cpp
 * @lcpr version=30204
 *
 * [744] 寻找比目标字母大的最小字母
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
    char nextGreatestLetter(vector<char>& letters, char target) {
        // int n = letters.size();
        // for (int i = 0; i < n; i++) {
        //     if (target < letters[i]) {
        //         return letters[i];
        //     }
        // }
        // return letters[0];
        // II. 二分
        return target < letters.back() ? *upper_bound(letters.begin(), letters.end() - 1, target) : letters[0];
    }
};
// @lc code=end



/*
// @lcpr case=start
// ['c', 'f'\n'a'\n
// @lcpr case=end

// @lcpr case=start
// ['c','f','j']\n'c'\n
// @lcpr case=end

// @lcpr case=start
// ['x','x','y','y']\n'z'\n
// @lcpr case=end

 */

