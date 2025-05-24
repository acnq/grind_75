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

#include <set>
// @lcpr-template-end
// @lc code=start
class MedianFinder {
    // I. 优先队列
    // qMax, qMin 分别记录大于中位数和小于等于中位数的数
    // 如果累积数的数量为奇数，qMin的数量一定比qMax多一个，
    // 此时中位数就是qMin的队头，否则二者数量相同，
    // 中位数为她们的平均值
    // 添加num到结构中时：
    //      1. num <= max{qMin}
    //          num <= 中位数，将该数添加到qMin中，新中位数
    //          小于等于原来的，因此我们将qMin最大数移动到qMax中
    //      2. num > max{qMin}
    //          num > 中位数，添加到qMax中，新中位数大于等于原来的
    //          因此可能需要将最小的数移到qMin中
    // 开始时，我们将第一个数添加到queMin中

    // II. 有序集合 + 双指针
    // 有序集合看做自动排序的数组，双指针总是指向中位元素
    // 累积为奇数，双指针指向同一个元素，否则指向构成中位数的两个数
    // addNum:
    //      1. 有序集合为空，则左右指针指向num所在
    //      2. 有序集合有奇数个元素时，l,r同时指向中位数,若num >= 中位数
    //          left左移，否则right右移即可
    //      3. 有偶数个元素时，l,r指向构成中位数的两个数
    //          num成为新的中位数，则l右移，r左移，指向num即可
    //          num>=r, l右移
    //          num<r, r左移，注意如果num=l, 那么num将被插入l右侧，l,r距离增大
    //              所以还需要额外让l指向移动后的r
public:
    // priority_queue<int, vector<int>, less<int>> qMin;
    // priority_queue<int, vector<int>, greater<int>> qMax;

    multiset<int> nums;
    multiset<int>::iterator left, right;

    MedianFinder(): left(nums.end()), right(nums.end()) {
        // I 没有任何变化，II.增加了构造参数
    }
    
    void addNum(int num) {
        // if (qMin.empty() || num <= qMin.top())
        // {
        //     qMin.push(num);
        //     if (qMax.size() + 1 < qMin.size())
        //     {
        //         qMax.push(qMin.top());
        //         qMin.pop();
        //     }
        // } else {
        //     qMax.push(num);
        //     if (qMax.size() > qMin.size())
        //     {
        //         qMin.push(qMax.top());
        //         qMax.pop();
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
        // if (qMin.size() > qMax.size())
        // {
        //     return qMin.top();
        // }
        // return (qMin.top() + qMax.top()) / 2.0;
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



