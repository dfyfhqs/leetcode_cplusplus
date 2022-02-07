/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        int depth = GetDepth(root);
        return (depth >= 0);
    }

    int GetDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int depthLeft = GetDepth(root->left);
        int depthRight = GetDepth(root->right);
        if (depthLeft < 0 || depthRight < 0) {
            return -1;
        }
        
        if (abs(depthLeft - depthRight) > 1) {
            return -1;
        }
        return max(depthLeft, depthRight) + 1;
    }
};
// @lc code=end

