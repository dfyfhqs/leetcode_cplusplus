/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 *
 * https://leetcode.cn/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (39.12%)
 * Likes:    9447
 * Dislikes: 0
 * Total Accepted:    2.4M
 * Total Submissions: 6.2M
 * Testcase Example:  '"abcabcbb"'
 *
 * 给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: s = "abcabcbb"
 * 输出: 3 
 * 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: s = "bbbbb"
 * 输出: 1
 * 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入: s = "pwwkew"
 * 输出: 3
 * 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
 * 请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= s.length <= 5 * 10^4
 * s 由英文字母、数字、符号和空格组成
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      // 滑动窗口
      int left = 0, right = 0;
      while (right < s.size()) {
        // 扩张滑动窗口
        if (curStr_.count(s[right]) == 0) {
          curStr_.insert(s[right]);
          right++;
        } else {
          // 缩小窗口`
          while (left <= right && curStr_.count(s[right]) == 0) {
            curStr_.erase(s[left]);
            left++;
          }
          curStr_.erase(s[left]);
          left++;
          result_ = max(result_, right - left + 1);
        }
      }
      result_ = max(result_, right - left);
      return result_;
    }
    unordered_set<char> curStr_;
    int result_ = 0;
};
// @lc code=end

