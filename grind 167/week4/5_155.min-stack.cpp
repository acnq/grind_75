/*
 * @lc app=leetcode.cn id=155 lang=cpp
 * @lcpr version=30204
 *
 * [155] 最小栈
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
class MinStack {
    // 辅助栈
    // 让原来的栈和每个元素a与
    // 当前栈最小值m时刻一一对应：

    // 1. 入栈： 取得当前辅助栈的栈顶元素，
    // 与需要入栈的元素比较求出最小值, 
    // 将这个最小值插入辅助栈中

    // 2. 出栈：辅助栈的栈顶元素一并弹出

    // 3. 如此可保证辅助栈的栈顶就是原栈的最小值

public:
    stack<int> org_stack;
    stack<int> min_stack;

    MinStack() {
        min_stack.push(INT_MAX);
    }
    
    void push(int val) {
        org_stack.push(val);
        min_stack.push(min(min_stack.top(), val));
    }
    
    void pop() {
        org_stack.pop();
        min_stack.pop();
    }
    
    int top() {
        return org_stack.top();
    }
    
    int getMin() {
        return min_stack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end



/*
// @lcpr case=start
// ["MinStack","push","push","push","getMin","pop","top","getMin"][[],[-2],[0],[-3],[],[],[],[]]\n
// @lcpr case=end

 */

