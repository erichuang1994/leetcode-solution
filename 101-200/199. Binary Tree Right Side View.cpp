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
  vector<int> rightSideView(TreeNode *root) {
    queue<TreeNode *> q;
    vector<int> ret;
    if (root == NULL)
      return ret;
    q.push(NULL);
    q.push(root);
    bool f = false;
    TreeNode *tmp;
    while (!q.empty()) {
      tmp = q.front();
      q.pop();
      if (q.empty())
        break;
      if (f) {
        ret.push_back(tmp->val);
      }
      f = tmp == NULL ? true : false;
      if (tmp == NULL) {
        q.push(NULL);
        continue;
      }
      if (tmp->right != NULL) {
        q.push(tmp->right);
      }
      if (tmp->left != NULL) {
        q.push(tmp->left);
      }
    }
    return ret;
  }
};
