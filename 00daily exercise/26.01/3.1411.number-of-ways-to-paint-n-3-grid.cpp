/*
 * @lc app=leetcode.cn id=1411 lang=cpp
 * @lcpr version=30204
 *
 * [1411] 给 N x 3 网格图涂色的方案数
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
    // I. 递推
    // f[i][type]: 网格大小为i*3且最后一行的填色方法为type时的方案
    // 因为我们在填充第i行时，会影响我们填充方案的只有上一行(i-1)行
    // 如何计算f[i][type]:
    //  1. type用三进制表示，例如type = (102)_3: 表示从左到右黄红绿
    //     这样一来，我们预处理所有满足要求的type, 只要相邻格子颜色不同即可
    //  2. f[i][type] = \sum_{type'} f[i - 1][type'],
    //      其中type'和type可以作为相邻的行：也就是对应位置不可相同
    // tc: O(T^2N) T:满足要求的type数字，为12; sc: O(T^2 + TN)

    // 数学
    // 显然，所有满足要求的type只有如下12种
    // 010, 012, 020, 021, 101, 102;
    // 120, 121, 201, 202, 210, 212
    // 其中ABC(三颜色彼此不同)共6种：
    //  012, 021, 102, 120, 201, 210
    // ABA(左右两侧颜色相同)也6种：
    //  010, 020, 101, 121, 202, 212
    // f[i][0]: 网格大小为i*3且最后一行填色方法为ABC类的
    // f[i][1]: ......                        ABA类的
    // 第i-1行为ABC类，第i行也为ABC类，方案数为2
    //          ABC           ABA           2
    //          ABA           ABC           2
    //          ABA           ABA           3
    // f[i][0] = 2f[i-1][0] + 2f[i-1][1]
    // f[i][1] = 2f[i-1][0] + 3f[i-1][1]
private:
    static constexpr int mod = 1e9 + 7;
public:
    int numOfWays(int n) {
        // I.
        // 预处理所有满足条件的type
        // vector<int> types;
        // for (int i = 0; i < 3; i++) {
        //     for (int j = 0; j < 3; j++) {
        //         for (int k = 0; k < 3; k++) {
        //             if (i != j && j != k) {
        //                 // 相邻颜色不同即可
        //                 // 化为十进制保存
        //                 types.push_back(i * 9 + j * 3 + k);
        //             }
        //         }
        //     }
        // }

        // int type_cnt = types.size();
        // // 预处理所有可以作为相邻行的type对, 
        // // relate[i][j] = 1 <=> types[i]和types[j]可以相邻
        // vector<vector<int>> related(type_cnt, vector<int>(type_cnt));
        // for (int i = 0; i < type_cnt; i++) {
        //     // 得到types[i]的三个位置颜色
        //     int x1 = types[i] / 9, x2 = types[i] / 3 % 3, x3 = types[i] % 3;
        //     for (int j = 0; j < type_cnt; j++) {
        //         // 得到types[j]三个位置颜色
        //         int y1 = types[j] / 9, y2 = types[j] / 3 % 3, y3 = types[j] % 3;
        //         // 对应位置不同色，才能作为相邻行
        //         if (x1 != y1 && x2 != y2 && x3 != y3) {
        //             related[i][j] = 1;
        //         }
        //     }
        // }
        // // 递推数组
        // vector<vector<int>> f(n + 1, vector<int>(type_cnt));
        // // 边界情况，第一行可使用任何type
        // for (int i = 0; i < type_cnt; i++) {
        //     f[1][i] = 1;
        // }
        // for (int i = 2; i <= n; i++) {
        //     for (int j = 0; j < type_cnt; j++) {
        //         for (int k = 0; k < type_cnt; k++) {
        //             // f[i][j] = sum_{k和j可相邻} f[i - 1][k]
        //             if (related[k][j]) {
        //                 f[i][j] += f[i - 1][k];
        //                 f[i][j] %= mod;
        //             }
        //         }
        //     }
        // }
        // // 最终\sum_{\forall types} f[n][types]为答案
        // int ans = 0;
        // for (int i = 0; i < type_cnt; i++) {
        //     ans += f[n][i];
        //     ans %= mod;
        // }
        // return ans;

        // II.
        int fi0 = 6, fi1 = 6;
        for (int i = 2; i <= n; i++) {
            int new_fi0 = (2LL * fi0 + 2LL * fi1) % mod;
            int new_fi1 = (2LL * fi0 + 3LL * fi1) % mod;
            fi0 = new_fi0;
            fi1 = new_fi1;
        }

        return (fi0 + fi1) % mod;
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

// @lcpr case=start
// 7\n
// @lcpr case=end

// @lcpr case=start
// 5000\n
// @lcpr case=end

 */

