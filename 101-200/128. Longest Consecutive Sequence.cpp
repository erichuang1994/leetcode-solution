#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
// struct Node{
// 	struct Node *left,*right;
// 	int count;
// 	int key;
// 	Node(int cur,int key){
// 		left = this;
// 		right = this;
// 		count = cur;
// 		this->key = key;
// 		// cout<<this<<endl;
// 	};
// };
// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
//     	unordered_map<int,Node*> m;
// 		int l;
// 		int r;
// 		int cur;
// 		auto searchl = m.find(1);
// 		auto searchr = m.find(1);
// 		auto searchi = m.find(1);
// 		int max = 0;

//     	for(auto i : nums){
//     		// auto i = long(_i);
//     		if(m.find(i)!=m.end()){
//     			continue;
//     		}
//     		searchl = m.find(i-1);
//     		if(searchl!=m.end()){
//     			l = searchl->second->count;
//     			// cout<<searchl->second.left<<endl;
//     		}else{
//     			l = 0;
//     		}
//     		searchr = m.find(i+1);
//     		if(searchr!=m.end()){
//     			// cout<<"here"<<endl;
//     			r = searchr->second->count;
//     			// cout<<searchr->second.right<<endl;
//     		}else{
//     			r = 0;
//     		}
//     		cur = l + r + 1;
//     		// Node temp(cur,i);
//     		Node* temp = new Node(cur,i);
//     		searchi = m.insert(make_pair(i,(temp))).first;
//     		// cout<<searchi->second.left<<endl;
//     		if(l == 0){
//     			// cout<<"there";
//     			searchl = searchi;
//     		}
//     		if(r == 0){
//     			// cout<<"here";
//     			searchr = searchi;
//     		}

// 			searchl->second->left->count = cur;
// 			searchl->second->left->right = searchr->second->right;		
//     		searchr->second->right->count = cur;
//     		searchr->second->right->left = searchl->second->left;
//     		if(cur>max)max=cur;
//     		// printf("<%ld,%ld,%d> i=%ld\n",searchl->second->left->key,searchr->second->right->key,cur,i);
//     	}
    	
//     	return max;
//     }
// };
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
    	unordered_map<int,int> m;
		int l;
		int r;
		int cur;
		auto searchl = m.find(1);
		auto searchr = m.find(1);
		int max = 0;
    	for(auto i : nums){
    		// auto i = long(_i);
    		if(m.find(i)!=m.end()){
    			continue;
    		}
    		searchl = m.find(i-1);
    		if(searchl!=m.end()){
    			l = searchl->second;
    		}else{
    			l = 0;
    		}
    		searchr = m.find(i+1);
    		if(searchr!=m.end()){
    			r = searchr->second;
    		}else{
    			r = 0;
    		}
    		cur = l + r + 1;
    		m[i-l] = cur;
    		m[i+r] = cur;
    		m[i] = cur;
    		if(cur>max)max=cur;
    		// printf("<%ld,%ld,%d> i=%ld\n",i-l,i+r,cur,i);
    	}
    	
    	return max;
    }
};

int main(){
	Solution a;
	// int v[] = {100,4,200,1,3,2};//4
	int v[] = {0,3,7,2,5,8,4,6,0,1};//9
	// int v[] = {1};// 1
	// int v[] = {4,0,-4,-2,2,5,2,0,-8,-8,-8,-8,-1,7,4,5,5,-4,6,6,-3};
	vector<int> vec(v,v+sizeof(v)/sizeof(v[0]));
	cout<<a.longestConsecutive(vec)<<endl;
}