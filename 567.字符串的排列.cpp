/*
 * @lc app=leetcode.cn id=567 lang=cpp
 *
 * [567] 字符串的排列
 *
 * https://leetcode.cn/problems/permutation-in-string/description/
 *
 * algorithms
 * Medium (44.49%)
 * Likes:    945
 * Dislikes: 0
 * Total Accepted:    268.3K
 * Total Submissions: 602.2K
 * Testcase Example:  '"ab"\n"eidbaooo"'
 *
 * 给你两个字符串 s1 和 s2 ，写一个函数来判断 s2 是否包含 s1 的排列。如果是，返回 true ；否则，返回 false 。
 * 
 * 换句话说，s1 的排列之一是 s2 的 子串 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s1 = "ab" s2 = "eidbaooo"
 * 输出：true
 * 解释：s2 包含 s1 的排列之一 ("ba").
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s1= "ab" s2 = "eidboaoo"
 * 输出：false
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s1.length, s2.length <= 10^4
 * s1 和 s2 仅包含小写字母
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
      std::unordered_map<char, int> label, cur;
      int validNum = 0;
      int left = 0, right = 0;
      for_each(s1.begin(), s1.end(), [&](char c) { label[c]++; });

      while (right < s2.size()) {
        char rc = s2[right];
        if (label.find(rc) == label.end()) {++right; continue;}
        if (++cur[rc] == label[rc]) {
          validNum++;
        }
        // std::cout << "left: " << left << " right: " << right << " validNum: " << validNum << std::endl;
        while (validNum == label.size()) {
          //std::cout << "left: " << left << " right: " << right << " validNum: " << validNum << std::endl;
          char lc = s2[left];
          if ((right - left + 1) == s1.size()) {
            return true;
          }
          if (label.find(lc) == label.end()) {++left; continue;}
          if (--cur[lc] < label[lc]) {
            --validNum;
          }
          ++left;
        }
        ++right;
      }
      return false;
    }
};
// @lc code=end

