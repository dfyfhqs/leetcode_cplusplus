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
  bool isValidBST(TreeNode *root) { return help(root); }

  bool help(TreeNode *root) {
    if (root == nullptr) {
      return true;
    }
    if (!help(root->left)) {
      return false;
    }

    // cout << "node: " << root->val << " pre: " << pre_ << endl;
    if (pre_ >= root->val) {
      return false;
    }
    pre_ = root->val;
    return help(root->right);
  }

  int64_t pre_ = INT64_MIN;
};
// @leet end
