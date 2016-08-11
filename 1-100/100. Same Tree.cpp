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
  bool isSameTree(TreeNode *p, TreeNode *q) {
    if ((p == NULL && q != NULL) || (p != NULL && q == NULL)) {
      return false;
    }
    if (p == NULL && q == NULL) {
      return true;
    }
    if (p->val == q->val) {
      if (isSameTree(p->left, q->left) == false) {
        return false;
      }
      if (isSameTree(p->right, q->right) == false) {
        return false;
      }
      return true;
    } else {
      return false;
    }
  }
};
