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
    return dfs(root, p, q);
  }

  TreeNode* dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == nullptr || root == p || root == q) {
      return root;
    }
    auto* left = dfs(root->left, p, q);
    auto* right = dfs(root->right, p, q);
    if (left && right) {
      return root;
    }
    return left == nullptr ? right : left;
  }
};
// @leet end
