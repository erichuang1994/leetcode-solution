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
  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    return _buildTree(inorder, postorder, 0, inorder.size() - 1, 0,
                      postorder.size() - 1);
  }
  TreeNode *_buildTree(vector<int> &inorder, vector<int> &postorder, int x1,
                       int x2, int y1, int y2) {
    for (int i = x1; i <= x2; i++) {
      if (inorder[i] == postorder[y2]) {
        TreeNode *temp = new TreeNode(inorder[i]);
        if (x1 <= i - 1) {
          temp->left =
              _buildTree(inorder, postorder, x1, i - 1, y1, y1 + (i - 1 - x1));
        }
        if (i + 1 <= x2) {
          temp->right =
              _buildTree(inorder, postorder, i + 1, x2, y1 + (i - x1), y2 - 1);
        }
        return temp;
      }
    }
    return NULL;
  }
};
