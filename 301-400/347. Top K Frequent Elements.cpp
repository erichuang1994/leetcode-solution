#include <iostream>
#include <vector>
#include <map>
using namespace std;
// 下面是nlg(k)的解法
// class Solution {
// public:
//     vector<int> topKFrequent(vector<int>& nums, int k) {
//         unordered_map<int,int> counts;
//         priority_queue<int,vector<int>,greater<int>> max_k;
//         for(auto i : nums){
//         	counts[i]++;
//         }
//         for(auto & i : counts){
//         	max_k.push(i.second);
//         	while(max_k.size()>k){
//         		max_k.pop();
//         	}
//         }
//         vector<int> res;
//         for(auto & i : counts){
//         	if(i.second >= max_k.top()){
//         		res.push_back(i.first);
//         	}
//         }
//         return res;
//     }
// };
// 下面是O(n)的解法
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> counts;
        for(auto i : nums){
        	counts[i]++;
        }
        vector<vector<int>> buckets(nums.size()+1);
        for(auto & i : counts){
        	buckets[i.second].push_back(i.first);
        }
        reverse(begin(buckets),end(buckets));
        vector<int> res;
        for(auto & bucket : buckets){
        	for(auto i : bucket){
        		res.push_back(i);
        		if(res.size() == k){
        			return res;
        		}
        	}
        }
        return res;
    }
};
int main(){
	vector<int> nums;
	int a[]={4,1,-1,2,-1,2,3};
	for(int i = 0;i<sizeof(a)/sizeof(*a);i++){
		nums.push_back(a[i]);
	}
	Solution s;
	s.topKFrequent(nums,2);
}