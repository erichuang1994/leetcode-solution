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
  vector<int> preorderTraversal(TreeNode *root) {
    stack<TreeNode *> s;
    vector<int> ret;
    if (root == NULL) {
      return ret;
    }
    s.push(root);
    while (!s.empty()) {
      TreeNode *temp = s.top();
      s.pop();
      ret.push_back(temp->val);
      if (temp->right) {
        s.push(temp->right);
      }
      if (temp->left) {
        s.push(temp->left);
      }
    }
    return ret;
  }
};
int main() {
  Solution a;
  int v = {};
  return 0;
}
