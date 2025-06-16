/*
 * @lc app=leetcode.cn id=621 lang=cpp
 * @lcpr version=30204
 *
 * [621] 任务调度器
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

#include <numeric>
// @lcpr-template-end
// @lc code=start
class Solution {
    // I. 模拟
    // 不在冷却中的任务，选择剩余执行次数最多的那个任务
    // (nextvalid_i, rest_i), 第i任务，
    // nextvalid_i: 因其冷却限制,最早可以执行的时间, 初始化为1
    // rest_i: 剩余执行此数，
    // 用time记录当前时间，根据策略，选择不在冷却中且剩余执行次数最多的那个任务
    // => 找到nextvalid_i <= time, 且rest_i最大的i
    // 之后更新nextvalid_i = time + n + 1, rest_i = rest_i - 1
    // time不需要不断增加1，但是可以将time更新为所有nextvalid_i中的最小值
    // 跳过待命(idle)状态, 当然，只有这个最小值大于time, 才需要如此快速更新
    // 证明：只需证明选a的时间点，改成选b,时间不减少即可

    // II. 构造
    // 假设执行次数的任务为A, 次数为maxExec
    // 构造一个宽为n + 1的矩阵可视化，由于A冷却时间为n, 将A全部排布在第一列
    // 这是总时间最少得排布，对应总时间(maxExec - 1)(n + 1) + 1
    // 如果需要执行时间maxExec次的任务总数量为maxCount, 
    // 对应总时间变为(maxExec - 1)(n + 1) + maxCount
    // 假设maxCount <= n + 1
    //  剩余任务的执行次数都小于maxExec, 从倒数第二行开始，按照反向列优先的顺序
    // (先放入靠左侧的列，同一列中先放入下方的行)同一种任务需要连续填入
    // 这样总时间不会变大
    // 考虑如果填的数量超过了n + 1列
    // 那么所有的 CPU 待命状态都是可以省去的, 
    // 因为CPU待命状态本身只是为了规定相邻任务的执行间隔至少为n
    // 所以如果列超过，总执行时间就是任务总数|task|
    // 总时间就是(maxExec - 1)(n + 1) + maxCount 和 |task|的较大值
    // 图见 https://leetcode.cn/problems/task-scheduler/solutions/509687/ren-wu-diao-du-qi-by-leetcode-solution-ur9w/

public:
    int leastInterval(vector<char>& tasks, int n) {
        // unordered_map<char, int> freq;
        // for(char ch: tasks) {
        //     freq[ch]++;
        // }

        // // 任务种类数量
        // int m = freq.size();
        // vector<int> nextValid, rest;
        // for(auto [_, v]: freq) {
        //     nextValid.push_back(1);
        //     rest.push_back(v);
        // }

        // int time = 0;
        // for (int i = 0; i < tasks.size(); i++)
        // {
        //     time++;
        //     int minNextValid = INT_MAX;
        //     for (int j = 0; j < m; j++)
        //     {
        //         if (rest[j])
        //         {
        //             minNextValid = min(minNextValid, nextValid[j]);
        //         }
        //     }
        //     time = max(time, minNextValid);
        //     int best = -1;
        //     for (int j = 0; j < m; j++)
        //     {
        //         if (rest[j] && nextValid[j] <= time)
        //         {
        //             if (best == -1 || rest[j] > rest[best])
        //             {
        //                 best = j;
        //             }
        //         }
        //     }
        //     nextValid[best] = time + n + 1;
        //     rest[best]--;
        // }
        // return time;
        unordered_map<char, int> freq;
        for(char ch: tasks) {
            freq[ch]++;
        }
        // 最多执行次数
        int maxExec = max_element(freq.begin(), freq.end(), [](const auto& u, const auto& v) {
            return u.second < v.second;
        })->second;
        // 有最多执行次数的任务数量
        int maxCount = accumulate(freq.begin(), freq.end(), 0, [=](int acc, const auto& u){
            return acc + (u.second == maxExec);
        });
        return max((maxExec - 1) * (n + 1) + maxCount, static_cast<int>(tasks.size()));
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["A","A","A","B","B","B"]\n2\n
// @lcpr case=end

// @lcpr case=start
// ["A","C","A","B","D","B"]\n1\n
// @lcpr case=end

// @lcpr case=start
// ["A","A","A","B","B","B"]\n3\n
// @lcpr case=end

 */

