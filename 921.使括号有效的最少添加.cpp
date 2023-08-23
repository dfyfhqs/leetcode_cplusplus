/*
 * @Author: stone stone
 * @Date: 2023-08-23 23:08:35
 * @LastEditors: stone stone
 * @LastEditTime: 2023-08-23 23:18:17
 * @FilePath: /leetcode_cplusplus/921.使括号有效的最少添加.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=921 lang=cpp
 *
 * [921] 使括号有效的最少添加
 *
 * https://leetcode.cn/problems/minimum-add-to-make-parentheses-valid/description/
 *
 * algorithms
 * Medium (73.02%)
 * Likes:    247
 * Dislikes: 0
 * Total Accepted:    67.8K
 * Total Submissions: 92.8K
 * Testcase Example:  '"())"'
 *
 * 只有满足下面几点之一，括号字符串才是有效的：
 * 
 * 
 * 它是一个空字符串，或者
 * 它可以被写成 AB （A 与 B 连接）, 其中 A 和 B 都是有效字符串，或者
 * 它可以被写作 (A)，其中 A 是有效字符串。
 * 
 * 
 * 给定一个括号字符串 s ，在每一次操作中，你都可以在字符串的任何位置插入一个括号
 * 
 * 
 * 例如，如果 s = "()))" ，你可以插入一个开始括号为 "(()))" 或结束括号为 "())))" 。
 * 
 * 
 * 返回 为使结果字符串 s 有效而必须添加的最少括号数。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "())"
 * 输出：1
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "((("
 * 输出：3
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 1000
 * s 只包含 '(' 和 ')' 字符。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int minAddToMakeValid(string s) {
      stack<char> label;
      int result = 0;
      for(auto c : s) {
        if (c == '(') {
          if (label.empty()) {
            label.push(c);
          } else if (label.top() == ')') {
            label.pop();
          } else {
            label.push(c);
          }
        } else {
          if (label.empty()) {
            result++;
            continue;
          } else {
            label.pop();
          }
        } 
      }
      return result + label.size();
    }
};
// @lc code=end

