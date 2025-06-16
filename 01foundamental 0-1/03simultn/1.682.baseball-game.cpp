// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=682 lang=cpp
 * @lcpr version=30204
 *
 * [682] 棒球比赛
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

#include <string> // stoi
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int calPoints(vector<string>& operations) {
        // int ans = 0;
        // vector<int> res;
        // for(string str: operations) {
        //     if (str != "C" && str != "D" && str != "+")
        //     {
        //         int num = stoi(str);
        //         res.push_back(num);
        //     } else if (str == "C")
        //     {
        //         res.pop_back();
        //     } else if (str == "D")
        //     {
        //         int tmp = res.back();
        //         res.push_back(2 * tmp);
        //     } else if (str == "+") 
        //     {
        //         int tmpN = res.size();
        //         int tmp1 = res[tmpN - 1];
        //         int tmp2 = res[tmpN - 2];
        //         res.push_back(tmp1 + tmp2);
        //     }
        // }
        // for(int elem: res) {
        //     ans += elem;
        // }
        // return ans;
        // 写了22分钟，感觉太慢了，看官方关键是得用栈而不是数组

        int ret = 0;
        vector<int> points;
        for(auto& op: operations) {
            int n = points.size();
            switch (op[0])
            {
            case '+':
                ret += points[n - 1] + points[n - 2];
                points.push_back(points[n - 1] + points[n - 2]);
                break;
            case 'D':
                ret += 2 * points[n - 1];
                points.push_back(2 * points[n - 1]);
                break;
            case 'C':
                ret += points[n - 1];
                points.pop_back();
                break;
            default:
                ret += stoi(op); // 直接在这里加就可以了
                points.push_back(stoi(op));
                break;
            }
        }
        return ret;
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["5","2","C","D","+"]\n
// @lcpr case=end

// @lcpr case=start
// ["5","-2","4","C","D","9","+","+"]\n
// @lcpr case=end

// @lcpr case=start
// ["1"]\n
// @lcpr case=end

 */

