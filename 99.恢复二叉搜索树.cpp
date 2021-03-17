/*
 * @lc app=leetcode.cn id=99 lang=cpp
 *
 * [99] 恢复二叉搜索树
 *
 * https://leetcode-cn.com/problems/recover-binary-search-tree/description/
 *
 * algorithms
 * Hard (62.01%)
 * Likes:    430
 * Dislikes: 0
 * Total Accepted:    50.2K
 * Total Submissions: 81K
 * Testcase Example:  '[1,3,null,null,2]'
 *
 * 给你二叉搜索树的根节点 root ，该树中的两个节点被错误地交换。请在不改变其结构的情况下，恢复这棵树。
 * 
 * 进阶：使用 O(n) 空间复杂度的解法很容易实现。你能想出一个只使用常数空间的解决方案吗？
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：root = [1,3,null,null,2]
 * 输出：[3,1,null,null,2]
 * 解释：3 不能是 1 左孩子，因为 3 > 1 。交换 1 和 3 使二叉搜索树有效。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：root = [3,1,4,null,null,2]
 * 输出：[2,1,4,null,null,3]
 * 解释：2 不能在 3 的右子树中，因为 2 < 3 。交换 2 和 3 使二叉搜索树有效。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树上节点的数目在范围 [2, 1000] 内
 * -2^31 
 * 
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* pre_;  // 前驱节点
    TreeNode* node1_; // 第一个节点
    TreeNode* node2_; // 第二个节点

    void recoverTree(TreeNode* root) {
        helper(root);
        auto tmp = node1_->val;
        node1_->val = node2_->val;
        node2_->val = tmp;
    }

    // 中序遍历二叉搜索树应该是递增的，因此找到逆序的第一个数和最后一个数交换即可
    void helper(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        helper(root->left);
        if ((pre_ != nullptr) && pre_->val >= root->val) {
            if (node1_ == nullptr) {
                node1_ = pre_;
            }
            node2_ = root;
        }
        pre_ = root;
        helper(root->right);
    }
};
// @lc code=end

