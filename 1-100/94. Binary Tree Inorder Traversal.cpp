/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// version 1 Generic version
class Solution {
public:
  vector<int> inorderTraversal(TreeNode *root) {
    stack<pair<TreeNode *, bool>> s;
    vector<int> ret;
    if (!root) {
      return ret;
    }
    s.emplace(root, false);
    while (!s.empty()) {
      auto cur = s.top();
      s.pop();
      if (cur.second) {
        ret.push_back(cur.first->val);
      } else {
        if (cur.first->right) {
          s.emplace(cur.first->right, false);
        }
        s.emplace(cur.first, true);
        if (cur.first->left) {
          s.emplace(cur.first->left, false);
        }
      }
    }
    return ret;
  }
};

// version 2
class Solution {
public:
  vector<int> inorderTraversal(TreeNode *root) {
    stack<TreeNode *> s;
    vector<int> ret;
    if (!root) {
      return ret;
    }
    auto cur = root;
    s.push(cur);
    while (cur->left) {
      s.push(cur->left);
      cur = cur->left;
    }
    while (!s.empty()) {
      auto cur = s.top();
      s.pop();
      ret.push_back(cur->val);
      if (cur->right) {
        s.push(cur->right);
        cur = s.top();
        while (cur->left) {
          s.push(cur->left);
          cur = cur->left;
        }
      }
    }
    return ret;
  }
};

// version 3
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
  vector<int> inorderTraversal(TreeNode *root) {
    stack<TreeNode *> s;
    vector<int> ret;
    if (!root)
      return ret;
    TreeNode *last = root;
    if (root->right)
      s.push(root->right);
    s.push(root);
    if (root->left)
      s.push(root->left);

    while (!s.empty()) {
      auto cur = s.top();
      s.pop();
      if (last->left == cur || last->right == cur) {
        if (cur->right)
          s.push(cur->right);
        s.push(cur);
        if (cur->left)
          s.push(cur->left);
      } else {
        ret.push_back(cur->val);
      }
      last = cur;
    }
    return ret;
  }
};
