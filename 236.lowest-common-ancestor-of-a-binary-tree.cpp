// @leet start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    return help(root, p, q);
  }

  TreeNode* help(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == p || root == q || root == nullptr) {
      return root;
    }
    auto* left = help(root->left, p, q);
    auto* right = help(root->right, p, q);
    if (left && right) {
      return root;
    }
    return left != nullptr ? left : right;
  }
};
// @leet end
