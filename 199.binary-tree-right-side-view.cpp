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
#include <vector>
class Solution {
public:
  vector<int> rightSideView(TreeNode *root) {
    vector<int> result;
    if (root == nullptr)
      return result;
    std::list<TreeNode *> label = {root};
    while (!label.empty()) {
      int size = label.size();
      auto *cur = label.front();
      result.push_back(cur->val);
      for (auto i = 0; i < size; ++i) {
        cur = label.front();
        if (cur->right) {
          label.push_back(cur->right);
        }
        if (cur->left) {
          label.push_back(cur->left);
        }
        label.pop_front();
      }
    }
    return result;
  }
};
// @leet end
