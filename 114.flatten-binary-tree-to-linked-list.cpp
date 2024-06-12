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

#include <list>
class Solution {
public:
  void flatten(TreeNode *root) {
    if (root == nullptr)
      return;
    std::list<TreeNode *> label;
    label.push_back(root);
    help(label);
  }

  void help(list<TreeNode *> &label) {
    if (label.empty()) {
      return;
    }
    int size = label.size();
    for (auto i = 0; i < size; ++i) {
      auto *cur = label.front();
      label.pop_front();
      if (pre_ != nullptr) {
        pre_->left = nullptr;
        pre_->right = cur;
      }
      pre_ = cur;
      if (cur->right) {
        label.push_front(cur->right);
      }
      if (cur->left) {
        label.push_front(cur->left);
      }
    }
    help(label);
  }

  TreeNode *pre_ = nullptr;
};
// @leet end
