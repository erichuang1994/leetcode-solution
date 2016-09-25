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
  void dfs(TreeNode *cur, int &ret, int flag) {
    if (cur == NULL) {
      return;
    }
    if (cur->left == NULL && cur->right == NULL && flag) {
      ret += cur->val;
      return;
    }
    dfs(cur->left, ret, 1);
    dfs(cur->right, ret, 0);
  }
  int sumOfLeftLeaves(TreeNode *root) {
    int ret = 0;
    dfs(root, ret, 0);
    return ret;
  }
};
