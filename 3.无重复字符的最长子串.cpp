/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 *
 * https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (37.31%)
 * Likes:    6273
 * Dislikes: 0
 * Total Accepted:    1.3M
 * Total Submissions: 3.3M
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
 * 示例 4:
 * 
 * 
 * 输入: s = ""
 * 输出: 0
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 
 * s 由英文字母、数字、符号和空格组成
 * 
 * 
 */

// @lc code=start
#include <string>
using namespace std;
class Solution {
public:
    // 子串是连续的，子序列可以是非连续的
    int lengthOfLongestSubstring(string s) {
        int maxLength = 0;
        string subStr = "";
        for (auto i = 0; i < s.size(); ++i) {
            auto pos = subStr.find(s[i]);
            if (pos != string::npos) {
                if (maxLength < subStr.size()) {
                    maxLength = subStr.size();
                }
                subStr = subStr.substr(pos+1);
            }
            subStr += s[i];
        }
        return max(maxLength, (int)subStr.size());
    }
};

//int main() {
//    Solution so;
//    so.lengthOfLongestSubstring("abcabcbb");
//}
// @lc code=end

