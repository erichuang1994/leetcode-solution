/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <iostream>
#include <stack>
using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class BSTIterator {
public:
  BSTIterator(TreeNode *root) {
    if (root) {
      TreeNode *cur = root;
      while (cur) {
        s.push(cur);
        cur = cur->left;
      }
    }
  }

  /** @return whether we have a next smallest number */
  bool hasNext() { return !s.empty(); }

  /** @return the next smallest number */
  int next() {
    TreeNode *cur, *ret;
    ret = s.top();
    cur = ret;
    s.pop();
    // cout << "???" << endl;
    if (cur->right != NULL) {
      cur = cur->right;
      while (cur != NULL) {
        s.push(cur);
        cur = cur->left;
      }
    }
    return ret->val;
  }

private:
  stack<TreeNode *> s;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
int main() {
  TreeNode a(1);
  TreeNode b(2);
  a.right = &b;
  BSTIterator it(&a);
  while (it.hasNext())
    cout << it.next();
}
