/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 *
 * https://leetcode-cn.com/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (40.31%)
 * Likes:    4230
 * Dislikes: 0
 * Total Accepted:    442.2K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,3]\n[2]'
 *
 * 给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums1 = [1,3], nums2 = [2]
 * 输出：2.00000
 * 解释：合并数组 = [1,2,3] ，中位数 2
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums1 = [1,2], nums2 = [3,4]
 * 输出：2.50000
 * 解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums1 = [0,0], nums2 = [0,0]
 * 输出：0.00000
 * 
 * 
 * 示例 4：
 * 
 * 
 * 输入：nums1 = [], nums2 = [1]
 * 输出：1.00000
 * 
 * 
 * 示例 5：
 * 
 * 
 * 输入：nums1 = [2], nums2 = []
 * 输出：2.00000
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * nums1.length == m
 * nums2.length == n
 * 0 
 * 0 
 * 1 
 * -10^6 
 * 
 * 
 * 
 * 
 * 进阶：你能设计一个时间复杂度为 O(log (m+n)) 的算法解决此问题吗？
 * 
 */

// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        auto m = nums1.size();
        auto n = nums2.size();

        if ((m + n) % 2) {
            auto find = (m+n)/2;
            return findKth(nums1,0, nums2,0, find);
        } else {
            auto find1 = (m+n)/2;
            auto find2 = find1 - 1;
            return (findKth(nums1,0, nums2,0, find1) + 
                    findKth(nums1,0, nums2,0, find2)) / 2.0;
        }
    }

    int findKth(const vector<int>& nums1, int start1, const vector<int>& nums2, int start2, int k) {
        if (start1 == nums1.size()-1) {
            return nums2[start2 + k - 1];
        } else if (start2 == nums2.size()-1) {
            return nums2[start1 + k - 1];
        }
        int index1 = start1 + min(k/2-1, nums1.size()-start1-1);
        int index2 = start2 + min(nums2.size()-start2-1, k-index1-start1);
        if (nums1[index1] < nums2[index2]) {
            return findKth(nums1, index1, nums2, start2, k-index1-start1+1);
        } else if (nums1[index1] == nums2[index2]) {
            return nums1[index1];
        }
        return findKth(nums1, start1, nums2, index2, k-index2-start2+1);

    }
};
// @lc code=end

