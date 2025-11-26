// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=3228 lang=cpp
 * @lcpr version=30204
 *
 * [3228] 将 1 移动到末尾的最大操作次数
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
    // I. 贪心 + 计数
    // 注意到每个1的相对位置不会改变，而每个1在移动过程中
    // 被挡住的次数越多，对答案的贡献越大，
    // 所以我们其实贪心的从左往右移动1，就可以使得每个1被挡住的次数最多
    // 这样就可以使得答案最大
    // 算法：
    // 1. 从左往右遍历字符串s，对于每段连续的0，只在遇到第一个0时
    //    将之前的1的数量加到答案中，因为之前所有的1都需要操作一次
    // 2. 如果当前字符1，则1的数量count1+1, 表示被挡住的1数量+1
    // tc: O(n), sc: O(1)
public:
    int maxOperations(string s) {
        int count1 = 0;
        int ans = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '0') {
                while ((i + 1) < s.length() && s[i + 1] == '0') {
                    i++;
                }
                ans += count1;
            } else {
                count1++;
            }
        }
        return ans;
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=maxOperations
// paramTypes= ["string"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// "1001101"\n
// @lcpr case=end

// @lcpr case=start
// "00111"\n
// @lcpr case=end

 */

