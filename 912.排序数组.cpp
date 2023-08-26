/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 *
 * https://leetcode.cn/problems/sort-an-array/description/
 *
 * algorithms
 * Medium (51.08%)
 * Likes:    894
 * Dislikes: 0
 * Total Accepted:    564.4K
 * Total Submissions: 1.1M
 * Testcase Example:  '[5,2,3,1]'
 *
 * 给你一个整数数组 nums，请你将该数组升序排列。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [5,2,3,1]
 * 输出：[1,2,3,5]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [5,1,1,2,0,0]
 * 输出：[0,0,1,1,2,5]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 5 * 10^4
 * -5 * 10^4 <= nums[i] <= 5 * 10^4
 * 
 * 
 */

// 注意优化： 1.随机Pivot 2. 重复元素的处理
// Author: Huahua, 60 ms
class Solution {
public:
  vector<int> sortArray(vector<int>& nums) {
    //QuickSort1(nums, 0, nums.size() - 1);
    // QuickSort2(nums, 0, nums.size()-1);
    QuickSort3(nums, 0, nums.size()-1);
    return nums;
  }

  void QuickSort1(vector<int>& nums, int l, int r) {
    if (l >= r) return;      
    int i = l;
    int j = r;
    int p = nums[l + rand() % (r - l + 1)];
    while (i <= j) {
      while (nums[i] < p) ++i;
      while (nums[j] > p) --j;
      if (i <= j)
        swap(nums[i++], nums[j--]);
    }
    QuickSort1(nums, l, j);
    QuickSort1(nums, i, r);
  };

  void QuickSort2(vector<int>& nums, int l, int r) {
    if (l >= r) return;
    int idx = l + rand() % (r - l + 1);
    //std::cout << "idx: " << idx << " l: " << l << " r: " << r << std::endl;
    swap(nums[idx], nums[l]);
    int label = nums[l];
    int i = l, j = r;
    while (i < j) {
      while (i < j && nums[j] >= label) --j;
      while (i < j && nums[i] <= label) ++i;
      swap(nums[i], nums[j]);
    }
    swap(nums[i], nums[l]);
    j = i;
    while (j > 0 && nums[j] == label) --j;
    QuickSort2(nums, l, j);
    j = i;
    while (j < r && nums[j] == label) ++j;
    QuickSort2(nums, j, r);
  }

  // 闭区间
  void QuickSort3(vector<int>& nums, int l, int r) {
    if (l >= r) return;
    int idx = l + rand() % (r - l + 1);
    swap(nums[idx], nums[r]);
    int label = nums[r];
    int i = l, j = r;
    while (i < j) {
      while (i < j && nums[i] <= label) ++i;
      while (i < j && nums[j] >= label) --j;
      swap(nums[i], nums[j]);
    }
    swap(nums[i], nums[r]);
    j = i;
    while (j > 0 && nums[j] == label) --j;
    QuickSort2(nums, l, j);
    j = i;
    while (j < r && nums[j] == label) ++j;
    QuickSort2(nums, j, r);
  }
};
// @lc code=end

