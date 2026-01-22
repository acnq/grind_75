/*
 * @lc app=leetcode.cn id=3510 lang=cpp
 * @lcpr version=30204
 *
 * [3510] 移除最小数对使数组有序 II
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

#include <numeric> // iota
// @lcpr-template-end
// @lc code=start

typedef long long ll;
const int MAX_N = 100005;

struct Node {
    ll value;
    int left;
};

using ListIt = std::list<Node>::iterator;

struct Pair {
    ListIt first;
    ListIt second;
    ll cost;
    size_t firstLeft;
    size_t secondLeft;

    Pair() {}
    Pair(ListIt fi, ListIt se, ll cost)
        : first(fi), second(se), firstLeft(fi->left), secondLeft(se->left), 
            cost(cost) {}
};

struct ComparePair{
    bool operator()(const Pair& a, const Pair& b) {
        if (a.cost != b.cost) {
            return a.cost > b.cost;
        }
        return a.firstLeft > b.firstLeft;
    }
};

class Solution {
    // I. 优先队列+惰删除
    // 假设弹出的相邻数对为(i, j) (j = i + 1)
    // 那么合并之后，i - 1, j + 1和合并之后的元素组成两个新的相邻数对
    // 于是我们把新数对加入优先队列，同时，(i - 1, i)和(j, j + 1)
    // 就变成了脏数据，我们使用惰删除：弹出操作中判断弹出的是否是脏而不立刻删除
    // 实现惰删除的方法：
    // 假设总是向左合并，考虑维护两个信息
    //  1. merged数组：判断某个位置的元素是否已经被合并，只有两个元素都没有合并，他们的引用才有效
    //  2. 存入数对时，同时存入当前的数对和。待弹出时，即使两个元素有效，如果数对和变化，也是脏的
    
    // 单调性用decreaseCount维护：当前nums有多少个相邻数对递减
    // decreaseCount = 0才单调递增
    // 合并(i, j)维护decreaseCount的方案：
    //  1. 本来就有nums[i] > nums[j]， decreaseCount -= 1
    //  2. i != 0, 比较nums[i - 1]和nums[i]在合并前后的变化，如果从递减辩伪递增，decreaseCount--, 否则++
    //  3. j != n - 1, 比较nums[j]和nums[j + 1], 仿2
    // decreaseCount = 0则跳出外层循环
    // 这样我们就不用直接遍历nums, 仅仅获得当前数对的前驱和后继即可
    // 我们用双向链表维护
public:
    

    int minimumPairRemoval(vector<int>& nums) {
        std::list<Node> list;
        std::bitset<MAX_N> merged;
        std::priority_queue<Pair, std::vector<Pair>, ComparePair> pq;

        int decreaseCount = 0;
        int count = 0;

        list.push_back({nums[0], 0});

        for (size_t i = 1; i < nums.size(); i++) {
            list.push_back({nums[i], (int)i});

            auto curr = std::prev(list.end());
            auto prev = std::prev(curr);

            pq.push({prev, curr, prev->value + curr->value});

            if (nums[i - 1] > nums[i]) {
                decreaseCount++;
            }
        }

        while (decreaseCount > 0 && !pq.empty()) {
            auto top = pq.top();
            pq.pop();

            if (merged[top.firstLeft] || merged[top.secondLeft]) {
                continue;
            }

            auto first = top.first;
            auto second = top.second;
            auto cost = top.cost;

            if (first->value + second->value != cost) {
                continue;
            }
            count++;

            if (first->value > second->value) {
                decreaseCount--;
            }
            ListIt prev = 
                (first == list.begin()) ? list.end() : std::prev(first);
            ListIt next = std::next(second);

            if (prev != list.end()) {
                if (prev->value > first->value && prev->value <= cost) {
                    decreaseCount--;
                }

                if (prev->value <= first->value && prev->value > cost) {
                    decreaseCount++;
                }
                pq.push({prev, first, prev->value + cost});
            }

            if (next != list.end()) {
                if (second->value > next->value && cost <= next->value) {
                    decreaseCount--;
                }
                if (second->value <= next->value && cost > next->value) {
                    decreaseCount++;
                }
                pq.push({first, next, cost + next->value});
            }

            first->value = cost;
            merged[second->left] = 1;
            list.erase(second);
        }
        return count;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [5,2,3,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,2]\n
// @lcpr case=end

 */

