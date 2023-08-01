/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 *
 * https://leetcode.cn/problems/longest-increasing-subsequence/description/
 *
 * algorithms
 * Medium (54.82%)
 * Likes:    3309
 * Dislikes: 0
 * Total Accepted:    763.6K
 * Total Submissions: 1.4M
 * Testcase Example:  '[10,9,2,5,3,7,101,18]'
 *
 * 给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。
 * 
 * 子序列 是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7]
 * 的子序列。
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [10,9,2,5,3,7,101,18]
 * 输出：4
 * 解释：最长递增子序列是 [2,3,7,101]，因此长度为 4 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [0,1,0,3,2,3]
 * 输出：4
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [7,7,7,7,7,7,7]
 * 输出：1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 2500
 * -10^4 <= nums[i] <= 10^4
 * 
 * 
 * 
 * 
 * 进阶：
 * 
 * 
 * 你能将算法的时间复杂度降低到 O(n log(n)) 吗?
 * 
 * 
 */

// @lc code=start
class Solution {
public:
     // 使用二分查找
     // https://labuladong.github.io/algo/di-er-zhan-a01c6/zi-xu-lie--6bc09/dong-tai-g-6ea57/
     int lengthOfLIS(vector<int>& nums) {
        std::vector<int> dp(nums.size(), INT_MIN);
        int size = 0;
        dp[0] = nums[0];
        for (auto i = 1; i < nums.size(); ++i) {
          int val = nums[i];
          int left = 0, right = size;
          while (left <= right) {
            int mid = left + (right - left) / 2;
            if (dp[mid] < val) {
              left = mid + 1;
            } else {
              right = mid - 1;
            }
          }
          if (left <= size && dp[left] >= val) {
            dp[left] = val;
          } else {
            size += 1;
            dp[size] = val;
          }
          std::cout << "i: " << i << " size: " << size << std::endl;
        }
        return size + 1;
     }

    /**
     * 动态规划  dp[i]表示以nums[i]结尾的最长递增子序列的长度
     *
     * @param nums vector of integers
     *
     * @return length of the longest increasing subsequence
     *
     * @throws None
     */
    int lengthOfLISDp(vector<int>& nums) {
      std::vector<int> dp(nums.size(), 1);
      int result = 1;
      for (auto i = 1; i < nums.size(); ++i) {
        for (auto j = 0; j < i; ++j) {
          if (nums[j] < nums[i]) {
            dp[i] = max(dp[i], dp[j] + 1);
            result = max(result, dp[i]);
          }
        }
      }
      return result;
    }
};
// @lc code=end

