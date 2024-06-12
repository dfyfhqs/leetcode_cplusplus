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
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    return help(preorder.begin(), preorder.end(), inorder.begin(),
                inorder.end());
  }

  TreeNode* help(vector<int>::iterator prebegin, vector<int>::iterator preend,
                 vector<int>::iterator inbegin, vector<int>::iterator inend) {
    if (prebegin == preend || inbegin == inend) {
      return nullptr;
    }
    vector<int>::iterator finditer = std::find(inbegin, inend, *prebegin);
    if (finditer == inend) {
      return nullptr;
    }
    int dist = finditer - inbegin;
    // cout << "dist: " << dist << endl;
    TreeNode* cur = new TreeNode(*prebegin);
    cur->left = help(prebegin + 1, prebegin + 1 + dist, inbegin, finditer);
    cur->right = help(prebegin + 1 + dist, preend, finditer + 1, inend);
    return cur;
  }
};
// @leet end
