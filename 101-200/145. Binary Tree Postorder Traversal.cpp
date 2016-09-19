/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
  void dfs(TreeNode *cur, vector<int> &ret) {
    if (cur->left != NULL) {
      dfs(cur->left, ret);
    }
    if (cur->right != NULL) {
      dfs(cur->right, ret);
    }
    ret.push_back(cur->val);
  }
  vector<int> postorderTraversal(TreeNode *root) {
    vector<int> ret;
    if (root == NULL) {
      return ret;
    }
    dfs(root, ret);
    return ret;
  }
};
