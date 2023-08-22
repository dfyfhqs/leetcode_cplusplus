/*
 * @Author: stone stone
 * @Date: 2023-08-23 00:26:57
 * @LastEditors: stone stone
 * @LastEditTime: 2023-08-23 00:46:47
 * @FilePath: /leetcode_cplusplus/560.和为-k-的子数组.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为 K 的子数组
 *
 * https://leetcode.cn/problems/subarray-sum-equals-k/description/
 *
 * algorithms
 * Medium (44.85%)
 * Likes:    2028
 * Dislikes: 0
 * Total Accepted:    342.5K
 * Total Submissions: 763.7K
 * Testcase Example:  '[1,1,1]\n2'
 *
 * 给你一个整数数组 nums 和一个整数 k ，请你统计并返回 该数组中和为 k 的连续子数组的个数 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,1,1], k = 2
 * 输出：2
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1,2,3], k = 3
 * 输出：2
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 2 * 10^4
 * -1000 <= nums[i] <= 1000
 * -10^7 <= k <= 10^7
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
      unordered_map<int, int> sumMap = {{0,1}};
      int sum = 0;
      int result = 0;
      for (size_t i = 0; i < nums.size(); ++i) {
        sum += nums[i];
        // attention : find sum - k not k - sum
        auto find = sumMap.find(sum - k);
        if (find != sumMap.end()) {
          result += find->second;
        }
        sumMap[sum] = sumMap[sum] + 1;
      }
      return result;

    }
};
// @lc code=end

