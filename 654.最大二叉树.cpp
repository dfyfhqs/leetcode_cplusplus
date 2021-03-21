/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return constructMaximumBinaryTree(nums, 0, nums.size());
    }

    int findMaxIndex(const vector<int>& nums, int left, int right) {
        int index = 0;
        int maxNum = INT_MIN;
        for(size_t i = left; i < right; ++i) {
            if (maxNum < nums[i]) {
                index = i;
                maxNum = nums[i];
            }
        }
        return index;
    }

    TreeNode* constructMaximumBinaryTree(const vector<int>& nums, int left, int right) {
        if (left >= right) {
            return nullptr;
        }
        int maxIndex = findMaxIndex(nums, left, right);
        auto root = new TreeNode(nums[maxIndex]);
        root->left = constructMaximumBinaryTree(nums, left, maxIndex);
        root->right = constructMaximumBinaryTree(nums, maxIndex+1, right);
        return root;
    }
};
// @lc code=end

