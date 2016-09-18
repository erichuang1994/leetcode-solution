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
  int sum;

public:
  void dfs(TreeNode *cur, int sum, vector<int> &path,
           vector<vector<int>> &ret) {
    sum += cur->val;
    path.push_back(cur->val);
    if (cur->left == NULL && cur->right == NULL && sum == this->sum) {
      ret.push_back(vector<int>(path));
    }
    if (cur->left != NULL)
      dfs(cur->left, sum, path, ret);
    if (cur->right != NULL) {
      dfs(cur->right, sum, path, ret);
    }
    path.pop_back();
  }
  vector<vector<int>> pathSum(TreeNode *root, int sum) {
    this->sum = sum;
    vector<int> path;
    vector<vector<int>> ret;
    if (root == NULL)
      return ret;
    dfs(root, 0, path, ret);
    return ret;
  }
};
