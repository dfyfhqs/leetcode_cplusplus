/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 *
 * https://leetcode-cn.com/problems/unique-binary-search-trees/description/
 *
 * algorithms
 * Medium (69.33%)
 * Likes:    1053
 * Dislikes: 0
 * Total Accepted:    109.8K
 * Total Submissions: 158.4K
 * Testcase Example:  '3'
 *
 * 给定一个整数 n，求以 1 ... n 为节点组成的二叉搜索树有多少种？
 * 
 * 示例:
 * 
 * 输入: 3
 * 输出: 5
 * 解释:
 * 给定 n = 3, 一共有 5 种不同结构的二叉搜索树:
 * 
 * ⁠  1         3     3      2      1
 * ⁠   \       /     /      / \      \
 * ⁠    3     2     1      1   3      2
 * ⁠   /     /       \                 \
 * ⁠  2     1         2                 3
 * 
 */

// @lc code=start
class Solution {
public:
    int numTrees(int n) {
        std::vector<int> result(n+1, 0);
        result[0] = result[1] = 1;
        if (n < 2) {
            return 1;
        }
        for (auto i = 2; i < n+1; ++i) {
            for (auto j = 0; j < i; ++j) {
                //std::cout << i << ": " << j << "," << i-1-j << std::endl;
                result[i] += result[j] * result[i-1-j];
            }
        }
        return result[n];
    }
};
// @lc code=end

