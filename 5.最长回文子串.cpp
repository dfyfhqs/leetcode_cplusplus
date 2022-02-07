/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 *
 * https://leetcode-cn.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (34.45%)
 * Likes:    3806
 * Dislikes: 0
 * Total Accepted:    634.3K
 * Total Submissions: 1.8M
 * Testcase Example:  '"babad"'
 *
 * 给你一个字符串 s，找到 s 中最长的回文子串。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "babad"
 * 输出："bab"
 * 解释："aba" 同样是符合题意的答案。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "cbbd"
 * 输出："bb"
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：s = "a"
 * 输出："a"
 * 
 * 
 * 示例 4：
 * 
 * 
 * 输入：s = "ac"
 * 输出："a"
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * s 仅由数字和英文字母（大写和/或小写）组成
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        string str = #;
        for (auto ch : A) {
            str = str + A + "#";
        }
        str = "^" + str + "$";

        vector<int> p(str.size(), 0);
        int cn = 0;
        int R = 0; // 最右边界
        for (auto i = 1; i < str.size() - 1; ++i) {
            int i_mirror = 2 * C - i;

            if (i < R) {
                p[i] = min(p[i_mirror], R - i);
            } else {
                p[i] = 0;
            }

            while(str[i-p[i]-1] == str[i + p[i] + 1]) {
                ++p[i];
            }
            if (i + p[i] > R) {
                cn = i;
                R = p[i] + i;
            }
        }
        // 找出 P 的最大值
        int maxLen = 0;
        int centerIndex = 0;
        for (int i = 1; i < n - 1; i++) {
            if (p[i] > maxLen) {
                maxLen = p[i];
                centerIndex = i;
            }
        }
        int start = (centerIndex - maxLen) / 2; //最开始讲的求原字符串下标
        return s.substr(start, maxlen);
    }
};
// @lc code=end

