/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
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
    int maxPathSum(TreeNode* root) {
      SideMaxPath(root);
      return max_depth_;
    }

    int SideMaxPath(TreeNode* root) {
      if (root == nullptr) {
        return 0;
      }
      int leftpath = max(0, SideMaxPath(root->left));
      int rightpath = max(0, SideMaxPath(root->right));
      max_depth_ = max(max_depth_, root->val + leftpath + rightpath);
      return max(leftpath + root->val, rightpath + root->val);
    }
public: 
    int max_depth_ = INT_MIN;
};
// @lc code=end

