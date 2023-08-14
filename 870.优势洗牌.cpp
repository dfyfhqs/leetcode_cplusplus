/*
 * @lc app=leetcode.cn id=870 lang=cpp
 *
 * [870] 优势洗牌
 *
 * https://leetcode.cn/problems/advantage-shuffle/description/
 *
 * algorithms
 * Medium (50.45%)
 * Likes:    391
 * Dislikes: 0
 * Total Accepted:    66.6K
 * Total Submissions: 131.8K
 * Testcase Example:  '[2,7,11,15]\n[1,10,4,11]'
 *
 * 给定两个长度相等的数组 nums1 和 nums2，nums1 相对于 nums2 的优势可以用满足 nums1[i] > nums2[i] 的索引 i
 * 的数目来描述。
 * 
 * 返回 nums1 的任意排列，使其相对于 nums2 的优势最大化。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums1 = [2,7,11,15], nums2 = [1,10,4,11]
 * 输出：[2,11,7,15]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums1 = [12,24,8,32], nums2 = [13,25,32,11]
 * 输出：[24,32,8,12]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums1.length <= 10^5
 * nums2.length == nums1.length
 * 0 <= nums1[i], nums2[i] <= 10^9
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
      std::multimap<int, int, std::greater<int>> nums2Map;
      for (int i = 0; i < nums2.size(); i++) {
        nums2Map.insert(std::pair<int, int>(nums2[i], i)); 
      }

      std::sort(nums1.begin(), nums1.end(), std::less<int>());

      vector<int> result(nums1.size(), 0);
      int left = 0, right = nums1.size() - 1;
      for (auto& value : nums2Map) {
        // auto idx = value.second;
        // auto val = value.first;
        // std::cout << idx << ", " << val << std::endl;
        if (value.first >= nums1[right]) {
          result[value.second] = nums1[left++];
        } else {
          result[value.second] = nums1[right--];
        }
      }
      return result;
    }
};
// @lc code=end

