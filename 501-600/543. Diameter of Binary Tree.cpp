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
    int best;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        this->best = 0;
        dfs(root);
        return best;
    }
    int dfs(TreeNode *root){
        if(root == NULL)return 0;
        int lmax, rmax;
        lmax = dfs(root->left);
        rmax = dfs(root->right);
        best = max(best, lmax+rmax);
        return max(lmax, rmax) + 1;
    }
};