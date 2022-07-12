/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
 */

// @lc code=start
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
#include <unordered_map>
class Solution {
 public:
  using VecInt = std::vector<int>;

  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    if (preorder.empty()) {
      return nullptr;
    }
    return buildTree(preorder, 0, preorder.size(), inorder, 0,
                     inorder.size());  // 22
  }

  TreeNode* buildTree(VecInt& preorder, int preStart, int preEnd,
                      VecInt& inorder, int inStart, int inEnd) {
    std::cout << preStart << "," << preEnd << " , " << inStart << "," << inEnd
              << std::endl;
    if (preStart >= preEnd || inStart >= inEnd) {
      return nullptr;
    }
    int idx = inStart;

    for (; idx < inEnd; ++idx) {
      if (inorder[idx] == preorder[preStart]) {
        break;
      }
    }
    if (idx >= inEnd) {
      return nullptr;
    }
    int leftNum = idx - inStart;

    TreeNode* result = new TreeNode(preorder[preStart]);
    result->left = buildTree(preorder, preStart + 1, preStart + 1 + leftNum,
                             inorder, inStart, idx);
    result->right = buildTree(preorder, preStart + 1 + leftNum, preEnd, inorder,
                              idx + 1, inEnd);
    return result;
  }
};
// @lc code=end
