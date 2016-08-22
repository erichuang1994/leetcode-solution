/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// #TODO use binary search complexity is O(log(n)^2)
class Solution {
public:
  int countNodes(TreeNode *root) {
    if (root == NULL)
      return 0;
    pair<int, int> ret;
    dfs(root, make_pair(0, 0), ret);
    return pow(2, ret.first) + ret.second;
  }
  bool dfs(TreeNode *tmp, pair<int, int> cur, pair<int, int> &ret) {
    if (tmp->right != NULL) {
      if (dfs(tmp->right, make_pair(cur.first + 1, cur.second * 2 + 1), ret)) {
        return true;
      }
    }
    if (tmp->left != NULL) {
      if (dfs(tmp->left, make_pair(cur.first + 1, cur.second * 2), ret)) {
        return true;
      }
    }
    if (tmp->left == NULL && tmp->right == NULL) {
      if (ret.first == -1) {
        ret.first = cur.first;
        ret.second = cur.second;
      } else if (cur.first > ret.first) {
        ret.first = cur.first;
        ret.second = cur.second;
        return true;
      }
    }
    return false;
  }
};
