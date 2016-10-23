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
  void naivePathSum(TreeNode *cur, int sum, const int &target, int &num) {
    if (cur == NULL)
      return;
    sum += cur->val;
    if (sum == target) {
      num++;
    }
    naivePathSum(cur->left, sum, target, num);
    naivePathSum(cur->right, sum, target, num);
  }
  void dfs(TreeNode *root, int &ret, const int &target) {
    if (root == NULL)
      return;
    naivePathSum(root, 0, target, ret);
    dfs(root->left, ret, target);
    dfs(root->right, ret, target);
  }
  int pathSum(TreeNode *root, int sum) {
    int ret = 0;
    dfs(root, ret, sum);
    return ret;
  }
};
