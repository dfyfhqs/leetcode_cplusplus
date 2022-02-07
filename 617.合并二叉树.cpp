/*
 * @lc app=leetcode.cn id=617 lang=cpp
 *
 * [617] 合并二叉树
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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr) {
            return root2;
        } else if (root2 == nullptr) {
            return root1;
        }
        TreeNode tmpRoot;
        help(&(tmpRoot.left), root1, root2);
        return tmpRoot.left;
    }

    void help(TreeNode** root, TreeNode* left, TreeNode* right) {
        if (left == nullptr && right == nullptr) {
            return;
        }
        if (left == nullptr) {
            *root = right;
            return;
        } else {
            *root = left;
            if (right == nullptr) {
                return;
            } else {
                (*root)->val = left->val + right->val;
            }
        }
        help(&((*root)->left), left->left, right->left);
        help(&((*root)->right), left->right, right->right);
        return;
    }
};
// @lc code=end

