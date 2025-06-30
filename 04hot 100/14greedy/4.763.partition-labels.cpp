/*
 * @lc app=leetcode.cn id=763 lang=cpp
 * @lcpr version=30204
 *
 * [763] 划分字母区间
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
    // I. 贪心
    // 同一个字母只能出现在一个片段=>
    // 同一个字母的第一次出现的下标位置和最后一次出现的下标位置必须出现在同一片段
    // 算法如下
    // 1. 从左到右遍历，维护当前片段的开始下标和结束下标start,end, 初始化为0
    // 2. 访问到字母c, 得到当前字母最后一次出现的下标位置end, 当前片段结束位置不小于end, 
    //      end = max(end, end_c)
    // 3. 访问到end时，当前片段访问结束，返回长度end - start + 1, 然后start = end + 1, 继续
    // 重复1-3直到遍历完
    // tc: O(n); sc: O(|\sigma| = 26), 
public:
    vector<int> partitionLabels(string s) {
        int last[26];
        int len = s.size();
        for (int i = 0; i < len; i++)
        {
            last[s[i] - 'a'] = i;
        }
        vector<int> part;
        int start = 0, end = 0;
        for (int i = 0; i < len; i++)
        {
            end = max(end, last[s[i] - 'a']);
            if (i == end)
            {
                part.push_back(end - start + 1);
                start = end + 1;
            }
        }
        return part;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "ababcbacadefegdehijhklij"\n
// @lcpr case=end

// @lcpr case=start
// "eccbbbbdec"\n
// @lcpr case=end

 */

