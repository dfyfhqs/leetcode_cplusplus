/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
 *
 * https://leetcode-cn.com/problems/validate-binary-search-tree/description/
 *
 * algorithms
 * Medium (33.79%)
 * Likes:    961
 * Dislikes: 0
 * Total Accepted:    236.2K
 * Total Submissions: 699K
 * Testcase Example:  '[2,1,3]'
 *
 * 给定一个二叉树，判断其是否是一个有效的二叉搜索树。
 * 
 * 假设一个二叉搜索树具有如下特征：
 * 
 * 
 * 节点的左子树只包含小于当前节点的数。
 * 节点的右子树只包含大于当前节点的数。
 * 所有左子树和右子树自身必须也是二叉搜索树。
 * 
 * 
 * 示例 1:
 * 
 * 输入:
 * ⁠   2
 * ⁠  / \
 * ⁠ 1   3
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入:
 * ⁠   5
 * ⁠  / \
 * ⁠ 1   4
 * / \
 * 3   6
 * 输出: false
 * 解释: 输入为: [5,1,4,null,null,3,6]。
 * 根节点的值为 5 ，但是其右子节点值为 4 。
 * 
 * 
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
    bool isValidBST(TreeNode* root) {
        return helper(root);
    }

    bool helper(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        if (root->left && (root->left->val >= root->val || !helper(root->left))) {
            cout << "left: " << root->left->val << "," << root->val;
            return false;
        }
        if (root->right && (root->right->val <= root->val || !helper(root->right))) {
            cout << "right: " << root->right->val << "," << root->val;
            return false;
        }
        // 找到左子树的最小值
        if (root->left) {
            auto curNode = root->left;
            while (curNode->right) {
                curNode = curNode->right;
            }
            if (curNode->val >= root->val) {
                return false;
            }
        }
        // 找到左节点的最小值
        if (root->right) {
            auto curNode = root->right;
            while (curNode->left) {
                curNode = curNode->left;
            }
            if (curNode->val <= root->val) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

