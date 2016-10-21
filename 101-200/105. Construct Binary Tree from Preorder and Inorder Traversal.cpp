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
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    for (int i = 0; i < inorder.size(); ++i) {
      m[inorder[i]] = i;
    }
    return _buildTree(preorder, 0, preorder.size() - 1, inorder, 0,
                      inorder.size() - 1);
  }
  TreeNode *_buildTree(vector<int> &preorder, int id1, int id2,
                       vector<int> &inorder, int id3, int id4) {
    if (id1 > id2) {
      return NULL;
    }
    TreeNode *root = new TreeNode(preorder[id1]);
    int i = m[preorder[id1]];

    root->left =
        _buildTree(preorder, id1 + 1, id1 + i - id3, inorder, id3, i - 1);
    root->right =
        _buildTree(preorder, id1 + i - id3 + 1, id2, inorder, i + 1, id4);
    return root;
  }

private:
  unordered_map<int, int> m;
};
