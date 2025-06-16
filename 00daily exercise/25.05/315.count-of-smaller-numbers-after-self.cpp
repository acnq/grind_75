/*
 * @lc app=leetcode.cn id=315 lang=cpp
 * @lcpr version=30204
 *
 * [315] 计算右侧小于当前元素的个数
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
    // I. 树状数组
    // 动态维护前缀和的数据结构
    // 1. 单点更新： update(i, v), 序列i位置加上v(从下文可以看出，本题v总是1)
    // 2. 区间查询： query(i), 查询[1:i]区间和，即i位置的前缀和
    // 修改和查询都是O(logn)

    // 实现方案：维护桶
    // e.g. a = {5, 5, 2, 3, 6}
    //      idx = {1, 2, 3, 4, 5, 6}
    //      val = {0, 1, 1, 0, 2, 1}
    // 对于序列val(上文中的v), 第i-1位的前缀和表示“有多少元素比i小”
    // 后续遍历a, 当前值位a_i, 则a_i对应的桶+1， 记a_i = p,
    // 把v序列p-1位置的前缀和加入到答案中算贡献
    // 那么如果含有元素过大怎么办呢？我们可以用离散化的方法，
    // 桶的idx只保留相对大小，而不必保留绝对大小
public:
    vector<int> c; // 树状数组本体
    vector<int> a; // 辅助离散化

    void init(int length) {
        c.resize(length, 0);
    }

    int lowbit(int x) {
        return x & (-x); // 提取x的最低位1
    }

    void update(int pos) {
        while (pos < c.size())
        {
            c[pos] += 1;
            pos += lowbit(pos);
        } // 从pos开始往上跳，每次跳lowbit(pos), 把c[pos]累加1
        // 直到超出范围
    }
    int query(int pos) {
        int ret = 0;
        while (pos > 0)
        { // 从pos开始往下跳
            ret += c[pos]; // 累加c[pos]
            pos -= lowbit(pos); // 每次跳lowbit(pos)
        }
        return ret; // 1:pos区间内的统计结果
    }
    void discretization(vector<int>& nums) {
        a.assign(nums.begin(), nums.end()); // 复制一份
        sort(a.begin(), a.end()); // 排序
        a.erase(unique(a.begin(), a.end()), a.end()); // 去重
    }
    int getId(int x) {
        return lower_bound(a.begin(), a.end(), x) - a.begin() + 1;
    } // 将原始值x转化为他在离散化数组a中的编号(第几小)
    // +1: 下标1开始，

    vector<int> countSmaller(vector<int>& nums) {
        // I
        vector<int> resultList;
        discretization(nums);
        init(nums.size() + 5);
        for (int i = (int)nums.size() - 1; i >= 0; i--)
        {
            int id = getId(nums[i]);
            resultList.push_back(query(id - 1));
            update(id);
        }

        reverse(resultList.begin(), resultList.end());
        return resultList;
        
    }
};
// @lc code=end



/*
// @lcpr case=start
// [5,2,6,1]\n
// @lcpr case=end

// @lcpr case=start
// [-1]\n
// @lcpr case=end

// @lcpr case=start
// [-1,-1]\n
// @lcpr case=end

 */

