/*
 * @lc app=leetcode.cn id=LCR 170 lang=cpp
 * @lcpr version=30204
 *
 * [LCR 170] 交易逆序对的总数
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

class BIT { // 树状数组
private:
    vector<int> tree;
    int n;

public:
    BIT(int _n): n(_n), tree(_n + 1) {}

    static int lowbit(int x) {
        return x & (-x);
    }
    
    int query(int x) {
        int ret = 0;
        while (x)
        {
            ret += tree[x];
            x -= lowbit(x);
        }
        return ret;
    }

    void update(int x) {
        while (x <= n)
        {
            tree[x]++;
            x += lowbit(x);
        }
    }
};

class Solution {
public:
    // I. 归并排序统计逆序对
    // 考虑归并排序, 归并L, R过程中
    // lPtr右移 => 当前lPtr指向的数字比rPtr小
    // 但是比R[0:rPtr-1]的数字都大
    // [0:rPtr-1]的其他数字本应排在lPtr对应的数字左边，
    // 但事实在右边，所以贡献了rPtr个逆序对

    // II. 离散化树状数组
    // 见315
    
    int mergeSort(vector<int>& record, vector<int>& tmp, int l, int r) {
        if (l >= r)
        {
            return 0;
        }

        int mid = (l + r) / 2;
        int inv_count = mergeSort(record, tmp, l, mid) + mergeSort(record, tmp, mid + 1, r);
        int i = l, j = mid + 1, pos = l;
        while (i <= mid && j <= r)
        {
            if (record[i] <= record[j])
            {
                tmp[pos] = record[i];
                i++;
                inv_count += (j - (mid + 1));
            } else {
                tmp[pos] = record[j];
                j++;
            }   
            pos++;         
        }
        for (int k = i; k <= mid; k++)
        {
            tmp[pos++] = record[k];
            inv_count += (j - (mid + 1));
        }
        for (int k = j; k <= r; k++)
        {
            tmp[pos++] = record[k];
        }
        copy(tmp.begin() + l, tmp.begin() + r + 1, record.begin() + l);
        return inv_count; 
    }
    int reversePairs(vector<int>& record) {
        // I.
        // int n = record.size();
        // vector<int> tmp(n);
        // return mergeSort(record, tmp, 0, n - 1);
    
        // II. 
        int n = record.size();
        vector<int> tmp = record;
        // 离散化
        sort(tmp.begin(), tmp.end());
        for(int& num: record) {
            num = lower_bound(tmp.begin(), tmp.end(), num) - tmp.begin() + 1;
        }
        // 树状数组统计逆序对
        BIT bit(n);
        int ans = 0;
        for (int i = n - 1; i >= 0; i--)
        { // 从末尾开始，枚举i, 们把 a_i​
            // 对应的桶的值自增 1，
            // 把 i−1 位置的前缀和加入到答案中算贡献 
            ans += bit.query(record[i] - 1);
            bit.update(record[i]);
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [9, 7, 5, 4, 6]\n
// @lcpr case=end

 */

