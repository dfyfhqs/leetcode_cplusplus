/*
 * @Author: stone stone
 * @Date: 2023-08-13 11:39:19
 * @LastEditors: stone stone
 * @LastEditTime: 2023-08-13 11:43:52
 * @FilePath: /leetcode_cplusplus/27.移除元素.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
      int left = 0, right = 0;
      for (; right < nums.size(); ++right) {
        if (val == nums[right]) {
          continue;
        }
        nums[left++] = nums[right];
      }
      return left;
    }
};
// @lc code=end

