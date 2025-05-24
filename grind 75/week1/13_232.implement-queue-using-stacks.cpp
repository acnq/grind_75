/*
 * @lc app=leetcode.cn id=232 lang=cpp
 * @lcpr version=30204
 *
 * [232] 用栈实现队列
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
class MyQueue {
public:
    stack<int> stk1; // input stack
    stack<int> stk2; // output stack
    // while input, nmlly instack;
    // while output, 
    //      if output stack is empty, 
    //          unstack all elem in input stack, then unstack top
    //      else
    //          unstack top in input stack.

    MyQueue() {
        
    }
    
    void push(int x) {
        stk1.push(x);
    }
    
    int pop() {
        if (!stk2.empty())
        {
            int x = stk2.top();
            stk2.pop();
            return x;
        } else {
            while (!stk1.empty())
            {
                int x = stk1.top();
                stk1.pop();
                stk2.push(x);
            }
            int x = stk2.top();
            stk2.pop();
            return x;
        }
    }
    
    int peek() {
        if (!stk2.empty())
        {
            int x = stk2.top();
            return x;
        } else {
            while (!stk1.empty())
            {
                int x = stk1.top();
                stk1.pop();
                stk2.push(x);
            }
            int x = stk2.top();
            return x;
        }
    }
    
    bool empty() {
        if (stk1.empty() && stk2.empty())
        {
            return true;
        } else {
            return false;
        }
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end



/*
// @lcpr case=start
// ["MyQueue", "push", "push", "peek", "pop", "empty"][[], [1], [2], [], [], []]\n
// @lcpr case=end

 */

