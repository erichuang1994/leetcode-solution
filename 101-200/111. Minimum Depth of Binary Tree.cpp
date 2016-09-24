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
  void dfs(TreeNode *cur, int depth, int &ret) {
    if (cur->left == NULL && cur->right == NULL) {
      ret = min(depth, ret);
      return;
    }
    if (cur->left) {
      dfs(cur->left, depth + 1, ret);
    }
    if (cur->right) {
      dfs(cur->right, depth + 1, ret);
    }
  }
  int minDepth(TreeNode *root) {
    int ret = 1e9;
    if (root == NULL) {
      return 0;
    }
    dfs(root, 1, ret);
    return ret;
  }
};
