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
  int pathSum(TreeNode* root, int targetSum) {
    // return help(root, targetSum);
    prefixSum[0] = 1;
    return preSum(root, 0, targetSum);
  }

  int preSum(TreeNode* root, long long cur, int targetSum) {
    if (root == nullptr) {
      return 0;
    }
    int ret = 0;
    cur += root->val;
    if (prefixSum.count(cur - targetSum)) {
      ret = prefixSum[cur - targetSum];
    }

    prefixSum[cur]++;
    ret += preSum(root->left, cur, targetSum);
    ret += preSum(root->right, cur, targetSum);
    prefixSum[cur]--;
    return ret;
  }
  std::unordered_map<long long, int> prefixSum;

  int help2(TreeNode* root, int64_t targetSum) {
    if (root == nullptr) return 0;
    int ret = 0;
    if (root->val == targetSum) {
      ret += 1;
    }
    ret += help2(root->left, targetSum - root->val);
    ret += help2(root->right, targetSum - root->val);
    return ret;
  }

  int help(TreeNode* root, int64_t targetSum) {
    if (root == nullptr) return 0;
    int ret = help2(root, targetSum);
    ret += help(root->left, targetSum);
    ret += help(root->right, targetSum);
    return ret;
  }
};

// @leet end
