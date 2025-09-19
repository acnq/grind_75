/*
 * @lc app=leetcode.cn id=3484 lang=cpp
 * @lcpr version=30204
 *
 * [3484] 设计电子表格
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
class Spreadsheet {
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
    Spreadsheet(int rows) {
        // I.
        // this->grid = vector<vector<int>>(rows + 1, vector<int>(26));
        
        // II.

    }
    
    void setCell(string cell, int value) {
        // I.
        // auto [x, y] = getPos(cell);
        // grid[x][y] = value;
        
        // II.
        cellValues[cell] = value;
    }
    
    void resetCell(string cell) {
        // I.
        // auto [x, y] = getPos(cell);
        // grid[x][y] = 0;
        
        // II.
        cellValues.erase(cell);
    }
    
    int getValue(string formula) {
        // I.
        // int i = formula.find('+');
        // string cell1 = formula.substr(1, i - 1);
        // string cell2 = formula.substr(i + 1);
        // return getCellVal(cell1) + getCellVal(cell2);

        // II.
        int i = formula.find('+');
        string cell1 = formula.substr(1, i - 1);
        string cell2 = formula.substr(i + 1);
        return (isalpha(cell1[0]) ? cellValues[cell1]: stoi(cell1)) +
                (isalpha(cell2[0]) ? cellValues[cell2]: stoi(cell2));
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

