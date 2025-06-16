/*
 * @lc app=leetcode.cn id=386 lang=cpp
 * @lcpr version=30204
 *
 * [386] 字典序排数
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
    // I. DFS
    // 没法直接排序，我们思考数学上，一个数字典序的后继是什么
    // 1. number 添加0在范围内(i.e. num * 10 <= n),则这是后继
    // 2. number mod 10 = 9, 或number + 1 > n, 则末尾数位搜索完成
    //  退后上一位，n = \floor{n / 10}, 继续判断
    //  直到number mod = 10 != 9 且 num + 1 <= n为止，则 n + 1是下一个
    // 从1开始搜索即可
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ret(n);
        int num = 1;
        for (int i = 0; i < n; i++)
        {
            ret[i] = num;
            if (num * 10 <= n)
            {
                num *= 10;
            } else {
                while (num % 10 == 9 || num + 1 > n)
                {
                    num /= 10;
                }
                num ++;
            }
        }
        return ret;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 13\n
// @lcpr case=end

// @lcpr case=start
// 2\n
// @lcpr case=end

 */

