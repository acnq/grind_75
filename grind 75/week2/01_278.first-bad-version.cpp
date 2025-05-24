/*
 * @lc app=leetcode.cn id=278 lang=cpp
 * @lcpr version=30204
 *
 * [278] 第一个错误的版本
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
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        // if (isBadVersion(1))
        // {
        //     return 1;
        // } else if (isBadVersion(2))
        // {
        //     return 2;
        // } else {
        //     int mid = (n + 1) / 2;
        //     while (isBadVersion(mid) == false)
        //     {
        //         mid = (mid + n) / 2;
        //     }
        //     return mid;        
        // }
        // 这种说法是不行的，因为右端点没动，bad = n肯定会超时
        // int mid = (n + 1) / 2;
        // while (mid != n)
        // {
        //     if(isBadVersion(mid) == false) {
        //         mid = (mid + n) % 2 ? (mid + n) / 2 + 1 : (mid + n) / 2;
        //     } else {
        //         n = mid;
        //         mid = (mid + n) % 2 ? (mid + n) / 2 + 1 : (mid + n) / 2;
        //     }
        // }
        // return mid;
        // 至少得有两个变量
        long left = 1, right = n;
        while (left < right)
        {
            long mid = (left + right) / 2;
            if (isBadVersion(mid) == false)
            {
                left = mid + 1;
            } else {
                right = mid;
            }
            
        }
        return (int)left;
        // 我自己的A.C.代码：
        // long mid = ((long)n + 1) / 2;
        // while (mid != n)
        // {
        //     if(isBadVersion(mid) == false) {
        //         mid = (mid + n) % 2 ? (mid + n) / 2 + 1 : (mid + n) / 2;
        //     } else {
        //         n = mid;
        //         mid = (n + 1) / 2;
        //     }
        // }
        // return (int) mid;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 5\n4\n
// @lcpr case=end

// @lcpr case=start
// 1\n1\n
// @lcpr case=end

 */

