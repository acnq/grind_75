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
// @lcpr-template-end
// @lc code=start
class Router {
    // I. 直接模拟：
    // 用二维数组grid来保存每个单元格的值，行数为row, 列数为26
    // 初始化：Spreadsheet(int rows), 列数设定为26，元素全部设定为0
    // 添加：void setCell(String cell, int value) 按照规则从字符串cell中解析出单元格对应的行列
    // 编辑：void resetCell(String cell), 仿上一条将其重置为0即可
    // 计算：int getValue(String formula): 因为这里只支持=X+Y的格式，所以
    //      依照此格式直接解析X/Y即可，如果X/Y首字母为字母则为单元格，从grid读取；否则解析为整数
    //      分别解析之后返回二者的和即可
    // 执行：从heap弹出任务，检查是否在taskInfo中存在且priority匹配，
    //      若匹配则删除并返回userId, 否则继续弹出直到找到或者堆空
    // C: 初始表格的列数，本题为26
    // tc: 初始化：O(C * rows); else: O(1);
    // sc: O(C * rows) 

    // II. 哈希表
    // 直接用哈希表将单元格字符串映射到单元格的值
private:
    // I.
    // vector<vector<int>> grid;

    // pair<int, int> getPos(const string& cell) {
    //     int x = stoi(cell.substr(1));
    //     int y = cell[0] - 'A';
    //     return {x, y};
    // }

    // int getCellVal(string& cell) {
    //     if (isalpha(cell[0])) {
    //         auto [x, y] = getPos(cell);
    //         return grid[x][y];
    //     } else {
    //         return stoi(cell);
    //     }
    // }
    
    // II.
    unordered_map<string, int> cellValues;

public:
    Router(int memoryLimit) {

    }
    
    bool addPacket(int source, int destination, int timestamp) {
    }
    
    vector<int> forwardPacket() {
    }
    
    int getCount(int destination, int startTime, int endTime) {
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

