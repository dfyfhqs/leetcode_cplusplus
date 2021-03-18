/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
 *
 * https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (69.37%)
 * Likes:    938
 * Dislikes: 0
 * Total Accepted:    167K
 * Total Submissions: 240.7K
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * 根据一棵树的前序遍历与中序遍历构造二叉树。
 * 
 * 注意:
 * 你可以假设树中没有重复的元素。
 * 
 * 例如，给出
 * 
 * 前序遍历 preorder = [3,9,20,15,7]
 * 中序遍历 inorder = [9,3,15,20,7]
 * 
 * 返回如下的二叉树：
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
        //return nullptr;
    }

    TreeNode* buildTree(const vector<int>& preorder, const vector<int>& inorder, int ps, int pe, int is, int ie) {
        if (ps > pe) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[ps]);
        int pos = 0;
        for (auto i = is; i <= ie; ++i) {
            if (inorder[i] == preorder[ps]) {
                pos = i;
                break;
            }
        }
        root->left = buildTree(preorder, inorder, ps+1, ps+pos-is, is, pos-1);
        root->right = buildTree(preorder, inorder, ps+pos-is+1, pe, pos+1, ie);
        return root;
    }


};
// @lc code=end

