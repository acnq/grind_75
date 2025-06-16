/*
 * @lc app=leetcode.cn id=440 lang=cpp
 * @lcpr version=30204
 *
 * [3442] 奇偶频次之间的最大差值 I
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
    // I. 枚举 + 双指针
    // 枚举题目中描述的字符a,b, a出现奇数此，b出现偶数次，a和b不相同
    // 我们用二进制位表示奇偶性，1表奇数，0表偶数，a先b后，有4中不同情况
    // [00, 01, 10, 11], 我们只要10的情况。

    // 使用双指针解决，右指针right每次右移一个位置，表示子串的右端点
    // 此时我们要更新呢字符串到下标right为止，ab出现的次数cnt_a和cnt_b,
    // 状态为 status_{right} = (cnt_a mod 2) * 2 + (cnt_b mod 2)
    // 左指针left只会在满足要求时，才会向右移动一个位置，也即只有下标<= left,
    // 才能作为左端点，prev_a, prev_b到下标left为止的，a,b出现的次数，左指针移动的条件
    // right - left >= k: 长度至少为k;
    // cnt_b - prev_b >= 2: b至少出现2次
    // 对一个满足要求的左指针，对应的答案：(cnt_a - cnt_b) - (prev_a - prev_b)
    // 用长度为4的数组best来维护每一种情况下prev_a - prev_b的最小值，即
    // status_{left} = (prev_a mod 2) * 2 + (prev_b mod 2)
    // 用prev_a - prev_b的值更新best[status_{left}];

    // 左指针移动完成后，对当前右指针计算答案，需要status = 10的字符串，
    // 那么状态就是status_{right} ^ (10)_2, ^: 异或
    // 答案: (cnt_a - cnt_b) - best[status_{right} ^ (10)_2]的最大值

public:
    int maxDifference(string s, int k) {
        auto getStatus = [](int cnt_a, int cnt_b) -> int {
            return ((cnt_a & 1) << 1) | (cnt_b & 1);
        };
        
        int n = s.size();
        int ans = INT_MIN;
        for(char a = '0'; a <= '4'; a++) {
            for(char b = '0'; b <= '4'; b++) { 
                // 只有4个符号让这种枚举可行，总的tc: O(N * |S|^2)
                // |S|代表字符总数
                if(a == b) {
                    continue;
                }

                int best[4] = {INT_MAX, INT_MAX, INT_MAX, INT_MAX};
                int cnt_a = 0, cnt_b = 0;
                int prev_a = 0, prev_b = 0;
                int left = -1;
                for(int right = 0; right < n; right++) {
                    cnt_a += (s[right] == a);
                    cnt_b += (s[right] == b);
                    while(right - left >= k && cnt_b - prev_b >= 2) {
                        int left_status = getStatus(prev_a, prev_b);
                        best[left_status] = min(best[left_status], prev_a - prev_b);
                        left++;
                        prev_a += (s[left] == a);
                        prev_b += (s[left] == b);
                    }
                    int right_status = getStatus(cnt_a, cnt_b);
                    if(best[right_status ^ 0b10] != INT_MAX) {
                        ans = max(ans, cnt_a - cnt_b - best[right_status ^ 0b10]);
                    }
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    int res1 = s.maxDifference("12233", 4);
    cout << res1 << endl;
    int res2 = s.maxDifference("1122211", 3);
    cout << res2 << endl;
}
// @lc code=end



/*
// @lcpr case=start
// "aaaaabbc"\n
// @lcpr case=end

// @lcpr case=start
// "abcabcab"\n
// @lcpr case=end

 */

