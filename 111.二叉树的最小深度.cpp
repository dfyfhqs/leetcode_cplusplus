/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
    int minDepth(TreeNode* root) {
        //return DFS(root);
        return BFS(root);
    }

    int BFS(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        queue<TreeNode*> q;
        q.push(root);
        int depth = 0;
        while(!q.empty()) {
            auto width = q.size();
            depth += 1;
            for (auto i = 0; i < width; ++i) {
                if ((q.front()->left == nullptr) && (q.front()->right == nullptr)) {
                    return depth;
                }
                if (q.front()->left) {
                    q.push(q.front()->left);
                }
                if (q.front()->right) {
                    q.push(q.front()->right);
                }
                q.pop();
            }
        }
        return depth;
    }

    int DFS(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        auto leftDepth = DFS(root->left);
        auto rightDepth = DFS(root->right);
        if (leftDepth == 0) {
            return 1 + rightDepth;
        }
        if (rightDepth == 0) {
            return 1 + leftDepth;
        }
        return 1 + min(leftDepth, rightDepth);
    }
};
// @lc code=end

