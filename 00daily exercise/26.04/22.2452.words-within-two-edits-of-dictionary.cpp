/*
 * @lc app=leetcode.cn id=2452 lang=cpp
 * @lcpr version=30204
 *
 * [2452] 距离字典两次编辑以内的单词
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
    // 暴力
    // 对于queries中的每个字符串queries[i], 查找dic中是否存在
    // 汉明距离<=2的字符串，如果存在，就添加答案
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;
        for (string query: queries) {
            for (string s: dictionary) {
                int dis = 0;
                for (int i = 0; i < query.size(); i++) {
                    if (query[i] != s[i]) {
                        dis++;
                    }
                }
                if (dis <= 2) {
                    ans.push_back(query);
                    break;
                }
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["word","note","ants","wood"]\n["wood","joke","moat"]\n
// @lcpr case=end

// @lcpr case=start
// ["yes"]\n["not"]\n
// @lcpr case=end

 */

