#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
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
public:
  int sumNumbers(TreeNode *root) {
    if (root == NULL) {
      return 0;
    }
    int ret = 0;
    dfs(root, 0, &ret);
    return ret;
  }
  void dfs(TreeNode *root, int cur, int *ret) {
    cur = (cur * 10) + root->val;
    if (root->left == NULL && root->right == NULL) {
      *ret = (*ret) + cur;
      return;
    }
    if (root->left != NULL) {
      dfs(root->left, cur, ret);
    }
    if (root->right != NULL) {
      dfs(root->right, cur, ret);
    }
  }
};

int main() {
  Solution a;
  // int v = {};
  return 0;
}
