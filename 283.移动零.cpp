/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
      int left = 0, right = 0;
      for (; right < nums.size(); right++) {
        if (nums[right] == 0) {
          continue;
        }
        nums[left++] = nums[right];
      }
      for (; left < nums.size(); left++) {
        nums[left] = 0; 
      }
    }
};
// @lc code=end

