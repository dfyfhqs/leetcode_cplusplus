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
  int kthSmallest(TreeNode *root, int k) {
    help(root, k);
    return result_;
  }

  int help(TreeNode *root, int k) {
    if (root == nullptr) {
      return 0;
    }
    int left = (root->left == nullptr) ? 0 : help(root->left, k);
    if (left > k) {
      return left;
    }
    cout << "root: " << root->val << " k: " << k << " left: " << left << endl;
    if (k == left + 1) {
      result_ = root->val;
      return k;
    }
    int right = help(root->right, k - left - 1);
    return left + 1 + right;
  }
  int result_ = INT_MIN;
};
// @leet end
