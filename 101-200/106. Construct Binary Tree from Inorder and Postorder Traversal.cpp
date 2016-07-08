#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
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
private:
  unordered_map<int, int> m;

public:
  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    int len = inorder.size();
    for (int i = 0; i < len; i++) {
      m[inorder[i]] = i;
    }
    if (len == 0)
      return NULL;
    return _buildTree(inorder, postorder, 0, inorder.size() - 1, 0,
                      postorder.size() - 1);
  }
  TreeNode *_buildTree(vector<int> &inorder, vector<int> &postorder, int x1,
                       int x2, int y1, int y2) {

    int i = m[postorder[y2]];
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

    return NULL;
  }
};
