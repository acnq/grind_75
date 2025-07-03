/*
 * @lc app=leetcode.cn id=895 lang=cpp
 * @lcpr version=30204
 *
 * [895] 最大频率栈
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
class FreqStack {
    // I. 哈希和栈
    // 我们需要把栈降解乘多个频率不同的栈序列，每个维护同一频率的元素
    // 当元素入栈时频率增加，将元素加入到高频率的栈中，低频率栈中的元素无需出栈
    // 当元素出栈时，频率最高的栈栈顶元素出栈即可。
    // 详细的，哈希表freq记录每个元素出现的次数，设当前最大频率maxFreq
    // 为1-maxFreq中每个元素单独设置一个栈，记freq[x]为x的频率，group[i]为频率i的栈
    // 1. x入栈，freq[x] + 1, x放入group[freq[x]]中，maxFreq = max(maxFreq, freq[x])
    // 此时group[1]-group[freq[x]]中的每个栈都包含x
    // 2. 出栈时，获取x = group[maxFreq].top()出栈，freq[x]--; 
    //      若x出栈后，group[maxFreq]为空，那么maxFreq--
    // tc: O(1); sc: O(n)
private:
    unordered_map<int, int> freq;
    unordered_map<int, stack<int>> group;
    int maxFreq;

public:
    FreqStack() {
        maxFreq = 0;
    }
    
    void push(int val) {
        freq[val]++;
        group[freq[val]].push(val);
        maxFreq = max(maxFreq, freq[val]);
    }
    
    int pop() {
        int val = group[maxFreq].top();
        freq[val]--;
        group[maxFreq].pop();
        if (group[maxFreq].empty())
        {
            maxFreq--;
        }
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
// @lc code=end



/*
// @lcpr case=start
// ["FreqStack","push","push","push","push","push","push","pop","pop","pop","pop"],[[],[5],[7],[5],[7],[4],[5],[],[],[],[]]\n
// @lcpr case=end

 */

