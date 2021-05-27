/*
 * @lc app=leetcode.cn id=172 lang=cpp
 *
 * [172] 阶乘后的零
 */

// @lc code=start
class Solution {
public:
    int trailingZeroes(int n) {
        int divid = 5;
        int result = 0;
        while (n >= divid) {
            result += n/divid;
            divid *= 5;
        }
        return result;
    }
};
// @lc code=end

