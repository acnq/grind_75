/*
 * @lc app=leetcode.cn id=3170 lang=cpp
 * @lcpr version=30204
 *
 * [3170] 删除星号以后字典序最小的字符串
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
    // 注意每次只能去掉字典序最小的字母，而我们又要保证去掉后的串字典序最小
    // 所以我们只需要去掉满足条件的最右边的字符即可，这样最小的字符便尽可能靠前

    // 我们直接用26个栈来保存已经遍历过的每种字符的索引
    // 1. 遇到非‘*’字符，当前索引压入对应的栈
    // 2. 遇到‘*’字符，找到非空且字典序最小的栈，标记栈顶元素对应的字符为'*'，移除栈顶元素
public:
    string clearStars(string s) {
        vector<stack<int>> cnt(26);
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != '*')
            {
                cnt[s[i] - 'a'].push(i);
            } else 
            {
                for (int j = 0; j < 26; j++)
                { // 枚举的顺序保证了遇到的第一个字符就是字典序最小的
                    if (!cnt[j].empty())
                    {
                        s[cnt[j].top()] = '*';
                        cnt[j].pop();
                        break;
                    }
                }
            }
        }
        
        string ans;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != '*')
            {
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "aaba*"\n
// @lcpr case=end

// @lcpr case=start
// "abc"\n
// @lcpr case=end

 */

