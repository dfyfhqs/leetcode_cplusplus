/*
 * @Author: stone stone
 * @Date: 2023-08-04 01:58:12
 * @LastEditors: stone stone
 * @LastEditTime: 2023-08-04 01:59:24
 * @FilePath: /leetcode_cplusplus/172.阶乘后的零.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=172 lang=cpp
 *
 * [172] 阶乘后的零
 */

// @lc code=start
class Solution {
public:
    int trailingZeroes(int n) {
      int result = 0;
      while (n >= 5) {
        result += int(n / 5);
        n = n /5;
      }
      return result;
    }
};
// @lc code=end

