/*
 * @lc app=leetcode.cn id=150 lang=cpp
 * @lcpr version=30204
 *
 * [150] 逆波兰表达式求值
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
public:
    bool isNumber(string& token) {
        return !(token == "+" || token == "-" || token == "*" || token == "/");
    };

    int evalRPN(vector<string>& tokens) {
        // stack
        // 遇到操作数，入栈
        // 遇到运算符，两个操作数出栈，进行运算，结果入栈
        // stack<int> stk;
        // int n = tokens.size();
        // for (int i = 0; i < n; i++)
        // {
        //     string& token = tokens[i];
        //     if (isNumber(token))
        //     {
        //         stk.push(atoi(token.c_str()));
        //     } else {
        //         int num2 = stk.top();
        //         stk.pop();
        //         int num1 = stk.top();
        //         stk.pop();
        //         switch (token[0])
        //         {
        //         case '+':
        //             stk.push(num1 + num2);
        //             break;
        //         case '-':
        //             stk.push(num1 - num2);
        //             break;
        //         case '*':
        //             stk.push(num1 * num2);
        //             break;
        //         case '/':
        //             stk.push(num1 / num2);
        //             break;
        //         }
        //     }
        // }
        // return stk.top();

        // 数组模拟器：
        // index表示栈顶元素的下标位置, 
        // 初始时栈为空，index = -1
        // 遇到操作数时，栈内元素+1: index++, 数赋值给stack[index]；
        // 遇到操作符，栈内元素-1: index--, 运算stack[index]和stack[index+1], 得到新值赋值给stack[index]；
        int n = tokens.size();
        vector<int> stk((n + 1) / 2);
        int index = -1;
        for (int i = 0; i < n; i++)
        {
            string& token = tokens[i];
            if (token.length() > 1 || isdigit(token[0]))
            {
                index++;
                stk[index] = atoi(token.c_str());
            } else {
                switch (token[0])
                {
                case '+':
                    index--;
                    stk[index] += stk[index + 1];
                    break;
                case '-':
                    index--;
                    stk[index] -= stk[index + 1];
                    break;
                case '*':
                    index--;
                    stk[index] *= stk[index + 1];
                    break;
                case '/':
                    index--;
                    stk[index] /= stk[index + 1];
                    break;
                default:
                    break;
                }
            }
        }
        return stk[index];
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["2","1","+","3","*"]\n
// @lcpr case=end

// @lcpr case=start
// ["4","13","5","/","+"]\n
// @lcpr case=end

// @lcpr case=start
// ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]\n
// @lcpr case=end

 */

