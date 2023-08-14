/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 *
 * https://leetcode.cn/problems/sliding-window-maximum/description/
 *
 * algorithms
 * Hard (49.63%)
 * Likes:    2425
 * Dislikes: 0
 * Total Accepted:    470.5K
 * Total Submissions: 949.3K
 * Testcase Example:  '[1,3,-1,-3,5,3,6,7]\n3'
 *
 * 给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k
 * 个数字。滑动窗口每次只向右移动一位。
 * 
 * 返回 滑动窗口中的最大值 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
 * 输出：[3,3,5,5,6,7]
 * 解释：
 * 滑动窗口的位置                最大值
 * ---------------               -----
 * [1  3  -1] -3  5  3  6  7       3
 * ⁠1 [3  -1  -3] 5  3  6  7       3
 * ⁠1  3 [-1  -3  5] 3  6  7       5
 * ⁠1  3  -1 [-3  5  3] 6  7       5
 * ⁠1  3  -1  -3 [5  3  6] 7       6
 * ⁠1  3  -1  -3  5 [3  6  7]      7
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1], k = 1
 * 输出：[1]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 * 1 <= k <= nums.length
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
      vector<int> result;
      deque<int> label;
      label.push_back(0);
      result.push_back(nums[0]);
      
      for (int i = 1; i < nums.size(); ++i) {

        while (!label.empty() && ((i - label.front() + 1) > k)) {
          label.pop_front();
        }
        //std::cout << "i: " << i << std::endl;
        //for (auto& val : label) {
        //  std::cout << "before: " << val << std::endl;
        //}
        // top 在 滑动窗口范围内
        auto cur = nums[i];
        while (!label.empty()) {
          auto back = nums[label.back()];
          if (cur > back) {
            label.pop_back();
            continue;
          }
          else {
            break;
          }
        }
        label.push_back(i);
        //for (auto& val : label) {
        //  std::cout << "after: " <<  val << std::endl;
        //}
        result.emplace_back(nums[label.front()]);
      }
      
      return std::vector<int>(result.begin()+k-1, result.end());
    }
};
// @lc code=end

