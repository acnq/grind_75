// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=1015 lang=cpp
 * @lcpr version=30204
 *
 * [1015] 可被 K 整除的最小整数
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
    // I. 遍历
    // n' =  10n + 1
    // r' = n' mod k = (10n + 1) mod k 
    //    = (10(n mod k) + 1) mod k = (10r + 1) mod k
    // 所以新余数r'可直接由旧余数r推导得出，我们可以避免记录过大的n
    // r是模k的余数，种类不会超过k, 一旦遇到重复的r，就会遇到循环
    // 我们用哈希记录余数，一旦重复，支集返回-1，否则r总会变为0
    // 此时哈希表元素个数就是n的长度
    // tc: O(k), sc: O(k)
    // II. 遍历优化
    // 如果k = 2 || 5, 一定无解，我们反问，如果k不是2或者5，
    // 那么问题是否一定有解呢？
    // 如若不然，resid随着1的增加总会进入循环，
    // 我们因此能找到一对模k同余的nm
    // n > m, => (n - m) = 0 mod k
    // n - m 可以表示为1...10...0的形式，故1...10...0 = 0 mod k
    // 1...10...0是k的倍数，且k不是2或5的倍数(k与10互质)
    // 所以n - m末尾的0可以去掉（反正整除的部分不在这里)
    // 所以1.....1 = 0 mod k, 矛盾，问题一定有解
    // tc: O(k), sc: O(1)
public:
    int smallestRepunitDivByK(int k) {
        // Ia. 我的写法：
        // int r = 1 % k;
        // unordered_set<int> hsh;
        // while (r != 0) {
        //     if (hsh.count(r) >= 1) {
        //         return -1;
        //     }
        //     hsh.insert(r);
        //     r = (10 * r + 1) % k;
        // }
        // return hsh.size() + 1;
        // Ib. 答案写法：
        // int resid = 1 % k, len = 1; // resid为余数，len为数字长度，初始值为1
        // unordered_set<int> st; // 创建一个无序集合，用于存储余数
        // st.insert(resid); // 插入余数1
        // while (resid != 0) {// 当余数为0时退出循环
        //     resid = (resid * 10 + 1) % k; // 计算下一个余数
        //     len++; // 数字长度+1
        //     if (st.find(resid) != st.end()) {// 如果余数重复出现，则无解
        //         return -1;
        //     }
        //     st.insert(resid); // 将余数插入集合
        // }
        // return len;

        // II.
        // 若 k 能被 2 或 5 整除，则无解，返回 -1
        if (k % 2 == 0 || k % 5 == 0) {
            return -1;
        }
        // 初始化余数为 1，表示一个数的最低位是 1
        int resid = 1 % k, len = 1;
        // 若余数不为 0，继续迭代
        while (resid != 0) {
            // 计算下一个数的余数，下一个数在当前余数后加一个 1
            resid = (resid * 10 + 1) % k;
            len++;
        }
        // 返回数字 1 的最小重复次数
        return len;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 1\n
// @lcpr case=end

// @lcpr case=start
// 2\n
// @lcpr case=end

// @lcpr case=start
// 3\n
// @lcpr case=end

 */

