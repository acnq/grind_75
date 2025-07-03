/*
 * @lc app=leetcode.cn id=179 lang=cpp
 * @lcpr version=30204
 *
 * [179] 最大数
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

#include <string> // to_string
// @lcpr-template-end
// @lc code=start
class Solution {
    // I. 排序
    // 只管放的方法就是把数值哒的数放到高维，比较数组每个元素的最高位，相同比较次高位
    // 以此类推，完成排序之后拼接起来
    // 那么有相同开头的时候怎么办呢？比如[4, 42]和[4, 45], 前者是4在前大（442>424), 后者是45在前大(454>445)
    // 这需要特判，比较两种结果，确定顺序
    // 之后我们定义了排序，需要枚举每种排序结果来拼接么，显然上述排序规则满足传递性
    // 证明见官方题解，直觉上是显然的，所以我们比较两两比较元素即可
    // tc: O(nlognlogm) (n: 序列长度，m32最大证书长度)； sc: O(logn)
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](const int &x, const int &y) {
            return to_string(x) + to_string(y) > to_string(y) + to_string(x);
        });
        if (nums[0] == 0)
        {
            return "0";
        }
        string ret;
        for (int& x: nums) {
            ret += to_string(x);
        }
        return ret;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [10,2]\n
// @lcpr case=end

// @lcpr case=start
// [3,30,34,5,9]\n
// @lcpr case=end

 */

