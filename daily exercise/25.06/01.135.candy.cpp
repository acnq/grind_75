/*
 * @lc app=leetcode.cn id=135 lang=cpp
 * @lcpr version=30204
 *
 * [135] 分发糖果
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
    // I. 两次遍历
    // 相邻孩子，评分高的孩子必须获得更多的糖果，(拆分为两个规则) =>
    // 1. ratings[i - 1] < ratings[i]: i号学生的糖果将比i - 1号的多 (左规则)
    // 2, ratings[i] > ratings[i + 1]: i号学生的糖果将比i + 1号的多 (右规则)
    // 遍历数组两次，处理每个学生分别满足左规则或右规则，最少需要被分得的糖果数量
    // 每个人最终分得的糖果数量即为两个数量的最大值。
    // 以做规则为例：从左到右遍历，到i, 若ratings[i - 1] < ratings[i], 
    // left[i] = left[i - 1] + 1，否则left[i] = 1.

    // II. 常数空间遍历
    // 从左到右枚举每个同学，记前一个同学分得的糖果数量prev
    // 1. 如果当前同学比上一个同学评分高，说明我们就在最近的递增序列中，分配pre + 1
    // 2. 否则就在一个递减序列，分配给当前同学一个糖果，并把当前同学所在的递减序列中所有同学多分配一个
    // 另外： 1. 无需显示额外分配糖果，记录当前递减序列的长度，即可知道需要额外分配的糖果数量
    //       2. 注意当前递减序列和上一个递增序列等长，需要把最近的递增序列最后一个同学也并进递减序列中
public:
    int candy(vector<int>& ratings) {
        // int n = ratings.size();
        // vector<int> left(n);
        // for(int i = 0; i < n; i++) {
        //     if(i > 0 && ratings[i] > ratings[i - 1]) {
        //         left[i] = left[i - 1] + 1;
        //     } else {
        //         left[i] = 1;
        //     }
        // }
        // int right = 0, ret = 0;
        // for(int i = n - 1; i >= 0; i--) {
        //     if(i < n - 1 && ratings[i] > ratings[i + 1]) {
        //         right++;
        //     } else {
        //         right = 1;
        //     }
        //     ret += max(left[i], right);
        // }
        // return ret;

        int n = ratings.size();
        int ret = 1;
        int inc = 1, dec = 0, pre = 1;
        for(int i = 1; i < n; i++) {
            if(ratings[i] >= ratings[i - 1]) {
                dec = 0;
                pre = ratings[i] == ratings[i - 1] ? 1 : pre + 1;
                ret += pre;
                inc = pre;
            } else {
                dec++;
                if(dec == inc) {
                    dec++;
                }
                ret += dec;
                pre = 1;
            }
        }
        return ret;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,0,2]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,2]\n
// @lcpr case=end

 */

