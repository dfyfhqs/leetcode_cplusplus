/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 *
 * https://leetcode.cn/problems/4sum/description/
 *
 * algorithms
 * Medium (36.93%)
 * Likes:    1719
 * Dislikes: 0
 * Total Accepted:    495.6K
 * Total Submissions: 1.3M
 * Testcase Example:  '[1,0,-1,0,-2,2]\n0'
 *
 * 给你一个由 n 个整数组成的数组 nums ，和一个目标值 target 。请你找出并返回满足下述全部条件且不重复的四元组 [nums[a],
 * nums[b], nums[c], nums[d]] （若两个四元组元素一一对应，则认为两个四元组重复）：
 * 
 * 
 * 0 <= a, b, c, d < n
 * a、b、c 和 d 互不相同
 * nums[a] + nums[b] + nums[c] + nums[d] == target
 * 
 * 
 * 你可以按 任意顺序 返回答案 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,0,-1,0,-2,2], target = 0
 * 输出：[[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [2,2,2,2,2], target = 8
 * 输出：[[2,2,2,2]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 200
 * -10^9 <= nums[i] <= 10^9
 * -10^9 <= target <= 10^9
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
      vector<int> singleResult;
      if (nums.empty()) {result_;}
      std::sort(nums.begin(), nums.end(), std::less<int>());

      numSum(singleResult, nums, 4, 0, target);
      return result_;
    }

    void numSum(vector<int>& singleResult, vector<int>& nums, int count, int start, int target) {
      if (start >= singleResult.size()) {
        return;
      }
      if (count == 1) {
        for (int i = start; i < nums.size(); ++i) {
          if (i > start && nums[i] == nums[i-1]) {
            continue;
          }
          if (nums[i] == target) {
            singleResult.push_back(nums[i]);
            result_.emplace_back(std::move(singleResult));
            return;
          } else if (nums[i] > target) {
            return;
          }
        }
        return;
      }
      for (int i = start; i < nums.size(); ++i) {
        if (i > start && nums[i] == nums[i-1]) {
          continue;
        }
        singleResult.emplace_back(nums[i]);
        numSum(singleResult, nums, count - 1, i+1, target - nums[i]);
        singleResult.pop_back();
      }
    }

    vector<vector<int>> result_;
};
// @lc code=end

