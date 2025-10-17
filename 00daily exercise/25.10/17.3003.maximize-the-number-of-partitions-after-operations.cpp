/*
 * @lc app=leetcode.cn id=3003 lang=cpp
 * @lcpr version=30204
 *
 * [3003] 执行操作后的最大分割数量
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
    // I. 位运算+预处理+枚举
    // 如果不进行修改，很轻松就能通过遍历字符串计算每个分割的位置
    // 假设我们修改了位置i的字符，并且假设这个位置在不进行修改时，在第t个分割内
    // 显然，修改i不影响t-1及以前的分割，另外，从尾到头观察，也知道这修改不影响t+1及以后得分割
    // 我们假设s[0：i-1]的最后一个分割为左相邻分割，s[i+1:n-1]的首个叫做右相邻分割
    // 这二者总共分为如下3种情况
    // 1. 即便修改i, 左右分割以及第i位不同字符数量仍然不超过k,
    //    所以左右分割以及第i位合并为一个，对答案贡献为1
    // 2. 左右分割不同字符数量位k，不超过25，把i修改为左右分割中不包含的字符后
    //      左右分割以及第i位重组为3个，贡献+3
    // 3. 其他情况对答案的贡献为2
    // 于是我们统计左右分割包含的信息left[i], right[i]
    // left[i][0]: 包含的分割数
    //        [1]: 包含的字符掩码
    //        [2]: 包含的字符数量
public:
    int maxPartitionsAfterOperations(string s, int k) {
        int n = s.length();
        vector<vector<int>> left(n, vector<int>(3)), right(n, vector<int>(3));
        int num = 0,mask = 0, count=0;
        for (int i = 0; i < n - 1; i++) {
            int binary = 1 << (s[i] -'a'); // 单字符掩码
            if (!(mask & binary)) {
                count++;
                if (count <= k) {
                    mask |= binary;
                } else {
                    num++;
                    mask = binary;
                    count = 1;
                }
            }
            left[i + 1][0] = num;
            left[i + 1][1] = mask;
            left[i + 1][2] = count;
        }
        num = 0, mask = 0, count = 0;
        for (int i = n - 1; i > 0; i--) {
            int binary = 1 << (s[i] -'a'); // 单字符掩码
            if (!(mask & binary)) {
                count++;
                if (count <= k) {
                    mask |= binary;
                } else {
                    num++;
                    mask = binary;
                    count = 1;
                }
            }
            right[i - 1][0] = num;
            right[i - 1][1] = mask;
            right[i - 1][2] = count;
        }
        int Max = 0;
        for (int i = 0; i < n; i++) {
            int seg = left[i][0] + right[i][0] + 2;
            int totMask = left[i][1] | right[i][1];
            int totCount = 0;
            while(totMask) {
                totMask = totMask & (totMask - 1);
                totCount++;
            }
            if (left[i][2] == k && right[i][2] == k && totCount < 26) {
                seg++;
            } else if (min(totCount + 1, 26) <= k) {
                seg--;
            }
            Max = max(Max, seg);
        }
        return Max;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "accca"\n2\n
// @lcpr case=end

// @lcpr case=start
// "aabaab"\n3\n
// @lcpr case=end

// @lcpr case=start
// "xxyz"\n1\n
// @lcpr case=end

 */

