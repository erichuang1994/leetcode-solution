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
  vector<vector<int>> levelOrderBottom(TreeNode *root) {
    queue<TreeNode *> q;
    vector<vector<int>> vec;
    if (root == NULL) {
      return vec;
    }
    q.push(NULL);
    q.push(root);
    TreeNode *tmp;
    while (!q.empty()) {
      tmp = q.front();
      q.pop();
      if (q.empty()) {
        break;
      }
      if (tmp == NULL) {
        vec.push_back(vector<int>());
        q.push(NULL);
      } else {
        vec.rbegin()->push_back(tmp->val);
        if (tmp->left != NULL) {
          q.push(tmp->left);
        }
        if (tmp->right != NULL) {
          q.push(tmp->right);
        }
      }
    }
    reverse(vec.begin(), vec.end());
    return vec;
  }
};
