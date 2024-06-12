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
  bool isSymmetric(TreeNode *root) {
    if (root == nullptr)
      return true;
    return help(root->left, root->right);
  }

  bool help(TreeNode *left, TreeNode *right) {
    if (left == nullptr && right == nullptr) {
      return true;
    }
    if (!(left && right)) {
      return false;
    }
    cout << "test ok " << endl;
    if (left->val != right->val)
      return false;
    return help(left->left, right->right) && help(left->right, right->left);
  }
};
// @leet end
