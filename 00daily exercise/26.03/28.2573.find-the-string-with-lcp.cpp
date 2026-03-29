/*
 * @lc app=leetcode.cn id=2573 lang=cpp
 * @lcpr version=30204
 *
 * [2573] 找出对应 LCP 矩阵的字符串
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
    // 从前往后构造字符串,填入尽可能小的字符
    // lcp[i][j]是最长公共前缀的长度,所以lcp[i][j] > 0
    // 有word[i] = word[j]
    // 我们于是如下构造
    // - 遍历字符串位置i, 如果为空,直接写上current
    // - 根据lcp, 如果lcp[i][j] > 0, 则j天上相同字符
    // - 当前最小字符超过小写字母最大值,直接返回空字符串
    // - 本次填充完成,current++, 研究下一个为空的字符
    // 
    // 然后我们再判断所得的字符串是否满足对应的lcp矩阵
    // 因为lcp有如下递推公式
    // lcp[i][j] = lcp[i + 1][j + 1] + 1, word[i] = word[j]
    // lcp[i][j] = 0                      word[i] != word[j]
    // 我们验证上述递推式,如果满足则说明构造正确
    // 否则直接返回空字符串,不可能通过修改字符串使得lcp满足
    //
    // tc: O(n^2), sc: O(1)
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        string word(n, '\0');
        char current = 'a';

        // 从'a'到'z'构造字符串
        for (int i = 0; i < n; i++) {
            if (word[i] == '\0') {
                if (current > 'z') {
                    return "";
                }
                word[i] = current;
                for (int j = i + 1; j < n; j++) {
                    if (lcp[i][j] > 0) {
                        word[j] = word[i];
                    }
                }
                current++;
            }
        }

        // 验证构造字符串是否满足LCP矩阵需要
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (word[i] != word[j]) {
                    if (lcp[i][j]) {
                        return "";
                    }
                } else {
                    if (i == n - 1 || j == n - 1) {
                        if (lcp[i][j] != 1) {
                            return "";
                        }
                    } else {
                        if (lcp[i][j] != lcp[i + 1][j + 1] + 1) {
                            return "";
                        }
                    }
                }
            }
        }
        return word;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[4,0,2,0],[0,3,0,1],[2,0,2,0],[0,1,0,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[4,3,2,1],[3,3,2,1],[2,2,2,1],[1,1,1,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[4,3,2,1],[3,3,2,1],[2,2,2,1],[1,1,1,3]]\n
// @lcpr case=end

 */

