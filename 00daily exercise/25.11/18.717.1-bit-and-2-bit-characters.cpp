// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=717 lang=cpp
 * @lcpr version=30204
 *
 * [717] 1 比特与 2 比特字符
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
    // I. 正序遍历
    // 和我的算法思路一样
    // tc: O(n), sc: O(1)
    // II. 倒序遍历
    // 据提议，0一定是字符结尾
    // 我们找到bits的倒数第二个0的位置，记作i(不存在i=-1)
    // bits[i + 1]显然不是字符开头，且bits[i+1:n-2]这n-2-i个比特均为1
    // 1.若n-2-i为偶数，可以组成(n-2-i)/2个第二种字符，
    //   bits最后一个比特0组成第一种字符
    // 2.若n-2-i为奇数，前n-3-i个组成(n-3-i)/2个第二种字符
    //   多出一个比特1和bits最后一位0组成第二种字符
    // 我们只需判断n-i的奇偶性即可，偶数返回true, 否则返回false
    // tc: O(n), sc: O(1)
public:
    bool isOneBitCharacter(vector<int>& bits) {
        // I. 我的写法
        // int n = bits.size();
        // if (n == 1) {
        //     if (bits[0]== 0) {
        //         return true;
        //     } else {
        //         return false;
        //     }
        // }
        // int i = 0;
        // while (i < n) {
        //     if (bits[i] == 1) {
        //         i += 2;
        //     } else {
        //         i++;
        //     }
        //     if (i == n - 1) {
        //         return true;
        //     }
        // }
        // return false;
        // I. 题目写法
        // int n = bits.size(), i = 0;
        // while (i < n - 1) {
        //     i += bits[i] + 1;
        // }
        // return i == n - 1;
        // II.
        int n = bits.size(), i = n - 2;
        while (i >= 0 && bits[i]) {
            i--;
        }
        return (n - i) % 2 == 0;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1, 0, 0]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,1,0]\n
// @lcpr case=end

 */

