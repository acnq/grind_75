/*
 * @lc app=leetcode.cn id=3508 lang=cpp
 * @lcpr version=30204
 *
 * [3508] 设计路由器
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

#include <string>
#include <set>
// @lcpr-template-end
// @lc code=start
class Router {
    // I. 直接模拟：
    // addPacket: 添加数据包：如果已经存在返回false, 否则返回true
    //  如果路由器内存已满，则将内存中最旧的（时间戳最小的）移除，然后再添加
    // forwardPacket: 先进先出的顺序转发下一个个数据包，返回其src, dest和timestamp
    // getCount: 返回当前路由器中目标为dest, 且时间戳再startTime-endTime之间的数据包
    //  包括两端。
    // 定义Router类中的成员：
    // memLimit: int, 内存大小
    // length: int 当前路由器内存中数据包的数量
    // isExist； int三元组，表示当前路由器内存中是否存在某个数据包
    // sameDestQue: 无序哈希表，以dest为key，以目标为dest的每个数据包
    // 的时间戳组成的双端队列为值，表示当前路由器内存中每个目标地址对应的数据包的时间戳
    // que: 三元组双端队列，表示当前路由器内存中的数据包
    // addPacket: 移除由forwardPacket完成；将需要添加的数据包存入que中，对应目标地址dest
    //  的时间戳timestamp存入sameDestQue中，然后再isExist中登记，最后返回true即可
    // forwardPacket: 判断que是否为空，是则返回空；否则取出que中首个元素，弹出此元素
    //  然后从isExist中移除，从sameDestQue中移除时间戳，最后返回其src, dest, timestamp
    // getCount: 从sameDestQue的目标地址为dest的队列中，使用二分查找lower/upper_bound
    //  找到startTime, endTime之间的元素个数即可
    // tc: init: O(1), addPacket,/forwardPacket/getCount: O(logn)
    // sc: init: O(n), else: O(1)
private:

public:
    //
    int memLimit = 0;
    int length = 0;
    set<tuple<int, int, int>> isExist;
    unordered_map<int, deque<int>> sameDestQue;
    deque<tuple<int, int, int>> que;

    Router(int memoryLimit) {
        //
        memLimit = memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        //
        tuple<int, int, int> packet = make_tuple(source, destination, timestamp);
        if (isExist.count(packet)) {
            return false;
        }
        if (length == memLimit) {
            forwardPacket();
        }
        length++;
        que.push_back(packet);
        sameDestQue[destination].push_back(timestamp);
        isExist.insert(packet);
        return true;
    }
    
    vector<int> forwardPacket() {
        //
        vector<int> data;
        if (!que.empty()) {
            tuple<int, int, int> packet = que.front();
            que.pop_front();
            data = vector<int>{get<0>(packet), get<1>(packet), get<2>(packet)};
            isExist.erase(packet);
            sameDestQue[data[1]].pop_front();
            length--;
        }
        return data;
    }
    
    int getCount(int destination, int startTime, int endTime) {
        auto pos1 = lower_bound(sameDestQue[destination].begin(), sameDestQue[destination].end(), startTime);
        auto pos2 = upper_bound(sameDestQue[destination].begin(), sameDestQue[destination].end(), endTime);
        return pos2 - pos1;
    }
    
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTim
 * /
// @lc code=end



/*
// @lcpr case=start
// ["Router","addPacket","addPacket","addPacket","addPacket","addPacket","forwardPacket","addPacket","getCount"]\n[[3],[1,4,90],[2,5,90],[1,4,90],[3,5,95],[4,5,105],[],[5,2,110],[5,100,110]]\n
// @lcpr case=end

// @lcpr case=start
// ["Router","addPacket","forwardPacket","forwardPacket"]\n[[2],[7,4,90],[],[]]\n
// @lcpr case=end

 */

