/*
 * @lc app=leetcode.cn id=3408 lang=cpp
 * @lcpr version=30204
 *
 * [3408] 设计任务管理器
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
class TaskManager {
    // I. 优先队列 + 哈希表：
    // 初始化：哈希表taskInfo存储每个任务的最新信息（priority/userId)
    //      同时放入最大堆heap中，存储priority/userId, 以便高效获取最高优先级任务
    // 添加：任务信息存入taskInfo, 并向heap推送对应的priority/userId
    // 编辑：更新taskInfo中任务的优先级，并向heap中推送新的priority/userId
    //      旧记录作懒删除
    // 删除：直接从taskInfo中移除，heap中的旧记录通过后续操作跳过（懒删除)
    // 执行：从heap弹出任务，检查是否在taskInfo中存在且priority匹配，
    //      若匹配则删除并返回userId, 否则继续弹出直到找到或者堆空
    // n: 初始化tasks长度，m: 后续操作次数
    // tc: 初始化：O(n logn); add/edit: O(log(n + m)); rmv: O(1); exec: O(log(n + m))
    // sc: O(n + m) 
private:
    unordered_map<int, pair<int, int>> taskInfo;
    priority_queue<pair<int, int>> heap;

public:
    TaskManager(vector<vector<int>>& tasks) {
        for (auto& task: tasks) {
            int userId = task[0], taskId = task[1], priority = task[2];
            taskInfo[taskId] = {priority, userId};
            heap.emplace(priority, taskId);
        }  
    }
    
    void add(int userId, int taskId, int priority) {
        taskInfo[taskId] = {priority, userId};
        heap.emplace(priority, taskId);
    }
    
    void edit(int taskId, int newPriority) {
        if (taskInfo.find(taskId) != taskInfo.end()) {
            taskInfo[taskId].first = newPriority;
            heap.emplace(newPriority, taskId);
        }
    }
    
    void rmv(int taskId) {
        taskInfo.erase(taskId);
    }
    
    int execTop() {
        while(!heap.empty()) {
            auto [priority, taskId] = heap.top();
            heap.pop();

            if (taskInfo.find(taskId) != taskInfo.end() &&
                taskInfo[taskId].first == priority) {
                int userId = taskInfo[taskId].second;
                taskInfo.erase(taskId);
                return userId;    
            }
        }
        return -1;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */
// @lc code=end



/*
// @lcpr case=start
// ["TaskManager", "add", "edit", "execTop", "rmv", "add", "execTop"][[[[1, 101, 10], [2, 102, 20], [3, 103, 15]]], [4, 104, 5], [102, 8], [], [101], [5, 105, 15], []]\n
// @lcpr case=end

 */

