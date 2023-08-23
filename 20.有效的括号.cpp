/*
 * @Author: stone stone
 * @Date: 2023-08-23 23:01:51
 * @LastEditors: stone stone
 * @LastEditTime: 2023-08-23 23:07:57
 * @FilePath: /leetcode_cplusplus/20.有效的括号.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 *
 * https://leetcode.cn/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (43.99%)
 * Likes:    4103
 * Dislikes: 0
 * Total Accepted:    1.6M
 * Total Submissions: 3.5M
 * Testcase Example:  '"()"'
 *
 * 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
 * 
 * 有效字符串需满足：
 * 
 * 
 * 左括号必须用相同类型的右括号闭合。
 * 左括号必须以正确的顺序闭合。
 * 每个右括号都有一个对应的相同类型的左括号。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "()"
 * 输出：true
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "()[]{}"
 * 输出：true
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：s = "(]"
 * 输出：false
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 10^4
 * s 仅由括号 '()[]{}' 组成
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
      std::stack<char> label;

      for (auto c : s) {
        if (c == '(' || c == '{' || c == '[') {
          label.push(c);
          continue;
        }
        if (label.empty()) return false;
        if ((c == ')' && label.top() == '(') ||
            (c == '}' && label.top() == '{') ||
            (c == ']' && label.top() == '[')) {
          label.pop();
          continue;
        } else {
          return false;
        }
      }
      return label.empty();
    }
};
// @lc code=end

