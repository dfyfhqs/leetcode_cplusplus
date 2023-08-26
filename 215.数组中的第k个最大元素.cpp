/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 *
 * https://leetcode.cn/problems/kth-largest-element-in-an-array/description/
 *
 * algorithms
 * Medium (63.48%)
 * Likes:    2255
 * Dislikes: 0
 * Total Accepted:    910K
 * Total Submissions: 1.4M
 * Testcase Example:  '[3,2,1,5,6,4]\n2'
 *
 * 给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。
 * 
 * 请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
 * 
 * 你必须设计并实现时间复杂度为 O(n) 的算法解决此问题。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: [3,2,1,5,6,4], k = 2
 * 输出: 5
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: [3,2,3,1,2,4,5,5,6], k = 4
 * 输出: 4
 * 
 * 
 * 
 * 提示： 
 * 
 * 
 * 1 <= k <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
      // findKthLargest(nums, 0, nums.size() - 1, k);
      // return result_;
      return HeadSort(nums, k);
    }

    void findKthLargest(vector<int>& nums, int start, int end, int k) {
      if (start > end) return;
      if (start == k - 1 && end == k - 1) { result_ = nums[start]; return; }

      //cout << "start: " << start << " end: " << end << " k: " << k << endl;
      int idx = start + rand() % (end - start + 1);
      swap(nums[idx], nums[end]);
      int pivot = nums[end];
      int i = start, j = end;
      while (i < j) {
        while (i < j && nums[i] >= pivot) i++;
        while (i < j && nums[j] <= pivot) j--;
        swap(nums[i], nums[j]);
      }
      swap(nums[i], nums[end]);
      // cout << "i: " << i << " j: " << j << " idx: " << idx << " k: " << k << endl;
      // for (auto& val : nums) {
      //   cout << "after: " << val << endl;
      // }
      if (i == k - 1) {result_ = nums[i];return;}
      if (i > k - 1) {
        int j = i;
        while (j > 0 && j > k - 1 && (nums[j-1] == pivot)) --j;
        if (j == k - 1) {result_ = nums[j];return;}
        findKthLargest(nums, start, j, k);
      } else {
        int j = i;
        if (j < nums.size()-1 && j < k - 1 && nums[j+1] == pivot) ++j;
        if (j == k - 1) {result_ = nums[j];return;}
        findKthLargest(nums, j, end, k);
      }
    }

    int HeadSort(vector<int>& nums, int k) {
      priority_queue<int, vector<int>, greater<int>> que;
      for (auto& val : nums) {
        if (que.size() < k) {que.push(val); continue;}
        if (val > que.top()) {
          que.pop();
          que.push(val);
        }
      }
      return que.top();
    }

    int result_ = INT_MIN;
};
// @lc code=end

