#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
// *
// struct TreeNode {
//       int val;
//       TreeNode *left;
//       TreeNode *right;
//       TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//  };
 //                 3
//                4      5
//               1 3 null 1
struct Node{
 	int y;
 	int n;
 	Node(int y,int n){
 		this->y = y;
 		this->n = n;
 	}
 };
class Solution {
public:
    int rob(TreeNode* root) {
    	Node ans = dfs(root);
    	return max(ans.y,ans.n);
    }
    Node dfs(TreeNode* root){
    	if(root == NULL){
    		return Node(0,0);
    	}
    	Node left = dfs(root->left);
    	Node right = dfs(root->right);
    	Node ret = Node(left.n+right.n+root->val,max(max(left.y,left.n),max(right.y,right.n)));
    	// printf("val = %d,y=%d,n=%d\n",root->val,ret.y,ret.n);
    	return Node(left.n+right.n+root->val,max(left.y,left.n)+max(right.y,right.n));
    }
};
int main(){
	return 0;
}