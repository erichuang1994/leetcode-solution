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

//  耐腐的非递归
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// class Solution {
// public:
//   bool isValidBST(TreeNode *root) {
//     stack<pair<TreeNode *, bool>> s;
//     s.push(make_pair(root, false));
//     bool f;
//     int last;
//     f = false;
//     while (!s.empty()) {
//       auto t = s.top();
//       s.pop();
//       if (t.first == NULL) {
//         continue;
//       }
//       if (t.second == true) {
//         if (f) {
//           if (!(last < t.first->val)) {
//             return false;
//           }
//         } else {
//           f = true;
//         }
//         last = t.first->val;
//       } else {
//         s.push(make_pair(t.first->right, false));
//         s.push(make_pair(t.first, true));
//         s.push(make_pair(t.first->left, false));
//       }
//     }
//     return true;
//   }
// };
