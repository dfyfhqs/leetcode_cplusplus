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
  int diameterOfBinaryTree(TreeNode *root) {
    return max(result_, help(root)) - 1;
  }

  int help(TreeNode *root) {
    if (root == nullptr)
      return 0;
    int left = help(root->left);
    int right = help(root->right);
    result_ = max(left + right + 1, result_);
    return max(left, right) + 1;
  }

  int result_ = 0;
};
// @leet end
