/*
 * @lc app=leetcode.cn id=1422 lang=cpp
 * @lcpr version=30204
 *
 * [1422] 分割字符串的最大得分
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
    // I. 模拟
    // 标准答案和我写的差不多，我只是抽取了函数
    // 导致用时稍多了点，但是不会超时。

    // II. 两次遍历
    // s[i] = 0: 左字符串得分+1，右字符串得分不变，总分+1
    // s[i] = 1: 左字符串得分不变，右字符串得分-1，总分-1;
public:
    // I.
    vector<int> count01(string s) {
        int ones = 0, zeros = 0;
        for(char ch: s) {
            if(ch == '1') {
                ones++;
            } else {
                zeros++;
            }
        }
        return{zeros, ones};
    }
    int maxScore(string s) {
        // I.
        // int ans = 0, n = s.size();
        // for(int i = 0; i < n - 1; i++) {
        //     string tmp1 = s.substr(0, i + 1);
        //     int a = count01(tmp1)[0];
        //     cout << tmp1 << " " << a << endl;
        //     string tmp2 = s.substr(i + 1, n - i - 1);
        //     int b = count01(tmp2)[1];
        //     cout << tmp2 << " " << b << endl;
        //     ans = max(ans, a + b);
        // }
        // return ans;

        // II.
        int score = 0;
        int n = s.size();
        if (s[0] == '0')
        {
            score++;
        }
        for (int i = 1; i < n; i++)
        { // 预处理确保score的值是对的
            if (s[i] == '1')
            {
                score++;    
            }
        }
        int ans = score;
        for (int i = 1; i < n - 1; i++)
        {
            if (s[i] == '0')
            {
                score++;
            } else {
                score--;
            }
            ans = max(ans, score);
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "011101"\n
// @lcpr case=end

// @lcpr case=start
// "00111"\n
// @lcpr case=end

// @lcpr case=start
// "1111"\n
// @lcpr case=end

 */

