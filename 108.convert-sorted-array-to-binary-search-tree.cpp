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
  TreeNode *sortedArrayToBST(vector<int> &nums) {
    auto *result = help(nums, 0, nums.size());
    return result;
  }

  TreeNode *help(vector<int> &nums, int start, int end) {
    if (start >= end) {
      return nullptr;
    }
    int mid = start + (end - start) / 2;
    auto *root = new TreeNode(nums[mid]);
    root->left = help(nums, start, mid);
    root->right = help(nums, mid + 1, end);
    return root;
  }
};
// @leet end
