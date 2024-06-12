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
  vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> result;
    list<TreeNode *> label;
    if (root == nullptr)
      return result;
    label.push_back(root);
    while (!label.empty()) {
      int size = label.size();
      vector<int> tmp;
      for (int i = 0; i < size; ++i) {
        auto *cur_node = label.front();
        label.pop_front();
        if (cur_node == nullptr)
          continue;
        tmp.emplace_back(cur_node->val);
        if (!cur_node->left && !cur_node->right) {
          continue;
        }
        // if (!cur_node->left) {
        label.emplace_back(cur_node->left);
        //}
        // if (!cur_node->right) {
        label.emplace_back(cur_node->right);
        //}
      }
      result.emplace_back(std::move(tmp));
    }
    return result;
  }
};

// @leet end
