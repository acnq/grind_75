/*
 * @lc app=leetcode.cn id=3443 lang=cpp
 * @lcpr version=30204
 *
 * [3443] K 次修改后的最大曼哈顿距离
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
    // I. 分步求解
    // 任意字符串，对应的曼哈顿距离如下：
    // |#_N - #_S| + |#_E - #_W| (#: 计数函数)
    // 修改字母无非三种情况：1. 修改横向/纵向中较少的字母，则曼哈顿距离+2
    // 2. 修改较多的字母，则曼哈顿距离-2； 3. 不修改，距离不变
    // 显然只有1会增大距离，那么我们将修改拆成2步：
    // 1. 修改纵向中较少的字母，若数量大于k, 则只修改k个，否则全部修改，
    // 设剩余的修改次数为t
    // 2. 修改横向中较少的字母，若大于t,则只能修改t个，否则全部修改
    // 遍历的同时修改并取最大值

    // II. 整体求解
    // 简单来说，可以统一采用如下的贪心策略：
    // 两个方向中数量较少的字母能改则改是最优的
    // 将两个方向中较少的字母当做一个整体，若整体数量大于k, 则需修改
    // 任意k个字母，对应的曼哈顿距离增大 2 * k, 否则较少的字母会全部被修改
public:
    int count(int dir1, int dir2, int times) {
        return abs(dir1 - dir2) + times * 2;
    }
    
    int maxDistance(string s, int k) {
        // I.
        // int ans = 0;
        // int north = 0, south = 0, east = 0, west = 0;
        // for (char it: s) {
        //     switch (it) {
        //         case 'N':
        //             north++;
        //             break;
        //         case 'S':
        //             south++;
        //             break;
        //         case 'E':
        //             east++;
        //             break;
        //         case 'W':
        //             west++;
        //             break;
        //     }
        //     int times1 = min({north, south, k});
        //     int times2 = min({east, west, k - times1});
        //     ans = max(ans, count(north, south, times1) + count(east, west, times2));
        // }
        // return ans;

        int latitude = 0, longitude = 0, ans = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            switch (s[i]) {
                case 'N':
                    latitude++;
                    break;
                case 'S':
                    latitude--;
                    break;
                case 'E':
                    longitude++;
                    break;
                case 'W':
                    longitude--;
                    break;
            }
            ans = max(ans, min(abs(latitude) + abs(longitude) + k * 2, i + 1));
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "NWSE"\n1\n
// @lcpr case=end

// @lcpr case=start
// "NSWWEW"\n3\n
// @lcpr case=end

 */

