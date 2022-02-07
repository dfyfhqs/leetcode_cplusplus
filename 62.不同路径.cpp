/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 *
 * https://leetcode-cn.com/problems/unique-paths/description/
 *
 * algorithms
 * Medium (66.26%)
 * Likes:    1156
 * Dislikes: 0
 * Total Accepted:    326.8K
 * Total Submissions: 492.9K
 * Testcase Example:  '3\n7'
 *
 * 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。
 * 
 * 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。
 * 
 * 问总共有多少条不同的路径？
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：m = 3, n = 7
 * 输出：28
 * 
 * 示例 2：
 * 
 * 
 * 输入：m = 3, n = 2
 * 输出：3
 * 解释：
 * 从左上角开始，总共有 3 条路径可以到达右下角。
 * 1. 向右 -> 向下 -> 向下
 * 2. 向下 -> 向下 -> 向右
 * 3. 向下 -> 向右 -> 向下
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：m = 7, n = 3
 * 输出：28
 * 
 * 
 * 示例 4：
 * 
 * 
 * 输入：m = 3, n = 3
 * 输出：6
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 题目数据保证答案小于等于 2 * 10^9
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int uniquePaths(int m, int n) {
        int result = 0;
        help(m, n, 0, 0, &result);
        return result;
    }

    void help(int m, int n, int startx, int starty, int* result) {
        cout << startx << ", " << starty << endl;
        if (startx < m) {
            (*result) += 1;
            help(m, n, startx+1, starty, result);
        }
        if (starty < n) {
            (*result) += 1;
            help(m,n, startx, starty+1, result);
        }
        return;
    }
};
// @lc code=end

