/*
 * @lc app=leetcode.cn id=3043 lang=cpp
 * @lcpr version=30204
 *
 * [3043] 最长公共前缀的长度
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

#include <string>
// @lcpr-template-end
// @lc code=start
class Solution {
    // I. 枚举前缀 + 哈希表
    // 显然，对arr1, 每个元素不断/10, 可以得到前缀
    // 将得到的前缀存入哈希表seen
    // 随后对arr2作同样的操作，若得到的前缀在seen中出现过
    // 说明存在一对数拥有该公共前缀，更新最大值即可
    // 返回best的十进制位数
    //
    // tc: O((n + m)logC) (C: 数组元素范围，因为最多有logC个前缀)
    // sc: O(nlogC) (seen的空间)
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> seen;

        for (int num: arr1) {
            while (num > 0) {
                seen.insert(num);
                num /= 10;
            }
        }

        int best = 0;
        for (int num: arr2) {
            while (num > 0) {
                if (seen.count(num)) {
                    best = max(best, num);
                }
                num /= 10;
            }
        }

        return best == 0 ? 0: to_string(best).size();
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,10,100]\n[1000]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n[4,4,4]\n
// @lcpr case=end

 */

