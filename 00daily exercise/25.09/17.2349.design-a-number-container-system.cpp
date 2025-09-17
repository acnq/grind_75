/*
 * @lc app=leetcode.cn id=2349 lang=cpp
 * @lcpr version=30204
 *
 * [2349] 设计数字容器系统
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
class NumberContainers {
    // I. 优先队列 + 惰性删除
    // 使用哈希表nums记录每个下标对应的数字
    // 同时使用哈希表+优先队列记录每个数字对应的下标集合
    // 1. change 函数：
    //  记录nums[idx] = number, 将index压入number对应的优先队列中
    // 2. find函数：
    //  change在替换的时候，没有删除对应优先队列的下标。
    //  因此我们在获取number的最小值时，需要先校验优先队列堆顶下标对应
    //  的数字是否等于number, 不等于时直接丢弃，等于则返回该下标，
    //  有点队列为空则返回-1

    // II. 有序集合
    // 仿I, 使用哈希表nums记录每个下标对应的数字，
    // 同时使用哈希表+有序集合记录每个数字对应的下标集合
    // 1. change函数：
    //  如果idx已经有数字，从该数字的下标有序集合中删除idx,
    //  记录nums[idx] = number, 同时将idx插入number对应的下标有序集合中
    // 2. find函数:
    //  如果number对应的下标有序集合非空，则返回该有序集合的最小值，否则返回-1


private:
    // I.
    // unordered_map<int, int> nums;
    // unordered_map<int, priority_queue<int, vector<int>, greater<>>> heaps;
    // II.
    unordered_map<int, int> nums;
    unordered_map<int, set<int>> us;

public:
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        // I.
        // nums[index] = number;
        // heaps[number].push(index);

        // II.
        if (nums[index] != 0) {
            us[nums[index]].erase(index);
        }
        us[number].insert(index);
        nums[index] = number;
    }
    
    int find(int number) {
        // // I.
        // while(!heaps[number].empty() && nums[heaps[number].top()] != number) {
        //     heaps[number].pop();
        // }
        // if (heaps[number].empty()) {
        //     return -1;
        // }
        // return heaps[number].top();

        // II.
        if (us[number].empty()) {
            return -1;
        }
        return *us[number].begin();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
// @lc code=end



/*
// @lcpr case=start
// ["NumberContainers", "find", "change", "change", "change", "change", "find", "change", "find"][[], [10], [2, 10], [1, 10], [3, 10], [5, 10], [10], [1, 20], [10]]\n
// @lcpr case=end

 */

