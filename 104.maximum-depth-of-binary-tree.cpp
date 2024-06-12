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
  int maxDepth(TreeNode *root) {
    int result = dp(root);
    return result;
  }

  int dp(TreeNode *root) {
    if (root == nullptr)
      return 0;
    int left = dp(root->left);
    int right = dp(root->right);
    return max(left, right) + 1;
  }
};
// @leet end
