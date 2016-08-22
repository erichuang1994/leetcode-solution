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
  bool get(TreeNode *root, int target, int l, int r) {
    TreeNode *tmp = root;
    int lo = l;
    int hi = r;
    while (tmp != NULL) {
      if (lo == hi && lo == target) {
        return true;
      }
      int mid = (lo + hi) / 2;
      if (target <= mid) {
        tmp = tmp->left;
        hi = mid;
      } else {
        tmp = tmp->right;
        lo = mid + 1;
      }
    }
    return false;
  }
  int countNodes(TreeNode *root) {
    // binary search
    if (root == NULL)
      return 0;
    TreeNode *tmp;
    tmp = root;
    int max_level = 0;
    while (tmp->left != NULL) {
      tmp = tmp->left;
      max_level++;
    }
    int l = pow(2, max_level);
    int r = (2 * l - 1);
    int lo = pow(2, max_level);
    int hi = (2 * lo - 1) + 1;
    while (lo + 1 < hi) {
      int mid = (lo + hi) / 2;
      if (get(root, mid, l, r)) {
        lo = mid;
      } else {
        hi = mid;
      }
    }
    return lo;
  }
};
