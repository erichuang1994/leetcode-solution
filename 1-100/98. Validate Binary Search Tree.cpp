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
  int last;
  bool f;

public:
  bool isValidBST(TreeNode *root) {
    f = false;
    return midorder(root);
  }
  bool midorder(TreeNode *root) {
    if (root == NULL) {
      return true;
    }
    if (midorder(root->left) == false) {
      return false;
    }
    if (f) {
      if (root->val <= last) {
        return false;
      }
    } else {
      f = true;
    }
    last = root->val;
    if (midorder(root->right) == false) {
      return false;
    }
    return true;
  }
};
