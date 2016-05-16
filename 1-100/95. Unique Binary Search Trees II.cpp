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
// struct TreeNode {
//   int val;
//   TreeNode *left;
//   TreeNode *right;
//   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };
class Solution {
public:
  vector<TreeNode *> generateTrees(int n) {
    vector<vector<vector<TreeNode *>>> dp(
        n + 2, vector<vector<TreeNode *>>(n + 2, vector<TreeNode *>()));
    // vectr<TreeNode*> a[n+1][n+1];
    for (int i = 1; i < n + 1; i++) {
      // TreeNode *temp = new TreeNode(i);
      dp[i][i].push_back(new TreeNode(i));
    }
    // 先用不同BST的数量写出递推式，找出所有BST也是类似的
    // C[l,r] = sum(c[l,r-1]*c[r+1,r]) for r from l to r
    // 即遍历所有点为根节点的数的可能性 然后求和
    // 代码则自底下向上令step=l-r,从step为0开始以此递增求解
    for (int step = 1; step < n; step++) {
      for (int i = 1; i <= n - step; i++) {
        int r = i + step;
        int l = i;
        // l=i r=i+step
        // 先特殊处理没有左子树和没有右子树的情况
        for (auto &node : dp[l + 1][r]) {
          TreeNode *temp = new TreeNode(l);
          temp->right = node;
          dp[i][r].push_back(temp);
        }
        // 没有右子树
        for (auto &node : dp[l][r - 1]) {
          TreeNode *temp = new TreeNode(r);
          temp->left = node;
          dp[l][r].push_back(temp);
        }
        // 其他情况
        for (int root = l + 1; root < r; root++) {
          for (auto &lchild : dp[l][root - 1]) {
            for (auto &rchild : dp[root + 1][r]) {
              TreeNode *temp = new TreeNode(root);
              temp->left = lchild;
              temp->right = rchild;
              dp[l][r].push_back(temp);
            }
          }
        }
      }
    }
    return dp[1][n];
  }
};

int main() {
  Solution a;
  a.generateTrees(0);
  return 0;
}
