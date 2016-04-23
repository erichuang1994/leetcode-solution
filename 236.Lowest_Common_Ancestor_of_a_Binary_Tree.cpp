#include <iostream>
#include <set>
#include <algorithm>
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
struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x),left(NULL), right(NULL){}
};
TreeNode *ans;
set<TreeNode*> flag;
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        flag.clear();
        dfs(root,p);
        for (set<TreeNode*>::iterator it=flag.begin(); it!=flag.end(); ++it)
            cout<<(*it)->val<<" ";
        cout<<endl;
        ans = NULL;
        dfs2(root,q);
        return ans;
    }
    bool dfs(TreeNode *root , TreeNode* target){
        if(root == target){
            flag.insert(root);
            return true;
        }
        if(root->left!=NULL){
            if(dfs(root->left,target)==true){
                flag.insert(root);
                return true;
            }
        }
        if(root->right!=NULL){
            if(dfs(root->right,target)==true){
                flag.insert(root);
                return true;
            }
        }
        return false;
    }
    bool dfs2(TreeNode *root,TreeNode* target){
        if(root == target){
            if(flag.find(root)!=flag.end()){
                ans = root;
            }
            return true;
        }
        if(root->left!=NULL){
            bool temp = dfs2(root->left,target);
            if(temp==true){
                if(ans==NULL and flag.find(root)!=flag.end()){
                    ans = root;
                } 
                return true;
            }
        }
        if(root->right!=NULL){
            bool temp = dfs2(root->right,target);
            if(temp==true){
                if(ans==NULL and flag.find(root)!=flag.end()){
                    ans=root;
                } 
                return true;
            }
        }
        return false;
    }
};
int main(){
	TreeNode root(0);
	TreeNode left(10);
	TreeNode right(80);
	root.left = &left;
	root.right = &right;
	TreeNode* ans = Solution().lowestCommonAncestor(&root,&left,&right);
	cout<<ans->val<<endl;

	return 0;
}