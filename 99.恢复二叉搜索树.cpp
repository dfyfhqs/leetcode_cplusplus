/*
 * @lc app=leetcode.cn id=99 lang=cpp
 *
 * [99] 恢复二叉搜索树
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
    void recoverTree(TreeNode* root) {
      TranverseTree(root);
      if (first_ && second_) {
        std::swap(first_->val, second_->val);
      }
    }

    void TranverseTree(TreeNode* root) {
      if (root == nullptr) {
        return;
      }
      TranverseTree(root->left);
      if (pre_ == nullptr) {
        pre_ = root;
      }
      if (root->val < pre_->val) {
        if (first_ == nullptr) {
          first_ = pre_;
        }
        second_ = root;
      }
      pre_ = root;
      TranverseTree(root->right);
    }

private:
    TreeNode* first_ = nullptr;
    TreeNode* second_ = nullptr;
    TreeNode* pre_ = nullptr;
};
// @lc code=end

