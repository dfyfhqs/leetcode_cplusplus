// @leet start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
 public:
  int maxPathSum(TreeNode* root) {
    help(root);
    return result_;
  }

  int help(TreeNode* root) {
    if (root == nullptr) return 0;
    int left = max(help(root->left), 0);
    int right = max(help(root->right), 0);
    result_ = max(left + right + root->val, result_);
    return max(left, right) + root->val;
  }

  int result_ = INT_MIN;
};
// @leet end
