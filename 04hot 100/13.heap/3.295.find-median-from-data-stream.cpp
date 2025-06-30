/*
 * @lc app=leetcode.cn id=295 lang=cpp
 * @lcpr version=30204
 *
 * [295] 数据流的中位数
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

#include <set> // multiset在这里，不存在<multiset>头文件
// @lcpr-template-end
// @lc code=start
class MedianFinder {
    // I. 优先队列
    // 两个队列queMax, queMin记录大于中位数和小于等于中位数的数。
    // 累积为奇数时，queMin比queMax多一个，中位数就是queMin的头，
    //       偶数时，两队列元素相同，中位数就是它们队头的平均值。
    // 加一个数字num到数据结构中，分情况讨论：
    // 1. num <= max{queMin}： num一定小于等于中位数，加入queMin, 
    //                         这时新的中位数可能会变小，要将queMin中较大的元移到queMax
    // 2. num > max{queMin}: num一定大于中位数，加入queMax;
    //                       新的中位数可能会变大，要将queMax中较小的移到queMin中
    // 第一个元素添加到queMin中
    // tc: add: O(logn), find: O(1); sc: O(n)

    // II. 有序集合 + 双指针
    // 把有序集合看做自动排序的数组，使用双指针指向有序集合中的中位数元素
    // 累积数量为奇数，指向同一个元素，为偶数时，指向构成中位数的两个数
    // 添加num时
    // 1. 初始集合空时，直接让左右指针指向num所在
    // 2. 有序集合中有奇数元素，left/right同时指向中位数，如果num<=中位数，left左移，否则right右移
    // 3. 有序集合中有偶数元素，left/right分别指向构成中位数的两数
    //      num成为新的唯一中位数，那么让left, right左移，他们这样都直接指向num所在的位置
    //      num >= right, left 右移
    //      num < right, right左移，如果num恰好等于left所指，则num插入left右侧，还需额外让left指向移动后的right

public:
    // I.
    // priority_queue<int, vector<int>, less<int>> queMin;
    // priority_queue<int, vector<int>, greater<int>> queMax;

    // II.
    multiset<int> nums;
    multiset<int>::iterator left, right;

    // I.
    // MedianFinder() {
        
    // }
    // II.
    MedianFinder() : left(nums.end()), right(nums.end()) {}
    
    void addNum(int num) {
        // I.
        // if (queMin.empty() || num <= queMin.top())
        // {
        //     queMin.push(num);
        //     if (queMax.size() + 1 < queMin.size())
        //     {
        //         queMax.push(queMin.top());
        //         queMin.pop();
        //     }
        // } else
        // {
        //     queMax.push(num);
        //     if (queMax.size() > queMin.size())
        //     {
        //         queMin.push(queMax.top());
        //         queMax.pop();
        //     }
        // }

        // II.
        const size_t n = nums.size();
        nums.insert(num);
        if (!n)
        {
            left = right = nums.begin();
        } else if (n & 1)
        {
            if (num < *left)
            {
                left--;
            } else {
                right++;
            }
        } else {
            if (num > *left && num < *right)
            {
                left++;
                right--;
            } else if (num >= *right)
            {
                left++;
            } else {
                right--;
                left = right;
            }
        }
    }
    
    double findMedian() {
        // I.
        // if (queMin.size() > queMax.size())
        // {
        //     return queMin.top();
        // }
        // return (queMin.top() + queMax.top()) / 2.0;

        // II.
        return (*left + *right) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end



